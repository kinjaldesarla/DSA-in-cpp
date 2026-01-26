#include<bits/stdc++.h>
using namespace std;

// 1. Sort Characters by frequency
string sort_fre(string s){
    int n=s.length();
    string ans;
    priority_queue<pair<int,char>>pq;
    map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    for(auto it :mpp){
        pq.push({it.second,it.first});
    }
    while(!pq.empty()){
        auto top=pq.top();pq.pop();
        ans.append(top.first,top.second);
    }
return ans;
}

//2.Maximum Nesting Depth of Paranthesis  TC==>O(n)  SC==>o(1)
int nesting_count(string s){
    int n=s.length();
    int maxi=INT_MIN;
    int balance=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            balance++;
            maxi=max(maxi,balance);
        }
       if(s[i]==')'){
        balance--;
       }
    }
    return maxi;
}

//3. Roman Number to Integer and vice versa
int conversion(string s){
    int n=s.length();
   unordered_map<char,int>mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
   int sum=0;
   for(int i=0;i<n-1;i++){
    if(mpp[s[i]]<mpp[s[i+1]]){
        sum-=mpp[s[i]];
    }
    else{
        sum+=mpp[s[i]];
    }
   }
   return sum+mpp[s[n-1]];
}


//4. Implement Atoi
int atoi(string s){
    int n=s.length();
    int sign =1;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]==' ')continue;
        if(s[i]=='-')sign=-1;
        if(s[i]=='+')sign=1;
        if(s[i]=='0')continue;
        if(isdigit(s[i])){
            ans=ans*10+s[i];
            if(sign*ans>INT_MAX)return INT_MAX;
            if(sign*ans<INT_MIN)return INT_MIN;
        }
    }
   return ans;
}


int main(){
    cout<<sort_fre("tree");
    cout<<nesting_count("(1)+((2))+(((3)))");
    cout<<conversion("LVIII");
    cout<<atoi(" -042");
    return 0;
}