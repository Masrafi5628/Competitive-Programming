#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int T,i,j,n,k;
    cin>>T;
    for(i=0;i<T;i++){
        cin>>k;
        n=(-1+sqrt(8*k-7))/2;
        if((n*(n+1))/2==k-1) cout <<"1 ";
        else cout << "0 ";
    }
    cout <<endl;

    return 0;
}
