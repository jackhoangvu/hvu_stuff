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
  int a,b; read(a,b);
  ll ans=a;
  ll mi=LLONG_MAX;
  ll l=a,r=b-1;
  while(l<=r){
    ll mid=l+(r-l)/2;
    ll a1=(a+mid)*(mid-a+1)/2;// l-> mid
    ll a2=(mid+1+b)*(b-mid)/2;// mid+1 -> r
    ll d=abs(a1-a2);
    if(d<mi){
      mi=d;
      ans=mid;
    }
    if(a1<a2) l=mid+1;
    else r=mid-1;
  }
  print(ans);
}
