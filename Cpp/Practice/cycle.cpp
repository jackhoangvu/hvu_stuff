#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,c,d,m; cin>>a>>b>>c>>d>>m;
  long long t=0;
  long long e=c+d;
  long long r=a*m;
  if(e==0){
    cout<<r;
    return 0;
  }
  long long x=m/e;
  long long y=m%e;
  t+=(x*b*c);
  if(y<=c) t+=(y*b);
  else t+=(c*b);
  cout<<abs(t-r);
}
