#include<bits/stdc++.h>
using namespace std;

// 1.Implement Stack using Arrays
class ArrayStack{
    int topindex=-1;
    int arr[10];
    void push(int x){
        if(topindex>=10)cout<<"stack overflow";
        else{
         topindex++;
         arr[topindex]=x;
        }
    }
   void pop(){
        if(topindex==-1)cout<<"stack empty";
        else  topindex--;
    }
    int top(){
        if(topindex==-1)cout<<"stack empty";
        else return arr[topindex];
    }
    int size(){
        return topindex+1;
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
            arr[end]=x;
           currsize++;
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
    Node* head = nullptr;   // top of stack
    int sz=0;
    public:
    void push(int x){
        Node* temp= new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    void pop(){
        Node* temp=head;
        head=head->next;
        sz--;
        delete temp;
    }
    int top(){
        return head->data;
    }
    int size(){
        return sz;
    }
};

// 4.Implement queue using Linkedlist
class LinkedlistQueue{
    private:
    Node* start;
    Node* end;
    int sz=0;

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
        sz++;
    }
    void pop(){
        Node* temp=start;
        start=start->next;
        sz--;
        delete temp;
    }
    int top(){
        return start->data;
    }
    int size(){
        return sz;
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

// 7. Balanced Paranthesis  TC==>o(n)  SC==>o(n)
 bool isValid(string s) {
       stack<char>st;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
        else{
            if(st.empty())return false;
            char ch=st.top();
            st.pop();
            if((s[i]==')'&&ch=='(')||(s[i]=='}'&&ch=='{')||(s[i]==']'&&ch=='['))continue;
            else return false;
        }
       }
       return st.empty();
    }


// 8. Implement Min Stack  
//  TC==>o(1)  SC==>o(2n)
class MinStack {
    stack<pair<int,int>>s;  
    void push(int val) {
     if(s.empty()) s.push({val,val});
     else {
        s.push({val,min(val,s.top().second)});
     }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};    

// TC==>o(1)  SC==>o(n)
class MinStack1{
    stack<long long>s;
    long long mini;
    void push(int val){
        long long x=val;
        if(s.empty()){
            mini=x;
            s.push(x);
        }
        else{
            if(x<mini){
                s.push(2*x-mini);
                mini=x;
            }
            else s.push(x);
        }
    }
    void pop(){
        long long el=s.top();
        s.pop();
        if(el<mini){
            mini=2*mini-el;
        }
    }
    int top(){
        long long el=s.top();
        if(el<mini){
            return mini;
        }
        return el;
    }
    int getMin() {
        return mini;
    }
};

int main(){
    cout<<isValid("()[{}(()]");
    return 0;
}