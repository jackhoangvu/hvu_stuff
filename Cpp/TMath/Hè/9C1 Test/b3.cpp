#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("CAU3.INP", "r", stdin);
  freopen("CAU3.OUT", "w", stdout);
  int n; cin>>n;
  int k; cin>>k;
  string s; cin>>s;
  int ans=0;
  for (char c='a'; c<='z'; c++){
    int l=0,r=0;
    int cnt=0;
    while(r<n){
      if (s[r]!=c){
        cnt++;
      }
      while(cnt>k){
        if (s[l]!=c){
          cnt--;
        }
        l++;
      }
      ans=max(ans,r-l+1);
      r++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
