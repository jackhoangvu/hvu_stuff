#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("CAU4.INP", "r", stdin);
  freopen("CAU4.OUT", "w", stdout);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    int ans=0;
    for (int i=n+1; i<=2*n; i++){
      if ((n*i)%(i-n)==0){
        ans++;
      }
    }
    cout<<2*ans-1<<"\n";
  }
  return 0;
}
