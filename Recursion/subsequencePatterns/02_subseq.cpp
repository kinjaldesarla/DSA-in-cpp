#include <bits/stdc++.h>
using namespace std;

// 1. Combination Sum - u can pick single element more than once to form sum
void combination_sum_rec(int arr[],int n,int index,int target,vector<int>&ds,vector<vector<int>> &ans){
    // base case
    if(index==n){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    // take it : so index would be same as sme element is picked up
    if(arr[index]<=target){
        ds.push_back(arr[index]);
        combination_sum_rec(arr,n,index,target-arr[index],ds,ans);
        ds.pop_back();
    }
    // not take it : so it would move to next element and index = index+1
    combination_sum_rec(arr,n,index+1,target,ds,ans);
}
vector<vector<int>> combinationSum(int arr[], int target,int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination_sum_rec(arr,n,0,target,ds,ans);
        return ans;
    }

int main(){
    int arr[]={2,3,6,7};
    vector<vector<int>> ans=combinationSum(arr,7,4);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}