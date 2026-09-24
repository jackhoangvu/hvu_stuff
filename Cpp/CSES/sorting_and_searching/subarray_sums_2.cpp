#include <bits/stdc++.h>

using namespace std;
int a[200005];
long long sum=0, cnt=0;
map<long long,int> freq={{0,1}};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  for (int i=0; i<n; i++){
    cin>>a[i];
    sum+=a[i];

    if(freq.find(sum-x)!=freq.end()){
      cnt+=freq[sum-x];
    }
    freq[sum]++;
  }
  cout<<cnt<<"\n";
  return 0;
}
