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
  int n; read(n);
  vt<ll> a(n+1);
  for(int i=1; i<=n; i++){
    read(a[i]);
  }
  if(a[1]==0){
    for(int i=1; i<=n; i++){
      if(a[i]!=0){
        print("NO");
        return 0;
      }
    }
    print("YES");
    return 0;
  }
  if(a[1]!=1){
    print("NO");
    return 0;
  }
  vt<bool> pr(n+1,true);
  if(n>=0) pr[0]=false;
  if(n>=1) pr[1]=false;
  for(int i=2; i*i<=n; i++){
    if(pr[i]){
      for(int j=i*i; j<=n; j+=i) pr[j]=false;
    }
  }
  for(int p=2; p<=n; p++){
    if(pr[p])
      for(int i=1; i*p<=n; i++){
        if(a[i*p]!=a[i]*a[p]){
          print("NO");
          return 0;
      }
    }
  }
  print("YES");
}
