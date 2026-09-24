#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  long long cnt[100005];
  for (int i=1; i<=n; ++i)
  {
    int x; cin>>x;
    cnt[i]=cnt[i-1]+(x%2==0);
  }
  while (q--)
  {
    int L,R;
    cin>>L>>R;
    long long c=cnt[R]-cnt[L-1];
    long long le=(R-L+1)-c;
    long long ans=0;
    if(c>=3) ans+=(c*(c-1)*(c-2))/6;
    if(c>=1&&le>=2) ans+=c*(le*(le-1)/2);
    cout<< ans<< "\n";
  }
  return 0;
}
