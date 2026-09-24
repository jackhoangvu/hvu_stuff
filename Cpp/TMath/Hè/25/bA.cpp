#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<long long,int> cnt;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  int q; cin>>q;
  while(q--){
    long long x; cin>>x;
    if(cnt.count(x)) cout<<cnt[x];
    else cout<<0;
    cout<<"\n";
  }
  return 0;
}
