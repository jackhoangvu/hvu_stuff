#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<int> a(n+2),b(n+2),d(n+3,0);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  while(k--){
    fill(d.begin(),d.end(),0);
    for(int i=1; i<=n; i++){
      d[max(1,i-a[i])]++;
      d[min(n,i+a[i])+1]--;
    }
    int cur=0;
    for(int i=1; i<=n; i++){
      cur+=d[i];
      b[i]=cur;
    }
    for(int i=1; i<=n; i++){
      a[i]=b[i];
    }
  }
  for(int i=1; i<=n; i++){
    cout<<a[i]<<" ";
  }
}
