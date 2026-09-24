#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  if(n==1) {cout<<"1"; return 0;}
  if(n==2||n==3){cout<<"NO SOLUTION"; return 0;}
  if(n==4){cout<<"2 4 1 3"; return 0;}
  vector<int> odd, even;
  for (int i=n; i>=1; i--){
    if(i%2) even.push_back(i);
    else odd.push_back(i);
  }
  for(int i=0; i<even.size(); ++i){
    cout<<even[i]<<" ";
  }
  for(int i=0; i<odd.size(); ++i){
    cout<<odd[i]<<" ";
  }
  return 0;
}
