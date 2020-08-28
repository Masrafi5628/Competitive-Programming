#include <bits/stdc++.h>

using namespace std;

bool arepair(char open,char close)
{
    if(open=='(' and close ==')') return true;
    if(open=='[' and close ==']') return true;
    return false;
}

int main()
{
    int n;
    string str;
    stack<char> s;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w",stdout);

    cin>>n;
    while(n--){
        getline(str);
        for(int i=0;i<str.length();i++){
            if(str[i]=='(' || str[i]=='[') s.push(str[i]);
            else {
                if(!s.empty() && arepair(s.top(),str[i])) s.pop();
                else s.push(str[i]);

            }
        }
        if(s.empty()) cout << "Yes\n";
        else cout<< "No\n";
        while(!s.empty()) s.pop();
    }

    return 0;
}
