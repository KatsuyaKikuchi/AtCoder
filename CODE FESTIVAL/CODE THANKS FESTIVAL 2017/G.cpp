#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool C[50][50];
//! 後半N/2個最大値
ll X[2000000];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        REP(j, N)
        {
            C[i][j] = false;
        }
    }

    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        C[a][b] = C[b][a] = true;
    }

    vector<ll> p, q;
    ll n = (N / 2) + N % 2;
    REP(i, pow(2, N - n))
    {
        ll m = 0;
        REP(j, N - n)
        {
            m = std::max(X[i & (~(1 << j))], m);
        }

        bool e = false;
        REP(j, N - n)
        {
            if (((i >> j) & 1) == 0)
                continue;
            REP(k, N - n)
            {
                if (((i >> k) & 1) == 0)
                    continue;
                if (C[n + j][n + k])
                {
                    e = true;
                    break;
                }
            }
            if (e)
                break;
        }
        if (!e)
        {
            ll t = 0;
            REP(j, N - n)
            {
                if (((i >> j) & 1) == 1)
                    t++;
            }
            m = std::max(m, t);
        }
        X[i] = m;
    }

    ll max = 0;
    REP(i, pow(2, n))
    {
        bool e = false;
        REP(j, n)
        {
            if (((i >> j) & 1) == 0)
                continue;
            REP(k, n)
            {
                if (((i >> k) & 1) == 0)
                    continue;
                if (C[j][k])
                {
                    e = true;
                    break;
                }
            }
            if (e)
                break;
        }
        if (e)
            continue;
        ll t = 0;
        REP(j, n)
        {
            if (((i >> j) & 1) == 1)
                t++;
        }

        ll m = 0;
        REP(j, n)
        {
            if (((i >> j) & 1) == 0)
                continue;
            REP(k, N - n)
            {
                if (!C[j][n + k])
                    m |= (1 << k);
            }
        }
        REP(j, n)
        {
            if (((i >> j) & 1) == 0)
                continue;
            REP(k, N - n)
            {
                if (C[j][n + k])
                    m &= ~(1 << k);
            }
        }

        max = std::max(max, t + X[m]);
    }
    cout << max << endl;
    return 0;
}