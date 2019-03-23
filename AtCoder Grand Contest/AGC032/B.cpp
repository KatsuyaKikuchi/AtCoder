#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N;
    cin >> N;
    bool o = N % 2 == 1;

    vector<pll> v;
    if (o)
        N--;
    //! 1-N,2-N-1をペアにする
    FOR(i, N + 1, 1)
    {
        FOR(j, N + 1, i + 1)
        {
            if (i + j == N + 1)
                continue;
            v.push_back(pll(i, j));
        }
    }

    if (o)
    {
        REP(i, N)
        {
            v.push_back(pll(i + 1, N + 1));
        }
    }
    cout << v.size() << endl;
    REP(i, v.size())
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}