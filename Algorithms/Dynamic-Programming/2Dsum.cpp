#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;

    long long ara[n+1][n+1];
    long long aux[n+1];
    

    int lft = 0, rgt = 0, mxLft, mxRgt, mxUp, mxDn;
    long long  cur_sum, maxSum = -999999;

    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin>>ara[i][j];
    	}
    }

    for(int k=0; k<n; k++) {
    	lft = k;
    	memset(aux, 0, sizeof aux);
	    for(int i=k; i<n; i++){
	    	
	    	rgt = i;
	    	for(int j=0; j<n; j++){
	    		aux[j] += ara[j][i];
	    	}
	    	cur_sum = 0;
	    	for(int j=0; j<n; j++){
	    		cur_sum = max(aux[j], aux[j]+cur_sum);

	    		if(cur_sum > maxSum) {
	    			maxSum = cur_sum;
	    		}
	    	}
	    }
	}
	cout<<maxSum<<endl;

    return 0;
}
