#include <bits/stdc++.h>

using namespace std;

const int sz=1e6;
int spf[sz];// smallest prime factor

void leastprimefactor(int n)
{
	spf[1]=1;
	for(int i=2;i<=n;i+=2)
		spf[i]=2;

	for(int i=3;i<=n;i+=2){
		if(spf[i] == 0){
			spf[i]=i;

			for(int j=2*i;j<=n;j+=i){
				if(spf[j] == 0){
					spf[j]=i;
				}
			}
		}
	}

}
void primefactor(int n)
{
	while(n != 1){
		cout << spf[n] << ' ';
		n/=spf[n];
	}
}

int main()
{
	int n;
	cin>>n;

	leastprimefactor(n);
	primefactor(n);

	return 0;
}