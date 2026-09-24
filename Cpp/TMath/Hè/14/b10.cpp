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
// bool pr(long long n){
//   if(n<=1) return false;
//   for(int i=2; i*i<=n; i++){
//     if(n%i==0) return false;
//   }
//   return true;
// }
const int mxn=1e5+5;
bool p[mxn];
void sang(int mx=mxn){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(int i=2; i*i<=mx; i++){
    if(p[i]){
      for(int j=i*i; j<=mx; j+=i){
        p[j]=false;
      }
    }
  }
}
bool check(int x){
  if(!p[x]) return false;
  int x2=x;
  while(x2>0){
    if(!p[x2]) return false;
    x2/=10;
  }
  vt<int> v={1,3,7,9};
  EACH(m,v){
    if(p[x*10+m]) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sang();
  int n; read(n);
  vt<int> a(n);
  read(a);
  int m; read(m);
  vt<int> pref(n+3,0);
  for (int i=1; i<=n; i++){
    pref[i]=pref[i-1]+check(a[i]);
  }
  while(m--){
    int u,v; read(u,v);
    print(pref[v]-pref[u-1]);
  }
}
