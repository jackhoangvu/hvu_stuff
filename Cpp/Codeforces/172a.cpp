#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string s[30005];
  string sc; cin>>sc;
  int cma=sc.length();
  for (int i=1; i<n; i++){
    string sn; cin>>sn;
    int ma=0;
    while(ma<cma && sc[ma]==sn[ma]) ma++;
    cma=ma;
  }
  cout<<cma;
  //s[i] vs s[i+1]

  return 0;
}
