#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pi acos(-1)


using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Rectangle
{
	int x1, y1, x2, y2;
};


int main()
{
	int t;
	cin>>t;

	while(t--) {
		Rectangle ara[2];

		for(int i=0; i<2; i++){
			cin>>ara[i].x1>>ara[i].y1>>ara[i].x2>>ara[i].y2;
		}
		int x=max(ara[0].x1, ara[1].x1);
		int y=max(ara[0].y1, ara[1].y1);

		int xx=min(ara[0].x2, ara[1].x2);
		int yy=min(ara[0].y2, ara[1].y2);

		if(x<xx && y<yy) {
			printf("%d %d %d %d\n", x, y, xx, yy);
		}
		else {
			cout<< "No Overlap\n";
		}
		if(t) printf("\n");
	}

	return 0;
}
