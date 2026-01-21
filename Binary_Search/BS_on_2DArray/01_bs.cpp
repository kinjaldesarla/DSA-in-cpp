#include<bits/stdc++.h>
using namespace std;

// 1. Find the row with maximum number of 1's
// brute force-  TC==>o(n*m)    SC==>o(1)
int max_ones(vector<vector<int>> arr){
    int n=arr.size();
    int m=arr[0].size();
    int max_cnt=-1,index=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=arr[i][j];
        }
        if(cnt>max_cnt){
            max_cnt=cnt;
            index=i;
        }
    }
    return index;
}

// bs-  TC==> o(n * log2(m))  SC==>o(1)
int lowerBound(vector<int>arr,int m,int k){
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=k)high=mid-1;
        else low=mid+1;
    }
    return low;
}
int max_ones_bs(vector<vector<int>> arr){
    int n=arr.size();
    int m=arr[0].size();
    int max_cnt=0,index=-1;
    for(int i=0;i<n;i++){
        int cnt=m-lowerBound(arr[i],m,1);
        if(cnt>max_cnt){
            max_cnt=cnt;
            index=i;
        }
    }
    return index;
}


// 2. Search in a 2 D matrix
// brute force-
bool search(vector<vector<int>> arr,int target){
     int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target)return true;
        }
    }
    return false;
}

// bs-  TC==>o(n + log2(m))   SC==>O(1)
bool searching(vector<int>arr,int m,int target){
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return true;
        else if(arr[mid]<target)low=mid+1;
        else high=mid-1;
    }
    return false;
}
bool search1(vector<vector<int>> arr,int target){
     int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        if(arr[i][0]<=target && target<=arr[i][m-1]){
            return searching(arr[i],m,target);
        }
    }
    return false;
}

// flaterring 2d to 1d- TC==>o(log2(n*m-1))  SC==>o(1)
bool search2(vector<vector<int>> arr,int target){
     int n=arr.size();
    int m=arr[0].size();
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m,col=mid%m;
        if(arr[row][col]==target)return true;
        else if(arr[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}


// 3. Search in a row and column wise sorted matrix
// brute force TC==>o(n*m)
// bs - same as above but for check for each row TC==>o(n*log2(m)) 
//optimal bs-  TC==>o(n+m)   SC==>o(1)
bool search3(vector<vector<int>> arr,int target){
      int n=arr.size();
    int m=arr[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(arr[row][col]==target)return true;
        else if(arr[row][col]<target)row++;
        else col--;
    }
    return false;
}


// 4. Find Peak Element (2D Matrix)
// TC==>o(log2(m)*n)   SC==>o(1)
int maxele_col(vector<vector<int>>arr,int n,int m,int mid){
    int maxi=-1,index=-1;
    for(int i=0;i<n;i++){
       if(arr[i][mid] > maxi){
        maxi=arr[i][mid];
        index=i;
       }
    }
    return index;
}
int peak_element(vector<vector<int>>arr){
    int n=arr.size();
    int m=arr[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=maxele_col(arr,n,m,mid);
        int left=mid-1>=0?arr[row][mid-1]:-1;
        int right=mid+1<m?arr[row][mid+1]:-1;
        if(arr[row][mid]>left && arr[row][mid]>right)return arr[row][mid];
        else if(arr[row][mid]<left)high=mid-1;
        else low=mid+1;
    }
    return -1;
}


// 5. Matrix Median   TC==>o(log2(max-min) * nlog2(m))
int upper(vector<int>arr,int n,int target){
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
int min_possible(vector<vector<int>>&arr,int n,int m,int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upper(arr[i],m,mid);
    }
    return cnt;
}
int median(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    int req=(n*m)/2;
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,arr[i][0]);
        high=max(high,arr[i][m-1]);
    }
    while(low<=high){
        int mid=(low+high)/2;
        int smallest=min_possible(arr,n,m,mid);
        if(smallest<=req)low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<vector<int>>vt={{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,1},{0,1,1,1,1}};
    cout<<max_ones_bs(vt);
     vector<vector<int>>v={{3,4,7,9},{12,13,16,18},{20,21,23,29}};
     cout<<search(v,23);
     vector<vector<int>> arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
     cout<<search3(arr,50);
     vector<vector<int>>peak={{1,4},{3,2}};
     cout<<peak_element(peak);
     vector<vector<int>>m={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
     cout<<median(m);
    return 0;
}