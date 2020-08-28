#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;
using pii = pair<int, int>;

int dr[] = {-1, 1, 0, 0};// up,down,left, right
int dc[] = { 0, 0,-1, 1};
int ships;
bool visit[101][101];

void dfs(string *str, int r, int c, int n)
{
	/*if(visit[r][c] || str[r][c]=='.')
		return;
	*/
	if(str[r][c] == 'x') ships++;

	visit[r][c] = true;
	for(int i=0; i<4; i++){
		int row=r+dr[i], col = c+dc[i];
		if((row>=0 && row<n) && (col>=0 && col<n)) {
			if(str[row][col] == 'x' || str[row][col] == '@') {
				if(!visit[row][col]) {
					
					dfs(str, row, col, n);
				}
			}
		}
	}
}

int main()
{
	int t, kase=1;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		string str[n];

		for(int i=0; i<n; i++){
			cin>>str[i];
		}
		int cnt=0;
		memset(visit, false, sizeof visit);

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) {
				if(str[i][j] != '.' && !visit[i][j]) {
					ships = 0;
					dfs(str, i, j, n);
					if(ships)
						cnt++;
				}
			}
		}
		printf("Case %d: %d\n", kase++, cnt);
	}

	return 0;
}