#include <bits/stdc++.h>

using namespace std;

const int inf = 111111;
int ara[111], lis[111];
int st, n;// maximum value er index

void lis_n_sq()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ara[i]<ara[j]){
                lis[j] = max(lis[j], 1+lis[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(lis[i]>ans){
            ans = lis[i];
            st = i;
        }
    }
    printf("length is %d\n", ans);
}

void nlogk()
{
    vector<int>insrt(n+1, inf);
    insrt[0] = -inf;

    for(int i=1; i<=n; i++){
        insrt[i] = inf;
    }

    for(int i=0; i<n; i++){
        lis[i] = lower_bound(insrt.begin(), 
            insrt.end(), ara[i])-insrt.begin();
        insrt[lis[i]] = ara[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(lis[i] > ans){
            ans = lis[i];
            st = i;
        }
    }
    printf("%d\n", ans);
}

void lds()
{
    for(int i=0; i*2<n; i++){
        swap(ara[i], ara[n-i-1]);
    }
    nlogk();

}

void find_seq()
{
    vector<int>seq;

    seq.push_back(ara[st]);

    for(int i=st-1; i>=0; i--){
        if(lis[i]+1==lis[st] && ara[i]<ara[st]){
            seq.push_back(ara[i]);
            st = i;
        }
    }
    printf("Sequence is \n");
    for(int i=seq.size()-1; i>=0; i--){
        printf("%d ", seq[i]);
    }
    printf("\n");

    /*for(auto it = seq.begin(); it!=seq.end(); it++){
        printf("%d ", *it);
    }
    printf("\n");*/
}

int main()
{

    cin>>n;
    for(int i=0; i<n ; i++){
        cin>>ara[i];
        lis[i] = 1;
    }

    //lis_n_sq();
    printf("len of lis is ");
    nlogk();
    find_seq();
    printf("len of lds is ");
    lds();
    //find_seq();*/

    return 0;
}