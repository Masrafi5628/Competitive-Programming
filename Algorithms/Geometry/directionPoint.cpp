#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x, y;
};

int main()
{
	point a, b, p;
	cin>>a.x>>a.y>>b.x>>b.y>>p.x>>p.y;

	// subtracting co-ordinates of point A from 
    // B and P, to make A as origin

	b.x -= a.x;
	b.y -= a.y;
	p.x -= a.x;
	p.y -= a.y;


	int cross_prod = b.x*p.y - b.y*p.x;

	if(!cross_prod) printf("Point is on the line\n");
	else if(cross_prod > 0) printf("Point is on right side\n");
	else printf("Point is on left side\n");

	return 0;
}