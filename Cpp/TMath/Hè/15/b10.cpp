#include <bits/stdc++.h>

using namespace std;
const int mxn=1e5+5;
bool p[mxn];
vector<int> pr;
void sang(int mx=mxn){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(int i=2; i*i<=mx; i++){
    for(int j=i*i; j<=mx; j+=i){
      p[j]=false;
    }
  }
  for (int i=3; i<mx; i++){
    if(p[i]) pr.push_back(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long m,n; cin>>m>>n;

  }
  return 0;
}
