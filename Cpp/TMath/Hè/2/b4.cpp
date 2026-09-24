#include <bits/stdc++.h>

using namespace std;
long long pr(long long n){
  if(n<=1) return false;
  long long cnt=0;
  long long mx=sqrt(n);
  for(int i=1; i<=mx; i++){
    if(n%i==0){
      cnt++;
      if(i*i!=n) cnt++;
    }
  }
  // cout<<cnt<<"\n\n\n";
  return cnt;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b; cin>>a>>b;
  int x=pr(a),y=pr(b);
  if(x>y) cout<<a<<"\n";
  else if(x<y) cout<<b<<"\n";
  else cout<<(a<b?b:a)<<"\n";
  if(x!=y) cout<<abs(x-y);
  return 0;
}
