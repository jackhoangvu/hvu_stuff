#include <bits/stdc++.h>

using namespace std;

long long n;
string st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n)) return 0;
    if (!(cin >> st)) return 0;
    vector<int> lp(256, -1);
    vector<int> id_res(n);
    for (int i = 0; i < n; i++) {
        char cur = st.at(i);
        id_res[i] = lp[cur];
        lp[cur] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << id_res[i] << " ";
    }

    return 0;
}
