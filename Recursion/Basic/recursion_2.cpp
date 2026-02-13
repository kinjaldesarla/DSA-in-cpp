#include<bits/stdc++.h>
using namespace std;


// reverse an array
void reverse_arr(int i,int arr[],int n){
   if (i>=n/2)return;
   swap(arr[i],arr[n-i-1]);
   reverse_arr(i+1,arr,n);
}

// check for palindrome
bool palind(int i,string &s){
    int n=s.size();
    if(i>=n/2)return true;
    if(s[i]!=s[n-i-1]) return false;
    palind(i+1,s);
}

// multiple recursive calls
// fibonacci 
int fibo(int n){
    if(n<=1)return n;
    int last=fibo(n-1);
    int slast=fibo(n-2);
    return last+slast;
}
int main(){
    cout<< fibo(4);
    return 0;
}