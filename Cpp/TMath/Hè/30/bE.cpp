#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int l=0,r=1e9;
  while(l<=r){
    int cuoi=a[0],cnt=0;
    int mid=l+(r-l)/2;
    for (int i=1; i<n; i++){
      if(abs(a[i]-cuoi)>=mid){
        cuoi=a[i];
        cnt++;
      }
    }
    if(cnt>=m-1) l=mid+1;
    else r=mid-1;
  }
  cout<<l-1;
  return 0;
}
