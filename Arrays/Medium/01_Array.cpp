#include <bits/stdc++.h>
using namespace std;

// 1. Two sum prblm 
// brute force- TC==>o(n^2)  SC==>o(1)
pair<int,int> twosum1(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                return{i,j};
            }
        }
    }
    return {-1,-1};
}

//better - TC==> o(nlogn)  SC==>o(n)
pair<int,int> twosum2(int arr[],int n,int k){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int remain=k-arr[i];
        if(mpp.find(remain) != mpp.end()){
            return{mpp[remain],i};
        }
        mpp[arr[i]]=i;
    }
    return{-1,-1};
}

// optimal - only for saying whether the pair present or not
//TC==>o(nlogn+n)  SC==>o(1)
void twosum3(int arr[],int n,int k){
    sort(arr,arr+n);
    int left=0;
    int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==k){cout<<"YES"; return;}
        else if(sum<k)left++;
        else right--;
    }
    cout<<"NO";
}

// 2. Sort an array of 0's 1's and 2's
// brute force- sorting the array   TC==>o(nlogn)  SC==>o(n);
// better - TC==> o(2n)  SC==>o(1);
void sorted(int arr[],int n){
    int zero_cnt=0;
    int one_cnt=0;
    int two_cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)zero_cnt++;
        else if(arr[i]==1) one_cnt++;
        else two_cnt++;
    }
    for(int i=0;i<zero_cnt;i++)arr[i]=0;
    for(int i=zero_cnt;i<zero_cnt+one_cnt;i++) arr[i]=1;
    for(int i=zero_cnt+one_cnt;i<n;i++) arr[i]=2;
}


// optimal-  TC==>o(n)  SC==>o(1)
// Dutch National Flag Algorithm- 
// [0...low-1] ==> 0
//[low...mid-1] ==> 1
//[mid...high] ==> unsorted part (0/1/2)
//[high+1...n] ==> 2
void dutch(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    for(int i=0;i<n;i++){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int n=5;
    int arr[]={1,2,6,5,8};
    pair<int,int> index=twosum2(arr,n,14);
    cout<<index.first <<" "<<index.second;
    twosum3(arr,n,15);
    int arr1[]={0,1,2,2,1,0,0,1,1,2,1};
   dutch(arr1,11);
     for(auto it:arr1)cout<<it<<" ";
    return 0;
}