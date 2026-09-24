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
int n,m;
vector<ll> a,b;
bool check(ll mid){
  int j=m-1;
  for(int i=n-1; i>=0; i--){
    if(a[i]>=mid) continue;
    while(j>=0&&a[i]+b[j]<mid) j--;
    if(j<0) return false;
    j--;
  }
  return true;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("B3.INP","r",stdin);
  freopen("B3.OUT","w",stdout);
  cin>>n>>m;
  a.resize(n);
  b.resize(m);
  read(a);
  read(b);
  ll maxA=*max_element(all(a));
  ll maxB=*max_element(all(b));
  ll lo=0,hi=maxA+maxB;
  ll ans=0;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(check(mid)){
      ans=mid;
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  print(ans);
  return 0;
}
