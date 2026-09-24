#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    vector<int> arr;
    int a,b,c; cin>>a>>b>>c;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    sort(arr.begin(),arr.end());
    cout<<arr[1]<<"\n";
  }

  return 0;
}
