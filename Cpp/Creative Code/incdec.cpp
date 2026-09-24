#include <bits/stdc++.h>

using namespace std;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  vector<long long> a(n);
  long long ans=0,ans2=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long lst=a[0],nxt=a[n-1];
  for (int i=1; i<n; i++){
    if(a[i]<lst) ans+=(lst-a[i]);
    else lst=a[i];
  }
  for (int i=n-2; i>=0; i--){
    if(a[i]<nxt) ans2+=(nxt-a[i]);
    else nxt=a[i];
  }
  cout<<min(ans,ans2);
  return 0;
}
