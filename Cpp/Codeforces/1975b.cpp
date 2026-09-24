#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int mi=*min_element(a.begin(),a.end());
  bool ok=true;
  vector<int> non;
  for (int i=0; i<n; i++){
    if(a[i]%mi !=0) {ok=false; non.push_back(a[i]);}
  }
  if(ok){
    cout<<"Yes"<<"\n";
  }
  else{
    bool ok2=true;
    int mi2=*min_element(non.begin(), non.end());
    for (int i=0; i<non.size(); i++){
      if(non[i]%mi2 != 0) ok2=false;
    }
    if(ok2) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
  }
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
