#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int mi=INT32_MAX;
  int ans=0;
  int x;
  for (int i=1; i<=n; i++){
    cin>>x;
    if (x<mi){
      mi=x;
      ans++;
    }
  }
  cout<<ans;
  return 0;
}
