#include <bits/stdc++.h>

using namespace std;
int lookup[3005][3005];
string str= "";

void LCS(string p,string q,int m,int n)
{
    if(m==0 || n==0) return ;

    if(p[m-1]==q[n-1]) {
        str+=p[m-1];
        return LCS(p,q,m-1,n-1);
    }

    if(lookup[m-1][n]>lookup[m][n-1]) return LCS(p,q,m-1,n);
    else return LCS(p,q,m,n-1);
}

int LCS_length(string p, string q,int m,int n)
{

    for(int i=0;i<=m;i++) lookup[i][0]=0;
    for(int j=0;j<=n;j++) lookup[0][j]=0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[i - 1] == q[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
	return lookup[m][n];
}

int main()
{
	string X;
	string Y;

	cin>>X>>Y;

	printf("Longest Common Subsequence length is %d\n",LCS_length(X,Y,X.length(),Y.length()));
	//LCS_length(X,Y,X.length(),Y.length());
	LCS(X,Y,X.length(),Y.length());

	for(int i=str.length()-1;i>=0;i--)
        cout <<str[i];
    cout <<endl;

	return 0;
}
