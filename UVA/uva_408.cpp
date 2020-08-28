#include <bits/stdc++.h>

using namespace std;

int main()
{
	int step, mod;

	while(scanf("%d%d", &step, &mod) != EOF){
		int cnt = 1;
		int st=0;
		while((step+st)%mod !=0){
			cnt++;
			st = (step+st)%mod;
		}
		string str;

		if(cnt == mod) {
			str = "Good Choice";
		}else {
			str = "Bad Choice";
		}
		printf("%10d%10d    %s\n\n", step, mod, str.c_str());
	}

	return 0;
}