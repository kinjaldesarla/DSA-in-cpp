#include<bits/stdc++.h>
using namespace std;

// 1. Solve Sudoku    TC==>o(9^(n*n))  
   bool isvalid(int row,int col,char c,vector<vector<char>>& board){
     for(int i=0;i<9;i++){
        if(board[row][i]==c)return false;
        if(board[i][col]==c)return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
     }
     return true;
   }
   bool sudokuRecu(vector<vector<char>>& board) {
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(i,j,c,board)){
                        board[i][j]=c;
                        if(sudokuRecu(board)==true)return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
      }
      return true;
   }   
    void solveSudoku(vector<vector<char>>& board) {
        sudokuRecu(board);
    }


//2. Expression Add Operators   TC==>o(4^n)   SC==>o(n)
  void addOperators_rec(string num,int target,int index,long long current_value, long long last_operand,string expression,vector<string> &result){
        if(index==num.size()){
            if(current_value==target){
           result.push_back(expression);
            return;
            }
        }
        for(int i=index;i<num.size();i++){
            //Skip leading zeros in numbers
            if(i>index && num[index]=='0')return;
            string current_num = num.substr(index, i - index + 1); 
            long long current_num_val = stoll(current_num);
                  // If we are at the first number, just start the expression
            if (index == 0) {
                addOperators_rec(num, target, i + 1, current_num_val, current_num_val, current_num, result);
            } else {
                // Add the current number with '+'
              addOperators_rec(num, target, i + 1, current_value + current_num_val, current_num_val, expression + "+" + current_num, result);
                
                // Add the current number with '-'
                addOperators_rec(num, target, i + 1, current_value - current_num_val, -current_num_val, expression + "-" + current_num, result);
                
                // Add the current number with '*'
               addOperators_rec(num, target, i + 1, current_value - last_operand + last_operand * current_num_val, last_operand * current_num_val, expression + "*" + current_num, result);
            }
        }
    }    

    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string s;
        addOperators_rec(num,target,0,0,0,"",ans);
        return ans;
    } 
    // 3. Word Break (required DP as by normal rec TLE)
    bool  wordBreakRec(string s, vector<string>& wordDict,int index){
        if(index==s.size()){
            return true;
        }
        for(int i=0;i<wordDict.size();i++){
            int wordSize=wordDict[i].size();
            string demo=s.substr(index,wordSize);
            if(wordDict[i]==demo){
               if(wordBreakRec(s,wordDict,index+wordSize))return true;
            }
        }
        return false;
     }

     bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakRec(s, wordDict,0);
    }
    
int main(){
     string s = "aaaaaaa";
     vector<string> wordDict = {"a","aa","aaa"};
     cout<<wordBreak(s,wordDict);
    return 0;
}