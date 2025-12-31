#include<bits/stdc++.h>
using namespace std;

// 1. find the longest subarray with sum k
//brute force- TC==> o(n^2)  SC==>o(1)
int longest_subarray1(int arr[],int n,int k){
    int maxlen=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}

// better - Tc==>o(nlogn)  SC==>o(n)
// this is the optimal solution when array have positive,negative, zero
int longest_subarray2(int arr[],int n,int k){
    map <int,int>presum_mpp;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int remaining=sum-k;
        if(presum_mpp.find(remaining) != presum_mpp.end()){
            maxlen=max(maxlen,i-presum_mpp[remaining]);
        }
        if(presum_mpp.find(sum) == presum_mpp.end()){
            presum_mpp[sum]=i;
        }
    }
    return maxlen;
}

// optimal- TC==>o(2n)   SC==>o(1)
// 2 pointer approach when array have only posiitive and zeros
int longest_subarray3(int arr[],int n,int k){
    int maxlen=0;
    int left=0;
    int right=0;
    int sum=arr[0];
        while(right<n){
              while(left<=right && sum >k){
                sum-=arr[left];
                left++;
            }
            if(sum==k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
            if(right<n) sum+=arr[right];
        }
        return maxlen;
    }

int main(){
    int arr[7]={1,0,0,4,1,1,0};
   cout << longest_subarray3(arr,7,6);
     return 0;
}