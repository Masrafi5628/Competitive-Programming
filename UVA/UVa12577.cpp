#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kase=1;
    char str[10];

    while(scanf("%s",str)){
        if(!strcmp(str, "*")) break;

        printf("Case %d: ",kase++);
        if(!strcmp(str, "Hajj")) cout << "Hajj-e-Akbar\n";
        else cout << "Hajj-e-Asghar\n";
    }

    return 0;
}
