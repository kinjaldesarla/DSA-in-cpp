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
    int low=0,high=n-1;
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
    int low=0,high=n-1;
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

// 4. Find the first or last occurrence of a given number in a sorted array

// using lower and upper bound-1     TC==>2 o(log2 n)
pair<int,int> first_last(int arr[],int n ,int target){
    int lb=lower(arr,n,target);
    if(lb==n || arr[lb]!=target)return {-1,-1};
    int ub=upper(arr,n,target)-1;
    return{lb,ub};
}

// using binary search             TC==>2 o(log2 n)
int first_occur(int arr[],int n,int target){
    int low=0,high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if (target>arr[mid])low=mid+1;
        else high=mid-1;
    }
    return first;
}
int last_occur(int arr[],int n,int target){
    int low=0,high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }
         else if (target>arr[mid])low=mid+1;
         else high=mid-1;
    }
    return last;
}
pair<int,int> first_last1(int arr[],int n ,int target){
    int lb=first_occur(arr,n,target);
    if(lb==-1)return {-1,-1};
    int ub=last_occur(arr,n,target);
    return{lb,ub};
}


// 5.Count occurrences of a number in a sorted array with duplicates
// find first and last occurence then last-first+1 

// 6. Search in Rotated Sorted Array I
int search_rotated(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid])high=mid-1;
            else low=mid+1;
        }
        else{
            if(arr[mid]<=target && target<=arr[high])low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

// 7. Search in Rotated Sorted Array II
  bool search_rotated_dup(int nums[], int n,int target) {
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)return true;
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                low++;high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target <=nums[mid])high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[high])low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }


// 8. Find minimum in Rotated Sorted Array
int min_rotated(int arr[],int n){
    int low=0,high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        // little optimzation
        if(arr[low]<= arr[high]){
            if(arr[low]<ans){
            ans=arr[low];
            index=low;
           }
          return index;
        }
        if(arr[low]<=arr[mid]){
           if(arr[low]<ans){
            ans=arr[low];
            index=low;
           }
            low=mid+1;
        }
        else{
            if(arr[mid]<ans){
            ans=arr[mid];
            index=mid;
           }
            high=mid-1;
        }
    }
    return index;
}

// 9. Find out how many times has an array been rotated
// the minimum element's index is the times the array rotated


int main(){
    int arr[]={3,4,6,7,9,12,16,17};
    cout<<upper(arr,8,9);
    cout<<floor_value(arr,8,8);
    int arr1[]={1,2,3,3,3,6};
   pair<int,int>vt=first_last1(arr1,7,3);
    cout<<vt.first<<' '<<vt.second;
    cout<<vt.second-vt.first+1;  // no. of occurence
int rotated[]={2,5,6,0,0,1,2};
cout<<search_rotated_dup(rotated,8,0);
int mini[]={7,8,0,2,5};
cout<<min_rotated(mini,5);
    return 0;
}