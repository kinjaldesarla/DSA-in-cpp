#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node* back;

    public:
    Node(int data1,Node*next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};

// array to dll
Node* array_doublylinkedlist(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
// print dll
void print(Node* head){
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// deletion concepts 
// delete head
Node* delete_head(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev= head;
    head= head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
  return head;
}

// delete tail
Node* delete_tail(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* temp =head;
    while(temp->next!=NULL){
        temp =temp->next;
    }
    Node* prev= temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    return head;
}

// delete kth element
Node* del_kth(Node* head,int k){
    if(head==NULL) return NULL;
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
       temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        return delete_head(head);
    }
    else if(front==NULL){
        return delete_tail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}

// delete node  (node != head)
void del(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return;
}

// insertion concepts
// insert before haed
Node* insert_before_head(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* newnode=new Node(val,head,nullptr);
    head->back=newnode;
    return newnode;
}
// insert before tail
Node* insert_before_tail(Node* head,int val){
    if(head->next==NULL) return insert_before_head(head,val);
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newnode=new Node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;
}
// insert before kth element 
Node* insert_before_kth(Node* head,int val ,int k){
    if(head==NULL)return new Node(val);
    if(k==1) return insert_before_head(head,val);
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt== k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=temp->back=newnode;
    return head;
}
//insert before node (node!=head)
void insert_before_node(Node* temp,int val){
    Node* prev= temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=temp->back=newnode;
}

// 1. reverse the dll
Node* reverse_dll(Node* head){
    if(head==NULL||head->next==NULL)return head;
    Node* curr=head;
   while(curr!=NULL){ 
     // Swap next and back pointers of current node
        Node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;
        // move 
        head=curr;
        curr=temp;
   }
   return head;
}

int main(){
    vector<int>arr={2,5,6,3};
    Node* head=array_doublylinkedlist(arr);
    head=del_kth(head,4);
    print(head);
    del(head->next);
    print(head);
    head=insert_before_kth(head,100,4);
    print(head);
    insert_before_node(head->next,100);
    print(head);
    head=reverse_dll(head);
    print(head);
    return 0;
}