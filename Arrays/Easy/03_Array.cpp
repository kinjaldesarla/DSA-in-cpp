#include<bits/stdc++.h>
using namespace std;

// 1. find missing number in array 
// brute force-  Tc==>o(n^2)  SC==>o(1)
int missing(int arr[],int N){
    int n=N-1;
 for(int i=1;i<=n;i++){
    bool flag=0;
    for(int j=0;j<n;j++){
        if(arr[j]==i) flag=1;
    }
    if(flag==0)return i;
 }
}
//better - by using hashing  TC==>o(2n)  SC==>o(n)
int hash_missing(int arr[],int N){
    int n=N-1;
    int maxi=N;
    int hash[maxi+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<maxi+1;i++)if(hash[i]==0)return i;
}
//optimal
//sum- Tc==>o(n)  Sc==>o(1)
int sum_missing(int arr[],int N){
    int sum=(N*(N+1))/2;
    int sum1=0;
    for(int i=0;i<N-1;i++){
        sum1=sum1+arr[i];
    }
    return sum-sum1;
}
// xor-  Tc==>o(n)  Sc==>o(1)  this is more good than sum when inputs are larger like 10^5
int xor_missing(int arr[],int N){
    int xor1=0;
    int xor2=0;
    for(int i=0;i<N-1;i++){
        xor1=xor1^arr[i];
        xor2=xor2^i+1;
    }
    xor2=xor2^N;
    return xor2^xor1;
}


// 2. maximum consecutive ones in array
// Tc==>o(n)  SC==>o(1)
int consecutives(int arr[],int n){
    int maxi=0;
    int ctn=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ctn++;
            maxi=max(maxi,ctn);
        }
        else{
            ctn=0;
        }
    }
    return maxi;
}

// 3.Find the number that appears once, and other numbers twice.
// brute force- we have to compare each element in array by picking every element in each pass 
//Tc==>o(n^2)  SC==>o(1)

//better- hashing  TC==> o(3n)  Sc==>o(maxi+1)
int find_num(int arr[],int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int hash[maxi+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=1;i<maxi+1;i++){
        if(hash[i]==1)return i;
    }
}

// but when input are big then use mapp  TC==> o(nlog(n/2 +1))+o(n/2 +1)   SC==> o(n/2 +1)
int find_num1(int arr[],int n){
    map<int ,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1)return it.first;
    }
}

//optimal - xor  TC==>o(n)  SC==>o(1)
int xor_find(int arr[],int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}


int main(){
    int arr[]={1,2,4,5,1,2,5};
    cout<<xor_find(arr,7);
    int arr1[14]={1,1,0,0,0,1,1,1,1,0,0,1,1,1};
    cout<<consecutives(arr1,14);
    return 0;
}