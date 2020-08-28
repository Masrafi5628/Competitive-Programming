#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    string st;
    while(cin>>st){
        long long x=0,cnt=0,arr[]={1,0,0};
        for(int a=0;a<st.length();a++){
            if(!isdigit(st[a])){
                x=0;
                arr[0]=1;
                arr[1]=arr[2]=0;
            }
            else {
                x=(x+st[a]-'0')%3;
                cnt+=arr[x];
                arr[x]++;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
