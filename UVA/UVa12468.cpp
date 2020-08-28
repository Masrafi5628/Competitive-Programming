#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;

    while(scanf("%d%d",&a,&b)){
        if(a==-1 && b==-1) break;

        cout<< min({(99-a)+b+1,a+(99-b)+1,abs(a-b)})<<endl;
    }

    return 0;
}

