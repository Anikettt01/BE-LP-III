#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>board;

bool check(int actualRow,int actualCol){
    // int actualRow=row;
    // int actualCol=col;
    int col=actualCol-1;
    int row=actualRow;
    while(col>=0){
        if(board[row][col]==1) return false;
        col--;
    }
    row=actualRow-1;
    col=actualCol-1;

    while(col>=0 && row>=0){
        if(board[row][col]==1) return false;
        row--;
        col--;
    }
    row=actualRow+1;
    col=actualCol-1;

    while(col>=0 && row<n){
        if(board[row][col]==1) return false;
        row++;
        col--;
    }
    return true;

}

bool solve(int col,int placedRow, int placedCol){
    if(col==n) return true;
    if(col==placedCol){
        if(check(placedRow,placedCol)) return solve(col+1,placedRow,placedCol);
        else return false;
    }
    for(int row=0;row<n;row++){
        if(check(row,col)){
            board[row][col]=1;
            if(solve(col+1,placedRow,placedCol)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    cout<<"Enter the value of n: ";
    cin>>n;

    board.assign(n,vector<int>(n,0));

    int r,c;
    cout<<"Enter the row and col number of first queen: ";
    cin>>r>>c;

    r--;
    c--;

    board[r][c]=1;

    if(solve(0,r,c)){
        cout<<"N-Queen Solution: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<". ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exists"<<endl;
    }
}