#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> fib;
  fib.push_back(1);
  fib.push_back(1);
  while(fib.back()<=1e18){
    long long x=fib[fib.size()-1]+fib[fib.size()-2];
    if(x>1e18) break;
    fib.push_back(x);
  }
  unordered_map<long long,long long> dp;
  dp[0]=1;
  long long pref=0;
  for(int i=1; i<=n; i++){
    long long x; cin>>x;
    pref+=x;
    long long cur=0;
    for(int j=0; j<fib.size(); j++){
      if(fib[j]<=pref){
        long long t=pref-fib[j];
        if(dp.find(t)!=dp.end()) cur=(cur+dp.find(t)->second)%mod;
      }
    }
    dp[pref]=cur;
  }
  cout<<dp[pref];
  return 0;
}
