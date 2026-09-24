#include <bits/stdc++.h>

using namespace std;
int a,b,c;
int ans=1e9;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int l=0;
  for(int r=0; r<s.size(); r++){
    a+=isdigit(s[r]);
    b+=islower(s[r]);
    c+=isupper(s[r]);
    while(r-l+1>=6&&a&&b&&c){
      ans=min(ans,r-l+1);
      a-=isdigit(s[l]);
      b-=islower(s[l]);
      c-=isupper(s[l]);
      l++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
