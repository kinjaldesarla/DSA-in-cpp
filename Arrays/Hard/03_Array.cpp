#include<bits/stdc++.h>
using namespace std;

// 1. Count Inversions
//brute force-check for each one in array   TC==>o(n^2)  SC==>o(1)

//optimal- TC==>o(nlogn)  SC==>o(n)

int mergee(int arr[], int low,int mid,int high){
    vector <int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            int length=mid-left+1;
            cnt+=length;
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(arr[left]);
         left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

int merge_sort(int arr[],int low,int high){
    int cnt=0;
    if(low>=high)return cnt;
     int mid=(low+high)/2;
    cnt+=merge_sort(arr,low,mid);
   cnt+= merge_sort(arr,mid+1,high);
    cnt+=mergee(arr,low,mid,high);
    return cnt;
}

int count_inversion(int arr[],int n){
    int low=0,high=n-1;
    return merge_sort(arr,low,high);
}


// 2. Reverse Pairs
// brute force - check for each one in array   TC==>o(n^2)  SC==>o(1)

//optimal-  TC==>o(2nlogn)   SC==>o(n)

int count_pairs(int arr[],int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
     while(right<=high && arr[i]>2*arr[right])right++;
     cnt+=right-(mid+1);
    }
    return cnt;
}

void merge2(int arr[], int low,int mid,int high){
    vector <int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(arr[left]);
         left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

int merge_sort2(int arr[],int low,int high){
    int cnt=0;
    if(low>=high)return cnt;
     int mid=(low+high)/2;
   cnt+= merge_sort2(arr,low,mid);
    cnt+=merge_sort2(arr,mid+1,high);
   cnt+=count_pairs(arr,low,mid,high);
    merge2(arr,low,mid,high);
    return cnt;
}

int reverse_pairs(int arr[],int n){
    int low=0,high=n-1;
    return merge_sort2(arr,low,high);
}


// 3. Maximum Product Subarray
//brute force- genearte all subarray   TC==>o(n^2)  SC==>o(1)

// optimal-  TC==>o(n)  SC==>o(1)
int max_product(int arr[],int n){
    int prefix=1,suffix=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix=prefix*arr[i];
        suffix=suffix*arr[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}

int main(){
    int arr[]={40,25,19,12,9,6,2};
    cout<<reverse_pairs(arr,7)<<endl;
    int arr1[]={2,3,-2,4};
    cout<<max_product(arr1,4);
    return 0;
}