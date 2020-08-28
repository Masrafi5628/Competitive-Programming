#include <bits/stdc++.h>

using namespace std;

string dp[255];

string add(string &a, string &b)
{
	int la = a.size(), lb = b.size();
	string ret;

	for(int i=0, c=0; i<la || i<lb || c>0; i++){
		if(i<la) c += a[i]-'0';
		//cout<<"c "<<c<<endl;
		if(i<lb) c += b[i]-'0';
		//cout<<"c "<<c<<endl;
		ret += '0'+c%10;
		//cout<<"ret "<<ret<<endl;
		c = c/10;
	}
	return ret;
}

int main()
{
	int n;

	dp[0] = dp[1] = "1";

	for(int i=2; i<=250; i++){
		//cout<< "i "<<i<<endl;
		dp[i] = "0";
		dp[i] = add(dp[i], dp[i-1]);
		dp[i] = add(dp[i], dp[i-2]);
		dp[i] = add(dp[i], dp[i-2]);
	}

	for(int i=2; i<=250; i++)
		reverse(dp[i].begin(), dp[i].end());

	while(cin>>n){
		printf("%s\n", dp[n].c_str());
	}

	return 0;
}