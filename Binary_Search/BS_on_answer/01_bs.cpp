#include<bits/stdc++.h>
using namespace std;

// 1. Find square root of a number in log n
int sqaure_root(int num){
    int low=1,high=num;
    while(low<=high){
        int mid=(low+high)/2;
        int ans=(mid*mid);
        if(ans<=num)low=mid+1;
        else high=mid-1;
    }
    return high;
}

// 2. Find the Nth root of a number using binary search  TC==>o(n)+o(log2(num));
int func(int num,int n,int mid){
     int ans=1;
    for(int i=1;i<=n;i++){
       ans=ans*mid;
       if(ans>num)return 2;
    }
    if(ans==num)return 1;
    return 0;
}
int nth_root(int num,int n){
    int low=1,high=num;
    while(low<=high){
        int mid=(low+high)/2;
        int ans=func(num,n,mid);
        if(ans==1)return mid;
        else if(ans==2)high=mid-1;
        else low=mid+1;
    }
    return -1;
}

//3. Koko Eating Bananas-   find minimum banana/hour    TC==>o(n) *o(log2(max(element)));
int maxi(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
int calulate_hours(int arr[],int n,int mid){
    int total=0;
    for(int i=0;i<n;i++){
        total=total+ceil((double)arr[i]/(double)mid);
    }
    return total;
}
int koko(int arr[],int n,int time){
   int low=1,high=maxi(arr,n);
   while(low<=high){
    int mid=(low+high)/2;
    int ans=calulate_hours(arr,n,mid);
    if(ans<=time)high=mid-1;
    else low=mid+1; 
   }
   return low;
}

// 4. Minimum days to make M bouquets   TC==>o(log2(maxi-mini+1))*o(n)
bool possible(int arr[],int n,int m,int k,int day){
    int bokeh=0;
      int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day)cnt++;
        else{
            bokeh+=cnt/k;
            cnt=0;
        }
    }
    bokeh+=cnt/k;
    if(bokeh>=m)return true;
    else return false;
}
int mini_day(int arr[],int n,int m,int k){
    if(m*k>n)return -1;
    int low=*min_element(arr,arr+n);
    int high=*max_element(arr,arr+n);
    while(low<=high){
        int mid=(low+high)/2;
        bool possibled=possible(arr,n,m,k,mid);
        if(possibled==true)high=mid-1;
        else low=mid+1;
    }
    return low;
}

// 5.Find the smallest divisor of given threshold   TC==>o(log2(maxelement) * n)
    int divisor_sum(vector<int>& nums,int n,int mid){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            int sum=divisor_sum(nums,n,mid);
            if(sum<=threshold)high=mid-1;
            else low=mid+1;
        }
        return low;
    }

// 6. Capacity to Ship Packages within D Days-   TC==> o(log2(sum-maxelement+1) * n)
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    return sum;
}
int day_required(int arr[],int n,int capacity){
    int day=1,load=0;
    for(int i=0;i<n;i++){
        if(load+arr[i]>capacity){
            day+=1;
            load=arr[i];
        }
        else load+=arr[i];
    }
    return day;
}
int capacity(int arr[],int n,int day){
int low=*max_element(arr,arr+n);
int high=sum(arr,n);
while(low<=high){
    int mid=(low+high)/2;
    int days_req=day_required(arr,n,mid);
    if(day_required(arr,n,mid)<=day)high=mid-1;
    else low=mid+1;
}
return low;
}

int main(){
    cout<<sqaure_root(28);
    cout<<nth_root(28,3);
    int arr[]={3,6,7,11};
    cout<<koko(arr,4,8);
    int arr1[]={7,7,7,7,13,11,12,7};
    cout<<mini_day(arr1,8,2,3);
    int ship[]={1,2,3,4,5,6,7,8,9,10};
    cout<<capacity(ship,10,5);
    return 0;
}
