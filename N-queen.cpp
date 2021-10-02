#include<iostream>
#include<bits/stdc++.h>
using namespace std;



bool isSafe(int row,int col,vector <string> board,int n){
  
   int pRow = row;
   int pCol = col;
    
   while(row >= 0 and col >=0){
   	  if(board[row][col]=='Q') return false;
   	  row--;
   	  col--;
   	}
   row = pRow;
   col = pCol;

   while(col >= 0){
   	if(board[row][col]=='Q') return false;
   	col--;
   }
   col = pCol;
   row = pRow;
  while(row < n  and col >=0){
   	  if(board[row][col]=='Q') return false;
   	  row++;
   	  col--;
   	}

  return true;
}

void solve(int col,vector<vector<string>> &ans,vector <string> &board, int n){
	if(n==col){
		ans.push_back(board);
		return;
	}

	for (int row =0;row<n ;row++){
        if(isSafe(row,col,board,n)){
        	board[row][col]='Q';
        	solve(col+1,ans,board,n);
        	board[row][col]='.';
        }
	}
}


vector<vector <string>> solveNQueens(int n){
	vector <vector<string>> ans;
	vector <string> board(n);
	string s(n,'.');
	for(int i =0;i<n;i++){
		board[i]=s;
	}
	solve(0,ans,board,n);
	return ans;
}
int main(){
	int n;
	cin >> n;
	
	vector <vector<string>> res=solveNQueens(n);

	for (auto it: res){
		for (auto it1 : it){
			cout << it1 <<" ";
		}
		cout << endl;
	}
	return 1;
}
