#include <bits/stdc++.h>

using namespace std;

// prb-1:Given sorted array a, and x
// find i and j such that a[i]+a[j] == x;
// try for triplet

void solve_prb1(int *ara, int n, int x )
{
	int lo=0, hi=n-1;
	while(lo<hi){
		if(ara[lo]+ara[hi] == x) {
			printf("i %d j %d\n", lo, hi);
			return;
		}else if(ara[lo]+ara[hi] > x){
			hi--;
		}else {
			lo++;
		}
	}
	printf("No such pair\n");

}

// Given two sorted arrays A and B, 
//each having length N and M respectively. 
//Form a new sorted merged array 
//having values of both the arrays in sorted format.
void solve_prb2(int *a, int *b, int n, int m)
{
	int la = 0, lb=0, idx=0;
	
	int c[n+m+2];

	while(la<n || lb<m){
		if(la<n && lb<m){
			if(a[la]<b[lb]){
				c[idx++] = a[la];
				la++;
			}else {
				c[idx++] = b[lb];
				lb++;
			}
		} else if(la<n){
			c[idx++] = a[la];
			la++;
		}else if(lb<m){
			c[idx++] = b[lb];
			lb++;
		}
	}
	for(int i=0; i<n+m; i++){
		cout<<c[i]<< ' ';
	}
	cout<<endl;
}
/*
Given an array containing N integers,
you need to find the length of the
smallest contiguous subarray that 
contains atleast K distinct elements in it.
Output "−1" if no such subarray exists.
*/

void solve_prb4(int *ara, int n, int k)
{
	int l=0, r = 0, ans = 11111;
	map<int, int >cnt;
	set<int>s;

	while(l<n){
		while(r<n && s.size()<k){
			s.insert(ara[r]);
			cnt[ara[r]]++;
			r++;
		}
		if(s.size()>=k){
			ans = min(ans, r-l);
		}
		
		if(cnt[ara[l]] == 1){
			s.erase(ara[l]);
		}
		cnt[ara[l]]--;
		l++;
	}
	if(ans == 11111) ans = -1;
	printf("%d\n", ans);
}
/*
Given two sorted array, find how many ways
we get a sum, you must select two element from
two array, and you can't select duplicate 
*/

void solve_bng(int *a, int *b, int n, int m, int sum)
{
	int lo=0, hi = m-1, cnt=0;
	while(lo < n){
		while(hi>0 && a[lo]+b[hi]>sum){
			hi--;// val incr so decr pointer
		}
		if(a[lo]+b[hi] == sum){
			cnt++;
		}
		lo++;
	}
	printf("%d ways you get %d\n", cnt, sum);
}

int main()
{
	/*int n;
	cin>>n;

	int ara[n+1];
	for(int i=0; i<n; i++){
		cin>>ara[i];
	}
	int x;
	cin>>x;

	solve_prb1(ara, n, x);*/
	/*
	int n, m;
	cin>>n>>m;

	int ara[n+2], cra[m+2];

	for(int i=0; i<n; i++) {
		cin>>ara[i];
	}
	for(int i=0; i<m; i++){
		cin>>cra[i];
	}

	solve_prb2(ara, cra, n, m);*/

	/*int n, k;
	
	cin>>n>>k;
	int ara[n+1];

	for(int i=0; i<n ; i++){
		cin>>ara[i];
	}
	solve_prb4(ara, n, k);*/

	// solve bangla
	int n, m;
	cin>>n>>m;

	int a[n+1], b[m+1];

	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];

	int k;
	cin>>k;// k banate hbe

	solve_bng(a, b, n, m, k);

	return 0;
}