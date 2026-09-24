#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define EACH(x, a) for (auto& x: a)

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {string t; read(t); d=stod(t);}
void read(long double& d) {string t; read(t); d=stold(t);}
template<class H, class... T> void read(H& h, T&... t) {read(h); read(t...);}
template<class A> void read(vt<A>& x) {EACH(a, x) read(a);}
template<class A, size_t S> void read(array<A, S>& x) {EACH(a, x) read(a);}
string to_string(char c) {return string(1, c);}
string to_string(bool b) {return b? "true":"false";}
string to_string(const char* s) {return string(s);}
string to_string(string s) {return s;}
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) {write(h); write(t...);}
void print() { write("\n"); }
template<class H, class... T> void print(const H& h, const T&... t) {write(h); if(sizeof...(t)) write(' '); print(t...);}
const int mod=1e9+7;
const int mxn=2e6+5;
long long fac[mxn],ifac[mxn];
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
void precompute(){
  fac[0]=1;
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long A(long long n,long long k,long long m=mod){
  if (k<0||n<0||k>n) return 0;
  return fac[n]*ifac[k]%m*ifac[n-k]%m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  precompute();
  ll m,n; read(m,n);
  vt<ll> a(n);
  read(a);
  ll sum=0;
  EACH(x,a) sum+=x;
  if(m<sum){print(0); return 0;}
  print(A(m-sum+n-1,n-1));
}
