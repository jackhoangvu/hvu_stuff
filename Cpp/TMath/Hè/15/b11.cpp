#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long a,b; cin>>a>>b;
    set<long long> sa,sb;
    for (long long i=2; i*i<=a; i++){
      if(a%i==0){
        sa.insert(i);
        while(a%i==0) a/=i;
      }
    }
    if(a>1) sa.insert(a);
    for (long long i=2; i*i<=b; i++){
      if(b%i==0){
        sb.insert(i);
        while(b%i==0) b/=i;
      }
    }
    if(b>1) sb.insert(b);
    if(sa==sb) cout<<"Co\n";
    else cout<<"Khong\n";
  }
  return 0;
}
