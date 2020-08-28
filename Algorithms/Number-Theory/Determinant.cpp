#include<bits/stdc++.h>
#include <cmath>

using namespace std;

int determinant(int mat[10][10],int col)
{
    int det=0,sub[10][10];

    if(col==2){
        return (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
    }
    else {
        for(int x=0;x<col;x++){
            int subi=0;
            for(int i=1;i<col;i++){
                int subj=0;
                for(int j=0;j<col;j++){
                    if(j==x) continue;
                    sub[subi][subj]=mat[i][j];
                    subj++;
                }
                subi++;
            }
            det=det+(pow(-1,x)*mat[0][x]*determinant(sub,col-1));
            printf("%d\n",det);
        }
    }
    return det;
}

int main()
{
    int mat[10][10],row,col;
    cin>>row>>col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>mat[i][j];
        }
    }
    cout << determinant(mat,col)<<endl;

    return 0;
}

