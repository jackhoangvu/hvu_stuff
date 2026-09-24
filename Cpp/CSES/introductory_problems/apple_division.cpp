#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  int a[21];
  long long total=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    total+=a[i];
  }
  long long ans=total;
  for (int i=0; i<(1<<n); i++){
    long long cur=0;
    for (int j=0; j<n; j++){
      if((i>>j)&1) cur+=a[j];
    }
    ans=min(ans, abs(total-2*cur));
  }
  cout<<ans;
  return 0;
}
