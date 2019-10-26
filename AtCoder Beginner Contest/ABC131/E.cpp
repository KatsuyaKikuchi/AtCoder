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
    ll N, K;
    cin >> N >> K;
    vector<pll> ans;
    vector<ll> v(N, 0);
    FOR(i, N, 1)
    {
        if (K == 0)
        {
            //! 今まで使った頂点全てと辺を結ぶ
            REP(j, i)
            {
                ans.push_back(pll(j, i));
            }
            continue;
        }
        ll mi = 0;
        REP(j, i)
        {
            if (v[mi] < v[j])
                mi = j;
        }
        K -= v[mi];
        REP(j, ans.size())
        {
            if (K >= 0)
                break;
            ll a = ans[j].first;
            ll b = ans[j].second;
            if (a == mi)
            {
                ans.push_back(pll(b, i));
                K++;
            }
            else if (b == mi)
            {
                ans.push_back(pll(a, i));
                K++;
            }
        }
        ans.push_back(pll(mi, i));
        v[mi]++;
        v[i]++;
    }

    if (K > 0)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        REP(i, ans.size())
        {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }

    return 0;
}