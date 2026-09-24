#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> a(n);
  priority_queue<int,vector<int>,greater<int>> pq;
  long long sum=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<k; i++){
    pq.push(a[i]);
    sum+=a[i];
  }
  cout<<sum<<"\n";
  for (int i=k; i<n; i++){
    if(a[i]>pq.top()){
      sum-=pq.top();
      sum+=a[i];
      pq.pop();
      pq.push(a[i]);
    }
    cout<<sum<<"\n";
  }

}
