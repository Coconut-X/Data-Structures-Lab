#include "MyStrVec.h"
#include <algorithm>

using namespace std;

bool MyStrVec::populate(string filename)
{
	ifstream input(filename.c_str());
	if(!input.good())
    {
		cout << "File can't be accessed. Do you have it in the current directory?" << endl;
		exit(-1);
    }
	
	while((input.peek() != EOF) && input.good())
    {
		if(!processOneLine(input))
			return false;
    }
	
	input.close();
	return true;
}

const list<MyString>::iterator MyStrVec::NOT_FOUND_LOCATION = list<MyString>::iterator();

list<MyString>::iterator MyStrVec::findString(const string& toFind)
{
	list<MyString>::iterator it;
	int i = 0;
	
	for(it = v.begin(); it != v.end(); it++, i++)
    {
		if(it->getString() == toFind)
			return it;
    }
	
	return NOT_FOUND_LOCATION;
}

bool MyStrVec::processOneLine(ifstream& f)
{
	string oneLine;
	MyString mystr;
	
	if(!getline(f, oneLine))
		return false;
	
	if(!oneLine.empty())
    {
		list<MyString>::iterator location = findString(oneLine);
		
		if(location == NOT_FOUND_LOCATION)
        {
			mystr.setString(oneLine);
			mystr.setCount(1);
			v.push_back(mystr);
			num_distinct_lines++;
        }
		else
			location->incrementCount();
		
		num_lines++;
    }
	
	return true;
}

void MyStrVec::printData()
{
	list<MyString>::iterator it;
	for(it = v.begin(); it != v.end(); it++)
		cout << it->getCount() << ". " << it->getString() << endl;
}

void MyStrVec::sort()
{
	v.sort();
}

int MyStrVec::getCount(string& s)
{
	for(list<MyString>::iterator it = v.begin(); it != v.end(); it++)
    {
		if(s == it->getString())
			return it->getCount();
    }
	
	return 0;
}

string MyStrVec::getMostFrequent()
{
	string most_frequent = "no string read from file";
	int frequency = 0;
	
	if(v.size() != 0)
    {
		list<MyString>::iterator it = v.begin();
		most_frequent = it->getString();
		frequency = it->getCount();
		it++;
		for(; it != v.end(); it++)
        {
			if(it->getCount() > frequency)
            {
				frequency = it->getCount();
				most_frequent = it->getString();
            }
        }
    }
	
	return most_frequent;
}

string MyStrVec::getLeastFrequent()
{
	string least_frequent = "no string read from file";
	int frequency = 0;
	
	if(v.size() != 0)
    {
		list<MyString>::iterator it = v.begin();
		least_frequent = it->getString();
		frequency = it->getCount();
		it++;
		for(; it != v.end(); it++)
        {
			if(it->getCount() < frequency)
            {
				frequency = it->getCount();
				least_frequent = it->getString();
            }
        }
    }
	
	return least_frequent;
}

const MyStrVec MyStrVec::operator+(MyStrVec& addend)
{
	MyString mystr;
	MyStrVec* result = new MyStrVec();
	*result = *this;
	
	for(list<MyString>::iterator it = addend.v.begin(); it != addend.v.end(); it++)
    {
		
		list<MyString>::iterator location = result->findString(it->getString());
		
		if(location == NOT_FOUND_LOCATION)
        {
			mystr.setString(it->getString());
			mystr.setCount(it->getCount());
			result->v.push_back(mystr);
			result->num_distinct_lines++;
        }
		else
			location->setCount(location->getCount()+it->getCount());
		
		result->num_lines+=it->getCount();
    }
	
	return *result;
}

int main()
{
/*
* This is a sample main method
* Add things as you wish to play around and understand how this sample code functions.
*/
	
	// greetings
	cout << "Welcome to the Movie/Actor Simple Database" << endl;
	cout << "==========================================" << endl;
	
	// read first filename from console
	cout << "Please Enter the first filename: ";
	string dataFileName;
	getline(cin, dataFileName);
	cout << "Reading first MSV" << endl;
	cout << "=================" << endl;  
	
	// read from first file and populate the MSV
	MyStrVec msv1;
	if(!msv1.populate(dataFileName))
    {
		cout << "Error reading file...exiting" << endl;
		exit(-1);
    }
	cout << "MSV Read Successful. list size is: " << msv1.getSize() << endl << endl;
	
	
	// read second filename from console 
	cout << "Please Enter the second filename: ";
	getline(cin, dataFileName);
	cout << "Reading second MSV" << endl;
	cout << "==================" << endl;
	
	// read from second file and populate the MSV
	MyStrVec msv2;
	if(!msv2.populate(dataFileName))
    {
		cout << "Error reading file...exiting" << endl;
		exit(-1);
    }
	cout << "MSV Read Successful. list size is: " << msv2.getSize() << endl << endl;
	
	// perform some simple operations
	msv1.sort();
	MyStrVec msv3;
	msv3 = msv2 + msv1;
	
	// print the MSVs
	cout << "Printing first MSV" << endl;
	cout << "==================" << endl;
	 msv1.printData();
	
	cout << "Printing second MSV" << endl;
	cout << "===================" << endl;
	 msv2.printData();
	
	cout << "Printing third MSV" << endl;
	cout << "==================" << endl;
	 msv3.printData();
	
	
	// show some statistics
	cout << "First file:" << endl;
	cout << "===========" << endl;
	cout << "Total Lines: " << msv1.num_lines << endl;
	cout << "Distinct Lines:" << msv1.num_distinct_lines << endl << endl;
	
	cout << "Second file:" << endl;
	cout << "============" << endl;
	cout << "Total Lines: " << msv2.num_lines << endl;
	cout << "Distinct Lines:" << msv2.num_distinct_lines << endl << endl;
	
	cout << "Sum of two MSVs:" << endl;
	cout << "================" << endl;
	cout << "list Size: " << msv3.getSize() << endl;
	cout << "Total Lines: " << msv3.num_lines << endl;
	cout << "Distinct Lines:" << msv3.num_distinct_lines << endl << endl;
	
	
	string mf = msv3.getMostFrequent();
	int mf_count = msv3.getCount(mf);
	cout << "Most Frequent: " << mf << endl << "Count: " << mf_count << endl;
	
	string lf = msv3.getLeastFrequent();
	int lf_count = msv3.getCount(lf); 
	cout << "Least Frequent: " << lf << endl << "Count: " << lf_count << endl;

	return 0;
}