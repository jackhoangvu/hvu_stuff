#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long sum=0;
  for (int i=1; i<n; i++){
    int x;cin>>x;
    sum+=x;
  }
  long long mx=n*(n+1)/2;
  long long ans=mx-sum;
  cout<<ans;
  return 0;
}
