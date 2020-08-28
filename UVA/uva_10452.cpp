#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;
using pii = pair<int, int>;
string ans = "IEHOVA#";

int dr[] = {-1, 0, 0};// up, left, right
int dc[] = { 0,-1, 1};

void bfs(string *str, int pos, int row, int col)
{
	queue<pii>q;
	q.push({row-1, pos});// starting position

	int idx=0;

	while(!q.empty()) {
		pii p = q.front();
		q.pop();
		int x=p.ff, y = p.ss;// x =row, y = col
		//printf("x %d y %d\n", x, y);

		if(x-1>=0 && str[x-1][y] == ans[idx]) {
			printf("forth");
			q.push({x-1, y});
		}
		else if(y-1>=0 && str[x][y-1] == ans[idx]) {
			printf("left");
			q.push({x, y-1});
		}
		else {
			printf("right");
			q.push({x, y+1});
		}
		if(idx != 6) 
			printf(" ");
		idx++;
		if(idx == 7) {
			printf("\n");
			break;
		}
	}

}

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n, m;
		cin>>n>>m;
		string str[n];

		for(int i=0; i<n; i++){
			cin>>str[i];
		}
		int col;
		for(int i=0; i<str[n-1].size(); i++){
			if(str[n-1][i] == '@')
				col = i;
		}
		bfs(str, col, n, m);
	}

	return 0;
}