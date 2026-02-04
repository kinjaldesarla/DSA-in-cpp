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

// 2. Clone a Linked List with random and next pointer
// brute force-  TC==>o(2n)  SC==>o(2n)
Node* clone(Node* head){
    Node* temp=head;
    map<Node*,Node*>mpp;
    while(temp!=NULL){
        Node* newnode=new Node(temp->data);
        mpp[temp]=newnode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        Node* copynode=mpp[temp];
        copynode->next=mpp[temp->next];
        copynode->random=mpp[temp->random]; 
        temp=temp->next;
    }
    return mpp[head];
}
//optimal-  TC==>o(3n)   SC==>o(n)
Node* clone1(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* copynode=new Node(temp->data);
        copynode->next=temp->next;
        temp->next=copynode;
        temp=temp->next->next;
    }
    temp=head;
    while(temp!=NULL){
        Node* copynode=temp->next;
        if(temp->random)copynode->random=temp->random->next;
        else copynode->random=NULL;
        temp=temp->next->next;
    }
    temp=head;Node* dummynode=new Node(-1);
    Node* current=dummynode;
    while(temp!=NULL){
        current->next=temp->next;
        temp->next=temp->next->next;
        current=current->next;
        temp=temp->next;
    }
    return dummynode->next;
}

// 3. design browser history
class BNode{
    public:
    string data;
    BNode* front;
    BNode* back;
    public:
    BNode(string data1){
        data=data1;
        front=nullptr;
        back=nullptr;
    }
};
class browser{
    BNode* current;
    public:
    //o(1)
    browser(string &url){
        current=new BNode(url);
    }
    //o(1)
    void visit(string url){
        BNode* newnode= new BNode(url);
        current->front=newnode;
        newnode->back=current;
        current=newnode;
    }
    //o(steps)
    string backward(int steps){
        while(steps){
            if(current->back)current=current->back;
            else break;
            steps--;
        }
        return current->data;
    }
    //o(steps)
    string forward(int steps){
        while(steps){
            if(current->front)current=current->front;
            else break;
            steps--;
        }
        return current->data;
    }
};

int main(){
    return 0;
}