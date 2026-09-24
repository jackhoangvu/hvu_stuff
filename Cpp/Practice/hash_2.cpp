#include <bits/stdc++.h>

using namespace std;
int mod;
string s;
const int mxn=1e4+5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>mod>>s;
  s=" "+s;
  int n=(int)s.length();
  int q; cin>>q;
  vector<long long> pref1(mxn+1,0),pref2(mxn+1,0);
  pref1[0]=1;
  for (int i=1; i<=n; i++){
    pref1[i]=(pref1[i-1]*31+mod)%mod;
    pref2[i]=(pref2[i-1]*31+(s[i]-'a'+1)+mod)%mod;
  }
  while(q--){
    int l,r; cin>>l>>r;
    // for (int i=1; i<=n; i++) cout<<pref2[i]<<" ";
    // cout<<"\n";
    cout<<(pref2[r]-(pref2[l-1]*pref1[r-l+1])%mod+mod)%mod<<"\n";
    // cout<<pref1[r-l+1]<<"\n";
  }
}
