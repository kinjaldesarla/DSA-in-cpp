#include<bits/stdc++.h>
using namespace std;

// 1. Generate Binary Strings Without Consecutive 1s    TC==>o(2^n)  SC==>o(n)
void genrateString(int n,string curr,vector<string> &result){
    if(curr.length()==n){
        result.push_back(curr);
        return;
    }
    genrateString(n,curr+'0',result);
    if(curr.empty()|| curr.back()!='1'){
        genrateString(n,curr+'1',result);
    }
}
void binaryStrings(int n){
    vector<string>result;
    genrateString(n,"",result);
    for(auto it : result){
        cout<<it<< endl;
    }
}

// 2.Generate Parentheses
// Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
// Each sequence takes O(n) to build.
// So, total complexity: O(C(n) × n)
// Space Complexity: O(n) recursion depth.
// O(C(n) × n) to store results.
void generateParentheses(int n,string curr,vector<string> &result,int open,int close){
    if(curr.length()==2*n){
        result.push_back(curr);
        return;
    }
    if(open<n ){
        generateParentheses(n,curr+'(',result,open+1,close);
    }
    if(close<open){
        generateParentheses(n,curr+')',result,open,close+1);
    }
}
void parentheses(int n){
    vector<string>result;
    generateParentheses(n,"",result,0,0);
    for(auto it:result){
        cout<<it<<endl;
    }
}

// 3. Power Set
// TC==>o(2^n * n)   SC==>o(1)
void str1(string s){
   int n=s.length();
    for(int i=0;i<(1<<n);i++){
        string ans="";
        for(int j=0;j<n;j++){
            if(i&(1<<j))ans+=s[j];
        }
        cout<<ans<<endl;
    }
}
// recursion-  TC==>o(2^n *n)   SC==>o(n)
void genrate_str(string s,string curr,int index){
    if(index==s.length()){
        cout<<curr<<endl;
        return;
    }
    // include the char
    genrate_str(s,curr+s[index],index+1);
    // exclude the char
    genrate_str(s,curr,index+1);
}
void str2(string s){
    genrate_str(s,"",0);
}


int main(){
   str2("abc");
    return 0;
}