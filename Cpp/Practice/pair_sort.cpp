#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> w(n);
  for (int i=0; i<n; i++){
    cin>>w[i];
  }
  vector<pair<int,int>> a(n);
  for (int i=0; i<n; i++){
    a[i]={w[i],i};
  }
  sort(a.begin(),a.end());
  vector<int> ok(n,0);
  long long sum=0;
  for (int i=0; i<n; i++){
    if (sum+a[i].first<=500){
      sum+=a[i].first;
      ok[a[i].second]=1;
    }
  }
  cout<<sum<<"\n";
  for (int i=0; i<n; i++){
    if (ok[i]){
      cout<<w[i]<<" ";
    }
  }
  return 0;
}
