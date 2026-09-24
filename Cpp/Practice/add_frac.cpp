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
struct ps{
  long long tu,mau;
};
void rutgon(ps &x){
  if(x.mau<0){
    x.mau=-x.mau;
    x.tu=-x.tu;
  }
  long long tam=gcd(x.tu,x.mau);
  x.tu/=tam,x.mau/=tam;
}
ps cong(ps x,ps y){
  ps t;
  t.mau=x.mau*y.mau;
  t.tu=x.tu*y.mau+x.mau*y.tu;
  rutgon(t);
  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ps a,b; read(a.tu,a.mau,b.tu,b.mau);
  print(cong(a,b).tu,cong(a,b).mau);
}
