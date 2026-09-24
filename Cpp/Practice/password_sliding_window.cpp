#include <bits/stdc++.h>

using namespace std;
int a,b,c,d;
int ans=1e9;
bool ch(const char& c){
  return c=='@'||c=='!'||c=='?'||c=='&'||c=='$';
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int l=0;
  vector<pair<int,int>> vt;
  for(int r=0; r<s.size(); r++){
    a+=isdigit(s[r]);
    b+=islower(s[r]);
    c+=isupper(s[r]);
    d+=ch(s[r]);
    while(a&&b&&c&&d){
      // ans=min(ans,r-l+1);
      if(r-l+1<ans){
        ans=r-l+1;
        vt.push_back({l,r});
      }
      a-=isdigit(s[l]);
      b-=islower(s[l]);
      c-=isupper(s[l]);
      d-=ch(s[l]);
      l++;
    }
  }
  // cout<<ans<<"\n";
  cout<<s.substr(vt.back().first,ans);
  return 0;
}
