#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i,j,T,n,input;
    bool ck;
    vector <int> v;

    cin>>T;
    for(i=1;i<=T;i++){
        ck=true;
        cin>>n;
        for(j=0;j<n;j++){
            cin>>input;
            v.push_back(input);
        }
        sort(v.rbegin(),v.rend());

        for(j=0;j<n-1;j++){
            if(v[j]==v[j+1]){
                cout << "NO"<<endl;
                ck=false;
                break;
            }
        }
        if(ck)cout << "YES"<<endl;
        v.clear();

    }

    return 0;
}
