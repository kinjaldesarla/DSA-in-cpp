#include <bits/stdc++.h>
using namespace std;

// 1. Combination Sum - u can pick single element more than once to form sum   TC==>o(2^t *k)  SC==>o(k*x)
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

// 2. Combination Sum II  TC==>o(2^n *k)  SC==>o(k*x)
void combinationSum2_recu(vector<int>& candidates,int index,int target,vector<int> &ds,vector<vector<int>> &ans) {
    // base case
        if(target==0){
          ans.push_back(ds);
         return;
        }
        for(int i= index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            combinationSum2_recu(candidates,i+1,target-candidates[i],ds,ans);
            ds.pop_back();
        }
   }   
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
       combinationSum2_recu(candidates,0,target,ds,ans);
       return ans;
    }


// 3. Subsets-I - using powerset  TC==>o(2^n * n)+ o(2^n(log(2^n)))  SC==>o(2^n)
void powerSet(int s[],int n){
   vector<int>result;
   // 1<<n is 2^n
    for(int i=0;i<(1<<n);i++){
        int ans=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))ans+=s[j];
        }
        result.push_back(ans);
    }
    sort(result.begin(),result.end());
    for(auto it:result)cout<<it<<" ";
}  
// TC==>o(2^n + 2^nlog(2^n))
void Subsets1_rec(int arr[],int n,int index,int sum,vector<int> &ans){
    if(index==n){
        ans.push_back(sum);
        return;
    }
   Subsets1_rec(arr,n,index+1,sum+arr[index],ans);
   Subsets1_rec(arr,n,index+1,sum,ans);
}  
void Subsets1(int arr[],int n){
    vector<int>ans;
    Subsets1_rec(arr,n,0,0,ans);
    sort(ans.begin(),ans.end());
    for(auto it:ans)cout<<it<<" ";
}

// 4.Subset-II    TC==>o(2^n * n) SC==> o(2^n)  auxillary space is o(n)
void subsetwithdup_rec(int arr[],int n,int index,vector<int> &ds,vector<vector<int>> &ans){
     ans.push_back(ds);
    for(int i=index;i<n;i++){
        if(i>index&&arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        subsetwithdup_rec(arr,n,i+1,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(int arr[],int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(arr,arr+n);
        subsetwithdup_rec(arr,n,0,ds,ans);
        for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
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
    int arr1[]={1,2,2};
    subsetsWithDup(arr1,3);
    return 0;
}