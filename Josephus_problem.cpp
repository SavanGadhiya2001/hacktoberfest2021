// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Josephus(vector<int> &v, int k, int index, int &ans){
	if(v.size() == 1){
		ans = v[0];
		return;
	}

	index = (index + k) % v.size();
	v.erase(v.begin() + index);

	Josephus(v, k, index, ans);
}

int main(){
	int n = 40, k = 7;
	vector<int> v;

	for(int i=1; i<=n; i++)
		v.push_back(i);

	k--;
	int ans = -1, index = 0;

	Josephus(v, k, index, ans);

	cout<<ans;
}