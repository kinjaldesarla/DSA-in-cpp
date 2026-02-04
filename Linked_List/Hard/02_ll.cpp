#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};
void print(Node* head){
       Node* temp=head;
    // traversal in LL  o(n)
    while(temp){           
        cout<<temp->data<<' ';
        temp=temp->next;
    }
} 
Node* array_linkedlist(vector<int>arr){
     Node* head=new Node(arr[0]);
     Node* mover=head;
     for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
     }
     return head;
}
// 1. merge k sorted list
// brute force-  TC==>o(n*k) + o(mlogm) + o(m)    SC==>o(2n*k)
// store to array-> sort them -> convert array to linkedlist
// better-
// TC==>  2n + 3n + 4n +...kn(for merging)
//     n(1+2+3...k) -> n* (k* k+1)/2  (near about n^3)
//     SC==>o(1)
Node* mergeing(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    while(temp1!=NULL&& temp2!=NULL){
        if(temp1->data<temp2->data){
            current->next=temp1;
            current=temp1;
            temp1=temp1->next;
        }
        else{
            current->next=temp2;
            current=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1)current->next=temp1;
    if(temp2) current->next=temp2;
    return dummynode->next;
}
Node* merge_klist(vector<Node*>list){
    Node* head=list[0];
    for(int i=1;i<list.size();i++){
       head= mergeing(head,list[i]);
    }
    return head;
}
// optimal-  TC==>o(k*logk)+o(n*k*3logk)   SC==>o(k)
Node* merge_klist1(vector<Node*>list){
    // min heap 
    priority_queue<pair<int,Node*>,
    vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
    for(int i=0;i<list.size();i++){
        pq.push({list[i]->data,list[i]});
    }
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next)pq.push({it.second->next->data,it.second->next});
        current->next=it.second;
        current=current->next;
    }
    return dummynode->next;
}

int main(){
    return 0;
}