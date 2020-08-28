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
	double x1, y1, x2, y2;
};


int main()
{
	char ch;
	int cnt=0;
	Rectangle r[15];
	while(cin>>ch, ch != '*') {
		
		cin>>r[cnt].x1>>r[cnt].y1>>r[cnt].x2>>r[cnt].y2;
		cnt++;
	}
	int Point = 1;
	while(1) {
		double x, y;
		cin>>x>>y;
		if(x==y && x== 9999.9) {
			break;
		}
		bool ck = true;
		for(int i=0; i<cnt; i++){
			if(x>r[i].x1 && x<r[i].x2 && 
				y>r[i].y2 && y<r[i].y1) {
				ck = false;
				printf("Point %d is contained in figure %d\n", Point, i+1);
			}
		}
		if(ck) {
			printf("Point %d is not contained in any figure\n", Point);
		}
		Point++;
	}

	return 0;
}