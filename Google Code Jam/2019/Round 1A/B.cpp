#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int X[7] = {11, 12, 13, 14, 15, 17, 18};
ll S[7];

int main()
{
    std::random_device rnd;
    int T;
    ll N, M;
    cin >> T >> N >> M;
    REP(cs, T)
    {
        memset(S, 0, sizeof(S));
        REP(num, 7)
        {
            REP(i, 18)
            {
                cout << X[num] << " ";
            }
            cout << endl;
            REP(i, 18)
            {
                int s;
                cin >> s;
                S[num] += s;
            }
            S[num] %= X[num];
        }

        FOR(i, M + 1, 1)
        {
            bool e = true;
            REP(j, 7)
            {
                if (i % X[j] != S[j])
                {
                    e = false;
                    break;
                }
            }
            if (e)
            {
                cout << i << endl;
                break;
            }
        }
        int ans;
        cin >> ans;
        if (ans == -1)
        {
            break;
        }
    }
    return 0;
}