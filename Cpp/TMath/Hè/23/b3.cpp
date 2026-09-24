#include <bits/stdc++.h>

using namespace std;
long long cfo(int n,int k){
  if (k<0||k>n) return 0;
  long long ans=1;
  for (int i=0; i<k; i++){
    ans*=(n-i);
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  if(n<2) cout<<0;
  else cout<<n*(n-1)<<"\n";
  //n!/(n-2)!
  return 0;
}
