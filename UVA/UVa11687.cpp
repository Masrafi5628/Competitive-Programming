#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    char str[1000005];

    while(scanf("%s",str)){
        if(!strcmp(str, "END")) break;

        n=atoll(str);

        int cnt=0,a=n,b,i=1;
        if(!n) cnt=1;
        while(n != 0){
            cnt++;
            n/=10;
        }
        b=cnt;
        while(a != b){
            cnt=0;
            a=b;
            n=b;

            while(n!=0){
                cnt++;
                n/=10;
            }
            b=cnt;
            i++;
        }
        cout<<i<<endl;
    }

    return 0;
}


