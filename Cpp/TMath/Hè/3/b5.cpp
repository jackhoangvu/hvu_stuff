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
struct bn{
  ll c,t;
};
bool cmp(const bn& a,const bn& b){
  if(a.c!=b.c) return a.c<b.c;
  return a.t<b.t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll s; int n; read(s,n);
  vt<bn> a(n);
  for (int i=0; i<n; i++){
    read(a[i].c,a[i].t);
  }
  sort(all(a),cmp);
  long long cnt=0;
  for(auto p:a){
    if(s<=0) break;
    ll buy=min(p.t,s/p.c);
    cnt+=buy;
    s-=buy*p.c;
  }
  cout<<cnt<<"\n";
}
