#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n+1), pre(n+1,0), freq(n,0);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  freq[0]=1;
  for (int i=1; i<=n; i++){
    pre[i]=((pre[i-1]+a[i])%n+n)%n;
    freq[pre[i]]++;
  }
  long long sum=0;
  for (int i=0; i<n; i++){
    long long k=freq[i];
    sum+=(k*(k-1)/2);
  }
  cout<<sum;
  // 3 1 2 7 4
  // -> 2 1 1 2 1
  return 0;
}
