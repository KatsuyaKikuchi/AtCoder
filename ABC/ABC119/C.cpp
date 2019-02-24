#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[10];
//! [bitで表される竹を使って][長さiの竹を作るための]=MP
ll mp[300][5];

int main()
{
    int N, S[3];
    cin >> N;
    REP(i, 3)
    {
        cin >> S[i];
    }
    REP(i, N)
    {
        cin >> L[i];
    }

    int m = pow(2, N);
    FOR(i, m, 1)
    {
        ll sum = 0;
        int n = 0;
        REP(j, N)
        {
            if (((i >> j) & 1) == 0)
                continue;
            n++;
            sum += L[j];
        }
        REP(j, 3)
        {
            mp[i][j] = 10 * (n - 1) + abs(sum - S[j]);
        }
    }

    ll min = INF;
    FOR(i, m, 1)
    {
        FOR(j, m, 1)
        {
            FOR(k, m, 1)
            {
                bool f = false;
                REP(l, N)
                {
                    int s = 0;
                    s = ((i >> l) & 1) + ((j >> l) & 1) + ((k >> l) & 1);
                    if (s > 1)
                    {
                        f = true;
                        break;
                    }
                }
                if (f)
                    continue;
                min = std::min(min, mp[i][0] + mp[j][1] + mp[k][2]);
            }
        }
    }
    cout << min << endl;
    return 0;
}