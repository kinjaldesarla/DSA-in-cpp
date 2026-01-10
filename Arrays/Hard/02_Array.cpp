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

// 2.  Merge two sorted arrays without extra space
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


// 3. Find the repeating and missing number
// brute force- comapre each number in array TC==>o(n^2)  SC==>o(1)
//better- hashing  TC==>o(2n)  SC==>o(n)
vector<int> repeating_missing(int arr[],int n){
    int hasharr[n+1]={0};
    int repeat=-1,missing=-1;
    for(int i=0;i<n;i++){
        hasharr[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hasharr[i]==2) repeat=i;
        else if(hasharr[i]==0) missing=i;

        if(repeat!=-1 && missing!=-1)break;
    }
    return{repeat,missing};
}

// optimal - 1.  TC==>o(n)  SC==>o(1)
vector<int> repeating_missing1(int arr[],int n){
    int s=0,s2=0;
    int sn=(n*(n+1))/2;
    int sn2=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=arr[i]*arr[i];
    }
    int val1=s-sn;
    int val2=s2-sn2;
    val2=val2/val1;
    int x=(val1+val2)/2;
    int y=x-val1;
    return{x,y};
}

//optimal - 2.  TC==>o(n)  SC==>o(1)
vector<int> repeating_missing2(int arr[],int n){
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    // to generate this int number= xr & ~(xr-1);
    int bitNo=0;
    while(1){
        if((xr &( 1<<bitNo)) !=0)break;
        bitNo++;
    }
    int one=0,zero=0;
    for(int i=0;i<n;i++){
        if((arr[i] &( 1<<bitNo)) !=0){
            one=one^arr[i];
        }
        else{
            zero=zero^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
          if((i &( 1<<bitNo)) !=0){
            one=one^i;
        }
        else{
            zero=zero^i;
        }
    }
     int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==one)cnt++;
    }
    if(cnt==2) return{one,zero};
    else return{zero,one};
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
    int arr[]={4,3,6,2,5,5};
    vector<int>v=repeating_missing1(arr,6);
    cout<<v[0]<<' '<<v[1];
    return 0;
}