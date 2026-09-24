#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  bool nt[1000001];
  int p[1000001];
  fill(nt, nt+1000001, true);
  nt[0]=nt[1]=false;
  for (int i=2; i*i <= 1000000; ++i)
    if (nt[i])
      for (int j = i*i; j <= 1000000; j+=i)
        nt[j] = false;
  p[0]=0;
  for (int i=1; i<=1000000; ++i)
    p[i] = p[i-1] + nt[i];
  int n;
  cin>>n;
  while (n--)
  {
    int a,b;
    cin >>a>>b;
    cout << p[b] - p[a-1] << '\n';
  }
  return 0;
}
