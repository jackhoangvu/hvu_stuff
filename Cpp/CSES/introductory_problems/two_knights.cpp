#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  for(long long k=1; k<=n; k++){
    long long ans=((k*k)*(k*k-1)/2)-(4*(k-1)*(k-2));
    cout<<ans<<"\n";
  }
  return 0;
}
