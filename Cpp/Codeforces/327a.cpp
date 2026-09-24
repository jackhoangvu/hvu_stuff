#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int a[105];
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  bool ok=false;
  for (int i=0; i<n-1; i++){
    if(a[i]!=a[i+1]) ok=true;
  }
  if(!ok) {cout<<n-1<<"\n"; return 0;}
  int best=0;
  for (int i=0; i<n; i++){
    for (int j=i; j<n; j++){
      int cnt=0;
      for (int k=0; k<n; k++){
        if(i<=k&&k<=j) cnt+=(1-a[k]);
        else cnt+=a[k];
      }
      best=max(cnt,best);
    }
  }
  cout<<best<<"\n";
  return 0;
}
