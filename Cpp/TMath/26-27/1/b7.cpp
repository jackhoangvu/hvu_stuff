#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q; cin>>n>>q;
  vector<int> a(n+2);
  vector<int> pref1(n+2,0),pref2(n+2,0),pref3(n+2,0);
  for (int i=1; i<=n; i++){
    cin>>a[i];
    pref1[i]=pref1[i-1]+(a[i]==1);
    pref2[i]=pref2[i-1]+(a[i]==2);
    pref3[i]=pref3[i-1]+(a[i]==3);
  }
  while(q--){
    int l,r; cin>>l>>r;
    cout<<pref1[r]-pref1[l-1]<<" "<<pref2[r]-pref2[l-1]<<" "<<pref3[r]-pref3[l-1]<<"\n";
  }
  return 0;
}
