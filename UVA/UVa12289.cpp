#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    char str[15];

    cin>>t;


    while(t--){
        scanf("%s",&str);

        if(!strcmp(str, "one") || (str[0]=='o' && str[2]=='e') || (str[1]=='n' && str[2]=='e')||(str[0]=='o'&&str[1]=='n'))
            cout <<1<<endl;
        else if(!strcmp(str, "two") || (str[0]=='t' && str[2]=='o') || (str[1]=='w' && str[2]=='o')||(str[0]=='t'&&str[1]=='w'))
            cout <<2<<endl;
        else
            cout <<3<<endl;
    }

    return 0;
}

