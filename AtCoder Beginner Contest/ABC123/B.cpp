#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[5];

ll dfs(vector<int> v)
{
    if (v.size() == 5)
    {
        ll t = 0;
        REP(i, 4)
        {
            t += A[v[i]];
            t += (10 - t % 10) % 10;
        }
        t += A[v[4]];
        return t;
    }

    ll min = INF;
    REP(i, 5)
    {
        bool e = false;
        REP(j, v.size())
        {
            if (i == v[j])
                e = true;
        }
        if (e)
            continue;
        v.push_back(i);
        min = std::min(min, dfs(v));
        v.pop_back();
    }
    return min;
}

int main()
{
    ll t = 0;
    REP(i, 5)
    {
        cin >> A[i];
    }

    vector<int> v;
    cout << dfs(v) << endl;
    return 0;
}