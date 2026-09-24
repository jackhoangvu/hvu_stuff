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
const int mxn=1e5+5;
bool p[mxn];
vt<int> pr;
void sang(int mx=mxn){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(int i=2; i*i<=mx; i++){
    for(int j=i*i; j<=mx; j+=i){
      p[j]=false;
    }
  }
  for (int i=3; i<mx; i++){
    if(p[i]) pr.pb(i);
  }
}
void solve(ll n){
  if(n<38) {print("No"); return;}
  n-=4;
  //a^2+b^2=n
  bool ok=false;
  EACH(b,pr){
    ll b2=(ll)b*b;
    ll c=round(sqrt(n-b2));
    if(c*c==(n-b2)&&p[c]&&c!=b) {ok=true; break;}
  }
  if(ok) print("Yes");
  else print("No");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sang();
  int t; read(t);
  while(t--){
    ll n; read(n);
    solve(n);
  }
}
