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
ll pfo(int n,int k){
  if(k<0||k>n){ return 0;}
  if(k==0||k==n) return 1;
  if(k>n/2){k=n-k;}
  ll ans=1;
  for (int i=1; i<=k; i++){
    ans=(ans*(n-i+1)/i);
  }
  return ans;
}
ll solve(int a,int b,int c, int k){
  ll ans=0;
  for(int x=1; x<=a; x++){
    for(int z=1; z<=c; z++){
      int y=k-x-z;
      if(y>=1 && y<=b){
        if(x+z==2*y){
          ans+=pfo(a,x)*pfo(b,y)*pfo(c,z);
        }
      }
    }
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a,b,c,k;
  read(a,b,c);
  read(k);
  if(k<0||a<0||b<0||c<0) print(0);
  else if (k<3||k>a+b+c) print(0);
  else print(solve(a,b,c,k));
}
