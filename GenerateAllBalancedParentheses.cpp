#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void GenerateAllBalencedParentheses(int open, int close, string s){
	if(open==0 && close==0){
		cout<<s<<endl;
		return;
	}

	if(open!=0){
		GenerateAllBalencedParentheses(open-1, close, s+'(');
	}

	if(close > open && close!=0){
		GenerateAllBalencedParentheses(open, close-1, s+')');
	}
}

int main(){
	int n=3;

	GenerateAllBalencedParentheses(n, n, "");
}