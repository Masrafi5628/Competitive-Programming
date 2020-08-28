#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    char str[1005];

    cin>>t;
    while(t--){
        scanf(" %[^\n]",str);
        int m=0,f=0;

        for(int i=0;i<strlen(str);i++){
            if(str[i]=='M') m++;
            else if(str[i]=='F') f++;
        }
        if(m==f && m!=1) printf("LOOP\n");
        else printf("NO LOOP\n");
    }

    return 0;
}

