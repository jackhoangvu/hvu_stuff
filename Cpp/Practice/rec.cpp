#include <bits/stdc++.h>

using namespace std;
int n;
int a[16];
int cnt=0;
set<tuple<int,int,int>> s;
void rec(int i,int sum1,int sum2,int sum3){
  if(i==n){
    if(sum1<=sum2&&sum1<sum3&&sum2<sum3){
      cnt++;
      return;
    }
  }
  rec(i+1,sum1+a[i],sum2,sum3);
  rec(i+1,sum1,sum2+a[i],sum3);
  rec(i+1,sum1,sum2,sum3+a[i]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  rec(0,0,0,0);
  cout<<cnt<<"\n";
}
