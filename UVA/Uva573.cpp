#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,u,d,f,cnt;
    double per;

    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w",stdout);

    while(scanf("%d%d%d%d",&h,&u,&d,&f)){
        if(!h) break;

        double init=0.0,Dist=0.0,Height_D=0,Height_N=0;

        per = (f*u*1.0/100);

        for(int i=0;;i++){
            init=Height_N;
            if(!i){
                Dist=u,Height_D+=init+Dist;
            }else {
                Dist-=per;
                if(Dist>0.0)
                    Height_D=init+Dist;
                else
                    Height_D=init;

            }
            Height_N=Height_D-d;

            if(Height_D>(h*1.0)){
                printf("success on day %d\n",i+1);
                break;
            }
            if(Height_N<0.0) {
                printf("failure on day %d\n",i+1);
                break;
            }
        }


    }

    return 0;
}
/*printf("init %f Dist %f He_D %f He_S %f\n",init,Dist,He_D,He_S);
for(int i=0;;i++){

            init = He_S;
            if(!i) {
                init+=Dist,Dist+=(u*1.0),He_D+=init+Dist;
            }
            else {
                Dist-=per;
                //if(Dist<0) Dist=init;
                He_D=init+Dist;
            }
            He_S=He_D-(d*1.0);


            printf("init %f Dist %f He_D %f He_S %f\n",init,Dist,He_D,He_S);

            if(He_D>(h*1.0)){
                printf("success on day %d\n",i+1);
                break;
            }
            if(He_S<0){
                printf("failure on day %d\n",i+1);
                break;
            }

        }*/
