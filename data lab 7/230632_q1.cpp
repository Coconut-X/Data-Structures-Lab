#include<iostream>
#include<vector>
using namespace std;


int temp=0;
    vector<vector<int>> v(3);



void display()
{
    for(int i=0;i<3;i++)
    {
        cout<<"Tower "<<i+1<<": ";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void hanoi(int n,int start,int end)
{
    if(n==1)
    {
        temp=v[start-1].back();
        v[start-1].pop_back();
        v[end-1].push_back(temp);
       
        return;
    }

    hanoi(n-1,start,6-start-end);
    hanoi(1,start,end);
    hanoi(n-1,6-start-end,end);

    return;
   
}



int main()
{
    int disks=2;

    for(int i=0;i<disks;i++)
    {
        v[0].push_back(disks-i);
    }

    cout<<"Initial State"<<endl;
    display();

    hanoi(disks,1,3);

    cout<<"Final State"<<endl;
    display();
   



    return 0;
}