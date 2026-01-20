#include<bits/stdc++.h>
using namespace std;

// 1.Aggressive Cows - (min distance btw cows is maximun) or (min)max
// TC ==> o(nlogn)+o(log2(max-min)) * o(n)    SC==>o(1)
bool can_place_cow(int arr[],int n,int cows,int distance){
    int cntcow=1,last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=distance){
            cntcow++;
            last=arr[i];
        }
        if(cntcow>=cows)return true;
    }
    return false;
}
int aggresive_cows(int arr[],int n,int cows){
    sort(arr,arr+n);
    int low=1,high=arr[n-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(can_place_cow(arr,n,cows,mid)==true)low=mid+1;
        else high=mid-1;
    }
    return high;
}

// 2. Book Allocation Problem- max pages is minimum    TC==> o(log2(sum-max) * n)
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    return sum;
}
int total_student(int arr[],int n,int min_page){
    int student=1,page=0;
    for(int i=0;i<n;i++){
        if(page+arr[i]<=min_page){
            page+=arr[i];
        }
        else{
            student++;
            page=arr[i];
        }
    }
    return student;
}
int book_allocate(int arr[],int n,int student){
    if(student>n)return -1;
    int low=*max_element(arr,arr+n);
    int high=sum(arr,n);
    while(low<=high){
        int mid=(low+high)/2;
        if(total_student(arr,n,mid)>student)low=mid+1;
        else high=mid-1;
    }
    return low;
}

// 3. Painter's partition / Split array - Largest Sum
// same as book allocation one

// 4. Minimize Max Distance to Gas Station
// brute force-  Tc==> o(k*n +n )   
double max_gs_distance(int arr[],int n,int k){
    int how_many[n-1]={0};
    for(int gs=1;gs<=k;gs++){
            double max_section=-1;
             int max_index=-1;
        for(int i=0;i<n-1;i++){
            int diff=arr[i+1]-arr[i];
            double section_leng=diff/(double)(how_many[i]+1);
            if(section_leng>max_section){
                max_section=section_leng;
                max_index=i;
            }
        }
        how_many[max_index]++;
    }
    double maxi=-1;
    for(int i=0;i<n-1;i++){
        double section_leng=(arr[i+1]-arr[i])/(double)(how_many[i]+1);
        maxi=max(maxi,section_leng);
    }
    return maxi;
}

// better -  TC==>o(nlogn + klogn)  SC==>o(n-1)
double max_gs_distance1(int arr[],int n,int k){
    int how_many[n-1]={0};
    priority_queue<pair<double,int>>pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gs=1;gs<=k;gs++){
      int sec_index=pq.top().second;
      pq.pop();
      how_many[sec_index]++;
      double new_diff=arr[sec_index+1]-arr[sec_index];
      double new_section_leng= new_diff/(double)(how_many[sec_index]+1);
      pq.push({new_section_leng,sec_index});
    }
  return pq.top().first;
}

//binary serach-  TC==> o(n + log2(range)*n)  SC==>o(1)
int count_gasstation(int arr[],int n,long double dis){
    int cnt=0;
    for(int i=0;i<n-1;i++){
        int gs=(int)((arr[i+1]-arr[i])/dis);
        if((arr[i+1]-arr[i])/dis == gs*dis)gs--;
        cnt+=gs;
    }
    return cnt;
}
long double max_gs_distance2(int arr[],int n,int k){
    long double low=0,high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }
    while(high-low>1e-6){
        long double mid=(low+high)/2.0;
        int cnt_gs=count_gasstation(arr,n,mid);
        if(cnt_gs>k) low=mid;
        else high=mid;
    }
    return high;
}


// 5. Median of 2 sorted arrays  
//brute force-
//TC==>o(n+m)   SC==>o(n+m)
double median(int arr1[],int arr2[],int n,int m){
    int left=0,right=0;
    vector<int>arr3;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right])arr3.push_back(arr1[left++]);
        else arr3.push_back(arr2[right++]);
    }
    while(left<n){
        arr3.push_back(arr1[left++]);
    }
    while(right<m){
        arr3.push_back(arr2[right++]);
    }
    int size=arr3.size();
    if(size%2==0){
        return ((arr3[size/2]+arr3[(size/2)-1])/2.0);
    }
    else return (arr3[size/2.0]);
}

//better-
//TC==>o(n+m)   SC==>o(1)
double median1(int arr1[],int arr2[],int n,int m){
    int left=0,right=0;
    int size=n+m;
    int index2=size/2;
   int index1=index2-1;
     int cnt=0;
     int el1=-1,el2=-1;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
           if(cnt==index1)el1=arr1[left];
           if(cnt==index2)el2=arr1[left];
           left++,cnt++;
        }
        else {
            if(cnt==index1)el1=arr2[right];
           if(cnt==index2)el2=arr2[right];
           right++,cnt++;
        }
    }
    while(left<n){
         if(cnt==index1)el1=arr1[left];
           if(cnt==index2)el2=arr1[left];
           left++,cnt++;
    }
    while (right<m)
    {
         if(cnt==index1)el1=arr2[right];
           if(cnt==index2)el2=arr2[right];
           right++,cnt++;
    }
    if(size%2==1)return el2;
    else{
        return (el1+el2)/2.0;
    }
    
}

// optimal-
// TC==>o(log2(min(n,m)))   SC==>o(1)
double median_bs(int arr1[],int arr2[],int n,int m){
    if(n>m)return median_bs(arr2,arr1,m,n);
    int length=(n+m+1)/2;
   int low=0,high=n;
   int size=n+m;
   while(low<=high){
     int l1=INT_MIN,l2=INT_MIN;
    int r1=INT_MAX,r2=INT_MAX;
    int mid1=(low+high)/2;
    int mid2=length-mid1;
    if(mid1<n)r1=arr1[mid1];
    if(mid2<m)r2=arr2[mid2];
    if(mid1-1>=0)l1=arr1[mid1-1];
    if(mid2-1>=0)l2=arr2[mid2-1];
    if(l1<=r2 && l2<=r1){
        if(size%2==1)return max(l1,l2);
        else{
            int e1=max(l1,l2);
            int e2=min(r1,r2);
            return ((e1+e2) /2.0);
        }
    }
    else if(l1>r2){
        high=mid1-1;
    }
    else low=mid1+1;
   }
}


// 6. Kth element of 2 sorted arrays
double kth_ele(int arr1[],int arr2[],int n,int m,int k){
    if(n>m)return kth_ele(arr2,arr1,m,n,k);
    int length=k;
   int low=max(0,k-m),high=min(k,n);
   int size=n+m;
   while(low<=high){
     int l1=INT_MIN,l2=INT_MIN;
    int r1=INT_MAX,r2=INT_MAX;
    int mid1=(low+high)/2;
    int mid2=length-mid1;
    if(mid1<n)r1=arr1[mid1];
    if(mid2<m)r2=arr2[mid2];
    if(mid1-1>=0)l1=arr1[mid1-1];
    if(mid2-1>=0)l2=arr2[mid2-1];
    if(l1<=r2 && l2<=r1){
        return max(l1,l2);
    }
    else if(l1>r2){
        high=mid1-1;
    }
    else low=mid1+1;
   }
}


int main(){
   int stalls[]={0,3,4,7,10,9};
   cout<<aggresive_cows(stalls,6,4);
   int pages[]={25,46,28,49,24};
   cout<<book_allocate(pages,5,4);
      int gs_dis[]={1,2,3,4,5,6,7};
      cout<<max_gs_distance2(gs_dis,7,6);
    int arr1[]={1,2},arr2[]={3,4};
    cout<<median_bs(arr1,arr2,2,2);
    int find1[]={2,3,6,7,9,11},find2[]={1,4,8,10,12}; 
    cout<<kth_ele(find1,find2,6,5,7);;
    return 0;
}