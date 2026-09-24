#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n,k; cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  bool ok=false;
  int mi=10005;
  int cnt=0;
  if(k==2||k==3||k==5){
    for (int i=0; i<n; i++){
      if(a[i]%k==0) {ok=true; cout<<0<<"\n"; break;}
      else{
        if(a[i]<k) mi=min(mi,abs(a[i]-k));
        else mi=min(mi,k-a[i]%k);
      }
    }
    if(!ok) cout<<mi<<"\n";
    // 2 5
    // 1 6
  }
  else{
    for (int i=0; i<n; i++){
      if(a[i]%4==0){ok=true; cout<<0<<"\n"; break;}
      else if(a[i]%2==0) cnt++;
      mi=min(mi,4-a[i]%4);
    }
    if(!ok){
      if(n>1){
        cout<<min(mi, max(0,2-cnt))<<"\n";
      }
      else{
        for (int i=0; i<n; i++){
          mi=min(mi,4-a[i]%4);
        }
        cout<<mi<<"\n";
      }
    }
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
