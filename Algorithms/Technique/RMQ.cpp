#include <bits/stdc++.h>

using namespace std;
vector <int> minwindow;

void slidingRMQ(int *a,int n,int k)
{
    deque<int> dq;
    int i;
    for(i=0;i<k;i++){
        while(!dq.empty() && a[i]<=a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    while(i<n){
        minwindow.push_back(a[dq.front()]);

        while(!dq.empty() && dq.front()<=i-k) dq.pop_front();

        while(!dq.empty() && a[i]<=a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        i++;
    }
    minwindow.push_back(a[dq.front()]);
}
int main()
{
    int ara[100],n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    slidingRMQ(ara,n,k);
    for(int i=0;i<minwindow.size();i++){
        cout <<minwindow[i]<< " ";
    }
    cout <<endl;

    return 0;
}
