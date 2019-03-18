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
ll B[100005];

int main()
{
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    REP(i, N)
    {
        cin >> A[i];
    }
    A[N] = INF;
    REP(i, M)
    {
        cin >> B[i];
    }
    B[M] = INF;

    ll S = 0;
    ll ans = 0;
    while (S < INF)
    {
        {
            ll ok = N, ng = -1;
            while (abs(ok - ng) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (A[mid] >= S)
                    ok = mid;
                else
                    ng = mid;
            }
            S = A[ok] + X;
        }
        {
            ll ok = M, ng = -1;
            while (abs(ok - ng) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (B[mid] >= S)
                    ok = mid;
                else
                    ng = mid;
            }
            S = B[ok] + Y;
            if (ok < M)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}