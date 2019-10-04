#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[200005];
pll B[200005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    REP(i, M)
    {
        cin >> B[i].first;
        B[i].second = i;
    }
    std::map<ll, pll> m;
    ll num = 0;
    REP(i, N)
    {
        REP(j, M)
        {
            ll s = A[i].first + B[j].first;
            num++;
            if (m.find(s) != m.end())
            {
                pll p = m[s];
                cout << p.first << " " << p.second << " " << A[i].second << " " << B[j].second << endl;
                return 0;
            }
            else
            {
                m.insert(std::make_pair(s, pll(A[i].second, B[j].second)));
            }
        }
        if (num > 5000000)
            break;
    }
    cout << -1 << endl;
    return 0;
}