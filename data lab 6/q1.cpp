#include<iostream>
using namespace std;

class node {

public:
	int data;
	node* prev;
	node* next;

	node() : prev(nullptr), next(nullptr){}
	node(int d) :data(d), prev(nullptr), next(nullptr) {}




	void insertAtEnd(node*& head, int data)
	{
		node* currentHead = head;

		node* newNode = new node(data);
		/*newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;*/

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
			return;
		}

		while (currentHead->next != NULL)
		{
			currentHead = currentHead->next;
		}
		currentHead->next = newNode;
		newNode->prev = currentHead;
		newNode->next = nullptr;

		cout << "Value Inserted At Tail" << endl;
	}

	void displayList(node* head)
	{
		if (head == nullptr)
		{
			cout << "List Is Empty!" << endl << endl;
			return;
		}

		while (head != nullptr)
		{
			cout << head->data << ((head->next != nullptr) ? ", " : "\n\n");
			head = head->next;
		}
	}


	void updateNodeDataByIndex(node* head, int index, int data)
	{
		if (head == NULL)
		{
			cout << "List Is Empty..!" << endl << endl;
			return;
		}
		node* currentHead = head;
		int i = 0;

		while (currentHead != NULL && i++ < index)
		{
			currentHead = currentHead->next;
		}

		if (currentHead == NULL) return;
		currentHead->data = data;
		cout << "Node Updated!" << endl << endl;
	}

	void updateNodeDataByValue(node* head, int key, int data)
	{
		if (head == NULL)
		{
			cout << "List Is Empty..!" << endl << endl;
			return;
		}

		int i = 0;
		node* currentHead = head;
		while (currentHead != NULL)
		{
			if (currentHead->data == key)
			{
				updateNodeDataByIndex(head, i, data);
			}
			i++;
			currentHead = currentHead->next;
		}
		cout << "Node Updated!" << endl << endl;
	}


	void searchNode(node* head, int key)
	{
		node* temp = head;
		int i = 0;
		bool found = 0;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				cout << "Found At Index " << i << endl;
				found = 1;
			}
			temp = temp->next;
			i++;
		}

		if (!found) cout << "Not Found" << endl;

		cout << endl;
	}


	int lengthOfList(node* head)
	{
		if (head == NULL) return 0;
		int length = 0;
		for (; head != NULL && (head = head->next); length++);
		return length + 1;

	}


	void sortList(node*& head, int type)
	{
		if (head == nullptr)
		{
			cout << "List Is Empty" << endl;
			return;
		}

		int length = lengthOfList(head);

		for (int i = 0; i < length; i++)
		{
			bool found = 0;
			node* current = head;
			node* NextNode = head->next;

			for (int j = 0; j < length - 1 - i; j++)
			{

				if ((type == 1 && current->data > NextNode->data) || (type == -1 && current->data < NextNode->data))
				{
					//if (temp == head);

					swap(current->data, NextNode->data);

					//int temp = current->data;
					//current->data = NextNode->data;
					//NextNode->data = temp;
					found = true;
					//cout << "swapped";
				}

				current = NextNode;
				NextNode = NextNode->next;
			}

			if (!found)
			{
				cout << "List Sorted" << endl;
				return;
			}
		}
	}



	void insertSorted(node*& head, int data)
	{
		node* newNode = new node(data);
	
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
			cout << "Inserted" << endl;
			return;
		}
		sortList(head, 1);

		//now inserting in sorted order 

		node* temp = head;// 1  2`	 3  4  5    7  8  9  10

		while (temp->next != nullptr)
		{
			if (temp->data > newNode->data)
			{
				node* prev = temp->prev;

				newNode->prev = temp->prev;
				temp->prev = newNode;
				newNode->next = temp;

				if (prev != nullptr)
				{
					prev->next = newNode;
				}
				else
				{
					head = newNode;
				}

				cout << "inserted";
				return;
			}
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;

		

	}

};


int main()
{
	node* head = new node();

	head = nullptr;

	int x = 0;
	head->insertAtEnd(head,4);
	head->insertAtEnd(head, 5);

	head->insertAtEnd(head, 1);
	head->insertAtEnd(head, 9);
	head->insertAtEnd(head, 10);

	head->displayList(head);

	head->insertSorted(head, 6);
	
	head->displayList(head);

	


	return 0;
}