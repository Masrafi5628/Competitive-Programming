#include <iostream>
#include <vector>

using namespace std;
#define max 105

int main()
{
    long long int i,j,n,input,count1,count2;

    while((scanf("%lld",&n))!=EOF){
        count1=count2=0;
        vector <int> ara(max,0);
        if(n==0) return 0;
        for(i=0;i<n;i++){
            cin>>input;
            ara[input]++;
        }
        for(i=0;i<max;i++){
            for(j=0;j<ara[i];j++){
                cout <<i;
                count2++;

                if(n!=count2) cout<< " ";
            }

        }
        cout <<endl;
        ara.clear();

    }

    return 0;
}
