#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  int cnt=0;
  for (long long i=2; i*i<=n; i++){
    if(n%i==0){
      cnt++;
      while(n%i==0) n/=i;
    }
  }
  if(n>1) cnt++;
  cout<<cnt;
  return 0;
}
