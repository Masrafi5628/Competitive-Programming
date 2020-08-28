#include <bits/stdc++.h>

using namespace std;

int dx[]={2,-2,2,-2,1,-1,1,-1};
int dy[]={1,1,-1,-1,2,2,-2,-2};

int valid(int x,int y)
{
    return x>=1 && y>=1 && x<=8 && y<=8;
}

int main()
{
    int n;
    char s[3];

    cin>>n;
    while(n--){
        int cnt=0;
        cin>>s;

        int x = s[0]-'a'+1;
        int y = s[1]-'0';

        for(int i=0;i<8;i++){
            cnt+=valid(x+dx[i],y+dy[i]);
        }
        cout <<cnt<<endl;
    }

    return 0;
}
