#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool visit[25][25];

void dfsVisit(string *str, int r, int c, int n)
{
	visit[r][c] = true;
	for(int i=0; i<8; i++){
		int row = r+dr[i], col = c+dc[i];

		if((row>=0 && row<n ) && (col>=0 && col<n)) {
			if(str[row][col] == '1') {
				if(!visit[row][col]) {
					dfsVisit(str, row, col, n);
				}
			}
		}
	}
}

int main()
{
	int n, kase=1;

	while(cin>>n) {
		memset(visit, false, sizeof visit);

		string str[n];
		for(int i=0; i<n; i++){
			cin>>str[i];
		}
		int cnt=0;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(str[i][j] == '1' && !visit[i][j]) {
					dfsVisit(str, i, j, n);
					cnt++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", kase++, cnt);
	}

	return 0;
}