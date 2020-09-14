/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
*/

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

//#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel
// istringstream ss(str) while(ss >> n)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const ll inf = 2e18;
const ll mod = 1e9+7;

int dr[] = {-1, 0, 1,  0};// up, right, down, left
int dc[] = { 0, 1, 0, -1};

// King moves similar to 8 direction
//int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
//int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};

// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};
// diagonal moves
int dgr[] = {-1, -1,  1, 1};
int dgc[] = { 1, -1, -1, 1};

int row, col;
int grid[11][111];
ll cost[11][111];
int path[11][111];

ll sol(int i, int j)
{
	//printf("i %d j %d\n", i, j);
	if(j >= col) return 0;
	if(cost[i][j] != inf) return cost[i][j];

	ll &ret = cost[i][j];
	/*
	return grid[i][j]+min({sol((i+row-1)%row, j+1),
		sol(i, j+1), sol((i+1)%row, j+1)});
	*/

	ll val = sol((i+row-1)%row, j+1);
	int r = (i+row-1)%row;

	if((ret > grid[i][j]+val) || 
		(ret == grid[i][j]+val && path[i][j] > r)) {
		ret = grid[i][j]+val;
		//path[r][j+1] = {i, j};
		path[i][j] = r;
	}
	ll val1 = sol(i, j+1);

	if((ret > grid[i][j]+val1) || (
		ret == grid[i][j]+val1 && path[i][j] > i)) {
		ret = grid[i][j]+val1;
		//path[i][j+1] = {i, j};
		path[i][j] = i;
	}
	
	ll val2 = sol((i+1)%row, j+1);
	r = (i+1)%row;

	if((ret > grid[i][j]+val2) || 
		(ret == grid[i][j]+val2 && path[i][j] > r)) {
		ret = grid[i][j]+val2;
		//path[r][j+1] = {i, j};
		path[i][j] = r;
	}
	return ret;
}
int main()
{
	while(scanf("%d%d", &row, &col) != EOF) {
		memset(grid, 0, sizeof grid);
		memset(cost, 0, sizeof cost);
		memset(path, 0, sizeof path);

		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				scanf("%d", &grid[i][j]);
				cost[i][j] = inf;
				path[i][j] = row+1;//{row+1, col+1};
			}
		}
		ll ans = inf;
		int idx;
		for(int i=0; i<row; i++) {
			if(ans > sol(i, 0)) {
				ans = cost[i][0];
				idx = i;
			}
		}
		for(int i=0; i<col; i++) {
			if(i) printf(" ");
			printf("%d", idx+1);
			idx = path[idx][i];
		}
		printf("\n");
		printf("%lld\n", ans);
	}

    return 0;
}