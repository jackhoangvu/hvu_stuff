#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long x, n;
  cin >> x >> n;
  set<long long> s{0,x};
  priority_queue<long long> pq;
  pq.push(x);
  unordered_map<long long,int> dead;
  string ans;
  while (n--){
    long long p;
    cin >> p;
    auto it = s.upper_bound(p);
    long long r = *it;
    long long l = *prev(it);
    dead[r-l]++;
    pq.push(p-l);
    pq.push(r-p);
    s.insert(p);
    while (dead[pq.top()]> 0){
      dead[pq.top()]--;
      pq.pop();
    }
    ans += to_string(pq.top());
    ans += ' ';
  }
  cout << ans << '\n';
  return 0;
}
