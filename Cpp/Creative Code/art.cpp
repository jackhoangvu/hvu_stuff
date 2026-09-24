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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n; read(n);
  vt<ll> a(n+1),b(n+1);
  vt<int> id(n);
  for(int i=1; i<=n; i++){
    read(a[i],b[i]);
  }
  vt<pair<ll,ll>> v(n);
  for(int i=1; i<=n; i++){
    v[i-1]={a[i],b[i]};
  }
  sort(v.begin(),v.end());
  vt<ll> A(n+1),B(n+1),P(n+1);
  for(int i=1; i<=n; i++){
    A[i]=v[i-1].first;
    B[i]=v[i-1].second;
  }
  for(int i=1; i<=n; i++){
    P[i]=P[i-1]+max(B[i],0LL);
  }
  ll ans=LLONG_MIN;
  ll mx=LLONG_MIN;
  for(int i=1; i<=n; i++){
    ans=max(ans,B[i]);
    if(i>=2){
      ll Y=B[i]+P[i-1]-A[i];
      ans=max(ans,Y+mx);
    }
    ll X=B[i]-P[i]+A[i];
    mx=max(mx,X);
  }
  write(ans,"\n");
}
