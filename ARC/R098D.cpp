#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];

//! xrとnの各bitを調べ、共に1が立っているところがないか確認する
bool check(ll xr, ll n)
{
    for (; xr > 0 && n > 0; xr >>= 1, n >>= 1)
    {
        if ((xr & 1) == 1 && (n & 1) == 1)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll xr = 0;
    int pi = 0;
    ll ans = 0;
    REP(i, N)
    {
        if (!check(xr, A[i]))
        {
            FOR(j, i, pi)
            {
                xr = xr xor A[j];
                if (check(xr, A[i]))
                {
                    pi = j + 1;
                    break;
                }
            }
        }
        xr = xr xor A[i];
        ans += i - pi + 1;
    }
    cout << ans << endl;
    return 0;
}