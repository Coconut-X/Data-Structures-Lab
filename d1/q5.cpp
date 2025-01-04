#include<iostream>
#include<string>
#include<fstream>
using namespace std;



class song {

public:

	string name;
	song* next;


	song():name(" "), next(nullptr){}
	song(string name):name(name), next(nullptr) {}

	
	void deleteList(song*&head)
    {
        song*temp=head;

        while(temp!=nullptr)
        {
            temp=temp->next;
            delete head;
            head=temp;
            cout<<"deleted ";
        }

    }

	void saveNewSong(string name)
	{
		fstream songs;
		songs.open("playlist.txt", ios::app);
		songs << name << endl;
		songs.close();
	}
	
	void insertFromFile(string name, song*& head)
	{
		song* newSong = new song(name);
		if (head == nullptr)
		{
			head = newSong;
			return;
		}

		song* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newSong;
	}


	void insertAndSave(string name, song*& head)
	{

		song* newSong = new song(name);

		if (head == nullptr)
		{
			head = newSong;
			saveNewSong(name);
			return;
		}

		song* temp = head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newSong;
		saveNewSong(name);
	}
	
	void loadSongs(song*& head)
	{
		string s;
		fstream songs;
		songs.open("playlist.txt", ios::in);
		
		while (getline(songs, s))
		{
			
			insertFromFile(s, head);
		}

		songs.close();

	}

	void display(song* head)
	{
		int x = 1;

		while (head != nullptr)
		{
			cout <<x++<<". " <<head->name << endl;
			head = head->next;
		}
	}

	void updateFileAfterDeletion(song* head)
	{
		string s;
		fstream songs;
		songs.open("playlist.txt", ios::out);

		while (head!=nullptr)
		{
			songs << head->name << endl;
			head = head->next;
		}

		songs.close();
	}


	void deleteSong(song*& head, song*& current)
	{
		display(head);
		cout << "Enter Song Number: " << endl;
		int number;
		cin >> number;

		song* temp = head;

		///deleting the head (first song)
		if (number == 1)
		{
			if (head == current) // if head is also the current song
			{
				if (current->next != nullptr)
					current = current->next; // move current to the next song
				else
					current = nullptr; // if no next song, current becomes null
			}

			head = head->next; // update the head
			delete temp; // delete the old head
			updateFileAfterDeletion(head);
			return;
		}

		///deleting a song from a position other than head
		int count = 1;
		song* prev = nullptr;

		while (count < number && temp != nullptr)
		{
			prev = temp;
			temp = temp->next;
			count++;
		}

		if (temp == nullptr)
		{
			cout << "Invalid song number." << endl;
			return;
		}

		///if the last song is being deleted and it is the current song
		if (temp->next == nullptr && current == temp)
		{
			current = head; // update current to the first song
			prev->next = nullptr;
			delete temp;
			updateFileAfterDeletion(head);
			return;
		}

		///if the song being deleted is the current song
		if (temp == current)
		{
			if (current->next != nullptr)
				current = current->next; // move current to the next song
			else
				current = head; // move current to the head if at the end
		}

		prev->next = temp->next; // remove the song from the list
		delete temp; // delete the node
		updateFileAfterDeletion(head);
	}




	int getLength(song*head)
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


	void shuffle(song*& head, song*& current)
	{
		srand(time(NULL));  
		int l = getLength(head); 
		song* kth, * temp;

		for (int i = 0; i < l; i++)
		{
			int selectIndex = (rand() % l) + 1;  
			int newIndex = (rand() % l) + 1;

		
			kth = head;
			int count = 1;
			while (count < selectIndex && kth != nullptr) 
			{
				kth = kth->next;
				count++;
			}

			
			string selectedSongName = kth->name;

			
			temp = head;
			count = 1;
			while (count < newIndex && temp != nullptr) 
			{
				temp = temp->next;
				count++;
			}

			
			string tempName = temp->name;
			temp->name = selectedSongName;
			kth->name = tempName;
		}


		///after shuffling, update the current song to any random song
		int randomIndex = (rand() % l) + 1;
		current = head;
		int count = 1;
		while (count < randomIndex && current != nullptr)
		{
			current = current->next;
			count++;
		}

		updateFileAfterDeletion(head);
	}


	void playNext(song* head, song* &current)
	{
		if (current->next == nullptr)
		{
			current = head;
			return;
		}

		current = current->next;
	}

	void displayCurrent(song* current)
	{
		if (current != nullptr)
			cout << "Currently Playing: " << current->name << endl << endl;
	}


};


int main()
{


	song* head = new song(" ");
	head = nullptr;
	head->loadSongs(head);
	song* current = head; //keep track of current song playing
	
	int option;
while(1)
{
	head->displayCurrent(current);


	cout << "Select an option:" << endl << "1. Play Next" << endl << "2. Add New Song" << endl << "3. Remove a Song from Play List" << endl << "4. Shuffle PLay List" << endl << "5. Turn on Repeat"<<endl<<"6. Display Play List" << endl;
	cin >> option;

	if (option == 1)
	{
		//system("cls");
		head->playNext(head, current);
	}
	else if (option == 2)
	{
		//system("cls");
		string newSong;
		cout << "Enter Name: "; 
		cin.ignore();

		getline(cin, newSong);
		head->insertAndSave(newSong, head);
	}
	else if (option == 3)
	{
		head->deleteSong(head, current);
	}
	else if (option == 4)
	{
		head->shuffle(head,current);
	}
	else if (option == 5)
	{
		//system("cls");
		head->display(head);
		head->display(head);
	}
	else if (option == 6)
	{
		//system("cls");

		head->display(head);
	}
	else
		break;
}	

head->deleteList(head);

	return 0;
}