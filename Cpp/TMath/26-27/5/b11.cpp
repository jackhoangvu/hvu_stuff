#include<bits/stdc++.h>
using namespace std;
long long m,n,k;
long long t;
vector<vector<long long>> pref;
void solve1(){
  long long ans=0;
  for(int s=1; s<=min(m,n); s++){
    for(int i=1; i<=m-s+1; i++){
      for(int j=1; j<=n-s+1; j++){
        long long x=pref[i+s-1][j+s-1]-pref[i-1][j+s-1]-pref[i+s-1][j-1]+pref[i-1][j-1];
        if(x<=t) ans=max(ans,1LL*s*s);
      }
    }
  }
  cout<<ans;
}
struct S{
  int r,c,s; long long x,a;
};
void solve2(){
  vector<S> vt;
  for(int i=1; i<=m; i++){
    for(int j=1;j<=n;j++){
      for(int s=1; s<=min(m-i+1,n-j+1); s++){
        long long x=pref[i+s-1][j+s-1]-pref[i-1][j+s-1]-pref[i+s-1][j-1]+pref[i-1][j-1];
        if(x<=t) vt.push_back({i,j,s,x,1LL*s*s});
      }
    }

  }
  if(vt.empty()){cout<<0;return;}
  sort(vt.begin(),vt.end(),[](S a,S b){return a.a>b.a;});
  long long ans=0;
  for(int i=0; i<(int)vt.size(); i++){
    for(int j=i+1; j<(int)vt.size(); j++){
      if(vt[i].a+vt[j].a<=ans) break;
      if(vt[i].r+vt[i].s-1<vt[j].r||vt[j].r+vt[j].s-1<vt[i].r||vt[i].c+vt[i].s-1<vt[j].c||vt[j].c+vt[j].s-1<vt[i].c){
        if(vt[i].x+vt[j].x<=t) ans=max(ans,vt[i].a+vt[j].a);
      }
    }
  }
  cout<<ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>m>>n>>k;
  cin>>t;
  vector<vector<long long>> a(m+1,vector<long long>(n+1,0));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  // vector<vector<long long>> pref(m+1,vector<long long>(n+1,0));
  pref.resize(m+1,vector<long long>(n+1,0));
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
    }
  }
  if(k==1) solve1();
  if(k==2) solve2();
  return 0;
}
