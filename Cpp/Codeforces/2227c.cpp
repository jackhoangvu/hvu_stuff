#include <bits/stdc++.h>

using namespace std;
void solve(){
  int n; cin>>n;
  vector<int> a(n),b,g2,g3,g6,g0;
  for(int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]%6==0){
      g6.push_back(a[i]);
    }
    else{
      if(a[i]%2==0){
        g2.push_back(a[i]);
      }
      else if(a[i]%3==0){
        g3.push_back(a[i]);
      }
      else g0.push_back(a[i]);
    }
  }
  for(int i=0; i<g2.size(); i++){
    b.push_back(g2[i]);
  }
  for(int i=0; i<g0.size(); i++){
    b.push_back(g0[i]);
  }
  for(int i=0; i<g3.size(); i++){
    b.push_back(g3[i]);
  }
  for(int i=0; i<g6.size(); i++){
    b.push_back(g6[i]);
  }
  for (int i=0; i<n; i++){
    cout<<b[i]<<" ";
  }
  cout<<"\n";
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
