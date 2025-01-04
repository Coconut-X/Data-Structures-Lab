#include <iostream>
#include <string>
#include<ctime>
#include<math.h>
using namespace std;



template<typename T>
class list {
	public:
	T data;
	list* next;
    //list*Head;
	bool visited;



	void deleteList(list*&head)
    {
        list*temp=head;

        while(temp!=nullptr)
        {
            temp=temp->next;
            delete head;
            head=temp;
            cout<<"deleted ";
        }

    }

	list():data(0), next(nullptr), visited(false) {}
	list(int data):data(data), next(nullptr), visited(false){}

	void insert(list*&head,int d)
	{
		list* node = new list(d);
		

		if (head == nullptr)
		{
			head = node;
			return;
		}

		list* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = node;

		
	}

	void display(list* head)
	{

		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl << endl;
	}

	int length(list* head)
	{
		if (head == nullptr) return 0;

		int count = 0;
		while (head != nullptr)
		{
			count++;
			head = head->next;
		}

		return count;

	}


	/*void makeCircular(list*& head)
	{

		srand(time(NULL));

		int index = rand() % length(head);
		list* mid = nullptr;
		list* tail = head;

		int count = 0;

		while (tail->next != nullptr)
		{
			count++;
			if (count == index) mid = tail;
			tail = tail->next;
		}

		tail->next = mid;

		cout << "Made Circular" << endl;

	}*/


	void makeCircular(list*& head)
	{
		if (!head) return;

		srand(time(NULL)); 

		int index = rand() % length(head); 
		list* mid = nullptr;
		list* tail = head;

		int count = 0;

		
		while (tail->next != nullptr)
		{
			if (count == index) mid = tail;  
			tail = tail->next;
			count++;
		}

		if (mid == nullptr) mid = head;  

		tail->next = mid;
		//cout <<endl<< tail->data << endl;
		cout << "Made circular by pointing tail to node with value: " << mid->data << endl;
	}



	bool isCircular(list* head)
	{
		while (head->next != nullptr)
		{
			if (head->visited)
			{
				cout << "it is circular" << endl;
				return 1;
			}
			head->visited = true;
			head = head->next;
		}
		cout << "It is not circular" << endl;
		return 0;
	}

	void removeCircular(list*& head)
	{

		cout<<"circularity removed"<<endl;

	}



};


int main()
{
	
		list<int>* head = new list<int>;

		head = nullptr;

		cout << "Enter size: " << endl;
		int s;
		cin >> s;

		cout << "Enter elements: " << endl;


		for (int i = 1; i <= s; i++)
		{
			int x;
			cin >> x;
			head->insert(head, x);
		}

		cout << "Original List " << endl;
		head->display(head);

		cout << "Calling function to check if it is circular" << endl;
	head->isCircular(head);

	cout << "Making it circular" << endl;
	head->makeCircular(head);
	//cout << "Calling function to check if it is circular" << endl;

    head->isCircular(head);

	//cout << "Displaying list to make sure it was circular" << endl;

	//head->display(head);

    head->deleteList(head);

	

	return 0;
}