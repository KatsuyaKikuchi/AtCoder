#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll W[40];

int main()
{
    ll N, X;
    cin >> N >> X;
    REP(i, N)
    {
        cin >> W[i];
    }

    ll n = N / 2;
    vector<ll> p, q;
    REP(i, pow(2, n))
    {
        ll t = 0;
        REP(j, n)
        {
            if (((i >> j) & 1) == 1)
                t += W[j];
        }
        p.push_back(t);
    }
    REP(i, pow(2, N - n))
    {
        ll t = 0;
        REP(j, N - n)
        {
            if (((i >> j) & 1) == 1)
                t += W[n + j];
        }
        q.push_back(t);
    }
    sort(q.begin(), q.end());

    ll ans = 0;
    REP(i, p.size())
    {
        ll a = p[i];
        ll low = q.size() - 1, lowng = -1;
        while (abs(low - lowng) > 1)
        {
            ll mid = (low + lowng) / 2;
            if (q[mid] + a >= X)
                low = mid;
            else
                lowng = mid;
        }
        if (a + q[low] != X)
            continue;
        ll up = 0, upng = q.size();
        while (abs(up - upng) > 1)
        {
            ll mid = (up + upng) / 2;
            if (q[mid] + a <= X)
                up = mid;
            else
                upng = mid;
        }
        ans += (up - low + 1);
    }
    cout << ans << endl;
    return 0;
}