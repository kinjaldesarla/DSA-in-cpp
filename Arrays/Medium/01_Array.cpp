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

// 3.	Majority Element (>n/2 times)
//brute force- take eaach element and check for majority 
// TC==> o(n^2) SC==>o(1)

//better- TC==>o(nlogn)  SC==>o(n)
int major1(int arr[],int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/2)return it.first;
    }
    return -1;
}

// optimal- TC==>o(n)  SC==>o(1)
// Moore's voting algorithm
int moore(int arr[],int n){
    int cnt=0;
    int element;
    for(int i=0;i<n;i++){
       if(cnt==0){
        element=arr[i];
        cnt++;
       }
       else if(arr[i]==element){
        cnt++;
       }
       else cnt--;
    }
    // tthis is to check only when question say may have majority element
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element) cnt1++;
        if(cnt1>n/2)return element;
    }
    return -1;
}


// 4. Kadane's Algorithm, maximum subarray sum or Print subarray with maximum subarray sum 
//brute force- take all subarray then find max sum subarray 
//Tc==>o(n^2)  SC==>o(1)

//optimal- TC==>o(n)  SC==>o(1)
//Kadane's Algorithm
int kadane(int arr[],int n){
    int maxi=INT_MIN;
    int sum=0;
    int start=-1,end=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
         if (sum>maxi) maxi=sum; end=i;
        if(sum<0)sum=0;
    }
    // this part is for returning subarray
    for(int i=start;i<end;i++){
        cout<<arr[i]<<" ";
    }
    return maxi;
}


// 5. Stock Buy and Sell -  TC==>o(n)  SC==>o(1)
int stock(int arr[],int n){
    int mini=arr[0];
    int profit=0;
    for(int i=1;i<n;i++){
        int cost =arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    return profit;
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
     int arr2[]={2,2,2,4,6,8,2,1,2,2};
     cout<<moore(arr2,10);
    int arr1[]={-2,-3,4,-1,-2,1,5,-3};
    cout<<kadane(arr1,8);
    int stocks[]={7,1,5,3,6,4};// buys in 1 and sells in 6 so profit is of 5
    cout<<stock(stocks,6);
    return 0;
}