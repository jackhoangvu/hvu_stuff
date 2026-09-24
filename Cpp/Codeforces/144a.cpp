#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  pair<int,int> mi={INT32_MAX,INT32_MAX};
  pair<int,int> ma={INT32_MIN,INT32_MAX};
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]<=mi.first){
      mi={a[i],i};
    }
    if(a[i]>ma.first){
      ma={a[i],i};
    }
  }
  int ans=0;
  if(ma.second>mi.second){
    ans=ma.second+(n-mi.second)-2;
  }
  else if(ma.second<mi.second){
    ans=ma.second+(n-mi.second)-1;
  }
  cout<<ans;
  return 0;
}
