#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;
    long long cnt=0;
    while(scanf("%c",&ch)==1)
    {
        if(ch=='"')
        {
            cnt++;
            if(cnt%2==1) printf("``");
            else if(cnt%2==0) printf("''");
        }
        else printf("%c",ch);
    }
}
