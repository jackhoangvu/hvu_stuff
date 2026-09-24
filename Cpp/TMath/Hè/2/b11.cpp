#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long sum=0;
  for (int i=1; i<=n; i++){
    sum+=(n/i);
  }
  cout<<sum;
  return 0;
}
