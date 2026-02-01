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


// 1. Check if LL is palindrome or not
// brute force-   TC==>o(2n)   SC==>o(n)
bool palind(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}
//optimal-  TC==>o(2n)   SC==>o(1)
Node* rev(Node* head){
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
bool palind1(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* newhead=rev(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL){
        if(first->data!=second->data){
            rev(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    rev(newhead);
    return true;
}

// 2. Add 1 to a number represented by LL
// brute force-   TC==>o(3n)  SC==>o(1)
Node* add1(Node* head){
    Node* newhead=rev(head);
    Node* temp=newhead;
    int carry=1;
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        temp->data=0;
        carry=1;
        temp=temp->next;
    }
    if(carry==1){
        Node* newnode=new Node(1);
        rev(newhead);
        newnode->next=head;
        return newnode;
    }
    rev(newhead);
    return head;
}
//optimal by recursion -   TC==>o(n)  SC==>o(n)recursive stack
int helper(Node* temp){
    if(temp==NULL)return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* add1_recursive(Node* head){
    int carry=helper(head);
    if(carry==1){
        Node* newnode=new Node(1);
        newnode->next=head;
        return newnode;
    }
    return head;
}

// 3. Find the intersection point of Y LL
//brute force-  TC==>o(n1*logn1 + n2*logn2)   SC==>o(n1)
Node* intersection(Node* head1,Node* head2){
    if(head1==NULL || head2==NULL)return NULL;
    Node* temp=head1;
    map<Node*,int>mpp;
    while(temp!=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end())return temp;
        temp=temp->next;
    }
    return NULL;
}
//better-    TC==>o(n1+2 n2)   SC==>o(1)
Node* collision(Node* head1,Node* head2,int d){
    Node* temp1=head1;
    Node* temp2=head2;
    while(d){
        d--;
        temp2=temp2->next;
    }
    while(temp1!=temp2){
        if(temp1=temp2)return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}
Node* intersection1(Node* head1,Node* head2){
     if(head1==NULL || head2==NULL)return NULL;
    Node* temp=head1;
    int n1=0,n2=0;
    while(temp!=NULL){
        n1++;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        n2++;
        temp=temp->next;
    }
    if(n1<n2) return collision(head1,head2,n2-n1);
    else return collision(head2,head1,n1-n2);
}
//optimal- TC==>o(n1+n2)  SC==>o(1)
Node* intersection3(Node* head1,Node* head2){
     if(head1==NULL || head2==NULL)return NULL;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2){
         temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2)return temp1;
        if(temp1==NULL)temp1=head2;
        if(temp2==NULL)temp2=head1;
    }
    return temp1;
}

// 4. Middle of a LinkedList [TortoiseHare Method]
//brute force-  TC==>o(n+n/2)   SC==>o(1)
Node* mid(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int mid_node=(cnt/2)+1;
    temp=head;
    while(temp!=NULL){
        mid_node--;
        if(mid_node==0)break;
        temp=temp->next;
    }
    return temp;
}
//optimal-  TC==>o(n/2)   SC==>o(1)
Node* tortoise_hair(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// 5.Detect a loop in LL
// brute force-  TC==>o(n * 2logn)  Sc==>o(n)
bool detect_loop(Node* head){
    Node* temp=head;
    map<Node*,int>mpp;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end())return true;
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
//optimal-     TC==>o(n)   SC==>o(1)
bool tortoise_in_loop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        if(fast==slow)return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}

//6.Length of Loop in LL
// brute force-
int length_loop(Node* head){
    Node* temp=head;
    int timer=1;
    map<Node*,int>mpp;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            int val=timer-mpp[temp];
            return val;
        }
        mpp[temp]=timer;
        temp=temp->next;
        timer++;
    }
    return 0;
}
// optimal
int length_loop(Node* slow,Node* fast){
    slow=slow->next;
    int cnt=1;
    while(slow!=fast){
        cnt++;
        slow=slow->next;
    }
    return cnt;
}
int tortoise_length_loop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        if(fast==slow) return length_loop(slow,fast);
        slow=slow->next;
        fast=fast->next->next;
    }
    return 0;
}

int main(){
    vector<int>arr={1,2,3,2,1};
     Node* head=array_linkedlist(arr);
     cout<<palind1(head);
     print(tortoise_hair(head));
    vector<int>arr={9,9,9,9};
     Node* head=array_linkedlist(arr);
     head=add1_recursive(head);
     print(head);


    return 0;
}