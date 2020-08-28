/*
Task: given two numbers n and r, 
count the number of integers in the interval [1;r]
that are relatively prime to n 
(their greatest common divisor is 1)
*/
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int r)
{
	vector<int>p;
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			p.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) p.push_back(n);

	int sum=0;
	for(int msk=1; msk<(1<<p.size()); msk++){
		int mult=1, bits=0;
		for(int i=0; i<(int)p.size(); i++){

			if(msk & (1<<i)) {// take i-th bit	
				++bits;
				mult *= p[i];
			}
		}
		//cout<<mult<<endl;
		int cur = r/mult;
		if(bits%2) 
			sum += cur;
		else 
			sum -= cur;
	}
	return r-sum;
}

int main()
{
	int n, r;
	cin>>n>>r;

	cout<<solve(n, r)<< "\n";

	return 0;
}