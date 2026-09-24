#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s1,s2,k,m; cin>>s1>>s2>>k>>m;
  long long sum1=0,sum2=0;
  vector<int> a(s1+2),b(s2+2);
  for (int i=0; i<s1; i++){
    cin>>a[i];
  }
  for(int i=0; i<s2; i++){
    cin>>b[i];
  }
  sort(a.begin(),a.begin()+s1);
  sort(b.begin(),b.begin()+s2);
  if(a[k-1]<b[s2-m]) cout<<"YES";
  else cout<<"NO";
  return 0;
}
