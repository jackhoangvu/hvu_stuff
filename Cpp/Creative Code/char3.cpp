#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>s;

  long long right[3] = {0}, left[3] = {0};
  long long ans = 0;
  //all right=> check if s[i] is b =>check a,b,c a,c,d b,a,c ,...
  for (char c : s){
    if (c >= 'a' && c <= 'c') right[c -'a']++; }
  for (char c : s){
    if (c >= 'a' && c <= 'c')
    {
      int i = c - 'a';
      right[i]--;
      if (i == 0){ans += left[1] * right[2] + left[2] * right[1];}
      else if (i == 1) ans += left[0] * right[2] + left[2] * right[0];
      else ans += left[0] * right[1] + left[1] * right[0];
      left[i]++;
    }
  }
  cout << ans;
  return 0;
}
