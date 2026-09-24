#include <bits/stdc++.h>

using namespace std;
long long n;
vector<long long> vt;
vector<int> p={1,3,7,9};
bool pr(long long n){
  if(n<=1) return false;
  for(int i=2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return true;
}
void rec(int x){
  if(x>n) return;
  if(pr(x)){
    vt.push_back(x);
    for (auto& v:p){
      rec(x*10+v);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  vector<int> m={2,3,5,7};
  for (auto& x:m){
    rec(x);
  }
  sort(vt.begin(),vt.end());
  for (auto& x:vt) cout<<x<<" ";
  return 0;
}
