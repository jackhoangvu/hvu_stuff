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
vector<int> q;
int n,k;

bool check(int d){
  for(int p:q){
    auto l=lower_bound(all(q),p-d);
    auto r=upper_bound(all(q),p+d);
    if(r-l>=k+1) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("chonphong.inp","r",stdin);
  freopen("chonphong.out","w",stdout);
      int n, m;
      cin >> n >> m;

      vector<ll> a(n), b(m);
      ll mn = LLONG_MAX, mxB = 0;
      for (ll &x : a) {
          cin >> x;
          mn = min(mn, x);
      }
      for (ll &x : b) {
          cin >> x;
          mxB = max(mxB, x);
      }

      // Chosen stack indices must be increasing: after using j, every
      // stack from j through n is unavailable, so the next index is > j.
      auto possible = [&](ll score) {
          int p = 0;
          for (ll x : a) {
              if (x >= score) continue;
              ll need = score - x;
              while (p < m && b[p] < need) ++p;
              if (p == m) return false;
              ++p;
          }
          return true;
      };

      ll lo = mn, hi = mn + mxB;
      while (lo < hi) {
          ll mid = lo + (hi - lo + 1) / 2;
          if (possible(mid)) lo = mid;
          else hi = mid - 1;
      }
      cout << lo << '\n';
      return 0;
}
