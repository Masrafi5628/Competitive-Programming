#include <bits/stdc++.h>

using namespace std;

const int station=5,line=2;

int entry_cost[]={2,4},exit_cost[]={3,6};
int station_cost[][station]={{7,9,3,4,8},{8,5,6,4,5}};
int transfer_cost[][station]={{0,2,3,1,3},{0,2,1,2,2}};
int l1[2][station];

void Optimal_path(int ll)
{
    int i=ll;
    cout << "Line "<<i<< " Station "<<station<<endl;
    for(int j=station-1;j>=1;j--){
        if(i%2==0) i=l1[1][j];
        else i=l1[0][j];
        cout << "Line "<<i<< " Station "<<j<<endl;
    }
}

void Factory_Assembly()
{
    int t1[station],t2[station],i;

    t1[0]=entry_cost[0]+station_cost[0][0];
    t2[0]=entry_cost[1]+station_cost[1][0];

    for(i=1;i<station;i++){
        if((t1[i-1]+station_cost[0][i]<=t2[i-1]+transfer_cost[1][i]+station_cost[0][i])){
            t1[i]=t1[i-1]+station_cost[0][i];
            l1[0][i]=1;
        }
        else {
            t1[i]=t2[i-1]+transfer_cost[1][i]+station_cost[0][i];
            l1[0][i]=2;
        }
        if((t2[i-1]+station_cost[1][i]<=t1[i-1]+transfer_cost[0][i]+station_cost[1][i])){
            t2[i]=t2[i-1]+station_cost[1][i];
            l1[1][i]=2;
        }
        else {
            t2[i]=t1[i-1]+transfer_cost[0][i]+station_cost[1][i];
            l1[1][i]=1;
        }
    }

    int ans,ll;

    if((t1[station-1]+exit_cost[0]<=t2[station-1]+exit_cost[1])) {
        ans = t1[station-1]+exit_cost[0];
        ll=1;
    }else {
        ans = t2[station-1]+exit_cost[1];
        ll=2;
    }
    cout << "Minimum cost is : "<<ans<<endl;

    Optimal_path(ll);
}

int main()
{
    Factory_Assembly();

    return 0;
}
