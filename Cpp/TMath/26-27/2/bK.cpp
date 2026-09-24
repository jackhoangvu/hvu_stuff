#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; long long s; cin>>n>>s;
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  long long sum=0;
  for (int i=0; i<n; i++){
    sum+=a[i];
  }
  long long mi=0,mi2=0;
  long long pref=0;
  for(int i=0; i<n; i++){
    pref+=a[i];
    mi2=min(mi2,pref-mi);
    mi=min(mi,pref);
  }
  cout<<sum;
  return 0;
}
