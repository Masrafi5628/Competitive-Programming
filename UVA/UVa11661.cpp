#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[2000005];
    int L;

    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);

    while(scanf("%d",&L), L && 1){
        cin>>str;
        int ans= INT_MAX;

        vector<int> D,R;

        for(int i=0;i<L;i++){
            if(str[i]=='D') D.push_back(i+1);
            else if(str[i]=='R') R.push_back(i+1);
            else if(str[i]=='Z') {
                ans = 0;
                break;
            }
        }
        if(ans != 0){
            for(int j=0;j<D.size();j++){
                for(int k=0;k<R.size();k++){
                    ans = min(ans,abs(D[j]-R[k]));
                }

            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
