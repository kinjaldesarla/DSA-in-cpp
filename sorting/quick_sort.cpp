#include <bits/stdc++.h>
using namespace std;

// TC ==> o(n logn) || worst case ==> o(n^2)    SC==>o(1)
int partitions(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void quick_sort(int arr[], int low,int high){
    if(low<high){
       int pindex= partitions(arr,low,high);
   quick_sort(arr,low,pindex-1);
        quick_sort(arr,pindex+1,high);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    quick_sort(arr,0,n-1);
    for(auto it:arr)cout<<it<<" ";

    return 0;
}