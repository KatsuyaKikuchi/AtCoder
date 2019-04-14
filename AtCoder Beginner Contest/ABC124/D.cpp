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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int k = 0;
    int l = 0;
    ll max = 0;
    REP(i, N)
    {
        if (S[i] == '0')
        {
            if (i == 0 || S[i - 1] == '1')
            {
                k++;
            }
        }
        while (k > K)
        {
            l++;
            if (l >= N)
                break;
            if (S[l] == '1' && S[l - 1] == '0')
                --k;
        }
        max = std::max(max, i - l + 1);
    }
    cout << max << endl;
    return 0;
}