#include <bits/stdc++.h>

using namespace std;

int Area(int *A,int n,int m)
{
    int i=0,area=0;
    static int max_area=0;
    stack<int>s;
    while(i<n || i<m){
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i++);
        else {
            int top=s.top();
            s.pop();

            if(s.empty()){
                area=A[top]*i;
            }
            else {
                area=A[top]*(i-s.top()-1);
            }
            if(area>max_area) max_area=area;
        }
    }
    while(!s.empty()){
        int top=s.top();
        s.pop();

        if(s.empty()){
            area=A[top]*i;
        }
        else {
            area=A[top]*(i-s.top()-1);
        }
        if(area>max_area) max_area=area;

    }
    return max_area;
}

int main()
{
    int n,m,ara[100][100],a[100],area;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ara[i][j];
            if(!i) a[j]=ara[i][j];
            else {
                if(ara[i][j]==0) a[j]=0;
                else a[j]+=ara[i][j];
            }
        }
        /*for(int k=0;k<m;k++){
            cout << a[k]<< " ";
        }
        cout <<endl;*/

        area=Area(a,n,m);
    }
    cout <<area<<endl;


    return 0;
}
