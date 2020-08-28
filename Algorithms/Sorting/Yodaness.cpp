#include <bits/stdc++.h>

using namespace std;

vector<string>yoda;
map<string, int>normal;
long long cnt=0;

void merge(int left, int mid, int right)
{
    int i=left, j=mid+1;
    vector<string>temp;

    while(i<=mid && j<=right){
        if(normal[yoda[i]] <= normal[yoda[j]]){
            temp.push_back(yoda[i++]);
        } else {
            cnt += mid - i +1;
            temp.push_back(yoda[j++]);
        }
    }
    for(; i<=mid; i++){
        temp.push_back(yoda[i]);
    }
    for(; j<=right; j++){
        temp.push_back(yoda[j]);
    }
    //cout<<cnt<<endl;
    for(int k=0; k<temp.size(); k++){
        yoda[left++] = temp[k];
        //cout<<temp[k] << ' ';
    }
    //cout<<endl;
    
}

void mergeSort(int left, int right)
{
    if(left != right){
        int mid = left + (right-left)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

int main()
{
    int t, n;
    string str;

    cin>>t;

    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>str;
            yoda.push_back(str);
        }
        for(int i=1; i<=n ; i++){
            cin>>str;
            normal.insert(make_pair(str, i));
        }
        mergeSort(0, n-1);
        cout<<cnt<<endl;
        yoda.clear();
        normal.clear();
        cnt =0;
    }

    return 0;
}