#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int LCM(int a, int b)
{
	return (a*b)/__gcd(a, b);
}
int ans;
void solve(int *ara, int idx, int lcm, int num, int totalElem, int n)
{
	// idx->last kon element nici tar index
	// num->koita element nici
	// n-> je range porjonto ans ber korte hbe
	//int ans = 0;
	if(idx == totalElem) {
		return ;
	}
	
	for(int i=idx; i<totalElem; i++){
		int cur_lcm = LCM(ara[i], lcm);
		//printf("lcm of %d %d is %d\n", ara[i], lcm, cur_lcm);
		if((num+1)%2) 
			ans += n/cur_lcm;
		else 
			ans -= n/cur_lcm;
		printf("ans %d\n", ans);
		solve(ara, i+1, cur_lcm, num+1, totalElem, n);
	}
}
int main()
{
	int ara[] = {2, 3};
	int n = 100;// 1..100 koto gula shonka 2 or 3 
					//dara divisible
	//int lcm=1;
	solve(ara, 0, 1, 0, 2, n);
	cout<<ans<<endl;

	return 0;
}