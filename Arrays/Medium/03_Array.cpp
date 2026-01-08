#include<bits/stdc++.h>
using namespace std;

// 1. Set Matrix Zeros
//brute force-  TC==> o((n*m  * n+m) + n*m) 

void set_matrix1(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
            for(int col=0;col<m;col++){
                if(arr[i][col]!=0){
                    arr[i][col]=-1;
                }
            }
            for(int row=0;row<n;row++){
                if(arr[row][j]!=0){
                    arr[row][j]=-1;
                }
            }
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}

// better-  TC==> o(2*n*m)  SC==> o(n+m)
void set_matrix2(vector<vector<int>>&arr){
     int n=arr.size();
    int m=arr[0].size();
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 ||col[j]==1){
                arr[i][j]=0;
            }
        }
    }
}

//optimal-  TC==> o(2*n*m)   SC==>o(1)
void set_matrix3(vector<vector<int>>&arr){
     int n=arr.size();
    int m=arr[0].size();
    // int col[m]={0};  arr[0][...]
    // int row[n]={0};   arr[...][0]
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0) arr[0][j]=0;
                else col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
    }
    if(arr[0][0]==0){
        for(int j=0;j<m;j++)arr[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++)arr[i][0]=0;
    }
}


// 2. Rotate Matrix by 90 degrees
//brute force -  TC==>o(n^2)   SC==>o(n^2)
void rotate1(vector<vector<int>>arr){
    int n=arr.size();
    int m=arr[0].size();
    int ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-1-i]= arr[i][j];
        }
    }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}

//optimal-  TC==> o((n/2 *n/2) + (n*n/2))  SC==>o(1)
void transpose_reverse(vector<vector<int>>arr){
    int n=arr.size();
    // tc==> o(n/2 *n/2)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // tc==> o(n*n/2)
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}


// 3. Print the matrix in spiral manner
// optimal-  TC==>o(n^2)  SC==>o(n^2)
vector<int> spirals(vector<vector<int>>arr){
     int n=arr.size();
    int m=arr[0].size();
    int left=0;
    int right=m-1;
    int top=0;
    int bottom=n-1;
    vector<int>ans;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top ;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom)
        {for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
        bottom--;}
        if(left<=right)
       { for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
        }
        left++;}
    
    }
    return ans;
}


// 4. Count subarrays with given sum
//brute force- taking each subarray then checking sum   TC==>o(n^2)  Sc==>o(1)

//optimal-TC==>o(n+logn)  SC==>o(n)
int subaary(int arr[],int n,int k){
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int presum=0,cnt=0;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
    }
    return cnt;
}

int main(){
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans=spirals(arr);
    for(auto it :ans) cout<<it<<" ";
    int arr1[]={1,2,3,-3,1,1,1,4,2,-3};
    cout<<subaary(arr1,10,3);
     return 0;
}