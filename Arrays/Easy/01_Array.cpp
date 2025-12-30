#include <bits/stdc++.h>
using namespace std;

// 1. largest element in array
// brute force- sort the array and last element is largest   TC-o(nlogn)
// optimal      TC-o(n)
int largest(int arr[],int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest)largest=arr[i];
    }
    return largest;
}

// 2. second largest element
// brute force- sort and then check for the second largest in array from last second element that whether it is different from largest one
// Tc-o(nlogn + n)
// better - TC-o(2n) 
int second_largest1(int arr[],int n){
     int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest)largest=arr[i];
    }
    int slargest =-1;
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest)slargest=arr[i];
    }
    return slargest;
}
//optimal-o(n)
int second_largest2(int arr[],int n){
    int largest=arr[0];
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){slargest=largest;largest=arr[i];}
        else if(arr[i]<largest && arr[i]>slargest)slargest=arr[i];
}
return slargest;
}

// 3. second smallest 
int second_smallest(int arr[],int n){
    int smallest=arr[0];
    int ssmalest=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            ssmalest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]!=smallest && arr[i]<ssmalest)ssmalest=arr[i];
    }
    return ssmalest;
}

// 4. check if the array is sorted  TC- o(n)
bool check_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else return false;
    }
    return true;
}

// 5. remove duplicates from array
// brute force- store element of array in set and then place unique element to array 
// TC-o(nlogn + n)      SC-o(n)
//optimal -  TC-o(n);
void remove_dup(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    remove_dup(arr,n);
     for(auto it :arr)cout<<it<<" ";
    return 0;
}