#include <bits/stdc++.h>

using namespace std;
int ara[22], n;

void find_combination(int idx, int cur_len, int req_len, bool *ck, int len)
{
	if(cur_len > req_len)
		return;
	if(cur_len == req_len) {
		for(int i=0; i<len; i++) {
			if(ck[i]) printf("%d ", ara[i]);
		}
		printf("\n");
		
		return;
	}
	if(idx == len) return;
	ck[idx] = true;
	find_combination(idx+1, cur_len+1, req_len, ck, len);
	ck[idx] = false;
	find_combination(idx+1, cur_len, req_len, ck, len);

}

int main()
{
	bool ck[22];
	memset(ck, false, sizeof ck);

	cin>>n;
	for(int i=0; i<n; i++) ara[i] = i;
	for(int i=n; i<2*n; i++) ara[i] = -1;

	find_combination(0, 0, 4, ck, n);

	return 0;
}