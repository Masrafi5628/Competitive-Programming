/*
Given n numbers ai and number r. 
You want to count the number of integers 
in the interval [1;r] that are multiple of 
at least one of the ai
*/
#include <bits/stdc++.h>

using namespace std;

int LCM(int a, int b)
{
	return (a*b)/__gcd(a, b);
}

int solve(vector<int>v, int r)
{
	int sum = 0;
	for(int msk=1; msk<(1<<v.size()); msk++){
		int lcm=1, bits=0;
		for(int i=0; i<(int)v.size(); i++){
			if(msk & (1<<i)) {
				bits++;
				lcm = LCM(lcm, v[i]);
			}
		}
		printf("lcm is %d\n", lcm);
		int cur = r/lcm;
		if(bits%2)
			sum += cur;
		else 
			sum -= cur;
	}
	return sum;
}

int main()
{
	int n, r;
	cin>>n>>r;
	vector<int>v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];

	cout<<solve(v, r)<<endl;

	return 0;
}