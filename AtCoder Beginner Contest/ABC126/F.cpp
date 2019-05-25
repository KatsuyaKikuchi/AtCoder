
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[300000];

int main()
{
    ll M, K;
    cin >> M >> K;

    ll t = pow(2, M) - 1;
    ll xr = 0;
    REP(i, t + 1)
    {
        xr ^= i;
    }

    if (K == 0)
    {
        REP(i, pow(2, M + 1))
        {
            cout << i / 2 << " ";
        }
        cout << endl;
        return 0;
    }

    memset(U, 0, sizeof(U));
    if (xr xor K == K)
    {
        vector<ll> n;
        REP(i, 32)
        {
            if (((K >> i) & 1) == 1)
            {
                ll m = 1LL << i;
                if (m > t)
                {
                    cout << -1 << endl;
                    return 0;
                }
                n.push_back(m);
                U[m] = true;
            }
        }

        vector<ll> ans;
        REP(i, t + 1)
        {
            if (U[i])
                continue;
            ans.push_back(i);
        }
        REP(i, n.size())
        {
            ans.push_back(n[i]);
        }
        for (ll i = t; i >= 0; --i)
        {
            if (U[i])
                continue;
            ans.push_back(i);
        }
        for (int i = n.size() - 1; i >= 0; --i)
        {
            ans.push_back(n[i]);
        }

        REP(i, ans.size())
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}