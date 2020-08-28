#include <bits/stdc++.h>

using namespace std;

const int lim = 2500002;

int trie[lim][5];// trie[u][d]: u teke d hoye jawa jai je node e
bool flag[lim];
int cnt[lim];
int idx;// koto number node
int ans;

void add(string str)
{
	int u=0;// root node teke deka suro korbo
	for(int i=0; i<str.size(); i++){

		int d = 3;// str[i] == 'T' hole

		if(str[i] == 'A')
			d = 0;
		else if(str[i] == 'C')
			d = 1;
		else if(str[i] == 'G')
			d = 2;


		// u hocce ager char ba node
		// d hocce bortoman char ba node

		if(!trie[u][d])
			trie[u][d] = ++idx;// u char teke d char ee jete na
							//	parle node banaite hbe

		//printf("u %d d %d idx %d\n", u, d, idx);
		u = trie[u][d];
		cnt[u]++;
		//printf("idx %d\n", idx);
	}
	flag[u] = true;// u tomo node ee string ses hoice
}

int dfs(int u, int c)
{
	//if(cnt[u] == 1) return c;
	
	ans = max(ans, c*cnt[u]);

	/*if(c*cnt[u] < ans)
		return ans;*/

	//printf("u %d c %d ans %d\n", u, c, ans);
	
	for(int i=0; i<4; i++){
		if(trie[u][i]) {
			//printf("u %d i %d\n", u, i);
			ans = max(ans, dfs(trie[u][i], c+1));
		}
	} 
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n, kase=1;
	cin>>t;

	while(t--){

		idx = 0;
		ans = 0;

		memset(trie, 0, sizeof trie);
		memset(flag, false, sizeof flag);
		memset(cnt, 0, sizeof cnt);

		cin>>n;
		string s;
		for(int i=0; i<n; i++){
			cin>>s;
			add(s);
		}
		//printf("ix %d\n", idx);
		printf("Case %d: %d\n", kase++, dfs(0, 0));
	}

	return 0;
}