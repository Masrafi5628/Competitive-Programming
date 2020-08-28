// HackerRank power sum problem
// more to improve this code
// 1. remove vector using in recursive function
//    you only need last element and sum so far
// 2. Use DP 
// 3. you can use i-th power and can't use i-th power
//    solve(x, n, val+1)+solve(x-(val^n), n ,val+1)

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int pwr(int a, int b)
{
	if(b==0) return 1;
	if(b%2==0) return pwr(a*a, b/2);
	return a*pwr(a*a, (b-1)/2);
}

int backtrack(int x, int n, vector<int>& num)
{
	int sum = 0;
	for(int val: num){
		printf("%d^%d + ", val, n);
		sum += pwr(val, n);
	}
	printf("\n");
	if(sum == x) {
		printf("!!!! Found solution !!!!\n"); 
		return 1;
	}
	else {
		int k = num.empty()?1:num.back()+1;
		int ans = 0;
		while(sum+pwr(k, n)<=x){
			num.pb(k);
			ans += backtrack(x, n, num);
			num.pop_back();
			k++;
		}
		printf("You can't add %d+%d^%d\n", sum, k, n);
		return ans;
	}
}

int main()
{
	int x, n;
	vector<int>num;
	cin>>x>>n;

	cout<<backtrack(x, n, num)<<endl;

	return 0;
}