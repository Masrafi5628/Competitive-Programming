#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

int matRow = 2;
int matCol = 2;

struct matrix
{
	ll mat[15][15];
	matrix(int type) {
		memset(mat, 0, sizeof mat);
		if(type==1) {// Identity matrix
			for(int i=0; i<matRow; i++)
				mat[i][i] = 1;
		}
		else if(type == 2){// Fibonacci matrix
			mat[0][0] = mat[0][1] = mat[1][0] = 1;
		}
	}
};

matrix matMul(matrix a, matrix b)
{
	matrix ans = matrix(0);
	for(int row=0; row<matRow; row++){
		for(int col=0; col<matCol; col++){
			for(int k=0; k<matCol; k++){
				ans.mat[row][col] += 
				(a.mat[row][k]*b.mat[k][col])%mod; 
			}
		}
	}
	return ans;
}

matrix matBigMOD(matrix a, ll b)
{
	if(b==0) return matrix(1);
	if(b%2) return matMul(matBigMOD(a, b-1), a);
	matrix ans = matBigMOD(a, b/2);
	return matMul(ans, ans);
}

int main()
{
	// First n-th fibonacci number with mod
	int n = 100;
	for(int i=1; i<=n; i++) {
		//ll i = 1e18;
		matrix ans = matBigMOD(matrix(2), (ll)i-1);
		printf("%lld-->%lld\n", (ll)i, ans.mat[0][0]);
	}
	

	return 0;
}