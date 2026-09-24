#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("LADDER.INP","r",stdin);
  freopen("LADDER.OUT","w",stdout);
  int n,m;
  cin>>n>>m;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  while(m--){
    int l,r; cin>>l>>r;
    l--;
    r--;
    int i=l;
    while(i<r&&a[i]<=a[i+1]){
      i++;
    }
    while(i<r&&a[i]>=a[i+1]){
      i++;
    }
    cout<<(i==r?"Yes":"No")<<"\n";
  }
}
