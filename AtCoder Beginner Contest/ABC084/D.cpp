#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005];
bool isPrime[100005];

void solve()
{
    REP(i, 100005)
    {
        isPrime[i] = true;
        T[i] = 0;
    }
    isPrime[0] = isPrime[1] = false;
    FOR(i, 100005, 2)
    {
        T[i] = T[i - 1];
        if (!isPrime[i])
            continue;
        if (isPrime[(i + 1) / 2])
            T[i]++;
        for (int j = i * 2; j < 100005; j += i)
            isPrime[j] = false;
    }
}

int main()
{
    solve();
    int Q;
    cin >> Q;
    REP(i, Q)
    {
        int l, r;
        cin >> l >> r;
        cout << T[r] - T[l - 1] << endl;
    }
    return 0;
}