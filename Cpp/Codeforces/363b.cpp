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
  long long j=1;
  for (int i=1; i<n-k+1; i++){
    sum=sum-a[i-1]+a[i+k-1];
    if(sum<mi){
      mi=sum;
      j=i+1;
    }
  }
  cout<<j;
  return 0;
}
