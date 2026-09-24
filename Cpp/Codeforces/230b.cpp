#include <bits/stdc++.h>

using namespace std;
bool check(long long n){
  long long r=sqrtl(n);
  return (r*r==n);
}
bool pr(long long n){
  if(n<2) return false;
  for(int i=2; i*i<=n; i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n+5);
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(check(a[i])&&pr(sqrt(a[i]))) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
  }
  return 0;
}
