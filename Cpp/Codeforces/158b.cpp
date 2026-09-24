#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+5);
  int cnt[5]={0};
  for (int i=0; i<n; i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  int ans=0;
  ans+=cnt[4];
  ans+=abs(cnt[3]-cnt[1]);
  //leftover cnt[3]
  if(cnt[3]>cnt[1]) ans+=cnt[3]-cnt[1];
  //with cnt[2] do in pair, if left 1 -> if cnt[1]<=2 then ans+=cnt[2]/2 else idk
  ans+=cnt[2]/2;
  if(cnt[2]%2==1){
    if(cnt[1]<=2){ans++;cnt[1]%=2;}
    //cnt[1]=5, cnt[2]=1, -> cnt[1]-=cnt[2]
    cnt[1]-=cnt[2];
  }
  if(cnt[1]>0) ans+=cnt[1]/4+1;
  cout<<ans<<"\n";
  return 0;
}
