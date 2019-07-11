#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string A[105];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll min = INF;
    FOR(w, N, 1)
    {
        FOR(b, N, 1)
        {
            int r = N - (w + b);
            if (r < 1)
                break;
            ll s = 0;
            REP(i, w)
            {
                REP(j, M)
                {
                    if (A[i][j] != 'W')
                        s++;
                }
            }
            REP(i, b)
            {
                REP(j, M)
                {
                    if (A[i + w][j] != 'B')
                        s++;
                }
            }
            REP(i, r)
            {
                REP(j, M)
                {
                    if (A[i + w + b][j] != 'R')
                        s++;
                }
            }
            min = std::min(min, s);
        }
    }
    cout << min << endl;
    return 0;
}