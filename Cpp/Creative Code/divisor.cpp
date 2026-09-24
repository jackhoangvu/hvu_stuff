#include <bits/stdc++.h>
using namespace std;
int n,c[2000010];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans=0;
  cin>>n;
  for (int i=0; i<n; i++){
    int x;cin>>x; c[x]++;
  }
  for (int i=1; i<=2000005; ++i) {
    if (c[i]<= 0) continue;
    ans += (long long) c[i]* (c[i]-1)/ 2;
    for (int j=2*i; j<= 2000005; j+= i) {
      if (c[j]> 0)
        ans += (long long) c[i] *c[j];
    }
  }
  cout <<ans;
  return 0;
}
