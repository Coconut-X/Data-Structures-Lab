#include<iostream>
using namespace std;

class list {

public:

	int data;
	list* next;
	list* prev;


	list():data(0),next(nullptr), prev(nullptr){}

	list(int data): data(data), next(nullptr), prev(nullptr) {}

    
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

	void insert(int data, list* &head)
	{

		list* node = new list(data);

		if (head == nullptr) 
		{
			head = node;
			node->next = nullptr;
			return;
		}

		if (head->next == nullptr)
		{
			head->next = node;
			node->prev = head;
			return;
		}

		list* current = head;

		while (current->next!= nullptr)
		{
			current = current->next;
		}

		current->next = node;
		node->prev = current;
		node->next = nullptr;
	}

	void display(list* head)
	{
		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}

	void reverse(int k, list*& head)
	{
		if (head == nullptr || k <= 1)
			return;

		list* current = head;
		list* prevTail = nullptr; //  previous group's tail
		list* newHead = nullptr;

		while (current != nullptr)
		{
			/// current group
			list* groupHead = current;
			list* groupTail = current;
			int count = 1;

			// go to k-th node of the current group
			while (count < k && groupTail->next != nullptr)
			{
				groupTail = groupTail->next;
				count++;
			}

			// keep next group's head
			list* nextGroup = groupTail->next;

			///reversing the current group
			list* prev = nextGroup;  // linking the next group after reversal
			list* temp = groupHead;

			while (temp != nextGroup)
			{
				list* nextNode = temp->next;
				temp->next = prev;
				prev = temp;
				temp = nextNode;
			}

			///agr pehla group tha to update the head
			if (newHead == nullptr)
			{
				newHead = groupTail; 
			}

			if (prevTail != nullptr)
			{
				prevTail->next = groupTail; 
			}

			prevTail = groupHead;  
			current = nextGroup;
		}

		head = newHead; 
	}
};

int main()
{
	list* head = nullptr;

	int size;
	cout << "Enter the size of the list: ";
	cin >> size;

	for (int i = 1; i <= size; i++) {
		int data;
		cout << "Enter element " << i << ": ";
		cin >> data;
		head->insert(data, head);
	}

	cout << "Original List: ";
	head->display(head);

	int k;
	cout << "Enter the group size for reversal (k): ";
	cin >> k;

	head->reverse(k, head);

	cout << "Reversed List in groups of " << k << ": ";
	head->display(head);

    head->deleteList(head);

	return 0;
}
