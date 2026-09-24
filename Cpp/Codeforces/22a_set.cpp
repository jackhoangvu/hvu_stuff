#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[105]; cin>>n;
  set<int> s;
  for (int i=0; i<n; i++){
    cin>>a[i];
    s.insert(a[i]);
  }
  if(s.size()<2){
    cout<<"NO";
    return 0;
  }
  else{
    auto it=s.begin();
    it++;
    cout<<*it<<"\n";
    return 0;
  }
  cout<<"NO";
  return 0;
}
