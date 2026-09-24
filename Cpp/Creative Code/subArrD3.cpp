#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q, r0[100005],r1[100005], r2[100005];
  cin>>n>>q;
  r0[0]=0;
  r1[0]=0;
  r2[0]=0;
  for(int i=1; i<=n; ++i){
    int x;cin>>x;
    r0[i]=r0[i-1];
    r1[i]=r1[i-1];
    r2[i]=r2[i-1];
    if(x %3==0) r0[i]++;
    else if(x% 3==1) r1[i]++;
    else r2[i]++;
  }
  for (int i=0; i<q; i++){
    int l,r;
    cin>>l>>r;
    int a0= r0[r]-r0[l-1],
        a1= r1[r]-r1[l-1],
        a2= r2[r]-r2[l-1];
    cout<< a0* (a0-1)/2 *1LL +a1*a2* 1LL<<'\n';
  }
  return 0;
}
