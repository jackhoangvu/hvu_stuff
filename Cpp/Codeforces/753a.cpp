#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  if(n==1) {cout<<"1"<<"\n"<<"1"; return 0;}
  if(n==2) {cout<<"1"<<"\n"<<"2"; return 0;}
  vector<int> val;
  int sum=0;
  int i=1;
  while(sum<n){
    if(sum+i<=n) val.push_back(i);
    else {val.back()+=n-sum; break;}
    sum+=i;
    i++;
  }
  cout<<val.size()<<"\n";
  for (int i=0; i<val.size(); i++){
    cout<<val[i]<<" ";
  }
  return 0;
}
