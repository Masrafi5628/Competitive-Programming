#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int ara[n+1][n+1];
	int pref[n+1][n+1];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>ara[i][j];
		}
	}
	memset(pref, 0, sizeof pref);

	pref[0][0] = ara[0][0];

	for(int i=1; i<n; i++){
		pref[0][i] += pref[0][i-1]+ara[0][i];
		pref[i][0] += pref[i-1][0]+ara[i][0];
	}
	for(int i = 1; i<n; i++){
		for(int j=1; j<n; j++){
			pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+ara[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", pref[i][j]);
		}
		printf("\n");
	}

	return 0;
}