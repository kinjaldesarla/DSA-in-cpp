#include<bits/stdc++.h>
using namespace std;

// for extracting numbers ==> lastdigit=n%10 and n=n/10

//count the digit in given number
int count_digit(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
 
}

// reverse the given number
int reverse(int n){
    int reverse=0;
    while(n>0){
        int lastdigit=n%10;
        reverse=(reverse*10)+lastdigit;
        n=n/10;
    }
    return reverse;
 
}

//palindrome  131 ==> reverse is same i.e 131
void palindrome(int n){
    int dup=n;
     int reverse=0;
    while(n>0){
        int lastdigit=n%10;
        reverse=(reverse*10)+lastdigit;
        n=n/10;
    }
    if(dup==reverse)cout<<"it is a palindrome";
    else cout<<"it is not a palindrome";
 
}

// armstrong number ==> 371=> 3^3+7^3+1^3 = 371
void armstrong(int n){
      int dup=n;
   int sum=0;
    while(n>0){
        int lastdigit=n%10;
        sum=sum+(lastdigit*lastdigit*lastdigit);
        n=n/10;
    }
    if(dup==sum)cout<<"it is a armstrong";
    else cout<<"it is not a armstrong";
 
}

// print all divisor
// 1. from 1 to n
void divisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<' ';
    }
}
// 2. from 1 to sqrt n
void divisor2(int n){
    vector<int>v;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
             v.push_back(i);
             if(n/i!=i)v.push_back(n/i);
            };
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    }
}

//prime numbers
void prime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
             if(n/i!=i)cnt++;
            };
    }
    if(cnt==2)cout<<"prime number";
    else cout<<"not a prime number";
}

//GCD 15=> factors 1,3,5,15  5==> factors 1,5  then gcd(5,15)=5
int gcd(int n1,int n2){
    for(int i=min(n1,n2);i>=1;i++){
        if(n1%i==0 && n2%i==0){
            return i;
            break;
        }
    }
}
// Euclidean algo for gcd says ==> gcd(a,b) where a>b == gcd(a-b,b)
int gcd2(int n1,int n2){
    while(n1>0 && n2>0){
        if(n1>n2) n1=n1%n2;
        else n2= n2%n1;
    }
    if(n1==0)return n2;
    else return n1;
}
int main(){
   int n1,n2;
   cin>>n1>>n2;
cout << gcd2(n1,n2);
    return 0;
}

