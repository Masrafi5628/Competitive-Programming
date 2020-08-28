#include <bits/stdc++.h>

using namespace std;

int pow(int b,int p)
{
    int m=1;
    for(int i=0;i<p;i++)
        m*=b;
    return m;
}

int digitsum(int i)
{
    int sum = 0;
    while(i>0){
        sum += i%10;
        i /= 10;
    }
    return sum;
}

int main()
{
    int n,mem[50];
    memset(mem,0,sizeof(mem));
    cin>>n;

    for(int i=0;i<pow(10,n/2);i++){
        int s = digitsum(i);
        mem[s]++;
    }
    int ans = 0;

    for(int i=0;i<pow(10,n/2);i++){
        int s = digitsum(i);
        ans += mem[s];
    }

    cout <<ans<<endl;

    return 0;
}
