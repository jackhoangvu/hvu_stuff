#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  set<long long> s;
  long long k=1;
  int i=0;
  while(t--){
    int type; cin>>type;
    if(type==1){
      long long val; cin>>val;
      s.insert(val);
    }
    else if(type==2){
      string st; cin>>st;
      if(st=="plus") k++;
      else k--;
    }
    else{
      auto it=s.begin();
      advance(it,k-1);
      cout<<*it<<"\n";
    }
  }
  return 0;
}
