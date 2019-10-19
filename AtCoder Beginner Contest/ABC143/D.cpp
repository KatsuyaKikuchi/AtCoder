#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[2005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> L[i];
    }
    sort(L, L + N);
    ll ans = 0;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            ll a = L[i];
            ll b = L[j];
            ll ok = j, ng = N;
            while (abs(ok - ng) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (L[mid] < a + b)
                    ok = mid;
                else
                    ng = mid;
            }
            ans += ok - j;
        }
    }
    cout << ans << endl;
    return 0;
}