#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll ans[1005];

bool solve(int R, int C)
{
    if (R < 4 && C < 4)
        return false;
    if (C >= 4)
    {
        vector<bool> u(C, false);
        u[0] = true;
        int last = -1;
        REP(i, C)
        {
            int c = -1;
            if (i == 0 || (C % 2 == 1 && R > 2))
                c = i;
            else
            {
                for (int j = C - 1; j >= 0; --j)
                {
                    if (u[j])
                        continue;
                    if (j == last || j == last + R - 1 || -j == R - 1 - last)
                        continue;
                    c = j;
                    u[j] = true;
                    break;
                }
            }
            if (c == -1)
                return false;
            REP(j, R)
            {
                if (j % 2 == 0)
                    last = c;
                else
                    last = (c + 2) % C;
                ans[i * R + j] = pll(j, last);
            }
        }
    }
    else
    {
        vector<bool> u(R, false);
        u[0] = true;
        int last = -1;
        REP(i, R)
        {
            int r = -1;
            if (i == 0 || (R % 2 == 1 && C > 2))
                r = i;
            else
            {
                for (int j = R - 1; j >= 0; --j)
                {
                    if (u[j])
                        continue;
                    if (j == last || j == last + C - 1 || -j == C - 1 - last)
                        continue;
                    r = j;
                    u[j] = true;
                    break;
                }
            }
            if (r == -1)
                return false;
            REP(j, C)
            {
                if (j % 2 == 0)
                    last = r;
                else
                    last = (r + 2) % R;
                ans[i * C + j] = pll(last, j);
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    REP(cs, T)
    {
        int R, C;
        cin >> R >> C;

        if (solve(R, C))
        {
            cout << "Case #" << cs + 1 << ": POSSIBLE" << endl;
            int test[30][30];
            memset(test, 0, sizeof(test));
            REP(i, R * C)
            {
                cout << ans[i].first % R + 1 << " " << ans[i].second % C + 1 << endl;
                test[ans[i].first % R][ans[i].second % C] = i + 1;
            }
            // REP(i, R)
            // {
            //     REP(j, C)
            //     {
            //         cout << setw(3)<<test[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        else
        {
            cout << "Case #" << cs + 1 << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}