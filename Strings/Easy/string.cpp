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



// 4. Longest Common Prefix TC==>O(nlogn +min(1st,last))   SC==>o(min(1st,last))
  string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) return "";
        sort(str.begin(), str.end());
        string first = str[0];
        string last = str[str.size() - 1];
        string ans = "";
        int minLength = min(first.size(), last.size());
        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }   

// 5.Isomorphic String-   s = "paper", t = "title"  like one to one mapping
//TC==>o(n)   SC==>o(1) as constant space is used
bool isomorphic(string s,string t){
    int arr1[256]={0},arr2[256]={0};
    for(int i=0;i<s.length();i++){
        if(arr1[s[i]]!=arr2[t[i]])return false;
        arr1[s[i]]=i+1;
        arr2[t[i]]=i+1;
    }
    return true;
}

// 6.check whether one string is a rotation of another
//brute force- search for each combination  TC==>o(n^2)
//optimal-  TC==>o(n)
bool rotated(string s,string goal){
    string resultant=s+s;
    if(s.length()!=goal.length())return false;
    return resultant.find(goal)!=string::npos;
}


// 7. Check if two strings are anagram of each other
// TC==>o(n)  SC==>o(1)
bool anagram(string s,string t){
    if(s.length()!=t.length())return false;
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0)return false;
    }
    return true;
}
    int main(){
    string s="(()())(())(()(()))";
    cout<<removeOuterParentheses(s);
   vector<string> str = {"dog","racecar","car"};
   cout<<longestCommonPrefix(str);
   cout<<isomorphic("paper","title"); 
   cout<<rotated("abcde","cdeab");
   cout<<anagram("abc","acb");
    return 0;
}