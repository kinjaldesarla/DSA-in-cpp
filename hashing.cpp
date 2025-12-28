#include<bits/stdc++.h>
using namespace std;

// hashing in array max hash array can have size of 10^6 and globally 10^7
// for char in string lowercase ==> ch-'a' and uupercase ==> ch-'A'  if all char are included then size can max to 256
// unordered map and mapp are also used for better result 
// TC unordered ==> best,average o(1) and worst O(n) due to collison
// TC mapp ==> o(log n) for all cases


int main(){
    int arr[7]={1,2,3,1,2,3,15};
    //precompute
    int hash[16]={0};
    for(int i=0;i<7;i++){
        hash[arr[i]]+= 1;
    }
        int num;
        cin>>num;
        //fetching
       cout<<hash[num];


    // string hashing
    string s="abcdeabc";
    int hash[25]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
      char ch;
        cin>>ch;
        //fetching
       cout<<hash[ch-'a'];


    // using maps

     int arr[7]={1,2,3,1,2,3,15};
    //precompute
   unordered_map<int,int> mpp;
   for(int i=0;i<7;i++){
    mpp[arr[i]]+=1;
   }
    int num;
     cin>>num;
    //fetching
     cout<<mpp[num];



    return 0;
}