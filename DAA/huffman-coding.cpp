#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int val){
        ch=c;
        freq=val;
        left=nullptr;
        right=nullptr;
    }
};

struct compare{
  bool operator()(Node* a, Node* b){
      return a->freq>b->freq;
  }  
};

void print(Node* root,string codes){
    if(!root) return;
    if(root->ch!='$'){
        cout<<root->ch<<" : "<<codes<<endl;
    }
    print(root->left,codes+"0");
    print(root->right,codes+"1");
}

int main(){
    int n;
    cout<<"Enter total number of characters: ";
    cin>>n;
    vector<char>chars(n);
    vector<int>frequency(n);
    cout<<"Enter Characters: ";
    for(int i=0;i<n;i++){
        cin>>chars[i];
    }
    cout<<"Enter frequency: ";
    for(int i=0;i<n;i++){
        cin>>frequency[i];
    }
    priority_queue<Node*,vector<Node*>,compare>pq;
    for(int i=0;i<n;i++) pq.push(new Node(chars[i],frequency[i]));

    while(pq.size()>1){
        Node* left=pq.top();
        pq.pop();
        Node* right=pq.top();
        pq.pop();
        Node* newNode = new Node('$',left->freq+right->freq);
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }
    cout<<"Answer: "<<endl;
    print(pq.top(),"");
    return 0;
}