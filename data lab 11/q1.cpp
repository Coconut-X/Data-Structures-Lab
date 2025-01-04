#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class maxHeap {
public:
    vector<vector<int>> arr;
    vector<int> ans;

    maxHeap(int s) {
        arr = {vector<int>(s, 0), vector<int>(s, 0)};
    }

    void display() {
        cout << "\n";
        for (int i = 0; i < arr[0].size(); i++) {
            cout << "Element: " << arr[1][i] << " Frequency: " << arr[0][i] << endl;
        }
    }

    void reheapDown(int i) 
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = arr[0].size();

        if (left < n && arr[0][left] > arr[0][largest])
            largest = left;

        if (right < n && arr[0][right] > arr[0][largest])
            largest = right;

        if (largest != i) {
            swap(arr[0][i], arr[0][largest]);
            swap(arr[1][i], arr[1][largest]);

            reheapDown(largest);
        }
    }

    void heapify() {
        int s = arr[0].size() / 2 - 1;
        for (int i = s; i >= 0; i--)
            reheapDown(i);
    }

    void buildHeap() 
    {
        int n = arr[0].size();
        for (int i = n / 2 - 1; i >= 0; i--)
            reheapDown(i);
    }

    void deleteAndReheap() 
    {
        if (arr[0].size() == 0)
            return;
        // move the last element to the root and pop it from the heap
        arr[0][0] = arr[0].back();
        arr[1][0] = arr[1].back();
        arr[0].pop_back();
        arr[1].pop_back();

        reheapDown(0);
    }

    void ktimes(int k) 
    {
        for (int i = 0; i < k; i++) 
        {
            cout << "Element: " << arr[1][0] << " Frequency: " << arr[0][0] << endl;
            if(arr[0][1]==0) //if no element has that frequency, break
                break;
            deleteAndReheap();
        }
    }

    void setFrequency(vector<int>& inputArr) 
    {
        sort(inputArr.begin(), inputArr.end());

        int index = 0;
        for (int i = 0; i < inputArr.size(); i++) {
            int count = 1;
           
            while (i + 1 < inputArr.size() && inputArr[i] == inputArr[i + 1])
                count++, i++; // count the frequency of the current element

            arr[0][index] = count;  // store the frequency
            arr[1][index] = inputArr[i];  // store the element
            index++;
        }
        buildHeap();
    }
};

int main() 
{
    vector<int> arr = {1, 2, 1, 2, 2, 3, 4};
    //vector<int> arr = {1,1,1,1};

    maxHeap h(arr.size());

    h.setFrequency(arr);
    cout<<"\n";
    h.ktimes(3);

    return 0;
}
