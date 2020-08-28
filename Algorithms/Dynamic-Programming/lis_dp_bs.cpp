#include <bits/stdc++.h>

using namespace std;

int lis_dp_bs(vector<int> const& a)
{
    int n = a.size();
    const int inf = 1e9;

    vector<int>d(n+1,inf),p(n+1,-1);// this is important for binary search
    d[0]=-inf;

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){ /* here we use binary search to reduce time complexity
                                j = upper_bound(d.begin(),d.end(),a[i])-d.begin()*/
            if(d[j-1]<a[i] && a[i]<d[j])
            {
                d[j]=a[i];
                p[i]=j;// ?seq vul ase
            }
        }
    }
    int len = 0,pos=0;
    for(int i=0;i<n;i++){
        if(p[i]>len) len = p[i],pos=i;
    }

    vector<int>subseq;
    subseq.push_back(a[pos]);

    for(int i=pos-1;i>=0;i--){
        if(a[i]<a[pos] && p[i]+1 == p[pos]){
            subseq.push_back(a[i]);
            pos=i;
        }
    }
    reverse(subseq.begin(),subseq.end());
    cout<<len<<endl;
    for(int i=0;i<len;i++)
        cout<<subseq[i]<< ' ';
    cout<<endl;

}

int main()
{
    int n;
    cin>>n;

    vector<int>ara(n);

    for(int i=0;i<n;i++)
        cin>>ara[i];

    lis_dp_bs(ara);


    return 0;
}
