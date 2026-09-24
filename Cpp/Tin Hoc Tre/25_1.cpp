#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long ans=n/9;
  ans=ans*(ans+1)/2;
  ans*=9;
  cout<<ans;
  return 0;
}
