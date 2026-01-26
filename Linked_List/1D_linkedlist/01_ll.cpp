#include<bits/stdc++.h>
using namespace std;

// basic-
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

// array to linklist  o(n)
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

//  traversal in LL  o(n)
void print(Node* head){
       Node* temp=head;
    // traversal in LL  o(n)
    while(temp){           
        cout<<temp->data<<' ';
        temp=temp->next;
    }
} 

int length_LL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

// search for element 
int check(Node* head,int k){
    Node* temp=head;
    while(temp){
        if(temp->data==k)return 1;
        temp=temp->next;
    }
    return 0;
}


// deletion concepts
// delete head
Node* removehead(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    delete temp;
return head;
}
// delete tail
Node* removetail(Node* head){
    if(head==NULL||head->next==NULL)return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
// delete kth position
Node* remove_kth(Node* head,int k){
    if(head==NULL)return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* prev=NULL;
    Node* temp =head;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
// delete element
Node* remove_ele(Node* head,int k){
    if(head==NULL)return head;
    if(head->data==k){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=NULL;
    Node* temp =head;
    while(temp){
        if(temp->data==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


// insertion concepts
// insert head
Node* inserthead(Node* head,int k){
    Node* temp=new Node(k);
    temp->next=head;
    return temp;
}
// insert tail
Node* inserttail(Node* head,int k){
    if(head==NULL)return new Node(k);
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    Node* insert=new Node(k);
    temp->next=insert;
    return head;
}
// insert kth position
Node* insert_kth(Node* head,int k ,int ele){
    if(head==NULL) return new Node(ele);
    if(k==1){
        Node* newnode=new Node(ele);
        newnode->next=head;
        return newnode;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
             Node* newnode=new Node(ele);
             newnode->next=temp->next;
             temp->next=newnode;
             break;
        }
        temp=temp->next;
    }
    return head;
}
//insert element before value
Node* insertval(Node* head,int ele,int val){
    if(head==NULL)return NULL;
    if(head->data==val){
        Node* newnode=new Node(ele);
        newnode->next=head;
        return newnode;
    }
    Node* temp=head;
    int cnt=0;
    while(temp->next!=NULL){
        cnt++;
        if(temp->next->data==val){
             Node* newnode=new Node(ele);
             newnode->next=temp->next;
             temp->next=newnode;
             break;
        }
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int>arr={2,5,6,3};
    Node* head=array_linkedlist(arr);
    cout<<head->data<<' ';
    // length
    cout<<length_LL(head);
    // search
    cout<<check(head,3);

    head=insertval(head,99,3);
    print(head);

    return 0;
}