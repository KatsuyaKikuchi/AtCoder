#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll R[105], B[105];
bool U[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> R[i].first >> R[i].second;
    }
    REP(i, N)
    {
        cin >> B[i].first >> B[i].second;
    }
    sort(B, B + N, [](pll a, pll b) { return a.first < b.first; });

    int sum = 0;
    REP(i, N)
    {
        int index = -1;
        REP(j, N)
        {
            if (U[j])
                continue;
            if (R[j].first >= B[i].first || R[j].second >= B[i].second)
                continue;

            if (index == -1)
                index = j;
            else
            {
                if (R[index].second < R[j].second)
                    index = j;
            }
        }
        if (index >= 0)
        {
            U[index] = true;
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}