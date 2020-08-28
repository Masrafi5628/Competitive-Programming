#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using pii  = pair<int, int>;
using pdd  = pair<double, double>;

vector<pdd>v;
int n;
double ans;

bool compY(pdd a, pdd b)
{
	if(a.ss == b.ss) return a.ff < b.ff;
	return a.ss < b.ss;
}

double sqr(double a)
{
	return a*a;
}

double dis(pdd a, pdd b)
{
	return sqrt(sqr(abs(a.ff-b.ff))+sqr(abs(a.ss-b.ss)));
}

// bruteforce for small range
double brute(int l, int r)
{
	double d = FLT_MAX;
	for(int i=l; i<r; i++) {
		for(int j=i+1; j<=r; j++) {
			d = min(d, dis(v[i], v[j]));
		}
	}
	return d;
}

// handle corner case when divide
double strip_closest(vector<pdd>strip, double d)
{
	sort(strip.begin(), strip.end(), compY);

	int len = strip.size();/*
	for(int i=0; i<len; i++) {
		printf("%d %d\n", strip[i].ff, strip[i].ss);
	}*/
	for(int i=0; i<len-1; i++) {
		// this makes program so fast
		for(int j=i+1; j<=len && (strip[j].ss-strip[i].ss < d); j++) {
			//printf("%d %d => %d %d\n", strip[i].ff, strip[i].ss, strip[j].ff, strip[j].ss);
			d = min(d, dis(strip[i], strip[j]));
			//printf("%f\n", d);
		}
	}
	return d;
}

// divide and conquer approach
double closest(int l, int r)
{
	//printf("l %d r %d \n", l, r);
	if(r-l <= 2){
		return brute(l, r);
	}
	int mid = l+((r-l)/2);

	double dl = closest(l, mid);
	double dr = closest(mid+1, r);
	//printf("dl %f dr %f\n", dl, dr);
	double d = min(dl, dr);
	vector<pdd>strip;

	for(int i=0; i<=r; i++) {
		if(abs(v[i].ff - v[mid].ff) < d) {
			strip.pb(v[i]);
		}
	}
	//printf(" d %f \n", d);
	return min(d, strip_closest(strip, d));
}

int main()
{
	while(cin>>n, n) {
		v.clear();

		for(int i=0; i<n; i++) {
			double x, y;
			cin>>x>>y;
			v.pb({x, y});
		}
		sort(v.begin(), v.end());// according to x co-ordinate
		/*
		for(int i=0; i<n; i++) {
			printf("%d %d\n", v[i].ff, v[i].ss);
		}*/
		double tmp = closest(0, n-1);

		if(tmp >= 10000) printf("INFINITY\n");
		else printf("%.4f\n", tmp);
	}



	return 0;
}