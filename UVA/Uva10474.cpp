#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    vector <int> v;
    vector <int> :: iterator it;
    int n,q,input,t=0,q1,ck;
    while(1){
        scanf("%d%d",&n,&q);
        t++;
        ck=1;
        if(n==0 && q==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>input;
            v.push_back(input);
        }
        sort(v.begin(),v.end());
        for(int j=0;j<q;j++){
            cin>>q1;
            it=(find(v.begin(),v.end(),q1));
            if(ck) {
                cout << "CASE# "<<t<<':'<<endl;
                ck=0;
            }
            if(it!=v.end()){
                 cout<<q1<< " found at "<<it-v.begin()+1<<endl;
            }
            else{
                cout<< q1<<" not found"<<endl;
            }

        }
        v.clear();
    }

    return 0;
}
