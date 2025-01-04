#include<iostream>
using namespace std;


class priorityQueue {
public:
	static int count;
	int id;
	int priority;
	float time;
	priorityQueue* next = nullptr;

	priorityQueue():id(0), priority(0), time(0), next(nullptr){}

	priorityQueue(int priority, int time): id(count++), priority(priority), time(time), next(nullptr){}

    
	void deleteQ(priorityQueue*&head)
    {
        priorityQueue*temp=head;

        while(temp!=nullptr)
        {
            temp=temp->next;
            delete head;
            head=temp;
            cout<<"deleted ";
        }

    }

	void insert(int priority, int time, priorityQueue*& head)
	{
		priorityQueue* newTask = new priorityQueue(priority, time);
		///for empty
		if (head == nullptr)
		{
			head = newTask;
			//cout << "ok1" << endl;

			return;
		}

		///if new has more pri than head
		if (newTask->priority < head->priority)
		{
			newTask->next = head;
			head = newTask;
			//cout << "ok2" << endl;
			return;
		}

	

		///                   n      c
		/// 2 3 4 5 6 7 8 9 9 9      11  12 
		///insert n=9
		///if it is between somewhere
	
		priorityQueue* temp = head;
		priorityQueue* prev = nullptr;

		while (temp != nullptr && newTask->priority >= temp->priority)
		{
			prev = temp;
			temp = temp->next;
		}

		///insert the new task between prev and temp, this also handles the end of list as temp can be equal to nullptr so new is added between prev->next=new, and new->next=nullptr/temp;
		prev->next = newTask;
		newTask->next = temp;

		//cout << "ok3" << endl;

	}


	void changePriority(int id, int newPriority, priorityQueue*& head)
	{
		if (id >= count || head == nullptr)
		{
			cout << "Invalid ID" << endl;
			return;
		}

		priorityQueue* toChange = head;
		priorityQueue* prev = nullptr;

		while (toChange != nullptr && toChange->id != id)
		{
			prev = toChange;
			toChange = toChange->next;
		}

		if (toChange == nullptr)
		{
			cout << "ID not found." << endl;
			return;
		}

		/// remove the node from its current position
		if (prev == nullptr) 
		{
			head = toChange->next;  
		}
		else
		{
			prev->next = toChange->next; 
		}

		toChange->priority = newPriority;

		///insert the node at the correct position
		if (head == nullptr || newPriority < head->priority)
		{
			toChange->next = head;
			head = toChange;
			return;
		}

		priorityQueue* temp = head;
		while (temp->next != nullptr && temp->next->priority <= newPriority)
		{
			temp = temp->next;
		}

		toChange->next = temp->next;
		temp->next = toChange;
	}

	void dequeue(priorityQueue*& head)
	{
		if (head == nullptr)
		{
			cout << "Queue Is Empty" << endl << endl;
			return;
		}

		priorityQueue* temp = head;
		head = head->next;
		delete temp;
	}


	void display(priorityQueue* head)
	{

		while (head != nullptr)
		{
			cout << "ID: " << head->id << "\tPriority: " << head->priority << "\tTime: " << head->time << endl;
			head = head->next;
		}
		cout << endl;

	}
};

int priorityQueue::count = 0;


int main()
{

	priorityQueue* head = new priorityQueue();
	head = nullptr;


	int s;
	cout << "Enter size: ", cin >> s;

	cout << "Enter elements: " << endl;
	for (int i = 1; i <= s; i++)
	{
		int p; float t;
		cout << "Priority: ", cin >> p, cout << "CPU Burst Time: ", cin >> t, cout << endl;
		head->insert(p, t, head);

	}

	int id,  newPri;

	start:
		system("cls");

		cout << "Your Queue: " << endl;
		head->display(head);


		int option = 0;
		cout << "1. Change Priority\n2.Enqueue\n3.Dequeue" << endl, cin >> option;

		if(option==1)
		{
			cout << "Enter ID of the task to change priority of: ", cin >> id;
			cout << "Enter new priority: ", cin >> newPri;
			head->changePriority(id, newPri, head);
		}
		else if (option == 2)
		{
			int p; float t;
			cout << "Priority: ", cin >> p, cout << "CPU Burst Time: ", cin >> t, cout << endl;
			head->insert(p, t, head);
		}
		else if (option == 3)
		{
			head->dequeue(head);
		}

	goto start;

    head->deleteQ(head);




	return 0;
}