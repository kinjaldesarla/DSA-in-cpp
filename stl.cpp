#include <bits/stdc++.h>
using namespace std;


int main(){

    // standard template library concepts
    // container:

// pairs  ==> holds the value in pairs
     pair<int,int> p={1,2};  // two pairs of integer
     pair<int ,pair<int,int>>p1={1,{1,2}};  // one integer and one pair of integer
     pair<int,int> arr[]={{1,2},{1,3}};
     // accessing
     cout<< p.first<<" "<<p.second<<endl;
     cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
     cout<<arr[1].second<<endl;



     

// vectors

// similar to array but dynamic in size
     vector<int> v(2,100) ;
     vector<int>v1={10,20,30,40,50};
     
// operations
     v.push_back(10);
     v.emplace_back(20);
     cout<<v[1];
     //iterators
     vector<int>::iterator it=v.end();
     // auto it =v.begin();
      it--;
     cout<<*(it);
     it--;
     cout<<*(it);     

    // v.begin() points to addrees of first element
    // v.end()  points to next address of last max_element
    // v.rbegin() point to first element address but it is reverse
    // v.rend()  point to last element address but it is reverse


    for( vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";

    }
    for( auto it : v){
        cout<<it;
    }
    v.erase(v.begin());
    v.insert(v.begin()+1,2,5);
    v.pop_back(); // {10,20}  => {10}



// list
list <int> ls;
ls.push_back(20); // {20}
ls.emplace_back(30); //{20,30}
ls.push_front(40);//{40,20,30}
ls.emplace_front(50);//{50,40,20,30}

for(auto it:ls){
    cout<<it<<endl;
}
// all other fuction are similar to vector



//DeQueue 
deque<int>dq;
dq.push_back(20); // {20}
dq.emplace_back(30); //{20,30}
dq.push_front(40);//{40,20,30}
dq.emplace_front(50);//{50,40,20,30}

dq.pop_back(); // {50,40,20}
dq.pop_front(); //{40,20}

for(auto it:dq){
    cout<<it<<endl;
}



// stack 
stack <int> s;
s.push(20);
s.push(30);
cout<<s.top();
s.pop();//{20}

// queue 
queue<int> q;
q.push(11);
q.emplace(12);
cout<<q.front();
cout<<q.back();


// priority queue 
priority_queue <int>pq;
pq.push(11);
pq.emplace(22);
pq.push(33);
cout<<pq.empty();
cout<<pq.top();


// priority_queue<int,vector<int>,greater<int>>pq ; // for max heap 



// set ==>  ordered and unique
set<int>st;
st.emplace(1);
st.insert(1);
st.insert(2),
st.insert(3);
 cout << *(st.find(2));

 st.erase(st.find(1),st.find(3));// last one is not included

st.emplace(1);
st.insert(1);
st.insert(2),
st.insert(3);
cout<<*(st.lower_bound(2));
cout<<*(st.upper_bound(3));



// multiset are same as set but here we can store duplicates
//unorderedset ==> unique and unordered


// map ==> stores {key,value} keys are unique and sorted
map<int,int>m;
m[1]=1;
m.insert({2,2});
cout<<m[1];

// multimaps can have duplicate keys
// unorderedmaps ==> unique key but not sorted

    return 0;
}

