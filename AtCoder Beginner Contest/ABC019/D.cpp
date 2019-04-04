#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    vector<pll> node;
};

Vertex V[55];

int main()
{
    int N;
    cin >> N;
    //! 頂点0と他の頂点の距離を調べる
    vector<pll> v;
    FOR(i, N, 1)
    {
        cout << "? 1 " << i + 1 << endl;
        ll dis;
        cin >> dis;
        v.push_back(pll(i, dis));
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.second < b.second; });
    int j = v[v.size() - 1].first;
    ll max = 0;
    REP(i, N)
    {
        if (j == i)
            continue;
        cout << "? " << i + 1 << " " << j + 1 << endl;
        ll dis;
        cin >> dis;
        max = std::max(dis, max);
    }
    cout << "! " << max << endl;
    return 0;
}