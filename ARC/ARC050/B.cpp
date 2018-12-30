#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll R, B, x, y;

bool check(ll n)
{
    ll r = R - n, b = B - n;
    if (r < 0 || b < 0)
        return false;
    return r / (x - 1) + b / (y - 1) >= n;
}

int main()
{
    cin >> R >> B >> x >> y;

    ll ok = 0, ng = max(R, B) + 1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}
