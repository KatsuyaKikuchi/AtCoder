#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll X[100005];
int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> X[i].first;
        X[i].second = i + 1;
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, K)
    {
        q.push(X[i]);
    }
    cout << q.top().second << endl;

    FOR(i, N, K)
    {
        pll t = q.top();
        if (t.first > X[i].first)
        {
            q.pop();
            q.push(X[i]);
            t = q.top();
        }
        cout << t.second << endl;
    }
    return 0;
}