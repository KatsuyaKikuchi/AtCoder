#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
ll B[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, N)
    {
        cin >> B[i];
        q.push(pll(B[i], i));
    }

    ll ans = 0;
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (t.first <= A[t.second])
            continue;
        ll s = B[(N + t.second - 1) % N] + B[(t.second + 1) % N];
        ll m = std::max(B[(N + t.second - 1) % N], B[(t.second + 1) % N]);
        ll sec = std::max(m, A[t.second]);
        ll k = (t.first - sec + s - 1) / s;
        t.first = B[t.second] = t.first - k * s;
        ans += k;
        if (t.first < A[t.second])
            break;
        q.push(t);
    }

    bool exist = true;
    REP(i, N)
    {
        if (A[i] != B[i])
            exist = false;
    }

    if (exist)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}