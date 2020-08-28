#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> const& a)
{
    int n =a.size();
    const int inf = 1e9+5;

    vector<int> d(n+1, inf),p(n,-1);
    d[0]=-inf;

    for(int i=0;i<n;i++){
        int j = upper_bound(d.begin(),d.end(),a[i])-d.begin();

        if(d[j-1]<a[i] && a[i]<d[j]){
            d[j]=a[i];
            p[i]=j;
        }
    }
    int len=0,pos=0;
    for(int i=0;i<n;i++){
        cout<<p[i]<< ' ';
        if(p[i]>len){
            len=p[i];
            pos=i;
        }
    }
    cout<<endl;

    vector<int>subseq;

    for(int i=pos-1;i>=0;i--){
        if(a[i]+1==a[pos] && p[i]+1 == p[pos]){
            subseq.push_back(pos);
            pos=i;
            if(!pos) subseq.push_back(0);
        }
        if(subseq.empty()) pos=i;
    }

    int sz=subseq.size();
    cout<<sz<<endl;
    for(int i=sz-1;i>=0;i--)
        cout<< subseq[i]+1<< ' ';
    cout<<endl;
}

int main()
{
    int n;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
}
