#include<bits/stdc++.h>
using namespace std;

// 1. Binary Search  TC==>o(log2(n))   
// iterative
int binary_search(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
//recursive
int binary_search1(int arr[],int low ,int high,int target){
    if(low>high)return -1;
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) return binary_search1(arr,mid+1,high,target);
        else  return binary_search1(arr,low,mid-1,target);
}
// overflow condition- when search space is 0...INT_MAX and low, high are at last index
//so mid=(INT_MAX+INT_MAX)/2     take mid as long long  OR  mid= low + (high-low)/2


// 	Lower Bound  - smallest index arr[i] >=target     lower_bound(arr.begin(),arr.end(),10)-arr.begin()
//  Uper Bound   - smallest index arr[i]>target       upper_bound(arr.begin(),arr.end(),10)-arr.begin()

// Implement Lower Bound-   TC==>o(log2(n)) 
int lower(int arr[],int n,int target){
    int low=-0,high=n-1;
    int ans=n; // if not having that element return last index
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

// Implement Upper Bound -   TC==>o(log2(n)) 
int upper(int arr[],int n,int target){
    int low=-0,high=n-1;
    int ans=n; // if not having that element return last index
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}


// 2. Search Insert Position- return index where elemnt is present and if not present return index where it should be placed
// exactly similar to lower bound 

// 3. Floor/Ceil in Sorted Array
// Ceil-smallest element >=target    same as lower bound
// Floor- largest element <=target
int floor_value(int arr[],int n,int target){
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            ans=arr[mid];
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

int main(){
    int arr[]={3,4,6,7,9,12,16,17};
    cout<<upper(arr,8,9);
    cout<<floor_value(arr,8,8);
    return 0;
}