#include<bits/stdc++.h>
using namespace std;

//selection sort ==> select min compares with first element of unstored part and swap
// TC ==> o(n^2)      n+(n-1)+(n-2)+...+2
void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]) min=j;
        }
        // swaping
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}


// bubble sort ==> push the max element at last during each iteration through adjacent swaping
// TC ==> worst, average  o(n^2)      n+(n-1)+(n-2)+...+2
// TC ==> best  o(n)  inner loop will run one times and no swaping would be done beacuse element are stored
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        int didswap =0;  // optimization
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didswap=1;
            }
        }
        if(didswap==0)break;
    }
}


// insertion sort ==> take the element and place it in correct order by doing right shift of other elment
// TC ==> worst, average  o(n^2)     
// TC ==> best  o(n)  
void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    insertion_sort(arr,n);
    for(auto it:arr)cout<<it<<" ";

    return 0;
}