#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n;
  vector<int> a(n+2);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  cin>>m;
  vector<int> b(m+2);
  for (int i=1; i<=m; i++){
    cin>>b[i];
  }
  map<int,int> freq;
  long long ans=0;
  for(int i=1; i<=m-1; i++){
    freq[b[i]+b[i+1]]++;
  }
  for(int i=1; i<=n-1;i++){
    long long sa=a[i]+a[i+1];
    auto it=freq.find(sa);
    if (it!=freq.end()) {
      ans+=it->second;
    }
  }
  cout<<ans;
  return 0;
}
