#include <iostream>
#include <algorithm>
using namespace std;int main(){int a,b,c,x,y;cin>>a>>b>>c>>x>>y;bool co=false;if(min(a,b)<=min(x,y)&&max(a,b)<=max(x,y)) co = true;if(min(a,c)<=min(x,y)&&max(a,c)<=max(x,y)) co=true;if (min(b,c) <= min(x,y)&&max(b,c)<=max(x,y))co=true;if(co) cout<<"CO";else cout<<"KHONG";return 0;}
