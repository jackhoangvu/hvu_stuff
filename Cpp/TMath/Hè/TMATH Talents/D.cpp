#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  vector<int> a(n+1,0), pref1(n+1,0), pref2(n+1,0);
  for (int i=1; i<=n; i++){
    cin>>a[i];
    pref1[i]=pref1[i-1]+(a[i]==1);
    pref2[i]=pref2[i-1]+(a[i]==2);
  }
  while(q--){
    int l,r; cin>>l>>r;
    int x=pref1[r]-pref1[l-1];
    int y=pref2[r]-pref2[l-1];
    if((x+y)%3!=0) cout<<-1<<"\n";
    else cout<<min(x,y)+2*abs(x-y)/3<<"\n";
  }
  return 0;
}
