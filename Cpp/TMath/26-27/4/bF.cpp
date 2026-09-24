#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long>a(n+2),p(n+2),mn(n+2),mx(n+2);
  for (int i=1; i<=n; i++){
    cin>>a[i];
    p[i]=p[i-1]+a[i];
  }
  mn[0]=p[0];
  for (int i=1; i<=n; i++){
    mn[i]=min(mn[i-1],p[i]);
  }
  mx[n]=p[n];
  for (int i=n-1; i>=0; i--){
    mx[i]=max(mx[i+1],p[i]);
  }
  int q; cin>>q;
  while(q--){
    int x,y; cin>>x>>y;
    cout<<mx[y]-mn[x-1]<<"\n";
  }
  return 0;
}
