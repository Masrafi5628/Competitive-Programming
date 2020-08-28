#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char str[50000];

    cin>>n;

    while(n--){
        cin>>str;
        int l=strlen(str);

        if(!strcmp(str, "1") || !strcmp(str, "4") || !strcmp(str, "78")) cout << '+'<<endl;
        else if(str[l-1] != '\0' && str[l-2]=='3' && str[l-1]=='5') cout << '-'<<endl;
        else if(str[l-1] != '\0' && str[0]=='9' && str[l-1]=='4') cout << '*'<<endl;
        else cout << '?'<<endl;
    }

    return 0;
}

