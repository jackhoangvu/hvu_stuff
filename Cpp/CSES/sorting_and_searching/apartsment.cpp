#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,k, ans=0, a[200005], b[200005];
  cin>>n>>m>>k;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<m; i++){
    cin>>b[i];
  }
  sort(a,a+n);
  sort(b,b+m);
  int l=0, r=0;
  while(l<n and r<m){
    if(abs(a[l]-b[r])<=k){
      l++;
      r++;
      ans++;
    }
    else if(b[r]<a[l]-k){
      r++;
    }
    else{
      l++;
    }
  }
  cout<<ans;
  return 0;
}
