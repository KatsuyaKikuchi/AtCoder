#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double H[105], W[105];

int main()
{
    int T;
    cin >> T;
    REP(t, T)
    {
        int N;
        double P;
        cin >> N >> P;
        double sum = 0;
        REP(i, N)
        {
            cin >> H[i] >> W[i];
            sum += (H[i] + W[i]) * 2;
        }
        double ans = sum;

        //! small caseのみの回答
        REP(i, N)
        {
            double u = sqrt(H[i] * H[i] + W[i] * W[i]);
            double l = std::min(H[i], W[i]);
            if (sum + 2 * u * (i + 1) < P)
                ans = sum + 2 * u * (i + 1);
            else if (sum + 2 * l * (i + 1) <= P)
                ans = P;
            else
                break;
        }
        cout << "Case #" << t + 1 << ": " << OF64 << ans << endl;
    }
    return 0;
}