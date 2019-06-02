#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int K[15];
int S[15][15];
int P[15];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> K[i];
        REP(j, K[i])
        {
            cin >> S[i][j];
            S[i][j]--;
        }
    }
    REP(i, M)
    {
        cin >> P[i];
    }

    ll ans = 0;
    REP(i, pow(2, N))
    {
        int m = 0;
        REP(j, M)
        {
            int t = 0;
            REP(k, K[j])
            {
                if (((i >> S[j][k]) & 1) == 1)
                    t++;
            }
            if (t % 2 == P[j])
                m++;
        }

        if (m == M)
            ans++;
    }
    cout << ans << endl;
    return 0;
}