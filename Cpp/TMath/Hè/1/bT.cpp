#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  vector<int> a(n),b(m);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  for (int i=0; i<m; i++){
    cin>>b[i];
    int cnt=upper_bound(a.begin(),a.end(),b[i])-a.begin();
    cout<<cnt<<" ";
  }

  return 0;
}
