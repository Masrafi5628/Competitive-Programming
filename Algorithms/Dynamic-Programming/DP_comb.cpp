#include <bits/stdc++.h>

using namespace std;

int comb[50][50];

int ncr(int n,int r)
{
    if(comb[n][r]!=0) return comb[n][r];
    if(r==1) return n;
    if(r==n) return 1;

    return comb[n][r]=ncr(n-1,r-1)+ncr(n-1,r);

}
int main()
{
    cout << ncr(30,13) <<endl;

    return 0;
}
