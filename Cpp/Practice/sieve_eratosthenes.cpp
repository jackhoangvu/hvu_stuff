#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<bool> pr(n+1,true);
  pr[0]=pr[1]=false;
  for(int i=2; i*i<=n; i++){
    if(pr[i]){
      for(int j=i*i; j<=n; j+=i){
        pr[j]=false;
      }
    }
  }
  for (int i=0; i<n; i++){
    if(pr[i]) cout<<i<<" ";
  }
  return 0;
}
