#include<bits/stdc++.h>
using namespace std;

// 1. Pascal's Triangle
// i -  find element if row and column are given    TC==>o(r)
int ncr(int n,int r){
    int resultant=1;
    for(int i=0;i<r;i++){
        resultant=resultant*(n-i);
        resultant=resultant/(i+1);
    }
    return resultant;
}

// ii - find nth row of triangle   TC==>o(n)  
void print_row(int n){
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
    cout<<endl;
}

// iii - print triangle     TC==>o(n^2)
    vector<int> generate_row(int n){
        vector<int> temp;
        temp.push_back(1);
        int ans=1;
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> pascal_triangle(int numRows) {
        int n=numRows;
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(generate_row(i));
        }
        return ans;
    }



// 2.  Majority Element (n/3 times)  [AtMost 2 element would be there in ans]
// brute force- check for each element in array
// better- hashing      TC==>o(n)  SC==>o(n)
vector<int> major(int arr[],int n){
    unordered_map<int,int>mpp;
    int mini=(n/3)+1;
    vector <int> ans;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini) ans.push_back(arr[i]);
        if(ans.size()==2)break;
    }
    return ans;
}

// optimal- moore's algo    TC==>o(2n)   SC==>o(1)
vector<int> moores(int arr[],int n){
    int cnt1=0,cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=arr[i]){
            el1=arr[i];
            cnt1+=1;
        }
        else if(cnt2==0 && el1!=arr[i]){
            el2=arr[i];
            cnt2+=1;
        }
        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
        else{
            cnt1--;cnt2--;
        }
    }
   cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]) cnt1++;
        else if(el2==arr[i])  cnt2++;
    }
    int mini=(n/3)+1;
    if(cnt1>=mini)ans.push_back(el1);
    if(cnt2>=mini)ans.push_back(el2);
    return ans;
}


// 3. 3-Sum Problem 
// brute force- generate all triplets then check  
// better -  TC==> o(n^2 +log m)    SC==> o(n) + 2O(no. of unique triplets) - [hashset+set+vector]
vector<vector<int>> three_sum(int arr[],int n){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1;j<n;j++){
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
     vector<vector<int>> ans(st.begin(),st.end());
     return ans;
}

//optimal-  TC==> nlogn +o(n^2)  SC==>O(no. of unique triplets) 
vector<vector<int>> three_sum1(int arr[],int n){
    sort(arr,arr+n);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]== arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j];
            sum+=arr[k];
            if(sum<0)j++;
            else if(sum>0)k--;
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k] == arr[k+1])k--;
            }
        }
    }
    return ans;
}


// 4.  4-Sum Problem
//brute force-  generate all quads then check  
//better-  o(n^3)+log m   SC==>2 o(no.of unique quads) + o(n)
vector<vector<int>> four_sum(int arr[],int n,int target){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int>hashset;
            for(int k=j+1;k<n;k++){
                long long sum=arr[i];
                sum+=arr[j]; sum += arr[k];
                long long fourth =target-(sum);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
}

//optimal  - TC==>nlogn +o(n^3)  SC==>o(no. of unique quads)
vector<vector<int>> four_sum1(int arr[],int n,int target){
    sort(arr,arr+n);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=arr[i];
                sum+=arr[j];sum+=arr[k];sum+=arr[l];
                if(sum<target)k++;
                else if(sum>target)l--;
                else{
                    vector <int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }
            }
           
        }
    }
    return ans;
}

int main(){
    //  int arr[]={1,1,1,2,2,3,3,3};
    //  vector<int> v=moores(arr,8);
    //  for(auto it:v)cout<<it<<' ';
    int arr1[]={1,0,-1,0,-2,2};
    vector<vector<int>>ans=four_sum1(arr1,6,0);
    for(auto it:ans){
        for(auto itt:it) cout<<itt<<" ";
        cout<<endl;
    }
     return 0;
}