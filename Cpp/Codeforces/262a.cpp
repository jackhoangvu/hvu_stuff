#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,m,a[102];
  cin>>n>>k;
  m=n;
  for (int i=0; i<n; ++i){
    string s; cin>>s;
    int cnt=0;
    for(char c:s){
      if(c=='4'||c=='7') cnt++;
    }
    if(cnt>k) m--;
  }
  cout<<m;
  return 0;
}
