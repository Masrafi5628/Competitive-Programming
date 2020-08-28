#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//int dr[] = {-1, 0, 1,  0};// up, right, down, left
//int dc[] = { 0, 1, 0, -1};

int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};

// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};

int bfs(pii cur, pii des)
{
	bool visit[8][8];
	int dista[8][8];

	memset(visit, false, sizeof visit);
	memset(dista, 0, sizeof dista);

	queue<pii>q;
	q.push(cur);

	visit[cur.ff][cur.ss] = true;
	while(!q.empty()) {
		cur = q.front();q.pop();
		int row = cur.ff, col = cur.ss;
		for(int i=0; i<8; i++){
			int r = row+kr[i], c=col+kc[i];
			if(r>=0 && c>=0 && r<8 && c<8) {
				if(!visit[r][c]) {
					q.push({r, c});
					visit[r][c] = true;
					dista[r][c] = dista[row][col]+1;
				}
			}
			if(r == des.ff && c == des.ss) {
				return dista[r][c];
			}
		}
	}

}

int main()
{
	string a, b;
	while(cin>>a>>b) {
		int cur_row, cur_col, des_row, des_col;

		cur_row = a[1]-'0'-1, cur_col = 'h' - a[0];
		des_row = b[1]-'0'-1, des_col = 'h' - b[0];

		printf("To get from %s to %s takes %d knight moves.\n", 
			a.c_str(), b.c_str(), bfs({cur_row, cur_col}, {des_row, des_col}));
	}

	return 0;
}