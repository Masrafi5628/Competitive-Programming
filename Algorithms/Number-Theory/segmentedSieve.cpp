#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll>prime;

void sieve(ll r)
{
      ll lim = sqrt(r);
      vector<bool>isPrime(lim+1, true);
      isPrime[0] = isPrime[1] = false;

      for(int i=4; i<= lim+1; i+=2) isPrime[i] = false;

      for(ll i=3; i<=lim+1; i+=2){
        if(isPrime[i]) {
          for(ll j = i*i; j<=lim+1; j+=i){
            isPrime[j] = false; 
          }
        }
      }
      prime.push_back(2);
      for(int i=3; i<=lim+1; i+=2)
        if(isPrime[i]) prime.push_back(i);
    
}

void segment_sieve(ll l, ll r)
{
    vector<bool>rangePrime(r-l+100, true);
    //rangePrime[0]->l, [1]->l+1, .....
    for(int i=0; i<prime.size() && prime[i]*prime[i] <= r; i++){

        // range er modde 1st konta
        // prime[i] er multiple
        //printf("priem %lld\n", prime[i]);
        ll base = prime[i]*prime[i];

        if(base < l) base = ((l+prime[i]-1)/prime[i])*prime[i];

        //printf("base %lld\n", base);
        for(ll j=base; j<=r; j+=prime[i])
            rangePrime[j-l] = false;
    }
    if(l == 1) 
        rangePrime[0] = false;

    for(ll i=0; i<=r-l; i++){
        if(rangePrime[i]) {
            printf("%lld\n", i+l);
        }
    }
}

int main()
{
  long long  l, r;// Prime between l and r
  cin>>l>>r;

  sieve(r);
  segment_sieve(l, r);

  return 0;
}
