#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<pll, bool> m;
ll num[10];

int main()
{
    ll H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<pll> v;
    REP(i, N)
    {
        pll g(0, 0);
        cin >> g.first >> g.second;
        m[g] = true;
        for (int x = -1; x <= 1; ++x)
        {
            for (int y = -1; y <= 1; ++y)
            {
                ll nx = g.first + x, ny = g.second + y;
                if (nx <= 1 || ny <= 1 || nx >= H || ny >= W)
                    continue;
                v.push_back(pll(nx, ny));
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    memset(num, 0, sizeof(num));
    REP(i, v.size())
    {
        int n = 0;
        for (int x = -1; x <= 1; ++x)
        {
            for (int y = -1; y <= 1; ++y)
            {
                ll nx = v[i].first + x, ny = v[i].second + y;
                if (m[pll(nx, ny)])
                    n++;
            }
        }
        num[n]++;
    }

    num[0] = (H - 2) * (W - 2) - v.size();
    REP(i, 10)
    {
        cout << num[i] << endl;
    }
    return 0;
}