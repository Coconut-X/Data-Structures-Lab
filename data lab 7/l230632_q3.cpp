#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> occupiedCols;
vector<int> occupiedRows;


bool isValidRow(int r, vector<vector<char>> &board)
{
    return find(occupiedRows.begin(),occupiedRows.end(),r)==occupiedRows.end()   || occupiedRows.size()==0;
}

bool isValidCol(int c, vector<vector<char>> &board)
{
    return find(occupiedCols.begin(),occupiedCols.end(),c)==occupiedCols.end() || occupiedCols.size()==0;
}

bool isValidDiagonal(int r,int c,vector<vector<char>> &board)
{
    for(int i=0;i<occupiedRows.size();i++)
    {
        if(abs(occupiedRows[i]-r)==abs(occupiedCols[i]-c))
        {
            return false;
        }
    }
    return true;
}

void setValue(int r,int c,vector<vector<char>> &board)
{
    board[r][c]='Q';
    occupiedCols.push_back(c);
    occupiedRows.push_back(r);   
}




void removeQueen(int r, int c, vector<vector<char>> &board) 
{
    board[r][c] = 'E';
    occupiedCols.pop_back();
    occupiedRows.pop_back();
}


void displayBoard(vector<vector<char>> &board) 
{
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void findQueens(int n, int currentRow, vector<vector<char>> &board) 
{
    
    if (currentRow == n) 
    {
        displayBoard(board);
        return;
    }

    
    for (int col = 0; col < n; col++) 
    {
        if (isValidRow(currentRow, board) && isValidCol(col, board) && isValidDiagonal(currentRow, col, board)) 
        {
            
            setValue(currentRow, col, board);//place queen in current row and column

            findQueens(n, currentRow + 1, board); //place queen in next row, because one queen per row allowed

            removeQueen(currentRow, col, board);    //agr current queen k baad koi valid position nhi milti toh remove the current queen and try next column, because current queen to valid hogi but next queen nhi hogi
        }
    }
}






int main()
{

    int n=5;
    vector<vector<char>> board(n, vector<char>(n, 'E'));
    findQueens(n, 0, board);


    return 0;
}