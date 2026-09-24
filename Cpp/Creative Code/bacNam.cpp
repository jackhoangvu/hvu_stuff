#include <bits/stdc++.h>
using namespace std;
int n,p[200005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i=1; i<=n; ++i){
    int a; cin>>a;
    p[a]= i;
  }
  int ans1= 1, e=p[1];
  for (int i=3; i<= n- 1; i+=2){
    if (p[i]< e) ans1++;
    e =p[i];
  }
  int ans2= 1, f=p[2];
  for (int i=4; i<= n; i+=2){
    if (p[i]< f) ans2++;
    f =p[i];
  }
  cout<< ans1<< "\n"<<ans2;
  return 0;
}
