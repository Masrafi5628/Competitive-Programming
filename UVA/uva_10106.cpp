#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str1, str2;
	

	while(cin>>str1>>str2) {

		if(str1[0] == '0' || str2[0]=='0') {
			printf("0\n");
			continue;
		}

		int ara[500][500];
		memset(ara, 0, sizeof ara);

		int k=-1;

		int len1= str1.size(), len2 = str2.size();
		/*if(len2>len1) {
			swap(len2, len1);
			swap(str1, str2);
		}*/

		for(int i=len2-1; i>=0; i--){
			int a=str2[i]-'0', carry=0;
			int idx1= ++k, idx2 = len1+len2;

			for(int j= len1-1; j>=0; j--){
				int b = str1[j]-'0';
				int temp = (a*b)+carry;
				//printf("temp %d\n", temp);
				//printf("i %d j %d\n", idx1, idx2-(idx1+1));
				ara[idx1][idx2-(idx1+1)] = temp%10;
				carry = temp/10;
				idx2--;
			}
			if(carry>0){
				//printf("idx %d\n", idx2);
				ara[idx1][idx2-(idx1+1)] = carry;
			}
		}
		//stack<int>s;
		deque<int>dq;

		int carry=0;
		for(int i=len1+len2-1; i>=0; i--){
			int temp=0;
			for(int j=0; j<=len1+len2-1; j++){
				temp += ara[j][i];
			}
			dq.push_front((temp+carry)%10);
			carry = (temp+carry)/10;
		}
		if(carry>0){
			dq.push_front(carry);
		}

		auto it = dq.begin();
		while(*it == 0) {
			it++;
		}
		
		for(; it!=dq.end(); it++){
			printf("%d", *it);
		}

		printf("\n");
	}

	return 0;
}