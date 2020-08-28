#include <bits/stdc++.h>

using namespace std;

bool valid(char first,int second)
{
    if((first>='a' && first<='h')&& (second>=1 && second<=8)) return true;
    return false;
}

int main()
{
    int n;
    char str[3];

    cin>>n;

    while(n--){
        int cnt=0;
        cin>>str;

        if(valid(str[0]-1,str[1]-'0'-2)) cnt++;///-1,-2
        if(valid(str[0]-1,str[1]-'0'+2)) cnt++;///-1,2
        if(valid(str[0]-2,str[1]-'0'-1)) cnt++;///-2,-1
        if(valid(str[0]+1,str[1]-'0'-2)) cnt++;///1,-2
        if(valid(str[0]-2,str[1]-'0'+1)) cnt++;///-2,1
        if(valid(str[0]+1,str[1]-'0'+2)) cnt++;///1,2
        if(valid(str[0]+2,str[1]-'0'-1)) cnt++;///2,-1
        if(valid(str[0]+2,str[1]-'0'+1)) cnt++;///2,1

        cout <<cnt<<endl;

    }

    return 0;
}
