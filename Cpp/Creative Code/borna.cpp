#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int n = s.size();
  unordered_set<int> st;
  int cur= 0;
  bool isnum = false;
  for (int i = 0; i < n; i++)
  {
    if (isdigit(s[i]))
    {
      cur = cur * 10 + (s[i] - '0');
      isnum = true;
    }
    else
    {
      if (isnum)
      {
        st.insert(cur);
        cur = 0;
        isnum = false;
      }
    }
  }
  if (isnum) st.insert(cur);
  cout << st.size();
  return 0;
}
