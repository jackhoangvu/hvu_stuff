#include <bits/stdc++.h>
using namespace std;
long long dg(const string &s,int k){
  long long ans=0;
  for(char c:s){
    ans=ans*k+(c-'0');
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k; cin>>k;
  string a,b; cin>>a>>b;
  long long a2 = dg(a,k);
  long long b2 = dg(b,k);
  long long ans=a2*b2;
  cout<<ans;
  return 0;
}
