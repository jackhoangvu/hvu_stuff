#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int l=0;
  long long ans=0;
  for (int r=0; r<n; r++){
    while(a[r]-a[l]>2) l++;
    if(r-l>=2) ans+=((r-l)*(r-l-1)/2);
  }
  cout<<ans;
  return 0;
}
