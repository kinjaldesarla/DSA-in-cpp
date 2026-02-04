#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node* child;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
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


// 1. Reverse LL in group of given size K
// TC==>o(2n) SC==>o(1)
Node* reversell(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* findkthnode(Node* head,int k){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    return temp;
}
Node* reverse_kgroup(Node* head,int k){
Node* temp=head;
 Node* prev=NULL;
while(temp!=NULL){
    Node* kthnode=findkthnode(temp,k);
    if(kthnode==NULL){
        if(prev)prev->next=temp;
        break;
    }
    Node* nextnode=kthnode->next;
    kthnode->next=NULL;
    reversell(temp);
    if(temp==head){
        head=kthnode;
    }else{
      prev->next=kthnode;
    }
    prev=temp;
    temp=nextnode;
}
return head;
}

// 2. Rotate a LL   TC==>o(2n)  SC==>o(1)
Node* rotate(Node* head,int k){
    if(head==NULL)return head;
    Node* temp=head;
    int cnt=1;
    while(temp->next!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(k%cnt==0)return head;
     temp->next=head;
     k=k%cnt;
     Node* kthnode=findkthnode(head,cnt-k);
     head=kthnode->next;
     kthnode->next=NULL;
     return head;
}

// 3. merge two sorted linkedlist 
// brute force- TC==>o(n1+n2) + o(NlogN) + o(n1+n2)    SC==>o(2(n1+n2))
// store all element in array -> sort array ->convert array to linkedlist->return head;
//optimal-    TC==>o(n1+n2)  SC==>o(1)
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

// 4. Flattening of LL    TC==>o(n*2m)   SC==>o(n)
Node* mergechild(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    while(temp1!=NULL&& temp2!=NULL){
        if(temp1->data<temp2->data){
            current->child=temp1;
            current=temp1;
            temp1=temp1->child;
        }
        else{
            current->child=temp2;
            current=temp2;
            temp2=temp2->child;
        }
        current->next=NULL;
    }
    if(temp1)current->child=temp1;
    if(temp2) current->child=temp2;
    return dummynode->child;
}
Node* flat(Node* head){
    if(head==NULL||head->next==NULL)return head;
   Node* mergedhead=flat(head->next);
   return mergechild(head,mergedhead);
}

// 5. Sort LL
// brute force- TC==>o(n)+ o(nlogn) +o(n)  SC==>o(n)
// store in array->sort ->place back in ll 
//optimal- using merge sort
// TC==>o(logn * (n+n/2))
Node* tortoise_hair(Node* head){
    Node* slow=head;
    Node* fast=head->next; // changed because to get m1 not m2 in case of even
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge_sort_ll(Node* head){
    if(head==NULL|| head->next==NULL)return head;
    Node* middle=tortoise_hair(head);
    Node* lefthead=head;
    Node* righthead=middle->next;
    middle->next=NULL;
    lefthead=merge_sort_ll(lefthead);
    righthead=merge_sort_ll(righthead);
   return mergeing(lefthead,righthead);
}

int main(){
    vector<int>arr={1,8,6,4,9,2};
    vector<int>arr1={2,4,5,8};
    Node* head=array_linkedlist(arr);
    Node* head1=array_linkedlist(arr1);
    head=mergeing(head,head1);
    print(head);

    head=merge_sort_ll(head);
    print(head);
    return 0;
}