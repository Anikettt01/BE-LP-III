// Author : Aniket Deore
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>dp;

int helper(int index,int capacity, vector<int>&value, vector<int>&weight){
    if(index==0 || capacity==0) return 0;
    if(dp[index][capacity]!=-1) return dp[index][capacity];
    if(capacity<weight[index-1]) return dp[index][capacity]=helper(index-1,capacity,value,weight);
    int include = value[index-1]+helper(index-1,capacity-weight[index-1],value,weight);
    int exclude=helper(index-1,capacity,value,weight);
    return dp[index][capacity]=max(include,exclude);
}

int main(){
    cout<<"Total Items: ";
    cin>>n;

    int capacity;
    cout<<"Enter total Capacity: ";
    cin>>capacity;

    dp.assign(n+1,vector<int>(capacity+1,-1));

    vector<int>value(n);
    vector<int>weight(n);

    cout<<"Enter value of each item: ";
    for(int i=0;i<n;i++) cin>>value[i];

    cout<<"Enter weight of each item: ";
    for(int i=0;i<n;i++) cin>>weight[i];

    cout<<helper(n,capacity,value,weight)<<endl;
    return 0;
}

// Sample testcase
// 3
// 50
// 120 100 60
// 10 20 30