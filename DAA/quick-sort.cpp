#include <bits/stdc++.h>
using namespace std;

void randomized(vector<int>&arr,int n,int left, int right){
    if(left>=right) return;
    int randomIndex=left+rand()%(right-left+1);
    swap(arr[randomIndex],arr[left]);
    int pivot=arr[left];
    int i=left;
    int j=right;

    while(i<j){
        while(i<j && arr[j]>=pivot) j--;
        while(i<j && arr[i]<=pivot) i++;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[i]);
    randomized(arr,n,left,i-1);
    randomized(arr,n,i+1,right);
}

void deterministic(vector<int>&arr,int n,int left, int right){
    if(left>=right) return;
    int pivot=arr[left];
    int i=left;
    int j=right;

    while(i<j){
        while(i<j && arr[j]>=pivot) j--;
        while(i<j && arr[i]<=pivot) i++;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[i]);
    deterministic(arr,n,left,i-1);
    deterministic(arr,n,i+1,right);
}

int main(){
    int n;
    cout<<"Total Elements: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"1. Deterministic Quick Sort"<<endl;
    cout<<"2. Randomized Quick Sort"<<endl;

    int choice;
    cout<<"Select Option: ";
    cin>>choice;

    if(choice==1){
        cout<<"Array after deterministic quick sort: ";
        deterministic(arr,n,0,n-1);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    else if(choice==2){
        cout<<"Array after Randomized quick sort: ";
        randomized(arr,n,0,n-1);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
}

// Sample testcase
// 5
// 5 -10 0 2 -3