#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
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

// 1. Delete all occurrences of a key in DLL    TC==>o(n)   SC==>o(1)
Node* delete_key(Node* head,int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
                delete temp;
            }
            Node* prevnode=temp->prev;
            Node* nextnode=temp->next;
            if(prevnode)prevnode->next=nextnode;
            if(nextnode)nextnode->prev=prevnode;
            delete temp;
            temp=nextnode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

// 2. Find pairs with given sum in DLL
// brute force-  TC==>o(n^2)   SC==>o(1)
vector<pair<int,int>> sum_pair(Node* head,int sum){
    Node* temp=head;
    vector<pair<int,int>>v;
    while(temp!=NULL){
        Node* nextnode=temp->next;
        while(nextnode!=NULL&&temp->data+nextnode->data<=sum){
            if(temp->data+nextnode->data==sum){
                v.push_back({temp->data,nextnode->data});
            }
            nextnode=nextnode->next;
        }
        temp=temp->next;
    }
    return v;
}
//optimal-   TC==>o(n)  SC==>o(1)
vector<pair<int,int>> sum_pair(Node* head,int sum){
    Node* left=head;
    vector<pair<int,int>>v;
    Node* right=head;
    while(right->next!=NULL){
        right=right->next;
    }
    while(left->data<right->data){
        if(left->data+right->data==sum){
            v.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data>sum){
            right=right->prev;
        }
        else{
            left=left->next;
        }
    }
    return v;
}

// 3. Remove duplicates from sorted DLL   TC==>o(n)  SC==>o(1)
Node* remove_dup(Node* head){
    Node* temp=head;
    while(temp!=NULL&& temp->next!=NULL){
        Node* nextnode=temp->next;
        while(nextnode!=NULL&&temp->data==nextnode->data){
            Node* dup=nextnode;
            nextnode=nextnode->next;
            delete dup;
        }
        temp->next=nextnode;
        if(nextnode)nextnode->prev=temp;
        temp=temp->next;
    }
    return head;
}

// 4.Delete the middle node of LL   TC==>o(n)  SC==>o(1)
Node* deleteMiddle(Node* head) {
        if(head==NULL)return head;
        if(head->next==NULL) return NULL;
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
       if(prev)prev->next=slow->next;
        delete slow;
        return head;
    }

// 5. Find the starting point in LL    TC==>o(n)  SC==>o(1)
 Node *detectCycle(Node *head) {
      if (head == NULL || head->next == NULL)
            return NULL;

        Node *slow = head;
        Node *fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (fast == NULL || fast->next == NULL)
            return NULL;

        // Step 2: Find start of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

int main (){
    return 0;
}