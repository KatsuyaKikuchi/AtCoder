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
ll A[105];
bool U[105];

string solve()
{
    sort(A, A + N);
    memset(U, 0, sizeof(U));
    vector<pll> v;
    v.push_back(pll(A[N - 1], 0));
    U[N - 1] = true;
    if (A[N - 1] != A[N - 2])
        return "Impossible";
    while (true)
    {
        bool e = false;
        REP(i, N)
        {
            if (U[i])
                continue;
            ll a = A[i];
            REP(j, v.size())
            {
                ll f = v[j].first;
                ll s = v[j].second;
                ll b = std::max(f - 1, s + 1);
                if (a != b)
                    continue;
                if ((f - 1 <= s + 1 && f > s) || (f - 1 >= s + 1))
                {
                    if (j != v.size() - 1)
                        continue;
                }
                e = true;
                v.push_back(pll(a, s + 1));
                U[i] = true;
                break;
            }
            if (e)
                break;
        }
        if (!e)
            break;
    }

    REP(i, N)
    {
        if (!U[i])
            return "Impossible";
    }
    return "Possible";
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    cout << solve() << endl;
    return 0;
}