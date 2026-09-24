#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long t1=0,t2=-INF;
  vector<long long> dp(n+1,0);
  for (int i=0; i<n; i++){
    long long new1=max(t1,t2+2*a[i]);
    long long new2=max(t2,t1+a[i]);
    t1=new1;
    t2=new2;
  }
  cout<<max(t1,t2);
  return 0;
}
