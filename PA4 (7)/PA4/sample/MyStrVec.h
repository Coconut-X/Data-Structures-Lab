#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class MyString
{
private:
	string str;
	int count;
public:
	string getString() const {return str;}
	void setString(string theString) {str = theString;}
	int getCount() const {return count;}
	void setCount(int c) {count = c;}
	void incrementCount() {count++;}
	
	bool operator<(const MyString& other) const
    {
		return (this->getCount() < other.getCount());
    }
};


class MyStrVec
{
public:
	list<MyString> v;
	bool processOneLine(ifstream&);
	
public:
	const MyStrVec operator+(MyStrVec& addend);
	MyStrVec(){num_lines = num_distinct_lines = 0;}
	string getMostFrequent();
	string getLeastFrequent();
	int getCount(string& s);
	bool populate(string);
	int getSize() {return v.size();}
	void printData();
	list<MyString>::iterator findString(const string&);
	static const list<MyString>::iterator NOT_FOUND_LOCATION;
	void sort();
	int num_lines;
	int num_distinct_lines;
};
