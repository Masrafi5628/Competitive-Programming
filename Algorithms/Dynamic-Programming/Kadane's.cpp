#include <bits/stdc++.h>

using namespace std;

long long max_subarray_sum(vector<long long> &v)
{
    long long max_so_far=INT_MIN,max_ending_here=0;

    for(int i=0;i<v.size();i++){

        max_ending_here+=v[i];
        if(max_ending_here>max_so_far)
            max_so_far=max_ending_here;
        if(max_ending_here<0)
            max_ending_here=0;
    }
    return max_so_far;
}

int main()
{
    int n;
    long long sum=0;
    cin>>n;
    vector <long long> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i],sum+=v[i];
    long long ans=max_subarray_sum(v);

    cout << 2*ans-sum<<endl;


    return 0;
}
