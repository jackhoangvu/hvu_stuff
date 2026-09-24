#include <bits/stdc++.h>
using namespace std;
const long long MxN=2e5+5;
bool p[MxN];
int pr[MxN], pt=0;
bool sang(){
  fill(p,p+MxN,true);
  p[0]=p[1]=false;
  for (int i=2; i*i<MxN; i++){
    for(int j=i*i; j<MxN; j+=i){
      p[j]=false;
    }
  }
  for (int i=2; i<MxN; i++){
    if(p[i]) pr[pt++]=i;
  }
  return true;
}
void solve(){
  int n; long long a[100005]; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int j=0; j<pt; j++){
    bool ok=false;
    for (int i=0; i<n; i++){
      if(gcd((long long)pr[j],a[i])==1){
        ok=true;
        break;
      }
    }
    if(ok){
      cout<<pr[j]<<"\n"; return;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  sang();
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
