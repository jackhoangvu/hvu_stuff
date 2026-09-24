#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string t; cin>>t;
  for(char c:t){
    if(c!='4'&&c!='7') {cout<<"NO"; return 0;}
  }
  int sum1=0, sum2=0;
  for(int i=0; i<n/2; ++i){
    sum1+=t[i]-'0';
  }
  for(int i=n/2; i<n; ++i){
    sum2+=t[i]-'0';
  }
  if(sum1==sum2) cout<<"YES";
  else cout<<"NO";
  return 0;
}
