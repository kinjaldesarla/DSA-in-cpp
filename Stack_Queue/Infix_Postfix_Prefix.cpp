#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch=='^')return 3;
    else if(ch=='*'||ch=='/')return 2;
    else if(ch=='+'||ch=='-')return 1;
    else return -1;
}

// 1.Infix to Postfix Conversion  TC==>o(n)+o(n)   SC==>o(n)+o(n)
string Infix2Postfix(string s){
    stack<char>st;string ans="";int i=0;
    while(i<s.size()){
        // opreands
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) ans+=s[i];
        // open brackets
        else if(s[i]=='(')st.push(s[i]);
        // close brackets
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        // operator
        else{
            while(!st.empty()&&priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

// 2.Infix to Prefix Conversion   TC==>o(n/2)+o(n)+o(n)+o(n/2)  SC==>o(n)+o(n)
string Infix2Prefix(string s){
    // step 1 -->  reverse the string
    reverse(s.begin(),s.end());
    // step 2 -->  Replace '(' with ')' and vice versa
     for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
            i++;
        } else if (s[i] == ')') {
            s[i] = '(';
            i++;
        }
    }
    // step 3 -->  infix->postfix
    stack<char>st;string ans="";int i=0;
    while(i<s.size()){
        // opreands
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) ans+=s[i];
        // open brackets
        else if(s[i]=='(')st.push(s[i]);
        // close brackets
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        // operator
        else{
            // for ^
            if(s[i]=='^'){
                 while(!st.empty()&&priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            }
        else{
             while(!st.empty()&&priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop();
            }
        }
        st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    // step 4 -->  reverse the ans
    reverse(ans.begin(),ans.end());
    return ans;
}

// 3.Postfix to Infix Conversion   TC==>o(n)  SC==>o(n)
string Postix2Infix(string s){
    stack<string>st;int i=0;
    while(i<s.size()){
        // operand
        if(isalnum(s[i])) st.push(string(1, s[i]));
        else {
            string t1=st.top();st.pop();
            string t2=st.top();st.pop();
            string conv='('+t2+s[i]+t1+')';  // might take o(n1+n2)
            st.push(conv);
        }
        i++;
    }
    return st.top();
}

// 4.Prefix to Infix Conversion  TC==>o(n)  SC==>o(n)
string Prefix2Infix(string s){
    // itreate backwards
    stack<string>st;int i=s.size()-1;
    while(i>=0){
        // operand
        if(isalnum(s[i])) st.push(string(1, s[i]));
        else {
            string t1=st.top();st.pop();
            string t2=st.top();st.pop();
            string conv='('+t1+s[i]+t2+')';  // might take o(n1+n2)
            st.push(conv);
        }
        i--;
    }
    return st.top();
}

// 5.Postfix to Prefix Conversion   TC==>o(n)  SC==>o(n)
string Postfix2Prefix(string s){
    stack<string>st;int i=0;
    while(i<s.size()){
        //operand
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else {
            string t1=st.top();st.pop();
            string t2=st.top();st.pop();
            st.push(s[i]+t2+t1);
        }
        i++;
    }
    return st.top();
}

// 6.Prefix to Postfix Conversion    TC==>o(n)  SC==>o(n)
string Prefix2Postfix(string s){
    stack<string>st;int i=s.size()-1;
    while(i>=0){
        //operand
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else {
            string t1=st.top();st.pop();
            string t2=st.top();st.pop();
            st.push(t1+t2+s[i]);
        }
        i--;
    }
    return st.top();
}


int main(){
    string s=Prefix2Postfix("/-AB*+DEF");
    for(auto it :s)cout<<it;
    return 0;
}