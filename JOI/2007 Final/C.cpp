#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll G[3005];
bool M[5005][5005];
int z[2] = {1, -1};

int main()
{
    ll N;
    cin >> N;
    memset(M, 0, sizeof(M));
    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
        M[G[i].first][G[i].second] = true;
    }
    ll max = 0;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            ll dx = abs(G[i].first - G[j].first);
            ll dy = abs(G[i].second - G[j].second);
            REP(k, 2)
            {
                pll p0(G[i].first + z[k] * dy, G[i].second - z[k] * dx);
                pll p1(G[j].first + z[k] * dy, G[j].second - z[k] * dx);
                if (p0.first < 0 || p0.second < 0 || p1.first < 0 || p1.second < 0)
                    continue;
                if (p0.first > 5000 || p0.second > 5000 || p1.first > 5000 || p1.second > 5000)
                    continue;
                if (M[p0.first][p0.second] && M[p1.first][p1.second])
                {
                    max = std::max(max, dx * dx + dy * dy);
                    break;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}