#include <bits/stdc++.h>

using namespace std;
// Euler Totient function count the number of 
// integers which is co-prime to n(given number)

// O(sqrt(n)) complexity per n

int solve(int n)
{
	int ans = n;

	for(int i=2; i*i <= n; i++){
		if(n%i == 0) {
			while(n%i == 0) n/=i;
			ans = ans-ans/i;
		}
	}
	if(n > 1) ans = ans-ans/n;
	return ans;
}

// Euler totient function from 1 to n in O(nloglogn)

void phi_1_to_n(int n)
{
	vector<int>phi(n+1);
	phi[0] = 0; phi[1] = 1;

	for(int i=2; i<=n; i++) phi[i] = i;

	for(int i=2; i<=n; i++){
		if(phi[i] == i){
			for(int j=i; j<=n; j+=i){
				phi[j] = phi[j]-(phi[j]/i);
			}
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d\t%d\n", i, phi[i]);
	}
}

// Finding the totient from 1 to n using the divisor sum property

void phi_div(int n)
{
	vector<int>phi(n+1);
	phi[0] = 0, phi[1] = 1;

	for(int i=2; i<=n; i++) 
		phi[i] = i-1;

	for(int i=2; i<=n; i++){
		for(int j=2*i; j<=n; j+=i){
			phi[j] = phi[j]-phi[i];// Interesting property
		}
	}

	for(int i=1; i<=n; i++){
		printf("%d\n", phi[i]);
	}
}

int main()
{
	int n;
	cin>>n;

	//cout << solve(n);
	//phi_1_to_n(n);
	phi_div(n);

	return 0;
}