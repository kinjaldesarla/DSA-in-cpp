#include <bits/stdc++.h>
using namespace std;

// patterns 

void pattern1(int n) {
    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            cout << "*";
        }
        cout << endl;
    }  
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout <<j <<" ";
        }
        cout << endl;
    }
}

void pattern5(int n){
    for(int i=n; i>0;i--){
     for(int j=0;j<i;j++){
        cout << "* ";
     }
     cout << endl;
    }
}

void pattern6(int n){
    for(int i=n; i>0;i--){
     for(int j=1;j<=i;j++){
        cout <<j << " ";
     }
     cout << endl;
    }
}

void pyramid(int n){
    for(int i=0;i<n;i++){
     for(int b=0;b<n-i-1;b++){
        cout << " ";
     }
     for(int j=0;j<i+1;j++){
        cout << "*";
     }
     for(int k=0;k<i;k++){
        cout << "*";
     }
       cout << endl;
    }
}

void invertedPyramid(int n){
    for(int i=0;i<n;i++){
        for(int b=0;b<i;b++){
            cout <<" ";
        }
        for(int j=0 ; j<n-i;j++){
            cout <<"*";
        }
        for(int k=0 ;k<n-i-1;k++){
            cout <<"*";
        }
     cout << endl;
    }
}

void invertedPyramid2(int n){
    for(int i=0;i<n;i++){
        for(int b=0;b<i;b++){
            cout <<" ";
        }
        for(int j=0 ; j<(2*n -(2*i+1));j++){
            cout <<"*";
        }
     cout << endl;
    }
}

void fullPyramid(int n){
      for(int i=0;i<n;i++){
     for(int b=0;b<n-i-1;b++){
        cout << " ";
     }
     for(int j=0;j<i+1;j++){
        cout << "*";
     }
     for(int k=0;k<i;k++){
        cout << "*";
     }
       cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int b=0;b<i;b++){
            cout <<" ";
        }
        for(int j=0 ; j<(2*n -(2*i+1));j++){
            cout <<"*";
        }
     cout << endl;
    }
}

void triangle(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i=0;i<n-1;i++){
         for(int j=n-1-i;j>0;j--){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n){
      int start=1;
    for(int i=0;i<n;i++){
      if(i%2==0) start=1;
        else start=0;
        for(int j=0;j<=i;j++){
            cout << start;
            start=1-start;
        }
        cout<< endl;
    }
}

void crown(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << j+1;
        }
        for(int b=0;b<2*(n-i-1);b++){
            cout << " ";
        }
        for(int k=i+1;k>0;k--){
            cout << k;
        }
        cout << endl;
    }
}

void pattern13(int n){
    int num=1;
    for(int i=0;i<n;i++){
     for(int j=0;j<=i;j++){
        cout << num << " " ;
        num++;
     }
     cout << endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
         char ch ='A';
     for(int j=0;j<=i;j++){
        cout << ch<< " " ;
        ch++;
     }
     cout << endl;
    }
}

void pattern15(int n){
    for(int i=0;i<n;i++){
         char ch ='A';
     for(int j=n-i;j>0;j--){
        cout << ch<< " " ;
        ch++;
     }
     cout << endl;
    }
}

void pattern16(int n){
      char ch ='A';
    for(int i=0;i<n;i++){  
     for(int j=n-i;j>0;j--){
        cout << ch<< " " ;
     }
      ch++;
     cout << endl;
    }
}

void charPyramid(int n){
    for(int i=0;i<n;i++){
     for(int b=0;b<n-i-1;b++){
        cout << " ";
     }
   char ch='A';
     for(int j=1;j<=(2*i + 1);j++){
         cout << ch;
       if(j <= (2*i+1)/2) ch++;
       else ch--;
     }
       cout << endl;
    }
}

void pattern18(int n){

    for(int i=0;i<n;i++){
      char startChar = 'A' + (n - i - 1);
        for (char ch = startChar; ch <= 'A' + n - 1; ch++) {
            cout << ch;
        }
       cout << endl;
    }
}

void rectangle(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout << "*";
        }
        for(int b=0;b<2*i;b++){
            cout<<" ";
        }
        for(int k=n-i;k>0;k--){
             cout << "*";
        }
        cout << endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        for(int b=0;b<2*(n-i-1);b++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
             cout << "*";
        }
        cout << endl;
    }

    
}

void butterfly(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<< "*";
        }
         for(int b=0;b<2*(n-i-1);b++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
             cout << "*";
        }
        cout << endl;
    }
     for(int i=0;i<n-1;i++){
        for(int j=n-i-1;j>0;j--){
            cout << "*";
        }
        for(int b=0;b<2*(i+1);b++){
            cout<<" ";
        }
        for(int k=n-i-1;k>0;k--){
             cout << "*";
        }
        cout << endl;
    }
}

void square(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1) cout << "*";
            else cout <<" ";
        }
        cout << endl;
    }
}

void pattern22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int bottom=(2*n-2)-i;
            int left=j;
            int right=(2*n-2)-j;
            cout<<n-min(min(left,right),min(top,bottom));
        }
        cout<<endl;
    }
}

int main (){
    
    int n;
    cin >> n;
   pattern22(n);
    
    return 0;
}