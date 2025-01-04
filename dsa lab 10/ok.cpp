#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

#include <sstream>

using namespace std;



class city{
    public:
    //contains distance to isb, lahore, gujranwala, karachi
    vector<vector<int>> distances;
    //contains 5 arrays of 4 elements each, each array contains distance to all cities
};

class list{
    public:
    city* c;
    list* next;
    list(city* c):c(c),next(nullptr){}

     int findMinimumPathForSigleNode(city* startCity, const vector<city*>& cities, const vector<int>& visitOrder) {
        int minDist = INT_MAX;
        vector<int> bestRoute;


        //here we will traverse all possible permutations of the cities to find the minimum distance
       
        vector<int> currentOrder = visitOrder;
        do {
            int distance = 0;
            city* currentCity = startCity;

            for (int cityIndex : currentOrder) {    //calculating the distance for the current order
                distance += currentCity->distances[0][cityIndex];
                currentCity = cities[cityIndex];
            }

            distance += currentCity->distances[0][0];   //adding the distance to return to the starting city

            if (distance < minDist) {
                minDist = distance;
                bestRoute = currentOrder;
            }
        } while (next_permutation(currentOrder.begin(), currentOrder.end()));

       //showing the optimal route and the minimum distance
        cout << "Optimal Route: Islamabad";
        for (int cityIndex : bestRoute) {
            if (cityIndex == 1) cout << " -> Lahore";
            else if (cityIndex == 2) cout << " -> Gujranwala";
            else if (cityIndex == 3) cout << " -> Karachi";
        }
        cout << " -> Islamabad";
        cout << " Minimum Distance: " << minDist << " km" << endl;

        return minDist;
    }

    void findOptimumRoute(string input, city* startCity, vector<city*> cities) {
    
        vector<int> visitOrder;
        unordered_map<string, int> cityMap = {{"Islamabad", 0}, {"Lahore", 1}, {"Gujranwala", 2}, {"Karachi", 3}};

        //using string stream to split the input string by commas or tokens
        stringstream ss(input);
        string cityName;
        while (getline(ss, cityName, ',')) {
            cityName.erase(remove(cityName.begin(), cityName.end(), ' '), cityName.end()); // remove spaces
            if (cityMap.find(cityName) != cityMap.end()) {
                visitOrder.push_back(cityMap[cityName]);
            }
        }

        findMinimumPathForSigleNode(startCity, cities, visitOrder);
    }

};


int main()
{

    city* isb = new city();

    isb->distances.push_back({0,300,250,500}); //distance to isb lahore gujranwala karachi route 1
    isb->distances.push_back({0,300,250,500}); //distance to isb lahore gujranwala karachi route 2
    isb->distances.push_back({0,300,250,500}); //distance to isb lahore gujranwala karachi route 3
    isb->distances.push_back({0,300,250,500}); //distance to isb lahore gujranwala karachi route 4
    isb->distances.push_back({0,300,250,500}); //distance to isb lahore gujranwala karachi route 5


    city* lahore = new city();

    lahore->distances.push_back({300,20,89,150}); //distance to isb lahore gujranwala karachi route 1
    lahore->distances.push_back({300,38,92,172}); //distance to isb lahore gujranwala karachi route 2
    lahore->distances.push_back({300,51,101,158}); //distance to isb lahore gujranwala karachi route 3
    lahore->distances.push_back({300,11,42,111}); //distance to isb lahore gujranwala karachi route 4
    lahore->distances.push_back({300,8,39,62}); //distance to isb lahore gujranwala karachi route 5


    city* gujranwala = new city();

    gujranwala->distances.push_back({250, 89, 11, 69}); // Route 1
    gujranwala->distances.push_back({250, 92, 15, 71}); // Route 2
    gujranwala->distances.push_back({250, 101, 9, 77}); // Route 3
    gujranwala->distances.push_back({250, 42, 2, 89}); // Route 4
    gujranwala->distances.push_back({250, 39, 4, 85}); // Route 5

    city* karachi = new city();
    karachi->distances.push_back({500, 150, 69, 22}); // Route 1
    karachi->distances.push_back({500, 172, 71, 28}); // Route 2
    karachi->distances.push_back({500, 158, 77, 59}); // Route 3
    karachi->distances.push_back({500, 111, 89, 51}); // Route 4
    karachi->distances.push_back({500, 62, 85, 72}); // Route 5


  vector<city*> cities = {isb, lahore, gujranwala, karachi};

    list* head = new list(isb);
    head->next = new list(lahore);
    head->next->next = new list(gujranwala);
    head->next->next->next = new list(karachi);


    cout<<"Enter start city:  \n 1. Islamabad \n 2. Lahore \n 3. Gujranwala \n 4. Karachi"<<endl;
    int start;
    cin>>start;

    cin.ignore();

    string input;
    cout << "Enter the list of cities you wish to visit separated by commas (e.g., Lahore, Gujranwala, Karachi): ";
    getline(cin, input);



    head->findOptimumRoute(input, cities[start-1], cities);

    cout<<"Thank you for using the City Route Planner. Safe travels!"<<endl;

    return 0;
}



