#include <bits/stdc++.h>

using namespace std;

struct Man{
    char name[100];
    double price;
    int met;
};

bool cmp(Man a,Man b)
{
    if(a.met != b.met)
        return a.met>b.met;
    if(a.price != b.price)
        return a.price<b.price;
}

int main()
{
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w",stdout);

    int kase = 1;

    char str[100][100];
    char temp[100][100];

    int n,p,ck=0;
    while(scanf("%d%d",&n,&p), n && p){
        if(ck) printf("\n");

        for(int i=0;i<n;i++){
            scanf(" %[^\n]",str[i]);
        }
        Man ara[100];
        for(int j=0;j<p;j++){

            scanf(" %[^\n]",ara[j].name);
            cin>>ara[j].price>>ara[j].met;

            for(int k=0;k<ara[j].met;k++){
                scanf(" %[^\n]",temp[k]);
            }
        }
        stable_sort(ara,ara+p,cmp);

        printf("RFP #%d\n",kase++);
        printf("%s\n",ara[0].name);

        ck++;
    }

    return 0;
}


