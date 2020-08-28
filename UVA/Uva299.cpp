#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    int i,j,n,T,length,input,count;

    cin>>T;
    for(i=0;i<T;i++){
        count=0;
        cin>>length;
        for(j=0;j<length;j++){
            cin>>input;
            v.push_back(input);
        }
        for(j=0;j<length-1;j++){
            for(int k=j+1;k<length;k++){
                if(v[j]>v[k]) count++;
            }
        }
        cout<< "Optimal train swapping takes "<<count<< " swaps."<<endl;
        v.clear();
    }

    return 0;
}
