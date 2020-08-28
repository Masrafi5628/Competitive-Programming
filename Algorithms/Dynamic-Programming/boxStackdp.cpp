#include <bits/stdc++.h>

using namespace std;

struct Box
{
	int h, w, d;
};

int max(int a, int b)
{
	return a<b? b: a;
}
int min(int a, int b)
{
	return a<b? a: b;
}

bool comp(Box a, Box b)
{
	return a.w*a.d > b.w*b.d;
}

int solve(Box *rot, int n)
{
	sort(rot, rot+n, comp);
	int lis[n+1];

	/*for(int i=0; i<n; i++){
		printf("%d\t%d\t%d\n", rot[i].h, rot[i].w,
			rot[i].d);
	}*/

	for(int i=0; i<n; i++)
		lis[i] = rot[i].h;

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(rot[i].w < rot[j].w && 
				rot[i].d < rot[j].d && 
				lis[i] < lis[j]+rot[i].h) {

				lis[i] = lis[j]+rot[i].h;
			}
		}
	}
	int ret = -1;
	for(int i=0; i<n; i++)
		ret = max(ret, lis[i]);

	return ret;
}

int main()
{
	int n;
	
	while(cin>>n, n!=0) { 

		Box rot[3*n];
		int idx = 0;

		for(int i=0; i<n; i++){
			int h, w, d;
			cin>>h>>w>>d;

			// First rotation
			rot[idx].h = h;
			rot[idx].d = max(w, d);
			rot[idx].w = min(w, d);

			idx++;
			// Second rotation
			rot[idx].h = w;
			rot[idx].d = max(h, d);
			rot[idx].w = min(h, d);

			idx++;
			// Third rotation
			rot[idx].h = d;
			rot[idx].d = max(h, w);
			rot[idx].w = min(h, w);

			idx++;
		}
		int ans = solve(rot, 3*n);// 3 gun besi hobe
		cout<<ans<<endl;
	}

	return 0;
}