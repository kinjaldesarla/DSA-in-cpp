#include<bits/stdc++.h>
using namespace std;

// 1. Pow(x, n)  TC==>o(log2n)  SC==>o(log2n)
double fastpow(double x,long long n){
    if(n==0) return 1;
    double half=fastpow(x,n/2);
    if(n%2==1){
        return half*half*x;
    }else{
        return half*half;
    }
   }    
double myPow(double x, int n) {
      long long N=n;
      if(N<0){
        x=1/x;
        N=-N;
      }
      return fastpow(x,N);
    }

// 2. Count Good numbers  TC==>o(log2n)  SC==>o(log2n)
 long long fastPow(long long x, long long n) {
        if (n == 0) return 1;
        int MOD = 1e9 + 7;
        long long half = fastPow(x, n / 2);
        long long res = (half * half) % MOD;

        if (n % 2 == 1)
            res = (res * x) % MOD;

        return res;
    }
int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        int MOD = 1e9 + 7;
        long long res =(fastPow(5, even) * fastPow(4, odd)) % MOD;

        return res;
    }

// 3. Recursive Implementation of atoi()   TC==>o(n)  SC==>o(n)
int helper(string s,int i,long long num,int sign){
    if(i>=s.size()|| !isdigit(s[i])){
        return (int) (sign*num); 
    }
    num=num*10+(s[i]-'0');
    if (sign * num <= INT_MIN) return INT_MIN;
    if (sign * num >= INT_MAX) return INT_MAX;
    return helper(s,i+1,num,sign);
  }
int myAtoi(string s) {
      int i=0;
     while(i<s.size()&& s[i]==' ')i++;
      if(i==s.size())return 0;
      int sign=1;
     if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
     return helper(s,i,0,sign);
    }    
    
 int main(){
    return 0;
}