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
    ll N;
    cin >> N;
    vector<ll> S;
    ll p = pow(2LL, N);
    REP(i, p)
    {
        ll s;
        cin >> s;
        S.push_back(s);
    }
    sort(S.begin(), S.end(), [](ll a, ll b) { return a > b; });
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    q.push(pll(S[0], N));
    multiset<ll> set;
    REP(i, p - 1)
    {
        set.insert(-S[i + 1]);
    }
    set.insert(0);
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (t.second == 0)
            continue;

        auto n = set.lower_bound(-t.first + 1);
        // cout << t.first << " " << -(*n) << endl;
        if (*n == 0)
        {
            cout << "No" << endl;
            return 0;
        }
        set.erase(n);
        q.push(pll(-(*n), t.second - 1));
        q.push(pll(t.first, t.second - 1));
    }
    cout << "Yes" << endl;
    return 0;
}