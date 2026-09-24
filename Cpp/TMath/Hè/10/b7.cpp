#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  long long sum=0;
  long long cur=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%3!=0){
    cout<<0;
    return 0;
  }
  long long t=sum/3;
  long long ans=0;
  long long cnt=0;

  for (int i=0; i<n-1; i++){
    cur+=a[i];
    if(cur==2*t) ans+=cnt;
    if(cur==t) cnt++;
  }
  cout<<ans;
  return 0;
}
