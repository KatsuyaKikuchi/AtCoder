#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[105];
ll x[3] = {1, 1, 0};
ll y[3] = {0, 1, 1};
int main()
{
    ll H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> M[i];
    }

    for (int h = H - 1; h >= 0; --h)
    {
        for (int w = W - 1; w >= 0; --w)
        {
            if (M[h][w] == '#')
                continue;
            bool win = false;
            REP(i, 3)
            {
                ll nh = x[i] + h, nw = y[i] + w;
                if (nh >= H || nw >= W)
                    continue;
                if (M[nh][nw] == '#')
                    continue;

                if (M[nh][nw] == 'x')
                {
                    win = true;
                    break;
                }
            }
            if (win)
                M[h][w] = 'o';
            else
                M[h][w] = 'x';
        }
    }

    if (M[0][0] == 'o')
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}