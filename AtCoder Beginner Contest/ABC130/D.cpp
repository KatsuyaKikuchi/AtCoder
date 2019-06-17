#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll S[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    S[0] = 0;
    REP(i, N)
    {
        S[i + 1] += A[i] + S[i];
    }
    S[N + 1] = INF;

    ll ans = 0;
    REP(i, N)
    {
        ll ok = N, ng = i - 1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            ll s = S[mid + 1] - S[i];
            if (s >= K)
                ok = mid;
            else
                ng = mid;
        }
        ans += N - ok;
    }
    cout << ans << endl;
    return 0;
}