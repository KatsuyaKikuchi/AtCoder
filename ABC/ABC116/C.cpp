#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i];
    }

    ll sum = 0;
    int index = 0;
    while (index < N)
    {
        if (H[index] == 0)
        {
            index++;
            continue;
        }

        ll min = H[index];
        int i = index;
        for (; i < N; ++i)
        {
            if (H[i] > 0)
            {
                min = std::min(min, H[i]);
                continue;
            }
            break;
        }
        sum += min;
        FOR(j, i, index)
        {
            H[j] -= min;
        }
    }
cout << sum << endl;
return 0;
}