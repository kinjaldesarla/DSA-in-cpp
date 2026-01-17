#include<bits/stdc++.h>
using namespace std;

// 1.Aggressive Cows - (min distance btw cows is maximun) or (min)max
// TC ==> o(nlogn)+o(log2(max-min)) * o(n)    SC==>o(1)
bool can_place_cow(int arr[],int n,int cows,int distance){
    int cntcow=1,last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=distance){
            cntcow++;
            last=arr[i];
        }
        if(cntcow>=cows)return true;
    }
    return false;
}
int aggresive_cows(int arr[],int n,int cows){
    sort(arr,arr+n);
    int low=1,high=arr[n-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(can_place_cow(arr,n,cows,mid)==true)low=mid+1;
        else high=mid-1;
    }
    return high;
}

int main(){
   int stalls[]={0,3,4,7,10,9};
   cout<<aggresive_cows(stalls,6,4);
    return 0;
}