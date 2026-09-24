#include <bits/stdc++.h>

using namespace std;

void solve(){
  int m,n; cin>>m>>n;
  vector<vector<int>> a(m,vector<int>(n));
  vector<int> v;
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      cin>>a[i][j];
      v.push_back(a[i][j]);
    }
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  int l=0,r=v.size()-1,ans=0;
  while(l<=r){
    int mid=l+(r-l)/2;
    bool ok=true;
    // bool ok2=false;
    bool ok3=false;
    for(int j=0; j<n; j++){
      bool ok4=false;
      for(int i=0; i<m; i++){
        if(a[i][j]>=v[mid]) ok4=true;
      }
      if(!ok4) ok=false;
    }
    for(int i=0; i<m; i++){
      int cnt=0;
      for(int j=0; j<n; j++){
        if(a[i][j]>=v[mid]) cnt++;
      }
      if(cnt>=2) ok3=true;
    }
    if(ok&&ok3){
      ans=v[mid];
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  cout<<ans<<"\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
}
