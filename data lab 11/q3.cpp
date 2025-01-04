#include<iostream>
#include<vector>
using namespace std;



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

    void heapify()
    {
        
        int s=arr.size()/2 -1;
        for(int i=s;i>=0;i--)
            reheapDown(i);
    }


    void displayAndremove()
    {
        int x=1;
        while(arr.size()>0 and x++<=10) //display top 10 elements
        {
            cout<<arr[0]<<" ";
            deleteMax();
        }
        cout<<endl;

        //clear the vector
        arr.clear();
    }

};



class User {
public:
    int userId;
    int Id;

    static int tweetId;
    vector<int> tweets;  //tweets id
    vector<int> following;  //following users id

};

int User::tweetId = 1;

class Twitter
{
public:
    vector<User> users;
    static int count;

    Twitter() 
    {
        users.resize(10);
        //assigning userIds to users
        for(int i=0;i<10;i++)
            users[i].userId = i+1;
    }

    void postTweet(int userId, int tweetId) 
    {
        users[userId-1].tweets.push_back(tweetId);
    }

    void follow(int followerId, int followeeId) 
    {
        users[followerId-1].following.push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) 
    {
        //remove followee from the follower's following list
        for (int i = 0; i < users[followerId-1].following.size(); i++) 
        {
            if (users[followerId-1].following[i] == followeeId) 
            {
                users[followerId-1].following.erase(users[followerId-1].following.begin() + i);
                break;
            }
        }
    }

    void getNewsFeed(int userId) 
    {
        maxHeap m;
        //add user's tweets to newsFeed
        for(int i=0;i<users[userId-1].tweets.size();i++)
            m.insert(users[userId-1].tweets[i]);

        //add followee's tweets to newsFeed
        for(int i=0;i<users[userId-1].following.size();i++)
            for(int j=0;j<users[users[userId-1].following[i]-1].tweets.size();j++)
                m.insert(users[users[userId-1].following[i]-1].tweets[j]);

        //return top 10 recent tweet ids in the users news feed only
        cout<<"News Feed for User "<<userId<<": ";
        m.displayAndremove();
    }

};

int Twitter::count = 1;


int main()
{

    Twitter* twitter= new Twitter();
    twitter->postTweet(1,5);
    twitter->getNewsFeed(1);

    twitter->follow(1,2);
    twitter->postTweet(2,6);

    twitter->getNewsFeed(1);

    twitter->unfollow(1,2);
    twitter->getNewsFeed(1);

    //to test the case when the news feed has more than 10 tweets

    twitter->postTweet(1,7);
    twitter->postTweet(1,8);
    twitter->postTweet(1,9);
    twitter->postTweet(1,10);
    twitter->postTweet(1,11);
    twitter->postTweet(1,12);
    twitter->postTweet(1,13);
    twitter->postTweet(1,14);
    twitter->postTweet(1,15);
    twitter->postTweet(1,16);
    twitter->postTweet(1,17);
    twitter->postTweet(1,18);
    twitter->postTweet(1,19);
    twitter->postTweet(1,20);
    twitter->postTweet(1,21);
    twitter->postTweet(1,22);
    twitter->postTweet(1,23);
    twitter->postTweet(1,24);
    twitter->postTweet(1,25);
    twitter->postTweet(1,26);

    twitter->getNewsFeed(1);

    delete twitter;

    return 0;
}