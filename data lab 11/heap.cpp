#include<iostream>
#include<vector>
using namespace std;
#include <cmath>


class minHeap{
    public:
    vector<int> arr;

    void insert(int x)
    {
        arr.push_back(x);
        int s=arr.size();

        for(int i=s-1;i>0;)
        {
            if(arr[i]<arr[(i-1)/2])
                {
                    swap(arr[i],arr[(i-1)/2]);
                    i=(i-1)/2;
                }
            else
                break;
        }

    }


    void reheapUp(int i)
    {
        if(i==0)
            return; //parent pr agya to return
        if(arr[i]<arr[(i-1)/2])
        {
            swap(arr[i],arr[(i-1)/2]);
            reheapUp((i-1)/2);
        }

    }

    void insertAndReheap(int x)
    {
        arr.push_back(x);
        reheapUp(arr.size()-1);
    }

    void deleteMin()
    {
        if(arr.size()==0)
            return;
        //end wala element ko start pr le aao, or end wala pop krdo
        arr[0]=arr[arr.size()-1];
        arr.pop_back();

        int s=arr.size();

        //find smallest child, if that is smaller than the parent, swap it with the parent
        for(int i=0;i<s;)
        {
            int left=2*i+1;
            int right=2*i+2;

            int smallest=i;

            if(left<s and arr[left]<arr[smallest])
                smallest=left;
            if(right<s and arr[right]<arr[smallest])
                smallest=right;
            if(smallest!=i)   //if smallest is not the parent, swap it with the parent
            {
                swap(arr[i],arr[smallest]);
                i=smallest; //i ko smallest mei le aao, because smallest pr parent chala gya h
            }
            else
                break;

        }

    }


    void reheapDown(int i)
    {
        //base case
        if(i>=arr.size())
            return;

        int s=arr.size();
        int left=2*i+1;
        int right=2*i+2;

        int smallest=i;

        if(left<s and arr[left]<arr[smallest])
            smallest=left;
        if(right<s and arr[right]<arr[smallest])
            smallest=right;
        if(smallest!=i)   //if smallest is not the parent, swap it with the parent
        {
            swap(arr[i],arr[smallest]);
            reheapDown(smallest);
        }

    }

    void deleteAndReheap()
    {
        if(arr.size()==0)
            return;
        //end wala element ko start pr le aao, or end wala pop krdo
        arr[0]=arr[arr.size()-1];
        arr.pop_back();

        reheapDown(0);
    }

    void display()
    {
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }


    void heapify()
    {
        
        int s=arr.size()/2 -1;
        for(int i=s;i>=0;i--)
            reheapDown(i);
    }

};


class maxHeap{
    public:
    vector<int> arr;

    void insert(int x)
    {
        arr.push_back(x);
        int s=arr.size();

        for(int i=s-1;i>0;)
        {
            if(arr[i]>arr[(i-1)/2])
                {
                    swap(arr[i],arr[(i-1)/2]);
                    i=(i-1)/2;
                }
            else
                break;
        }

    }


    void reheapUp(int i)
    {
        if(i==0)
            return; //parent pr agya to return
        if(arr[i]>arr[(i-1)/2])
        {
            swap(arr[i],arr[(i-1)/2]);
            reheapUp((i-1)/2);
        }

    }

    void insertAndReheap(int x)
    {
        arr.push_back(x);
        reheapUp(arr.size()-1);
    }


    void deleteMax()
    {
        if(arr.size()==0)
            return;
        //end wala element ko start pr le aao, or end wala pop krdo
        arr[0]=arr[arr.size()-1];
        arr.pop_back();

        int s=arr.size();

        //find largest child, if that is larger than the parent, swap it with the parent
        for(int i=0;i<s;)
        {
            int left=2*i+1;
            int right=2*i+2;

            int largest=i;

            if(left<s and arr[left]>arr[largest])
                largest=left;
            if(right<s and arr[right]>arr[largest])
                largest=right;
            if(largest!=i)   //if largest is not the parent, swap it with the parent
            {
                swap(arr[i],arr[largest]);
                i=largest; //i ko largest mei le aao, because largest pr parent chala gya h
            }
            else
                break;

        }
    }


    void reheapDown(int i)
    {
        //base case
        if(i>=arr.size())
            return;

        int s=arr.size();
        int left=2*i+1;
        int right=2*i+2;

        int largest=i;

        if(left<s and arr[left]>arr[largest])
            largest=left;
        if(right<s and arr[right]>arr[largest])
            largest=right;
        if(largest!=i)   //if largest is not the parent, swap it with the parent
        {
            swap(arr[i],arr[largest]);
            reheapDown(largest);
        }

    }


    void deleteAndReheap()
    {
        if(arr.size()==0)
            return;
        //end wala element ko start pr le aao, or end wala pop krdo
        arr[0]=arr[arr.size()-1];
        arr.pop_back();

        reheapDown(0);
    }


    void display()
    {
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void heapify()
    {
        
        int s=arr.size()/2 -1;
        for(int i=s;i>=0;i--)
            reheapDown(i);
    }

};



int main()
{


    cout<<"Min Heap"<<endl;
    vector<int> v={10,20,30,25,5,40,35};
    minHeap h;
    for(int i=0;i<v.size();i++)
        //h.insert(v[i]); //using loop
        h.insertAndReheap(v[i]); //using recursion


    //h.deleteMin();//using loop
    //h.deleteAndReheap();//using recursion
    h.display();

    cout<<"Heapify"<<endl;
    minHeap h2;
    h2.arr={10,20,30,25,5,40,35};
    h2.heapify();
    h2.display();

    cout<<"Max Heap"<<endl;
    vector<int> v2={10,20,30,25,5,40,35};
    maxHeap h3;
    for(int i=0;i<v2.size();i++)
        //h3.insert(v2[i]); //using loop
        h3.insertAndReheap(v2[i]); //using recursion

    //h3.deleteMax();//using loop
    //h3.deleteAndReheap();//using recursion
    h3.display();

    cout<<"Heapify"<<endl;
    maxHeap h4;
    h4.arr={10,20,30,25,5,40,35};
    h4.heapify();
    h4.display();



    return 0;
}