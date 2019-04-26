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
    ll N;
    cin >> N;
    ll sum = 0;
    FOR(i, N + 1, 1)
    {
        sum += i;
        if (sum > N)
        {
            cout << "No" << endl;
            return 0;
        }
        if (sum < N)
            continue;

        cout << "Yes" << endl;
        int k = 2 * N / i;
        cout << k << endl;
        vector<vector<int>> S(k);
        int index = 0;
        int h = 1;
        FOR(j, N + 1, 1)
        {
            S[index].push_back(j);
            S[index + h++].push_back(j);
            if (S[index].size() == i)
            {
                ++index;
                h = 1;
            }
        }

        REP(j, k)
        {
            cout << i;
            REP(n, i)
            {
                cout << " " << S[j][n];
            }
            cout << endl;
        }
        break;
    }
    return 0;
}