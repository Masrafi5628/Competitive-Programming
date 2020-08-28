#include <bits/stdc++.h>

using namespace std;

int egcd(int a, int b, int& x, int& y)
{
	if(!b) {
		x=1, y=0; return a;
	}
	int x1, y1;
	int d = egcd(b, a%b, x1, y1);
	//printf("d %d x1 %d y1 %d\n", d, x1, y1);
	x = y1;
	y = x1-(a/b)*y1;
	
	printf("x %d y %d d %d\n", x, y, d);

	/*
	if((a*x)+(b*y) == d)
		printf("yes!!!!!\n");
	else 
		printf("no!!!\n");
		*/

	return d;
	
}

int main()
{
	int a, b, x, y, gcd;
	cin>>a>>b;

	gcd = egcd(a, b, x, y);
	printf("%d %d %d\n", x, y, gcd);

	return 0;
}