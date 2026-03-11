#include<bits/stdc++.h>
using namespace std;

// 1.Implement Stack using Arrays
class ArrayStack{
    int top=-1;
    int arr[10];
    void push(int x){
        if(top>=10)cout<<"stack overflow";
        else{
         top++;
         arr[top]=x;
        }
    }
   void pop(){
        if(top==-1)cout<<"stack empty";
        else  top--;
    }
    int top(){
        if(top==-1)cout<<"stack empty";
        else return arr[top];
    }
    int size(){
        return top+1;
    }
};

// 2.Implement Queue using Arrays
class ArrayQueue{
    private:
    int start=-1,end=-1,currsize=0;
    int arr[10];
    public:
       void push(int x){
        if(currsize>=10){
            cout<<"Queue overflow";
            return;
        }
        if(currsize==0){
            start=0,end=0;
        }
        else{
          end=(end+1)%10;
          arr[end]=x;
          currsize++;
        }
       }
       int pop(){
        if(currsize==0){
            cout<<"Queue empty";
            return -1;
        }
        int el=arr[start];
        if(currsize==1){
            start=end=-1;
        }
        else start=(start+1)%10;
        currsize--;
        return el;
       }
       int top(){
        if(currsize==0){
            cout<<"Queue empty";
            return -1;
        }
        return arr[start];
       }
       int size(){
        return currsize;
       }
};

// 3.Implement stack using Linkedlist
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class LinkedlistStack{
    private:
    Node* top;    // top of stack
    int size=0;
    public:
    void push(int x){
        Node* temp= new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        Node* temp=top;
        top=top->next;
        size--;
        delete temp;
    }
    int top(){
        return top->data;
    }
    int size(){
        return size;
    }
};

// 4.Implement queue using Linkedlist
class LinkedlistQueue{
    private:
    Node* start;
    Node* end;
    int size=0;

    public:
    void push(int x){
        Node* temp=new Node(x);
        if(start==NULL){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        size++;
    }
    void pop(){
        Node* temp=start;
        start=start->next;
        size--;
        delete temp;
    }
    int top(){
        return start->data;
    }
    int size(){
        return size;
    }
};

// 5.Implement Stack using Queue
class QueueStack {
      queue<int> q;
public:
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int el=q.front();
        q.pop();
        return el;
    }
    
    int top() {
       return  q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

//6.Implement Queue using Stack
//Using two Stacks where push operation is O(N)
class StackQueue {
    stack<int>s1;
    stack<int>s2;
public:
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
         while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int el=s1.top();
        s1.pop();
        return el;
    }
    
    int peek() {
       return s1.top();
    }
    
    bool empty() {
    return s1.empty();
    }
};
//Using Two Stacks Where Push Operation is O(1)
class StackQueue1{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int el=s2.top();
             s2.pop();
             return el;
        }
        else{
            while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
       int el=s2.top();
             s2.pop();
             return el;
        }
    }
    
    int peek() {
           if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty()&& s2.empty();
    }
};


int main(){
    return 0;
}