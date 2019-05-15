#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll R[100005];

int main()
{
    ll N, D;
    cin >> N >> D;
    REP(i, N)
    {
        cin >> R[i];
    }
    R[N] = INF;
    sort(R, R + N);
    ll ans = 0;
    REP(i, N)
    {
        int ok = i + 1, ng = N;
        while (abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (R[mid] - R[i] <= D)
                ok = mid;
            else
                ng = mid;
        }

        if (ok < N && ok - i >= 2)
        {
            ll t = ok - i;
            ans += t * (t - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}