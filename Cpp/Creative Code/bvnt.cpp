#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+5;
bool p[mxn];
void sang(int mx=mxn){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(int i=2; i*i<=mx; i++){
    if(p[i]){
      for(int j=i*i; j<=mx; j+=i){
        p[j]=false;
      }
    }
  }
}
vector<vector<int>> pref(10,vector<int>(10,0));
long long val(int x1,int y1,int x2,int y2){
  return pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  sang();
  int m,n; cin>>m>>n;
  vector<vector<int>> a(m+1,vector<int>(n+1));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  pref.resize(m+1,vector<int>(n+1));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      int bad=!p[a[i][j]];
      pref[i][j]=bad+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    }
  }
  auto ch=[&](int k){
    for(int i=1; i+k-1<=m; i++){
      for(int j=1; j+k-1<=n; j++){
        if(val(i,j,i+k-1,j+k-1)<=1)
          return true;
      }
    }
    return false;
  };
  int l=1,r=min(m,n);
  long long ans=0;
  while(l<=r){
    int mid=(l+r)/2;
    if(ch(mid)){
      ans=mid;
      l=mid+1;
    }
    else r=mid-1;
  }
  cout<<ans*ans;
  return 0;
}
