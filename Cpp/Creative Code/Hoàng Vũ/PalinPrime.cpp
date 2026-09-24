#include <bits/stdc++.h>

using namespace std;
const int mxn=1e7+5;
bool p[mxn];
vector<int> pref;
bool isPal(int x){
  if (x<0 || (x% 10 == 0 && x!=0)) return false;
  int rev=0;
  while (x>rev) { rev= rev* 10+x % 10; x /= 10; }
  return x==rev || x==rev/10;
}
void sang(int mx=mxn-1){
  fill(p,p+mxn,true);
  p[0]=p[1]=false;
  for(long long i=2; i*i<=mx; i++){
    for(long long j=i*i; j<=mx; j+=i){
      p[j]=false;
    }
  }
  pref[0]=0;
  for (int i=1; i<mxn; i++){
    pref[i]=pref[i-1]+(p[i]&&isPal(i));
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("PalinPrime.Inp","r",stdin);
  freopen("PalinPrime.Out","w",stdout);
  pref.resize(mxn+2);
  sang();
  int t; cin>>t;
  while(t--){
    int u,v; cin>>u>>v;
    cout<<pref[v]-pref[u-1]<<"\n";
  }
  return 0;
}
