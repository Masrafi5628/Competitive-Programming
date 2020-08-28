#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    /*freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);*/

    int i;
    set <string> s;
    set <string> :: iterator it;
    string str;

    while(getline(cin,str)){
        transform(str.begin(),str.end(),str.begin(), ::tolower);

        stringstream s1(str);

        string st,final="";

        while(s1>>st){
            for(i=0;st[i]!='\0';i++){
                if(st[i]>='a' && st[i]<='z') final+=st[i];

            }

        }
    }
    for(it=s.begin();it!=s.end();it++){
            cout<<*it<<endl;
    }


    return 0;
}
