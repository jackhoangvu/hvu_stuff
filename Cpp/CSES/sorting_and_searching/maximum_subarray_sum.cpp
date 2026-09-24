#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long x1; cin>>x1;
  long long sum=x1, mx=x1;
  for (int i=1; i<n; i++){
    long long x;
    cin>>x;
    sum=max(x,x+sum);
    mx=max(mx,sum);
  }
  cout<<mx;
  return 0;
}
