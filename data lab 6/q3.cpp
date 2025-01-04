#include<iostream>
using namespace std;


int sum(int  n)
{
	if (n == 0)
		return 0;
	else
		return n % 10 + sum(n /10);
}


int main()
{

	int n = 123;
	cout << "Sum: " << sum(n) << endl;

	return 0;
}