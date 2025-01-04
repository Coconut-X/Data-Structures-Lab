#include<iostream>
#include<vector>

using namespace std;


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

    void ktimes(int k)
    {
        for(int i=1;i<k;i++)
        {
            deleteAndReheap();
        }

        cout<<"Kth smallest element: "<<arr[0]<<endl;
    }

};


int main()
{

    vector<vector<int>> arr={
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50} 
        };  

        int k=3;

        minHeap h;
        for(int i=0;i<arr.size();i++)
            for(int j=0;j<arr[i].size();j++)
                h.insertAndReheap(arr[i][j]);

        
        cout<<"\n";
        h.ktimes(k);


}