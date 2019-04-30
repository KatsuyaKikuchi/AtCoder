#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool u[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<int> p;
    for (int i = 2; i < 100005; ++i)
    {
        if (u[i])
            continue;
        p.push_back(i);
        for (int j = i; j < 100005; j += i)
            u[j] = true;
    }

    vector<int> t;
    REP(i, p.size())
    {
        while (N % p[i] == 0)
        {
            t.push_back(p[i]);
            N /= p[i];
        }
        if (N == 1)
            break;
    }
    if (N > 1)
        t.push_back(N);

    if (t.size() < K)
        cout << "-1" << endl;
    else
    {
        REP(i, K - 1)
        {
            cout << t[i] << " ";
        }
        ll s = 1;
        FOR(i, t.size(), K - 1)
        {
            s *= t[i];
        }
        cout << s << endl;
    }

    return 0;
}