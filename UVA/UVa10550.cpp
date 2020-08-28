#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;

    while(scanf("%d%d%d%d",&a,&b,&c,&d),(a || b || c || d)){
        cout << 1080+((a-b+40)%40+(c-b+40)%40+(c-d+40)%40)*9<<endl;
    }

    return 0;
}

