#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll D[200005];
int main()
{
    ll M;
    cin >> M;
    REP(i, M)
    {
        cin >> D[i].first >> D[i].second;
    }

    ll ans = 0;
    vector<ll> v;
    REP(i, M)
    {
        vector<ll> t;
        ll p = D[i].second;
        ll n = D[i].first;
        while (p > 1)
        {
            ans += p / 2LL;
            if (p % 2LL == 1)
                t.push_back(n);
            p /= 2LL;
            n = 2 * n;
            if (n >= 10)
            {
                ans += p;
                n = (n % 10) + 1;
            }
        }
        t.push_back(n);

        stack<ll> s;
        REP(j, t.size())
        {
            s.push(t[t.size() - 1 - j]);
        }
        while (s.size() > 1)
        {
            ll a = s.top();
            s.pop();
            ll b = s.top();
            s.pop();

            ans++;
            ll m = a + b;
            if (m >= 10)
            {
                m = (m % 10) + 1;
                ans++;
            }
            s.push(m);
        }
        ll top = s.top();
        v.push_back(top);
    }

    {
        stack<ll> s;
        REP(i, v.size())
        {
            s.push(v[v.size() - 1 - i]);
        }

        while (s.size() > 1)
        {
            ll a = s.top();
            s.pop();
            ll b = s.top();
            s.pop();

            ans++;
            ll n = a + b;
            if (n >= 10)
            {
                n = (n % 10) + 1;
                ans++;
            }
            s.push(n);
        }
    }

    cout << ans << endl;
    return 0;
}