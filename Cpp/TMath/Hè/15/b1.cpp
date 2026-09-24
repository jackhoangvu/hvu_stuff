#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  for (long long i=2; i*i<=n; i++){
    if(n%i==0){
      cout<<i;
      return 0;
    }
  }
  cout<<n;
  return 0;
}
