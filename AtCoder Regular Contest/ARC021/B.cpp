#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[100005];

int main()
{
    ll N;
    cin >> N;
    ll x = 0;
    REP(i, N)
    {
        cin >> B[i];
        x ^= B[i];
    }

    if (x != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<ll> v;
        v.push_back(0);
        REP(i, N - 1)
        {
            v.push_back(B[i] ^ v[v.size() - 1]);
        }
        REP(i, N)
        {
            cout << v[i] << endl;
        }
    }

    return 0;
}