#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int d,x,y;

const int mod = 1e9+9;

void extendedEuclid(int a,int b)
{
    if(b==0) {
        d=a,x=1,y=0;
    }else {
        extendedEuclid(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}

int binaryExponentiation(int x,int n)
{
    if(n==0) return 1;
    else if(n%2==0)
        return binaryExponentiation(x*x,n/2);
    return x*binaryExponentiation(x*x,(n-1)/2);
}

ll modularExponentiation(ll a, ll b)
{
    if(!b) return 1;
    if(b == 1) return a;
    if(b%2) return ((a%mod)*(modularExponentiation((a*a)%mod, (b-1)/2))%mod)%mod;
    return modularExponentiation((a*a)%mod, b/2)%mod;
}
//if m is prime
int modularInverse(int a,int m)
{
    return modularExponentiation(a,m-2);
}

int modInv(int a,int m)
{
    extendedEuclid(a,m);
    return (x%m+m)%m;
}

int main()
{
    printf("Mod %lld\n", modularExponentiation(257,9));
    printf("3 to the power 5 is %d\n",binaryExponentiation(3,5));
    //printf("Modular inverse %d\n",modInv(5,17));

    printf("x = %d,y = %d,d = %d\n",x,y,d);

    return 0;
}
