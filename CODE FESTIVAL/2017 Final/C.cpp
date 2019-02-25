#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[15];

int get(ll n)
{
    ll min = 12;
    REP(i, 24)
    {
        FOR(j, 24, i + 1)
        {
            if (((n >> i) & 1) == 0 || ((n >> j) & 1) == 0)
                continue;
            min = std::min(min, std::min(j - i, 24 + i - j));
        }
    }
    return min;
}

int solve(ll n = 0, int index = 0)
{
    if (index > 12)
        return get(n);

    if (T[index] == 0)
        return solve(n, index + 1);

    ll n0 = 1 << index;
    ll n1 = 1 << ((24 - index) % 24);
    if (T[index] == 2)
        return solve(n | n0 | n1, index + 1);
    return std::max(solve(n | n0, index + 1), solve(n | n1, index + 1));
}

int main()
{
    int N;
    cin >> N;
    T[0] = 1;
    REP(i, N)
    {
        int d;
        cin >> d;
        T[d]++;
    }

    bool isZero = false;
    REP(i, 13)
    {
        if (T[i] > 2)
            isZero = true;
    }
    if (T[0] > 1 || T[12] > 1)
        isZero = true;

    int ans = 0;
    if (!isZero)
    {
        ans = solve();
    }
    cout << ans << endl;
    return 0;
}