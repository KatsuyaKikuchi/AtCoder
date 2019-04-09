#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll R, C, H, V;
string M[105];

string solve(int n)
{
    if (n % ((H + 1) * (V + 1)) != 0)
        return "IMPOSSIBLE";
    if (n == 0)
        return "POSSIBLE";
    n = n / ((H + 1) * (V + 1));
    ll sum = 0;

    vector<int> hi;
    hi.push_back(-1);
    REP(h, R)
    {
        REP(w, C)
        {
            if (M[h][w] == '@')
                sum++;
        }
        if (sum > n * (V + 1))
            return "IMPOSSIBLE";
        if (sum < n * (V + 1))
            continue;
        hi.push_back(h);
        sum = 0;
        if (hi.size() == H + 2)
            break;
    }

    sum = 0;
    vector<int> wi;
    wi.push_back(-1);
    REP(w, C)
    {
        REP(h, R)
        {
            if (M[h][w] == '@')
                sum++;
        }
        if (sum > n * (H + 1))
            return "IMPOSSIBLE";
        if (sum < n * (H + 1))
            continue;

        REP(i, hi.size() - 1)
        {
            int m = 0;
            FOR(j, w + 1, wi[wi.size() - 1] + 1)
            {
                FOR(k, hi[i + 1] + 1, hi[i] + 1)
                {
                    if (M[k][j] == '@')
                        m++;
                }
            }
            if (m != n)
                return "IMPOSSIBLE";
        }
        wi.push_back(w);
        sum = 0;
    }
    return "POSSIBLE";
}

int main()
{
    int T;
    cin >> T;
    REP(t, T)
    {
        cin >> R >> C >> H >> V;
        int n = 0;
        REP(i, R)
        {
            cin >> M[i];
            REP(j, C)
            {
                if (M[i][j] == '@')
                    n++;
            }
        }

        cout << "Case #" << t + 1 << ": " << solve(n) << endl;
    }
    return 0;
}