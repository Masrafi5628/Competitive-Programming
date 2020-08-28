#include <bits/stdc++.h>

using namespace std;

const long long inf = 99999999999999;

long long v[111111];
int lis[111111];
int idx;

int lis_nlogk()
{
	vector<long long>insrt(idx+1, inf);
	insrt[0] = -inf;
	int n = idx;

	for(int i=0; i<n; i++){
		//printf("eto %d\n", v[i]);
		lis[i] = lower_bound(insrt.begin(), insrt.end(), v[i])-insrt.begin();
		insrt[lis[i]] = v[i];
	}
	int len = 0, st;
	for(int i=n-1; i>=0; i--){
		if(lis[i] > len){
			len = lis[i];
			st = i;
		}
	}
	printf("%d\n-\n", len);
	return st;

}

void find_seq(int st)
{
	vector<long long>ss;
	ss.push_back(v[st]);

	for(int i=st-1; i>=0; i--){
		if(v[i] < v[st] && lis[i]+1 == lis[st]){
			ss.push_back(v[i]);
			st = i;
		}
	}
	for(int i=ss.size()-1; i>=0; i--){
		printf("%d\n", ss[i]);
	}
}

int main()
{
	long long  a;
	
	while(scanf("%lld", &a) != EOF){
		v[idx++] = a;
		//printf("yy\n");
	}
	//cout<<v.size()<<endl;
	find_seq(lis_nlogk());

	return 0;
}