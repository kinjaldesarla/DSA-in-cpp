#include<bits/stdc++.h>
using namespace std;

// 1. left rotate by place one 
//optimal-  TC==>o(n) sc==>o(1)
void left_rotate_1(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

// 2. left rotate by place of d
//brute force - TC==> o(n+d)     SC==>o(d)
void left_rotate(int arr[],int n,int d){
    d=d%n; // because if n is 7 and d is 8 then for 7 it is going to result in same array. so do only one place shifting
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
}
//optimal -  TC==>o(2n)  sc==>o(1)
void left_rotated(int arr[],int n,int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

// right rotate
  void rotate(vector<int>& nums, int k) {
     int n = nums.size();
      k =k%n;
      reverse(nums.begin(),nums.end());
      reverse(nums.begin(),nums.begin()+k);
      reverse(nums.begin()+k,nums.end());
    }


// 3. move zeros to end
// brute force-  store non zeros to temp them place them to arr agian and all other reaming values in array is zero
// TC==> o(2n) SC==>o(n)

// optimal - TC==>o(n)  SC==>o(1)
   void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
         if(j==-1) return;
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }


// linear search - TC==> o(n)  SC==>o(1)
int linear(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
}    

// union of two sorted array
// brute force- use set two store  unique element and in order TC==> o(n1logn + n2logn) + o(n1+n2)
//optimal- 2 pointer   TC==>o(n+m)  SC==>o(n+m)
void union_arrays(int arr1[],int arr2[],int n,int m){
    int i=0;
    int j=0;
    vector <int> unionarr;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
             if(unionarr.size()==0 || unionarr.back()!=arr1[i]){
            unionarr.push_back(arr1[i]);
        }
        i++;
      }
       else{
            if(unionarr.size()==0 || unionarr.back()!=arr2[j]){
            unionarr.push_back(arr2[j]);
        }
        j++;
    }
}
while(i<n){
       if(unionarr.size()==0 || unionarr.back()!=arr1[i]){
            unionarr.push_back(arr1[i]);
          
}
  i++;
}
while(j<m){
  if(unionarr.size()==0 || unionarr.back()!=arr2[j]){
            unionarr.push_back(arr2[j]);
          
}
  j++;
}
for(auto it:unionarr)cout<<it<<" ";
}


//intersection
//brute force - TC==>o(n*m)   Sc==>o(m)
void intersect(int a[],int b[],int n,int m){
    int visited[m]={0};
   vector<int> intersect;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j] && visited[j]==0){
                intersect.push_back(a[i]);
                visited[j]=1;
            }
            if(b[j]>a[i])break;
        }
    }
    for (auto it:intersect)cout<<it<<' ';
}

//optimal- 2pointer   TC==>o(n+m)   SC==>o(1)
void intersection(int a[],int b[],int n,int m){
    int i=0;
    int j=0;
    vector<int> intersect;
    while(i<n && j<m){
        if(a[i]<b[j])i++;
        else if(b[j]<a[i])j++;
        else{
            intersect.push_back(a[i]);
            i++;
            j++;
        }
    }
     for (auto it:intersect)cout<<it<<' ';
}

int main(){
   int arr1[]={1,2,3,4,5,6};
   int arr2[]={3,4,5,6,7,8};
  union_arrays(arr1,arr2,6,6);
   intersection(arr1,arr2,6,6);
    return 0;
}