#include <bits/stdc++.h>
using namespace std;
const int N= 1e7+5;
vector<bool> p(N,true);
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b,ans=0;
  cin>>a>>b;
  p[0]=p[1]= false;
  for (int i = 2; 1LL*i*i <= b; ++i)
    if (p[i])
      for (int j = i*i; j <= b; j+=i)
        p[j]= 0;
  for (int i = 2; 1LL * i*i*i <= b; ++i)
    if (p[i] && 1LL * i*i*i >= a) ans++;
  vector<int> pr;
  for (int i = 2; i <= b; i++)
    if (p[i]) pr.push_back(i);
  for (int i=0; i<(int)pr.size();++i)
    for (int j = i+1; j<(int)pr.size();++j)
    {
      long long x = 1LL * pr[i] * pr[j];
      if (x > b) break;
      if (x >= a) ans++;
    }
  cout << ans;
}
