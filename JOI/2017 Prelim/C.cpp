#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string Map[105];

int main()
{
    ll N, M, D;
    cin >> N >> M >> D;
    REP(i, N)
    {
        cin >> Map[i];
    }

    ll ans = 0;
    REP(h, N)
    {
        REP(w, M)
        {
            //! 横に
            {
                bool e = true;
                REP(i, D)
                {
                    if (w + i >= M || Map[h][w + i] == '#')
                    {
                        e = false;
                        break;
                    }
                }
                if (e)
                    ans++;
            }
            //! 縦に
            {
                bool e = true;
                REP(i, D)
                {
                    if (h + i >= N || Map[h + i][w] == '#')
                    {
                        e = false;
                        break;
                    }
                }
                if (e)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}