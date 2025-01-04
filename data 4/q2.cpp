#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


bool isSudokuValid(vector<vector<int>> &board)
{
    unordered_map<int,int>row[9],col[9],box[3][3]; //to store the count of each number in each row, column and box

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)  continue;

            if(row[i][board[i][j]] or col[j][board[i][j]] or box[i/3][j/3][board[i][j]])
            {
                cout<<endl<<i<<" "<<j<<endl;
                return false;
            }

            row[i][board[i][j]]=1;
            col[j][board[i][j]]=1;
            box[i/3][j/3][board[i][j]]=1;
        }
    }

    return true;
}


int main()
{

    vector<vector<int>> zeros={
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    vector<vector<int>> sudoku = {
    {5, 3, 0, 0, 0, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


    if(isSudokuValid(sudoku))
        cout<<"Valid Sudoku"<<endl;
    else
        cout<<"Invalid Sudoku"<<endl;


    // //return 0;

    // string s="abcdefghi";

    // int i=0;
    // int j=0;
    // int window=1;

    // //using sliding window technique to print all substrings of length 1 to n

    // while(window<=s.size())
    // {
    //     while(j<s.size())
    //     {
    //         cout<<s.substr(i,window)<<endl;
    //         j++;
    //         i++;
    //     }
    //     i=0;
    //     window++;
    //     j=window-1;
    // }

    return 0;



}

