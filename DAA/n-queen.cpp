// Author : Aniket Deore
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>board;
int n;

bool check(int row,int col){
    // previous row
    int i=row;
    int j=col-1;
    while(j>=0){
        if(board[i][j]==1) return false;
        j--;
    }
    // prev upper diagonal
    i=row-1;
    j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]==1) return false;
        i--;
        j--;
    }
    // prev lower diagonal
    i=row+1;
    j=col-1;
    while(i<n && j>=0){
        if(board[i][j]==1) return false;
        i++;
        j--;
    }
    return true;

}

bool helper(int col,int placedRow, int placedCol){
    if(col==n) return true;
    if(col==placedCol){
        if(check(placedRow,placedCol)) return helper(col+1,placedRow,placedCol);
        else return false;
    }
    for(int row=0;row<n;row++){
        if(check(row,col)){
            board[row][col]=1;
            if(helper(col+1,placedRow,placedCol)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    cout<<"Enter board size: ";
    cin>>n;

    int r,c;
    cout<<"Enter first queen's row and col: ";
    cin>>r>>c;

    r--;
    c--;
    
    board.assign(n,vector<int>(n,0));
    board[r][c]=1;

    if(helper(0,r,c)){
        cout<<"Found Answer Successfully"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<". ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No Solution found"<<endl; 
    }
    return 0;
}
// reference possible answer
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0
