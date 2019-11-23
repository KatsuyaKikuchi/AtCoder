#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(20)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
pll X[10];
vector<vector<ll>> V;

void dfs(vector<ll> v)
{
    if (v.size() == N)
    {
        V.push_back(v);
        return;
    }

    REP(i, N)
    {
        bool e = false;
        REP(j, v.size())
        {
            if (v[j] == i)
            {
                e = true;
                break;
            }
        }
        if (e)
            continue;
        v.push_back(i);
        dfs(v);
        v.pop_back();
    }
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> X[i].first >> X[i].second;
    }

    V.resize(0);
    vector<ll> v;
    dfs(v);

    double s = 0;
    REP(i, V.size())
    {
        auto t = V[i];
        REP(j, N - 1)
        {
            double x = X[t[j]].first - X[t[j + 1]].first;
            double y = X[t[j]].second - X[t[j + 1]].second;
            s += sqrt(x * x + y * y);
        }
    }

    s = (s / (double)(V.size()));
    cout << OF64 << s << endl;
    return 0;
}