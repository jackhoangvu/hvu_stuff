#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> a(n+5);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long sum=0;
  for (int i=0; i<k; i++){
    sum+=a[i];
  }
  long long mi=sum;
  for (int i=1; i<n-k+1; i++){
    sum=sum-a[i-1]+a[i+k-1];
    mi=min(mi,sum);
  }
  cout<<mi;
  return 0;
}
