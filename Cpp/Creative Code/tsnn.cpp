#include<bits/stdc++.h>
#include<numeric>
using namespace std;
using ll=long long;
using i128=__int128_t;
ll mul(ll a,ll b,ll mod){
  return(i128)a*b%mod;
}
ll pw(ll a,ll d,ll mod){
  ll r=1;
  while(d){
    if(d&1)
      r=mul(r,a,mod);
    a=mul(a,a,mod);
    d>>=1;
  }
  return r;
}
bool isPrime(ll n){
  if(n<2)
    return false;
  for(ll p:{2,3,5,7,11,13,17,19,23,29}){
    if(n==p)
      return true;
    if(n%p==0)
      return n==p;
  }
  ll d=n-1,s=0;
  while(!(d&1))
    d>>=1,s++;
  for(ll a:{2,325,9375,28178,450775,9780504,1795265022}){
    if(a%n==0)
      continue;
    ll x=pw(a,d,n);
    if(x==1||x==n-1)
      continue;
    bool comp=true;
    for(int i=1; i<s; i++){
      x=mul(x,x,n);
      if(x==n-1){
        comp=false;
        break;
      }
    }
    if(comp) return false;
  }
  return true;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll pollard(ll n){
  if(n%2==0)
    return 2;
  ll c=uniform_int_distribution<ll>(1,n-1)(rng);
  ll x=uniform_int_distribution<ll>(0,n-1)(rng);
  ll y=x;
  auto f=[&](ll x){
    return(mul(x,x,n)+c)%n;
  };
  while(true){
    x=f(x);
    y=f(f(y));
    ll d=std::gcd(llabs(x-y),n);
    if(d==1)
      continue;
    if(d==n)
      return pollard(n);
    return d;
  }
}
void factor(ll n,map<ll,int>&mp){
  if(n==1)
    return;
  if(isPrime(n)){
    mp[n]++;
    return;
  }
  ll d=pollard(n);
  factor(d,mp);
  factor(n/d,mp);
}
ll solve(ll x){
  map<ll,int>mp;
  factor(x,mp);
  ll y=1;
  for(auto&p:mp)
    if(p.second&1)
    y*=p.first;
  return y;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  while(n--){
    ll x;
    cin>>x;
    cout<<solve(x)<<'\n';
  }
  return 0;
}
