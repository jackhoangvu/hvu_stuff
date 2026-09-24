#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> vx,vy;
  for (int i=0; i<n; i++){
    int x,y; cin>>x>>y;
    vx.push_back(x);
    vy.push_back(y);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  int mx = vx[n/2];
  int my = vy[n/2];
  cout<<mx<<" "<<my<<"\n";
  return 0;
}
