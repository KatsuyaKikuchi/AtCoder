#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[105];
bool U[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> B[i];
    }
    bool c = true;
    REP(i, N)
    {
        if (B[i] > i + 1)
            c = false;
    }
    if (!c)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> v;
    //! 後ろの要素から入れていく
    REP(i, N)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            if (U[j] || B[j] > i + 1)
                continue;
            //! B[j]を入れたい
            bool c = true;
            FOR(k, N, j + 1)
            {
                if (B[j] > B[k] && !U[k])
                {
                    c = false;
                    break;
                }
            }
            int n = 0;
            REP(k, j)
            {
                if (U[k])
                    n++;
            }
            if (!c || n < B[j] - 1)
                continue;
            v.push_back(B[j]);
            U[j] = true;
            break;
        }
    }

    REP(i, v.size())
    {
        cout << v[i] << endl;
    }
    return 0;
}