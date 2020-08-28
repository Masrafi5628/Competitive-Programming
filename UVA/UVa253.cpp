#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main()
{
    int ara[24][3]={{1,2,3},
                    {1,4,2},
                    {1,5,4},
                    {1,3,5},
                    {2,6,3},
                    {2,4,6},
                    {2,1,4},
                    {2,3,1},
                    {3,6,5},
                    {3,2,6},
                    {3,1,2},
                    {3,5,1},
                    {4,6,2},
                    {4,5,6},
                    {4,1,5},
                    {4,2,1},
                    {5,6,4},
                    {5,3,6},
                    {5,1,3},
                    {5,4,1},
                    {6,2,4},
                    {6,3,2},
                    {6,5,3},
                    {6,4,5}
    };
    char str[13];
    string str1;
    string str2;
    string temp;
    bool ck;

    while((scanf("%s",str))!=EOF){
        ck=true;
        str1="";
        str2="";
        for(int i=0;i<6;i++){
            str1+=str[i];
            str2+=str[i+6];
        }
        for(int j=0;j<24;j++){
            temp="";
            for(int k=0,l=1;k<6;k++){
                if(k<3) temp+=str[ara[j][k]-1];
                else {
                    temp+=str[6-ara[j][k-l]];
                    l+=2;
                }
            }
            if(temp==str2) {
                cout<< "TRUE\n";
                ck=false;
                break;
            }
        }
        if(ck) cout<< "FALSE\n";
    }


    return 0;
}
