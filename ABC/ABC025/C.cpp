#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int B[10], C[10];

pll dfs(vector<int> v, int i = 0)
{
    if (i == v.size())
    {
        pll s(0, 0);
        //! Bの計算
        REP(j, 3)
        {
            REP(i, 2)
            {
                int a = 3 * i + j;
                int b = 3 * (i + 1) + j;
                if (v[a] == v[b])
                    s.first += B[a];
                else
                    s.second += B[a];
            }
        }

        //! Cの計算
        REP(i, 3)
        {
            REP(j, 2)
            {
                int a = 3 * i + j;
                int b = 3 * i + j + 1;
                if (v[a] == v[b])
                    s.first += C[2 * i + j];
                else
                    s.second += C[2 * i + j];
            }
        }
        return s;
    }

    pll max(0, 0);
    REP(j, v.size())
    {
        if (v[j] >= 0)
            continue;

        vector<int> t = v;
        t[j] = i % 2;
        pll m = dfs(t, i + 1);

        if (i % 2 == 0)
            max = max.first > m.first ? max : m;
        else
            max = max.second > m.second ? max : m;
    }
    return max;
}

int main()
{
    REP(i, 6)
    {
        cin >> B[i];
    }
    REP(i, 6)
    {
        cin >> C[i];
    }

    vector<int> v(9, -1);
    pll m = dfs(v);
    cout << m.first << endl;
    cout << m.second << endl;
    return 0;
}