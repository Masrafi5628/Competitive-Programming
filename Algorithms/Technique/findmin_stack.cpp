#include <bits/stdc++.h>

using namespace std;

void sliding_window_minimum(int *a,int n,int k)
{
    deque<pair<int,int> >window;

    for(int i=0;i<n;i++){

        while(!window.empty() && window.back().first>=a[i]){
            window.pop_back();
            i++;
        }
        window.push_back(make_pair(a[i],i));

        while(window.front().second <= i-k) {
            window.pop_front();
        }

        cout << window.front().first<<endl;
    }
}

int main()
{
    int n,k;
    int ara[100];

    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>ara[i];
    sliding_window_minimum(ara,n,k);


    return 0;
}
