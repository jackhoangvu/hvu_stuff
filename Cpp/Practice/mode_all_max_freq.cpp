#include <bits/stdc++.h>

using namespace std;
int cnt[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int mx=INT32_MIN;
  int mxn=INT32_MIN;
  for (int i=0; i<n; i++){
    int x; cin>>x;
    cnt[x]++;
    mx=max(mx,cnt[x]);
    mxn=max(mxn,x);
  }
  for(int i=0; i<=mxn; i++){
    if(cnt[i]==mx) cout<<i<<" ";
  }
  return 0;
}
