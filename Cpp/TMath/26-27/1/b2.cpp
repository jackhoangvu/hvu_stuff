#include <bits/stdc++.h>

using namespace std;
bool pr(unsigned long long n){
  if(n<=1) return false;
  for(unsigned long long i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned long long n; cin>>n;
  unsigned long long a=1, b=1, ans=0;
  for (int i=2; i<=93; i++){
    unsigned long long c=a+b;
    if(c>n) break;
    if(pr(c)) ans=c;
    a=b;
    b=c;
  }
  cout<<ans<<"\n";
  return 0;
}
