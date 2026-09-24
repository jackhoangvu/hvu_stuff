#include <bits/stdc++.h>
long long a[300005], b[300005], s1[300005];
using namespace std;
void solve(){
  int n; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i]>>b[i];
  }
  s1[0]=max(1LL*0,a[0]-b[n-1]);
  for (int i=1; i<=n-1; i++){
    s1[i]=max(1LL*0,a[i]-b[i-1]);
  }
  long long total=0, mi=LLONG_MAX;
  for (int i=0; i<n; i++){
    total+=s1[i];
  }
  for (int i=0; i<n; i++){
    a[i]+=(total-s1[i]);
    mi=min(a[i],mi);
  }
  cout<<mi<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
