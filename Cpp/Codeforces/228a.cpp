#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s1,s2,s3,s4; cin>>s1>>s2>>s3>>s4;
  set<int> cnt;
  cnt.insert(s1);
  cnt.insert(s2);
  cnt.insert(s3);
  cnt.insert(s4);
  cout<<4-cnt.size()<<"\n";
  return 0;
}
