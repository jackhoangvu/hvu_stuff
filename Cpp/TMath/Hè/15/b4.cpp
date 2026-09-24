#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> fac;
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
  int n; cin>>n;
  analyze(n);
  cout<<n<<" =";
  for(int i=0; i<fac.size(); i++){
    cout<<" "<<fac[i].first<<"^"<<fac[i].second<<(i==fac.size()-1?"":" *");
  }

  return 0;
}
