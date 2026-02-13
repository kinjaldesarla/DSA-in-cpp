
// recursion ==> when function calls itself until specified condition met

#include<bits/stdc++.h>
using namespace std;

// print name n times
void name(int i,int n){
    if(i>n)return;
    cout << "kinjal "<< endl;
    name(i+1,n);
}

// print from 1 to N
void print(int i,int n){
    if(i>n)return;
    cout<<i<<endl;
    print(i+1,n);
}


// print from N to 1
void reverse(int i,int n){
    if(i<1)return;
    cout<<i<<endl;
    reverse(i-1,n);
}

// print 1 to n but not using i++ doing (backtrack)
void print1(int i,int n){
    if(i<1)return;
    print1(i-1,n);
    cout<<i<<endl;
}

//print from N to 1 but not using i-- doing (backtrack)
void reverse1(int i, int n){
    if(i>n)return;
    reverse1(i+1,n);
    cout<<i<<endl;
}

// sum of forst N numbers 
//1. parameterized
void sums(int i,int sum){
 if(i<1){
    cout<<sum;
    return;
 };
 sums(i-1,sum+i);
}

// 2. functional 
int sum1(int n){
    if(n==1)return 1;
    return n+sum1(n-1);
}

// factorial
int fact(int n){
    if(n==1)return 1;
    return n*fact(n-1);
}
int main(){
cout<<fact(3);
    return 0;
}
