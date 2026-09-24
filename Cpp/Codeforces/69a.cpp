#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int s1=0,s2=0,s3=0;
  for (int i=0; i<n; i++){
    int x,y,z;
    cin>>x>>y>>z;
    s1+=x; s2+=y; s3+=z;
  }
  if(s1==s2&&s2==s3&&s1==0) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
  return 0;
}
