#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[102],sum=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    sum+=a[i];
  }
  sort(a,a+n,greater<int>());
  int ans=1,cur=0;
  for (int i=0; i<n; i++){
    ans++; cur+=a[i];
    if(cur>sum-cur) break;
  }
  cout<<ans-1<<"\n";
  return 0;
}
