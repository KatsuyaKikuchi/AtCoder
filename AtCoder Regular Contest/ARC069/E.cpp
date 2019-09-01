#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    memset(B, 0, sizeof(B));
    vector<pll> v;
    vector<ll> index;
    v.push_back(pll(0, 0));
    index.push_back(0);
    ll n = 0;
    REP(i, N)
    {
        if (A[i] > n)
        {
            v.push_back(pll(A[i], 1));
            index.push_back(i);
            n = A[i];
            continue;
        }
        ll ok = v.size() - 1, ng = 0;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (A[i] <= v[mid].first)
                ok = mid;
            else
                ng = mid;
        }

        B[index[ok]] += A[i] - v[ok - 1].first;
        v[ok - 1].second++;
    }

    for (int i = v.size() - 1; i > 0; --i)
    {
        B[index[i]] += (v[i].first - v[i - 1].first) * v[i].second;
        v[i - 1].second += v[i].second;
    }

    REP(i, N)
    {
        cout << B[i] << endl;
    }
    return 0;
}