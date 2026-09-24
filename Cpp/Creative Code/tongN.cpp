#include <bits/stdc++.h>

using namespace std;
long long rec(long long n){
  if(n==0) return 0;
  return n+rec(n-1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long ans=rec(n);
  cout<<ans;
  return 0;
}
