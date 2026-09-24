#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, int>> fac;
void analyze(long long k){
  for(long long i=2; i*i<=k; i++){
    if(k%i==0){
      int cnt=0;
      while(k%i==0){
        cnt++;
        k/=i;
      }
      fac.push_back({i,cnt});
    }
  }
  if(k>1) fac.push_back({k,1});
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  analyze(n);
  long long sum=0;
  long long s1=0;
  for (auto p:fac){
    sum+=p.second;
    if(p.second%2==0) s1+=p.second;
  }
  cout<<s1<<"\n"<<sum-s1;
  return 0;
}
