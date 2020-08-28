#include <bits/stdc++.h>
#include <cmath>

#define pi 3.14159

using namespace std;

double dist(double x1,double y1,double x2,double y2)
{
    double dx = (x1-x2);
    double dy = (y1-y2);

    return sqrt(dx*dx+dy*dy);
}

int main()
{
    int N;
    double r,a,b,ans=0;
    vector<pair<double,double> > v;

    cin>>N>>r;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for(int i=0;i<N;i++){
        if(i+1==N){
            ans+=dist(v[i].first,v[i].second,v[0].first,v[0].second);
        }
        if(i+1<N){
            ans+=dist(v[i].first,v[i].second,v[i+1].first,v[i+1].second);
        }
    }
    ans+=2*pi*r;

    printf("%.2f\n",ans);

    return 0;
}
