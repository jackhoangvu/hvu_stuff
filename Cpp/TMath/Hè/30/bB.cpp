#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int ans=0;
  for(int i=0; i<n;){
    int j=upper_bound(a.begin()+i,a.end(),a[i]+m)-a.begin()-1;
    i=upper_bound(a.begin()+j,a.end(),a[j]+m)-a.begin();
    ans++;
  }
  cout<<ans;
  return 0;
}
