#include<bits/stdc++.h>
using namespace std;

//1.Palindrome partitioning
bool ispalind(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])return false;
    }
    return true;
}
void palind_recu(string s,int index,vector<string> &path,vector<vector<string>> &ans){
    if(index==s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalind(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            palind_recu(s,i+1,path,ans);
            path.pop_back();
        }
    }
}
void palind(string s){
    vector<string> path;
    vector<vector<string>>ans;
    palind_recu(s,0,path,ans);
    for(auto it:ans){
        for(auto i:it) cout<<i<<" ";
        cout<<endl;
    }
}

// 2. Word Search   TC==>o(n*m*4L)   SC==>o(L)   L is length of word
bool dfs_wordSearch(vector<vector<char>> &board,string word,int i,int j,int index){
    if(index==word.size()){
        return true;
    }
    if(i<0||j<0||i>= board.size() || j >= board[0].size()||board[i][j]!=word[index])return false;

    char temp=board[i][j];
    //mark it visited
    board[i][j]='#';
    // check for up,down,left,right
    bool found=dfs_wordSearch(board, word, i + 1, j, index + 1) ||
                     dfs_wordSearch(board, word, i - 1, j, index + 1) ||
                     dfs_wordSearch(board, word, i, j + 1, index + 1) ||
                     dfs_wordSearch(board, word, i, j - 1, index + 1);
    
      // Restore the character (backtracking)
        board[i][j] = temp;
        
     return found;   
}
bool word_search(vector<vector<char>> &board,string word){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(dfs_wordSearch(board,word,i,j,0)){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

int main(){
    // palind("aabb");
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
   cout<< word_search(board,"ABCB");
    return 0;
}