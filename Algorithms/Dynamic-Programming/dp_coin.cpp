#include <bits/stdc++.h>

using namespace std;

int k, n;// k ta coin , n banate hobe
int coin[111];



void banano_jbe_kina()
{
	bool psbl[111];//psbl[i]=1 hbe jodi i banano jai
	memset(psbl, false, sizeof psbl);

	psbl[0] = true;// kono ta na niye zero

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(i>=coin[j])
				psbl[i] = psbl[i] | psbl[i-coin[j]];
			else 
				psbl[i] = false;
		}
	}
	if(psbl[n])
		printf("banano jabe\n");
	else
		printf("jabe na\n");

}

void koto_babe_jbe()
{
	int way[111];
	
	memset(way, 0, sizeof way);
	way[0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k ; j++){
			if(i>=coin[j]){
				way[i]+=way[i-coin[j]];

			}
		}
	}
	printf("%d babe\n", way[n]);
}

// coin 1 barer besi newa jabe na

void banano_jbe_kina()
{
	bool psbl[111][111];//psbl[i][j]=1 hbe jodi j poriman i-th
						//coin diye banano jai
	memset(psbl, false, sizeof psbl);

	psbl[0][0] = true;// kono ta na niye zero

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(i>=coin[j])
				psbl[i] = psbl[i] | psbl[i-coin[j]];
			else 
				psbl[i] = false;
		}
	}
	if(psbl[n])
		printf("banano jabe\n");
	else
		printf("jabe na\n");

}

int main()
{
	
	cin>>k>>n;
	for(int i=1; i<=k; i++){
		cin>>coin[i];
	}

	banano_jbe_kina();
	koto_babe_jbe();
	
	return 0;
}