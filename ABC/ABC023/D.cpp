#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
pll B[100005];

//! score sを取ることが可能か
bool isPossible(ll s)
{
    vector<ll> n;
    REP(i, N)
    {
        ll m = s - B[i].first;
        if (m < 0)
            return false;
        m /= B[i].second;
        n.push_back(m);
    }
    sort(n.begin(), n.end());
    REP(i, N)
    {
        if (n[i] < i)
            return false;
    }
    return true;
}

int main()
{
    cin >> N;
    ll max = 0;
    REP(i, N)
    {
        cin >> B[i].first >> B[i].second;
        max = std::max(max, B[i].first + B[i].second * N);
    }

    ll ok = max, ng = 0;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (isPossible(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}