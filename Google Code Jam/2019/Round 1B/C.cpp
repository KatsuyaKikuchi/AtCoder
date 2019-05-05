#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[100005];
ll D[100005];
ll LMC[100005], RMC[100005];
ll LMD[100005], RMD[100005];

int main()
{
    int T;
    cin >> T;
    REP(cs, T)
    {
        ll N, K;
        cin >> N >> K;
        REP(i, N)
        {
            cin >> C[i];
        }
        REP(i, N)
        {
            cin >> D[i];
        }
#if false
        memset(LMC, 0, sizeof(LMC));
        memset(RMC, 0, sizeof(RMC));
        memset(LMD, 0, sizeof(LMD));
        memset(RMD, 0, sizeof(RMD));
        REP(i, N)
        {
            if (i > 0)
            {
                LMC[i] = std::max(C[i], LMC[i - 1]);
                LMD[i] = std::max(D[i], LMD[i - 1]);
                RMC[N - 1 - i] = std::max(C[N - 1 - i], RMC[N - i]);
                RMD[N - 1 - i] = std::max(D[N - 1 - i], RMD[N - i]);
            }
            else
            {
                LMC[i] = C[i];
                LMD[i] = D[i];
                RMC[N - 1 - i] = C[N - 1 - i];
                RMD[N - 1 - i] = D[N - 1 - i];
            }
        }
        ll ans = 0;
        REP(i, N)
        {
            if (abs(LMC[i] - LMD[i]) <= K)
                ans += i + 1;
            if ((abs(LMC[i] - RMD[i + 1]) <= K || abs(LMD[i] - RMC[i + 1]) <= K) && abs(RMC[i + 1] - RMD[i + 1]) > K)
                ans -= N - 1 - i;
        }
#else
        ll ans = 0;
        if (N <= 200)
        {
            REP(l, N)
            {
                FOR(r, N, l)
                {
                    ll c = 0;
                    FOR(i, r + 1, l)
                    {
                        c = std::max(c, C[i]);
                    }
                    ll d = 0;
                    FOR(i, r + 1, l)
                    {
                        d = std::max(d, D[i]);
                    }
                    if (abs(c - d) <= K)
                        ans++;
                }
            }
        }
#endif
        cout << "Case #" << cs + 1 << ": " << ans << endl;
    }
    return 0;
}