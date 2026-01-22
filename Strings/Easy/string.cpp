#include<bits/stdc++.h>
using namespace std;

//1.Remove outermost Paranthesis   TC==>o(n)  SC==>o(n)
string removeOuterParentheses(string s) {
    int balance=0;
    int start=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')balance++;
        else balance--;
        if(balance==0){
             ans+=s.substr(start+1,i-start-1);
             start=i+1;
        }
    }
    return ans;
}


// 2. Reverse Words in a String  TC==>o(n)  SC==>o(n)
string reverseWords(string s) {
        int n=s.length();
        string ans="";
        int i=n-1;
        while(i>=0){
           while(i>=0 &&s[i]==' ')i--;
           if (i < 0) break;
            int j=i;
            while(i>=0 && s[i]!=' ')i--;
            if(!ans.empty()) ans+=' ';
            ans+=s.substr(i+1,j-i);
        }
        return ans;
    }


// 3.Largest Odd Number in String  TC==>o(n)   SC==>o(1)
 string largestOddNumber(string num) {
     int n=num.length();
     for(int i=n-1;i>=0;i--){
        int digit=num[i]-'0';
        if(digit%2==1)return num.substr(0,i+1);
     }
     return "";
    }    


int main(){
    string s="(()())(())(()(()))";
    cout<<removeOuterParentheses(s);
    return 0;
}