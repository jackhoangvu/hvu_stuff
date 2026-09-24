#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt[7][7]={},ans= 0,ps= 0,pq= 0;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cnt[0][0]= 1;
  for (int i = 1; i <= n; i++)
  {
    long long x;
    cin >> x;
    ps = (ps+x%7)%7;
    pq=(pq+(x%7)* (x%7)%7)%7;
    for (int s0 = 0; s0 < 7; s0++)
    {
      for (int q0 = 0; q0 < 7; q0++)
      {
        long long ds= ((ps-s0)%7+7) % 7,dq= ((pq-q0)%7+7) % 7;
        if (ds*ds % 7 == dq) ans += cnt[s0][q0];
      }
    }
    cnt[ps][pq]++;
  }
  cout <<ans;
  return 0;
}
