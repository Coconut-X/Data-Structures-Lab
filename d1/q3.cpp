#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
template<typename T>
class path {

public:
	T data;
	path* next;
	bool isVisited = false;

	path(int data): data(data), next(nullptr){}

    void deleteList(path*&head)
    {
        path*temp=head;

        while(temp!=nullptr)
        {
            temp=temp->next;
            delete head;
            head=temp;
            //cout<<"deleted ";
        }

    }


	void insert(path*& head, int data)
	{
		path* n = new path(data);
		if (head == nullptr)
		{
			head = n;
			return;
		}
		path* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = n;
	}

	void makePath(path*& head, int s)
	{
		for (int i = 0; i < 25; i++)
			arr.push_back(i);
		
		int end = s;
		srand(time(0));

		for (int i = 0; i < s ; i++)
		{
			int index = rand() % end;
			int val = arr[index];
			arr.erase(arr.begin()+index);
			insert(head, val);
			end--;
		}

	}

	void display(path* head)
	{
		while (head != nullptr)
		{
			cout << head->data<<" ";
			head = head->next;
		}
	}


	void mergeList(path*& small, path*& big,int index)
	{
		path* temp = small;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		srand(time(0));

		int x = rand() % index;
		path* temp2 = big;
		for (int i = 0; i <= x; i++)
		{
			temp2 = temp2->next;
		}

		temp->next = temp2;

		cout << endl << "point " << temp->data << " pointed to " << temp2->data << endl;
	}


	void findMergePoint(path* a, path* b)
	{
		while (a != nullptr)
		{
			a->isVisited = true;
			a=a->next;
		}

		while (b != nullptr)
		{
			if (b->isVisited)
			{
				cout << "Merge Point: " << b->data;
				return;
			}	
			b=b->next;
		}
		cout << "No merge point" << endl;
	}

};


int main()
{

	int s1 = 24;
	int s2 = 20;

	path<int>* path1 = new path<int>(0);
	path1 = nullptr;

	path1->makePath(path1, s1);

	path<int>* path2 = new path<int>(0);
	path2 = nullptr;

	cout << endl << endl;
	path2->makePath(path2, s2);


	if (s2 < s1) path1->mergeList(path2, path1, s1);
	else path1->mergeList(path1, path2, s2);

	path1->display(path1);
	cout << endl << endl;
	path2->display(path2);
	cout << endl;



	path1->findMergePoint(path1,path2);

    cout<<endl;

    path1->deleteList(path1);
    path2->deleteList(path2);



	return 0;
}