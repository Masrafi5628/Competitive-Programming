#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char str[105][105];
    char temp[16][12]={
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "Rujia",
        "Happy",
        "birthday",
        "to",
        "you"
    };

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>str[i];

    for(int i=0;i<n || i%16 != 0;i++){

        printf("%s: %s\n",str[i%n],temp[i%16]);

    }

    return 0;
}
