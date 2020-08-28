#include <bits/stdc++.h>

using namespace std;

bool arepair(char opening,char closing)
{
    if(opening=='(' && closing==')') return true;
    else if(opening=='{' && closing=='}') return true;
    else if(opening=='[' && closing==']') return true;
    else return false;
}

int main()
{
    stack<char> s;
    char str[2000];
    char ch;
    int n;

    freopen("input.txt","r",stdin);
    freopen("output.txt", "w",stdout);

    scanf("%d",&n);
    scanf("%c",&ch);
    for(int i=0;i<n;i++){
        bool ck=true;


        gets(str);

        for(int i=0;i<strlen(str);i++){
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                s.push(str[i]);
            }
            else {
                if(s.empty() || !arepair(s.top(),str[i])){
                    printf("No\n");
                    ck=false;
                }
                else {
                    s.pop();
                }
            }
            if(!ck) break;
        }
        if(ck){
            if(s.empty()) printf("Yes\n");
            else {
                 printf("No\n");
            }
        }
        while(!s.empty()){
            s.pop();
        }
    }

    return 0;
}
