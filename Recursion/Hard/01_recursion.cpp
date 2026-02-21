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

// 3. N Queen
void nQueen_recu(int col,int n, vector<vector<string>> &ans,vector<string> &board,vector<int> &leftRow,vector<int> &upperDaigonal,vector<int> &lowerDaigonal){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(leftRow[i]==0 && upperDaigonal[(n-1)+(col-i)]==0 && lowerDaigonal[(i+col)]==0){
            board[i][col]='Q';
            leftRow[i]=1;
            upperDaigonal[(n-1)+(col-i)]=1;
            lowerDaigonal[i+col]=1;
            nQueen_recu(col+1,n,ans,board,leftRow,upperDaigonal,lowerDaigonal);
            board[i][col]='.';
             leftRow[i]=0;
            upperDaigonal[(n-1)+(col-i)]=0;
            lowerDaigonal[i+col]=0;
        }
    }
}
vector<vector<string>> nQueen(int n){
     vector<vector<string>> ans;
    vector<string> board;
    string s=".";
    for(int i=0;i<4;i++){
      board.push_back(s);
    }
    // hashing
    vector<int> leftRow(n,0), upperDaigonal(2*n-1,0), lowerDaigonal(2*n-1,0);
    nQueen_recu(0,n,ans,board,leftRow,upperDaigonal,lowerDaigonal);
    return ans;
}

// 4. Rat in a Maze  TC==>o(4^(n*m))  SC==>o(n*m)
void ratRecu(int i,int j,int n,vector<vector<int>> &maze,string path,vector<string> &ans,vector<vector<int>> &vis){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
// instead of writing four if statement 
    // // downward
    // if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1){
    //     vis[i][j]=1;
    //     ratRecu(i+1,j,n,maze,path+"D",ans,vis);
    //     vis[i][j]=0;
    // }
    // // left
    // if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1){
    //     vis[i][j]=1;
    //     ratRecu(i,j-1,n,maze,path+"L",ans,vis);
    //     vis[i][j]=0;
    // }
    // // right
    // if(j+1<n && !vis[i][j+1] && maze[i][j+1]==1){
    //     vis[i][j]=1;
    //     ratRecu(i,j+1,n,maze,path+"R",ans,vis);
    //     vis[i][j]=0;
    // }
    // // upward
    // if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1){
    //     vis[i][j]=1;
    //     ratRecu(i-1,j,n,maze,path+"U",ans,vis);
    //     vis[i][j]=0;
    // }

// better one is 
    string dir="DLRU";
    int di[]={+1,0,0,-1};
    int dj[]={0,-1,+1,0};
    for(int ind=0;ind<4;ind++){
        int nexti=i+di[ind];
        int nextj=j+dj[ind];
        if(nexti<n && nextj<n && nexti>=0 && nextj>=0 && !vis[nexti][nextj] && maze[nexti][nextj]==1){
            vis[i][j]=1;
            ratRecu(nexti,nextj,n,maze,path+dir[ind],ans,vis);
            vis[i][j]=0;
        }
    }

}
void rat_in_maze(vector<vector<int>>maze,int n){
    vector<string>ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
   if(maze[0][0]==1) ratRecu(0,0,n,maze,"",ans,vis);
   for(auto it:ans)cout<<it<<" ";
}

int main(){
    // palind("aabb");
//     vector<vector<char>> board = {
//         {'A','B','C','E'},
//         {'S','F','C','S'},
//         {'A','D','E','E'}
//     };
//    cout<< word_search(board,"ABCB");
      vector<vector<int>> maze = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
      rat_in_maze(maze,4);
    return 0;
}