#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  vector<long long> pre(n+1, 0);
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    pre[i]= pre[i-1] + x;
  }
  vector<long long> gt(pre.begin()+1, pre.begin()+n);
  sort(gt.begin(),gt.end(),greater<long long>());
  long long ans= (long long)k*pre[n];
  for (int i = 0; i < k-1; i++) ans -= gt[i];
  cout<<ans;
  return 0;
}
