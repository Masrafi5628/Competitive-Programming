#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    int a[100],n,top,area=0,max_area=0,i=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(i<n){
        if(s.empty() || a[s.top()]<=a[i]){
            s.push(i++);
        }
        else {
            top=s.top();
            s.pop();

            if(s.empty()){
                area=a[top]*i;

            }
            else {
                area=a[top]*(i-s.top()-1);
            }
            if(area>max_area) max_area=area;

        }

    }
    while(!s.empty()){
        top=s.top();
        s.pop();

        if(s.empty()){
            area=a[top]*i;
        }
        else {
            area=a[top]*(i-s.top()-1);
        }
        if(area>max_area) max_area=area;
    }
    cout << "Maximum area of histogram rectangle is "<<max_area<<endl;

    return 0;
}
