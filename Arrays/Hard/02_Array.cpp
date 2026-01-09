#include<bits/stdc++.h>
using namespace std;

// 1. Merge Overlapping Subintervals
// brute force-     TC==>nlogn + 2o(n)      SC==>o(n)
vector<vector<int>>merging(vector<vector<int>> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];   
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

//optimal-  TC==>nlohn +o(n)    Sc==>o(n)
vector<vector<int>>merging1(vector<vector<int>> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
     vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty()||arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }

    }
    return ans;
}

// 2.Merge two sorted arrays without extra space
//brute force- TC==>o(2(n+m))   SC==>o(n+m)
void merge_arrays(int arr1[],int arr2[],int n,int m){
    int arr[n+m];
    int left=0;
    int right=0;
    int index=0;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            arr[index]=arr1[left];
            left++;
            index++;
        }
        else{
             arr[index]=arr2[right];
            right++;
            index++;
        }
    }
    while(left<n)arr[index++]=arr1[left++];
    while(right<m)arr[index++]=arr2[right++];
    for(int i=0;i<n+m;i++){
       if(i<n) arr1[i]=arr[i];
       else arr2[i-n]=arr[i];
    }
}

//optimal 1.  TC==>o(min(n,m)) +o(nlogn) +o(mlogm)  SC==>o(1)
void merge_arrays1(int arr1[],int arr2[],int n,int m){
    int left=n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr1[left]>=arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;right++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

//optimal 2. TC==>o(log n+m)+o(n+m)  SC==>o(1)
void swap_greater(int arr1[],int arr2[],int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}
void merge_arrays2(int arr1[],int arr2[],int n,int m){
    int gap=((n+m)/2)  + ((n+m)%2);
    while(gap>0){
         int left=0;
         int right=left+gap;
         while(right<n+m){
            // compare arr1 arr2
            if(left<n && right>=n){
                swap_greater(arr1,arr2,left,right-n);
            }
            //compare arr2 arr2
            else if(left>=n){
                swap_greater(arr2,arr2,left-n,right-n);
            }
            //compare arr1 arr1
            else{
                swap_greater(arr1,arr1,left,right);
            }
            left++;right++;
         }
          if(gap==1)break;
         gap=(gap/2)+(gap%2);
    }
}

int main(){
    vector<vector<int>> vt={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>> ans=merging1(vt);
    for(auto it:ans){
        for (auto itt: it) cout<<itt<<" ";
        cout<<endl;
    }
    int arr1[]={1,2,5,6},arr2[]={0,3,4,8,9};
    merge_arrays2(arr1,arr2,4,5);
    for(auto it :arr1)cout<<it<<' ';
    for(auto it :arr2)cout<<it<<' ';
    return 0;
}