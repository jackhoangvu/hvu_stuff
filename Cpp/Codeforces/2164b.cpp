#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int l=min(n,60);
  for (int i=0; i<l; i++){
    for (int j=i+1; j<l; j++){
      if((a[j]%a[i])%2==0) {cout<<a[i]<<" "<<a[j]<<"\n"; return;}
    }
  }
  cout<<-1<<"\n";
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
