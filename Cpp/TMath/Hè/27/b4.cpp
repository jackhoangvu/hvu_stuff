#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x; cin>>x;
  vector<int>m={500,200,100,50,20,10,5,2,1};
  long long cnt=0;
  for(auto j:m){//2tr/500
    cnt+=x/j;
    x%=j;
  }
  cout<<cnt;
  return 0;
}
