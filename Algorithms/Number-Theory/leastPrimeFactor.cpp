#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int leastPriFact[maxN];

void leastPF(int n)
{
	leastPriFact[1]=1;

	for(int i=4;i<=n;i+=2)
		leastPriFact[i]=2;

	for(int i=2;i<=n;i++){
		if(leastPriFact[i] == 0){
			leastPriFact[i]=i;

			for(int j=2*i;j<=n;j+=i){
				if(leastPriFact[j]==0){
					leastPriFact[j]=i;
				}
			}
		}
	}
}

int main()
{

	int n;
	cin>>n;

	leastPF(n);

	for(int i=1;i<=n;i++){
		printf("least prime factor of %d is %d\n", i, leastPriFact[i]);
	}

	return 0;
}