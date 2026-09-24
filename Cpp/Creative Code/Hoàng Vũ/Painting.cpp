#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("Painting.Inp","r",stdin);
  freopen("Painting.Out","w",stdout);
  long long a,b,x,y; cin>>a>>b>>x>>y;
  long long n=max(a,x);
  long long m=max(b,y);
  long long c=(n+(b+y))*2;
  long long d=(m+(a+x))*2;
  cout<<min(c,d)<<"\n";
  return 0;
}
