#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> a(n+1);
  int stand=0,sit=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]>k) sit++;
    else stand++;
  }
  cout<<stand+2*sit;
  return 0;
}
