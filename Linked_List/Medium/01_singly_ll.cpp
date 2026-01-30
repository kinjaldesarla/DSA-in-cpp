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



// 1. Add 2 numbers in LL        TC==>o(max(n1,n2))  SC==>o(max(n1,n2))
Node* add(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummynode=new Node(-1);
    Node* curr=dummynode;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL){
        int sum=carry;
        if(temp1)sum+=temp1->data;
         if(temp2)sum+=temp2->data;
        carry=sum/10;
        sum=sum%10;
        Node* newnode=new Node(sum);
        curr->next=newnode;
        curr=newnode;
        if(temp1)temp1=temp1->next;
        if(temp2)temp2=temp2->next;
    }
    if(carry){
        Node* newnode=new Node(carry);
        curr->next=newnode;
    }
    return dummynode->next;
}

// 2.Segrregate odd and even nodes in LL
// brute force     TC==>o(2n)   SC==>o(n)
Node* segrregate(Node* head){
       if(head==NULL || head->next==NULL)return head;
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){       // o(n/2)
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){      // o(n/2)
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp=head;
    int i=0;
    while(temp){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}
//optimal          TC==>o(n)    SC==>o(1)
Node* segrregate1(Node* head){
       if(head==NULL || head->next==NULL)return head;
    Node* odd= head;
    Node* even=head->next;
    Node* evenhead=even;
    while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
    }
    odd->next=evenhead;
    return head;
}

//3. Sort a LL of 0's 1's and 2's by changing links
//brute force-    TC==>o(2n)   SC==>O(1)
Node* sorting(Node* head){
    Node* temp=head;
    int cnt0=0,cnt1=0,cnt2=0;
    while(temp!=NULL){
        if(temp->data==0)cnt0++;
        else if(temp->data==1)cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else {
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}
//optimal -       TC==>o(n)    SC==>o(1)
Node* sorting1(Node* head){
    Node* zerodummy=new Node(-1);
    Node* onedummy=new Node(-1);
    Node* twodummy=new Node(-1);
    Node* zero=zerodummy;
    Node* one=onedummy;
    Node* two=twodummy;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    // attaching links
    zero->next=onedummy->next!=NULL?(onedummy->next):twodummy->next;
    one->next=twodummy->next;
    two->next=NULL;
    Node* newHead=zerodummy->next;
    delete zerodummy;
    delete onedummy;
    delete twodummy;
    return newHead;
}

// 4. Remove Nth node from the back of the LL
//brute force-     TC==>o(len)+o(len-n)==>o(2n)      SC==>o(1)
Node* remove_nth_node(Node* head,int n){
    Node* temp =head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newhead=head->next;
        delete head;
        return newhead;
    }
    int resultant=cnt-n;
    temp=head;
    while(temp!=NULL){
        resultant--;
        if(resultant==0)break;
        temp=temp->next;
    }
    Node* delnode=temp->next;
    temp->next=temp->next->next;
    delete delnode;
    return head;
}
//optimal-    TC==>o(n)   SC==>o(1)
Node* remove_nth_node1(Node* head,int n){
    if(head==NULL||head->next==NULL)return head;
    Node* fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        Node* newnode=head->next;
        delete head;
        return newnode;
    }
    Node* slow= head;
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}

// 5.Reverse a LinkedList [Iterative]
// brute force- TC==>O(2n)   SC==>o(1)
Node* reverse_ll(Node* head){
  Node* temp=head;
  stack<int>st;
  while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    temp->data=st.top();
    st.pop();
    temp=temp->next;
  }
  return head;
}
// optimal-  TC==>o(n)  SC==>o(1)
Node* reverse_ll1(Node* head){
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

// Reverse a LL [Recursive]   TC==>o(n)   SC==>o(n)  [it is recursive stack space ]
Node* recursive_reverse(Node* head){
    if(head==NULL||head->next==NULL)return head;
    Node* newhead=recursive_reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}



int main(){
    vector<int> arr1={3,5};
    vector<int>arr2={0,2,2,1,2,1,0,2,1,0};
    Node* head1=array_linkedlist(arr1);
    Node* head2 =array_linkedlist(arr2);
    // Node* head=add(head1,head2);
    // print(head);
    Node* head3=segrregate1(head2);
    print(head3);
    Node* head=sorting1(head2);
    print(head);

    vector<int>arr={1,2,3,4,5};
     Node* head4 =array_linkedlist(arr);
     head4=recursive_reverse(head4);
     print(head4);
    return 0;
}