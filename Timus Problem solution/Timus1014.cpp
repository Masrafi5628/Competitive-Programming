#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    vector<int>v;
    cin>>N;

    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    if(N==0){
        cout<<10<<endl;
        return 0;
    }
    for(int i=9;i>1;i--){
        while(N%i==0){
            v.push_back(i);
            N/=i;
        }
    }
    if(N!=1) cout <<-1<<endl;
    else {
        for(int i=v.size()-1;i>=0;i--)
            cout <<v[i];
        cout <<endl;
    }
    return 0;
}
