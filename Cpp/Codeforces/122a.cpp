#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> nums={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
  for (int i=0; i<nums.size(); i++){
    if(n%nums[i]==0){cout<<"YES"; return 0;}
  }
  cout<<"NO";
  return 0;
}
