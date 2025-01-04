#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int counter=0;


vector<vector<int>> allPermutations;
vector<vector<int>> allCombination;
vector<int> temp;

void moveToAllPerm(vector<int>& arr, int r)
{
    counter++;
    //clear temp vector
    temp.clear();

    for(int i = 0; i < r; i++) {
        temp.push_back(arr[i]);
    }

    allPermutations.push_back(temp);
    cout << endl;
}


void removeRepeated(vector<vector<int>> &allPermutations)
{
    for(int i=0;i<allPermutations.size();i++)
    {
        for(int j=i+1;j<allPermutations.size();j++)
        {
            if(allPermutations[i]==allPermutations[j])
            {
                allPermutations.erase(allPermutations.begin()+j);
                j--;
            }
        }
    }
}


void printPermutation()
{
    for(int i=0;i<allPermutations.size();i++)
    {
        for(int j=0;j<allPermutations[i].size();j++)
        {
            cout<<allPermutations[i][j]<<" ";
        }
        cout<<endl;
    }
}



void findAllPermutations(int n, int r, vector<int> arr, int depth = 0)
{
    if (r == 0)  // base case, sotre the permutation when r reaches 0
    {
        moveToAllPerm(arr, depth);
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(arr[depth], arr[i]);  

        findAllPermutations(n, r-1, arr, depth + 1);

        swap(arr[depth], arr[i]);  //  undo the swap
    }

    findAllPermutations(n, r-1, arr, depth);  // to find nPn-1 permutations
}


void printCombination()
{
    for(int i=0;i<allCombination.size();i++)
    {
        for(int j=0;j<allCombination[i].size();j++)
        {
            cout<<allCombination[i][j]<<" ";

        }
        cout<<endl;
    }
}

void moveToAllComb(vector<int> arr, int r)
{
    counter++;
    //clear temp vector
    temp.clear();

    for(int i = 0; i < r; i++) {
        temp.push_back(arr[i]);
    }

    allCombination.push_back(temp);
    cout << endl;
}


void findAllCombinations()
{
    //simply sort the all arrays in allpermutations, further remove repeated

    for(int i=0;i<allPermutations.size();i++)
    {
        sort(allPermutations[i].begin(),allPermutations[i].end());
    }

    removeRepeated(allPermutations);

    for(int i=0;i<allPermutations.size();i++)
    {
        moveToAllComb(allPermutations[i],allPermutations[i].size());
    }
    
}


int main()
{
    vector<int> arr = {1, 2, 3}; 
    int n = arr.size();
    int r = n; 


    cout << "All permutations of size "<<endl;
    findAllPermutations(n, r, arr);

    removeRepeated(allPermutations);
    printPermutation();

    cout<<"Total Permutations: ";
    cout<<allPermutations.size()<<endl;


    cout << "All combinations of size " <<endl;
    findAllCombinations();
    printCombination();

    cout<<"Total Combinations: ";
    cout<<allCombination.size()-1<<endl;

   

    return 0;
}
