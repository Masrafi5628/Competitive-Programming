#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str1[30];
    char str2[30];

    while(gets(str1)){

        gets(str2);

        int sum1=0,sum2=0;

        for(int i=0;i<strlen(str1);i++){
            if(isupper(str1[i])) sum1+=str1[i]- 'A'+1;
            else if(islower(str1[i])) sum1+=str1[i]- 'a'+1;
        }

        for(int j=0;j<strlen(str2);j++){
            if(isupper(str2[j])) sum2+=str2[j]- 'A'+1;
            else if(islower(str2[j])) sum2+=str2[j]- 'a'+1;
        }

        int cnt1=0,cnt2=0;

        while(1){
            if(cnt1>9 && sum1==0){
                sum1=cnt1;
                cnt1=0;
            }
            if(cnt1<10 && sum1==0) break;

            cnt1+=sum1%10;
            sum1/=10;
        }
        while(1){
            if(cnt2>9 && sum2==0){
                sum2=cnt2;
                cnt2=0;
            }
            if(cnt2<10 && sum2==0) break;

            cnt2+=sum2%10;
            sum2/=10;
        }
        double ans;
        if(cnt1>cnt2){
            ans=(cnt2*100*1.0)/(cnt1*1.0);
        }else {
            ans=(cnt1*100*1.0)/(cnt2*1.0);
        }

        printf("%.2f %%\n",ans);
    }

    return 0;
}


