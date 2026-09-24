#include <bits/stdc++.h>
using namespace std;
int n;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<long long> a(n);
    long long max_val = -2e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    int ans = 0;
    if (max_val > 1000000) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrime(a[i] + a[j])) ans++;
            }
        }
    }
    else {
        int max = 2000000;
        vector<bool> p(max+1, true);
        p[0] = p[1] = false;
        for (int i=2; i*i <= max; i++) {
            if (p[i]) {
                for (int j = i * i; j <= max; j += i) p[j] = false;
            }
        }

        for (int i=0; i< n; i++) {
            for (int j= i+1; j<n; j++) {
                long long s = a[i] + a[j];
                if (s >= 2 && s <= max && p[s]) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
