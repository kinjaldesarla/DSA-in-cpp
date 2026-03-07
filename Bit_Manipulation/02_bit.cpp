#include<bits/stdc++.h>
using namespace std;

// 1. Single Number - II 
//brute force- using map and storring count     TC==>o(nlogM)+o(M)  SC==>o(m)
// bitwise - TC==>o(n*32) SC==>o(1)
int singleNum2_bitwise(vector<int>arr){
    int ans=0;
    for(int bitIdx=0;bitIdx<32;bitIdx++){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]&(1<<bitIdx))cnt++;
        }
        if(cnt%3==1){
            ans=ans|(1<<bitIdx);
        }
    }
    return ans;
}
// another approach-   TC==>o(nlogn)+o(n/3)  SC==>o(1)
int singleNum2(vector<int>arr){
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i=i+3){
        if(arr[i]!=arr[i-1])return arr[i-1];
    }
    return arr[arr.size()-1]; // maybe last element is single element
}

// 2. Single Number - III
//brute force- using map and storring count     TC==>o(nlogM)+o(M)  SC==>o(m)
// bitwise -  concpet of buckets    TC==>o(2n) SC==>o(1)
vector<int> singleNum3(vector<int>arr){
    long xorr=0;
    for(int i=0;i<arr.size();i++){
        xorr=xorr^arr[i];
    }
    int rightmost=(xorr&(xorr-1))^xorr;
    int b1=0,b2=0;
    for(int i=0;i<arr.size();i++){
        if(rightmost&arr[i])b1=b1^arr[i];
        else b2=b2^arr[i];
    }
    return {b1,b2};
}



//            ADVANCED MATHS


// 1. Print Prime Factors of a Number
// brute force- find the all factors then check for prime  TC==>o(sqrt(n)*2*sqrt(n))
// another method-
// but these method is giving o(n) for large numbers that are prime [37]
void primeFactors(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cout<<i<<" "; // prime factor
            while(n%i==0){
                n=n/i;
            }
        }
    }
}
// so we can run the loop till sqrt(n)  TC==>o(sqrt(n)*logn)
void primeFactors1(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" "; // prime factor
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1)cout<<n;
}


// 2. Divisors of a Number   TC==>o(sqrt(n))  SC==>o(1)
void divisors(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n/i!=i)cout<<(n/i)<<" ";
        }
    }
}

//        Sieve of Eratosthenes - 
// 3. Given N print all the prime numbers till N
// brute force- TC==>o(n*sqrt(n))
bool isprime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
             if(n/i!=i)cnt++;
            };
    }
    if(cnt==2)return true;
    return false;
}
void printAllPrime(int n){
    for(int i=2;i<=n;i++){
        if(isprime(i))cout<<i<<' ';
    }
}
// Sieve of Eratosthenes - TC==>o(n)+o(n*log(logn))+o(n)  SC==>o(n)
void printAllPrime1(int n){
    int prime[n+1];
    for(int i=2;i<=n;i++){
        prime[i]=1; // mark them 1
    }
    // pre calculated- o(n*log(logn))
    for(int i=2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==1)cout<<i<<' ';
    }
}

// 4. Count primes in range L to R
 int countPrimeNum(int n){
    int cnt=0;
     int prime[n+1];
    for(int i=2;i<=n;i++){
        prime[i]=1; // mark them 1
    }
    // pre calculated- o(n*log(logn))
    for(int i=2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<n;i++){
            if(prime[i]==1)cnt++;
        }
        return cnt;
 }
 int countPrimes(int n) {
    return countPrimeNum(n);
}

int main(){
    vector<int>arr={2,2,2,5,5,5,6};
    cout<<singleNum2(arr);
     vector<int>arr1={2,6,3,2,4,4,8,3};
    for(auto it:singleNum3(arr1))cout<<it<<' ';
    primeFactors1(780);
    divisors(36);
    printAllPrime1(10);
    return 0;
}