#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[1000];

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int a[2] = {0, 0};
    int ans = 0;
    REP(i, 2 * N - 1)
    {
        if (U[i])
            continue;

        if (S[i] != S[i + 1])
            U[i + 1] = true;
        else
        {
            if (a[(S[i] - '0' + 1) % 2] > 0)
            {
                a[(S[i] - '0' + 1) % 2]--;
            }
            else
            {
                ans++;
                a[S[i] - '0']++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}