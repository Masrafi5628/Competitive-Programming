#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[15];
    int kase=1;

    while(scanf("%s",str)){

        if(!strcmp(str, "#")) break;
        else if(!strcmp(str, "HELLO")) printf("Case %d: ENGLISH\n",kase++);
        else if(!strcmp(str, "HOLA")) printf("Case %d: SPANISH\n",kase++);
        else if(!strcmp(str, "HALLO")) printf("Case %d: GERMAN\n",kase++);
        else if(!strcmp(str, "BONJOUR")) printf("Case %d: FRENCH\n",kase++);
        else if(!strcmp(str, "CIAO")) printf("Case %d: ITALIAN\n",kase++);
        else if(!strcmp(str, "ZDRAVSTVUJTE")) printf("Case %d: RUSSIAN\n",kase++);
        else printf("Case %d: UNKNOWN\n",kase++);
    }

    return 0;
}
