#include <bits/stdc++.h>

using namespace std;

void lis_seq(vector<int> const &v)
{
    int n=v.size();
    vector<int>len(n,1),p(n,-1); // p store the sequence of index

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && len[i]<len[j]+1){
                len[i]=len[j]+1;
                p[i]=j;// length of i-th index found from adding 1 with j-th index
            }
        }
    }
    int ans=len[0],pos=0;

    for(int i=1;i<n;i++){
        cout<<len[i]<< ' ';
        if(len[i]>ans){
            ans = len[i];
            pos = i;// hold the index which have largest element of the sequence
        }
    }
    cout<<endl;
    vector<int>subseq;
    while(pos != -1){
        subseq.push_back(v[pos]);
        pos=p[pos];
    }

    reverse(subseq.begin(),subseq.end());
    for(int i=0;i<ans;i++)
        cout <<subseq[i]<< ' ';
    cout <<endl;
}

int main()
{
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    lis_seq(v);


    reverse(v.begin(), v.end());
    lis_seq(v);
    return 0;
}
