#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int p,q; cin>>p;
  set<int> s;
  for (int i=0; i<p; i++){
    int x; cin>>x;
    s.insert(x);
  }
  cin>>q;
  for (int i=0; i<q; i++){
    int x; cin>>x;
    s.insert(x);
  }
  if(s.size()>=n) cout<<"I become the guy.";
  else cout<<"Oh, my keyboard!";
  return 0;
}
