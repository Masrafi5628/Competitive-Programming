#include <bits/stdc++.h>

using namespace std;

int ara2[511], ara1[511];
int dp[511];
int pre[511];

stack<int>stk;

void lcis(int m, int n)
{
	for(int i=0; i<m; i++){
		int cur = 0, last = -1;
		for(int j=0; j<n; j++){
			if(ara1[i] == ara2[j] && cur+1 > dp[j]){
				dp[j] = cur+1;
				pre[j] = last;
			}
			if(ara1[i] > ara2[j] && dp[j]>cur){
				cur = dp[j];
				last = j;
			}
		}
	}
	int len=0, idx;
	for(int i=0; i<n; i++){
		if(dp[i] > len){
			len = dp[i];
			idx = i;
		}
	}

	if(len>0){
		while(idx != -1){
			stk.push(ara2[idx]);
			idx = pre[idx];
		}
		//cout<< 'm';
		cout<<stk.size()<<endl;

		while(!stk.empty()){
			cout<<stk.top()<< ' ';
			stk.pop();
		}
	}else {
		cout<<0<<endl;
	}
}

int main()
{
	int n, m;

	cin>>m;
	for(int i=0; i<m; i++)
		cin>>ara1[i];

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>ara2[i];

	lcis(m, n);

	return 0;
}