#include <iostream>

using namespace std;
int queen[20],column[20],diagonal1[20],diagonal2[20];

void nqueen(int at,int n)
{
    int i;
    if(at==n+1){
        printf("(Row Column) = ");
        for(i=1;i<=n;i++) {
            printf(" (%2d %d) ",i,queen[i]);
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(column[i]||diagonal1[i+at]||diagonal2[n+i-at]) continue;
        queen[at]=i;

        column[i]=diagonal1[i+at]=diagonal2[n+i-at]=1;
        nqueen(at+1,n);
        column[i]=diagonal1[i+at]=diagonal2[n+i-at]=0;
    }
}
int main()
{
    nqueen(1,10);

    return 0;
}
