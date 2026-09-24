#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int X, Y, K;
    cin >> n >> X >> Y >> K;
    vector<int> keo_thoa_man;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a >= X && a <= Y) {
            keo_thoa_man.push_back(a);
        }
    }
    sort(keo_thoa_man.begin(), keo_thoa_man.end());
    int res = 0;
    long long cur = 0;
    for (int a : keo_thoa_man) {
        if (cur + a <= K) {
            cur += a;
            res++;
        } else {
            break;
        }
    }
    cout << res << "\n";
    return 0;
}
