#include<iostream>
using namespace std;


int euclidean(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclidean(b, a % b);

}

int main()
{
	int a = 3;
	int b = 2;

	cout << "GCD: " << euclidean(max(a, b), min(a, b)) << endl;

	return 0;
}