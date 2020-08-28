#include <iostream>

using namespace std;
int num[20],n=5,k=3;
//int used[20];

void combination(int at,int last)
{
    if(at==k+1){
        for(int i=1;i<=k;i++)
            cout << num[i]<< ' ';
        cout<<endl;
        return;
    }
    for(int i=last+1;i<=n-k+at;i++)
    {
        num[at]=i;
        combination(at+1,i);
    }
}

int main()
{
    combination(1,0);

    return 0;
}
