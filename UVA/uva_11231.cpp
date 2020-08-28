#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()

{
	ll n, m, c;
	while(cin>>n>>m>>c) {
		if(!n && !m && !c) 
			break;
		printf("%lld\n", ((n-7)*(m-7)+c)/2);
	}

	return 0;
}