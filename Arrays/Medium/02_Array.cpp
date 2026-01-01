#include<bits/stdc++.h>
using namespace std;

// 1. Rearrange the array in alternating positive and negative items
// brute force- TC==>o(n+n/2)   SC==>o(n);
void rearrange(int arr[],int n){
    vector<int>pos;
    vector<int>neg;
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0)pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[index];
        arr[2*i +1]=neg[index];
        index++;
    }
}

//optimal- TC==>o(n)  SC==>o(n);
vector<int> rearrange1(int arr[],int n){
    vector<int>ans(n);
    int pos=0;
    int neg=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[pos]=arr[i];
            pos+=2;
        }
        else {
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    return ans;
}

// second variety in this- may or may not have equal pos ,neg element so add the remaing one in same order
void rearrange3(int arr[],int n){
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0)pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
        arr[2*i]=pos[i];
        arr[2*i +1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }
    else{
         for(int i=0;i<pos.size();i++){
        arr[2*i]=pos[i];
        arr[2*i +1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }
}



// 2. Next Permutation
// brute force - find all permutation then check for the next permutation of given one in mpp
// better- use next_permutation() stl
// optimal-  TC==>o(3n)  SC==>o(1)
void nextpermut(int arr[],int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
       if(index==-1){
        reverse(arr,arr+n);
    }
    for(int i=n-1;i>index;i--){
        if(arr[index]<arr[i]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr+index+1,arr+n);
}


// 3. Leaders in an Array problem  ==> the element is leader if it is greater than all the element that are in right side of it
//brute force- take each elemnet and compare with all  TC==> o(n*2)  SC==>o(n)

//optimal-  TC==>o(n +nlogn)  SC==>o(n)
vector<int> leaders(int arr[],int n){
    vector <int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
      maxi=max(maxi,arr[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int arr[]={3,-2,-4,4,1,-6,-2,-1};
    rearrange3(arr,8);
    for(auto it:arr)cout<<it<<" ";
    int arr1[]={2,1,5,4,3,0,0};
    nextpermut(arr1,7);
    for(auto it:arr1)cout<<it<<" ";
    int lead[]={10,22,12,3,0,6};
    vector<int> vt=leaders(lead,6);
    for(auto it:vt)cout<<it<<" ";
     return 0;
}