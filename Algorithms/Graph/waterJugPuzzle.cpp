#include <bits/stdc++.h>

using namespace std;

// fromCap -> from which water is poured
// toCap -> to which water is poured

int pour(int fromCap,int toCap,int d)
{
    int from = fromCap;
    int to = 0;

    int step=1;

    while(from !=d && to !=d){

        int temp = min(from,toCap-to);/*Find the maximum amount
                                        that can be poured*/
        to += temp;
        from -= temp;

        step++;

        printf("Jug1 %d Jug2 %d\n",from,to);

        if(from == d || to == d){
            break;
        }
        if(from == 0){
            from = fromCap;
            step++;
        }
        if(to == toCap){
            to=0;
            step++;
        }
    }
    cout << "\n\n";
    return step;
}

int minSteps(int m,int n,int d)
{
    //if(m>n) swap(m,n);
    //if(d>n) return -1;
    if((d%(__gcd(m,n)))!=0) return -1;

    return min(pour(n,m,d),pour(m,n,d));
}

int main()
{
    int m,n,d;

    cin>>m>>n>>d;

    printf("Minimum number of steps : %d\n",minSteps(m,n,d));

    return 0;
}
