#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pi acos(-1)


using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Point
{
	double x, y;
};


int main()
{
	Point a, b, c, d;

	while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y) {

		double x, y;
		if(a.x == c.x && a.y == c.y) {
			x = (b.x+d.x)-a.x, y = (b.y+d.y)-a.y;
		}
		else if(a.x == d.x && a.y == d.y) {
			x = (b.x+c.x)-a.x, y = (b.y+c.y)-d.y;
		}
		else if(b.x == c.x && b.y == c.y) {
			x = (a.x+d.x)-b.x, y = (a.y+d.y)-b.y;
		}
		else {
			x = (a.x+c.x)-b.x, y = (a.y+c.y)-b.y;
		}
		printf("%.3lf %.3lf\n", x, y);
	} 

	return 0;
}