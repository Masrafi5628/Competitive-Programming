#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int ara[111];

	cin>>n;
	for(int i=0; i<n; i++){
		cin>>ara[i];
	}
	// kadane's algorithm 
	
	int ans = 0, sum = 0 ;
	for(int k=0; k<n; k++){
		sum = max(ara[k], sum+ara[k]);
		ans = max(ans, sum);
		//printf("sum %d ans %d\n", sum , ans);
	}

	cout<<ans<< '\n';

	return 0;
}