
#include <iostream>
using namespace std;

const int Rows = 21;
const int Columns = 20;

int cMin=9;
int cMax=11;

void Print_R(const int R, const int C) 
{
    for (int i = 1; i <= Rows; i++) 
    {
        for (int j = 1; j <=Columns; j++) 
        {
        	
        	if( (i>=12 and i<=18) and (j>=cMin and j<=cMax)  )
        	{
        		cout<<"  ";
			}
        	
        	 else if((i>=4 and i<=5) and (j>=4 and j<=17)   || ( (i>=6 and i<=9) and (  (j>=4 and j<=5 )  || (j>=16 and j<=17) )  || (  (i>=10 and i<=11) and  (j>=4 and j<=17 )  )  ||( (i>=12 and i<=18) and (j>=4 and j<=5))   )           )
        		cout<<"  ";
        	
        	else cout<<"* ";
        	
        }
        
        if(i>=12 and i<=18) 
        	cMin++, cMax++;
        
        cout << endl;
    }
}

int main() {
    //Print_R(Rows, Columns);

    cout << "\nREPORT GENERATED SUCCESSFULLY.\n";

    

    return 0;
}
