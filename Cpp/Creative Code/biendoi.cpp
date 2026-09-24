#include <bits/stdc++.h>
using namespace std;
int n;
long long p,m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >>n;
  vector<long long> a(n+1),d(n+2);//hiệu 2 pt kề nhau
  for(int i = 0; i<n; i++){
    cin >>a[i];
    d[i]= (i==0)? a[0] : a[i]- a[i-1];
  }
  d[n]=-a[n-1]; //chia theo chiều ngang
  for(int i=0; i<n+1; ++i){
    if (d[i]>0) p+=d[i]; //hạ p
    else m -= d[i]; // nâng m, còn abs(p-m)
  }
  cout<<max(p,m);
  return 0;
}
