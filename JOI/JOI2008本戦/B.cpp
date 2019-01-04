#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll d[100005];
int main()
{
    ll D, N, M;
    cin >> D >> N >> M;
    d[0] = 0;
    REP(i, N - 1)
    {
        cin >> d[i + 1];
    }
    sort(d, d + N);
    ll sum = 0;
    REP(i, M)
    {
        ll k;
        cin >> k;
        int ok = 0, ng = N;
        while (abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (d[mid] <= k)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        sum += min(k - d[ok], abs((D + d[(ok + 1) % N]) - k) % D);
    }
    cout << sum << endl;
    return 0;
}