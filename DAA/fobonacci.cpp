#include <bits/stdc++.h>
using namespace std;

void iterative(int n){
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    while(n>2){
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
        n--;
    }
    cout<<endl;
}

int recursive(int n){
    if(n<=1) return n;
    return recursive(n-1)+recursive(n-2);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    while(true){
        cout<<"1. Iterative fibonacci numbers generation"<<endl;
        cout<<"2. Recursive fibonacci numbers generation"<<endl;
        cout<<"0. Stop"<<endl;

        int choice;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Fibonacci series till "<<n<<": ";
            iterative(n);
        }
        else if(choice==2){
            cout<<"Fibonacci series till "<<n<<": ";
            for(int i=0;i<n;i++){
                cout<<recursive(i)<<" ";
            }
        } 
        else if(choice==0) break;
        else cout<<"Enter Valid Choice"<<endl;
    }
}