#include<bits/stdc++.h>
using namespace std;

// 1. convert decimal to binary
string convertDecToBinary(int num){
    string binary="";
    while(num>1){
        binary+=num%2 ==0?'0':'1';
        num=num/2;
    }
    if(num==1)binary+='1';
    reverse(binary.begin(),binary.end());
    return binary;
}
// 2. convert binary to decimal
int convertBinaryToDec(string binary){
    int res=0,pow=1;
    for(int i=binary.size()-1;i>=0;i--){
        if(binary[i]=='1'){
            res+=pow;
        }
        pow=pow*2;
    }
    return res;
}
// 3. Check if the i-th bit is Set or Not
bool checkIBit(int num,int i){
    return (num & (1<<i) )==0?false:true;
}
// 4.Check if a Number is Odd or Not
bool checkOdd(int num){
    return (num&1)==0?false:true;
}
// 5.Check if a Number is Power of 2 or Not  [If power of 2 then only one bit is set]
bool checkPower2(int num){
    return (num & (num-1))==0?true:false;
}
// 6.Count the Number of Set Bits   TC==>o(no. of set bits)  SC==?o(1)
int countSetBit(int num){
    int cnt=0;
    while(num!=0){
        num=num&(num-1);
        cnt++;
    }
    return cnt;
}
// 7. Swap Two Numbers
void swaping(int a,int b){
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}
//8. Divide two numbers without multiplication and division
    int divide(int dividend, int divisor) {
       if(dividend==divisor)return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
       bool sign=true;
       if(dividend>=0&&divisor<0)sign=false;
       if(dividend<0&&divisor>0)sign=false;
       long n=dividend;
       long d=divisor;
       n=abs(n);
       d=abs(d);
       long quotient=0;
       while(n>=d){
       int cnt=0;
       while(n>=(d<<(cnt+1))){
        cnt++;
       }
       quotient+=1<<cnt;
       n=n-(d<<cnt);
       }
       if(quotient==(1<<31)&& sign==true)return INT_MAX;
       if(quotient==(1<<31)&& sign==false)return INT_MIN;
       return sign?quotient:(-1*quotient);
    }

// 9. Minimum Bit Flips to Convert Number  Tc==>o(no.of set bits) SC==>o(1)
int minBitFlips(int start, int goal) {
    int ans=start^goal;
    int cnt=0;
    while(ans!=0){
     ans=ans&(ans-1);
     cnt++;
    }
    return cnt;
}
// 10. Single Number I   TC==>o(n)  SC==>o(1)
 int singleNumber(vector<int>& nums) {
        int xor1=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xor1=xor1^nums[i];
        }
        return xor1;
    }  
// 11. Power Set Bit Manipulation  TC==>o(2^n * n)   SC==>o(2^n * n)
 vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int>list;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))list.push_back(nums[j]);
            }
            ans.push_back(list);
        }
        return ans;
    }  
// 12. XOR of numbers in a given range
// for (1 -> n)   TC==>o(1)  Sc==>o(1)
int xoring(int n){
    if(n%4==1)return 1;
    else if(n%4==2)return n+1;
    else if(n%4==3)return 0;
    else return n;
}
// for (n1 -> n2)  TC==>o(1)  SC==>o(1)
int xoring_range(int n1,int n2){
    return xoring(n1)^xoring(n2);
}       
int main(){
    cout<< convertDecToBinary(13)<<endl;
    cout<< convertBinaryToDec("1101")<<endl;
    cout<<checkIBit(13,1);
    cout<<checkOdd(13);
    cout<<checkPower2(33);
    cout<<countSetBit(13);
    swaping(12,15);
    return 0;
}