#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool ispali(char *s,int l,int r)
{
    return (l>=r)||(s[l]==s[r] && ispali(s,l+1,r-1));
}
int main()
{
    char str[100];
    scanf("%s",str);

    if(ispali(str,0,strlen(str)-1))
        cout <<str<< " is palindrome"<<endl;
    else
        cout <<str << " is not palindrome"<<endl;

    return 0;
}
