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
    int T, W;
    cin >> T >> W;
    REP(cs, T)
    {
        // vector<ll> t;
        // REP(i, 6)
        // {
        //     int n;
        //     cin >> n;
        //     t.push_back(n);
        // }

        if (W == 2)
        {
            cout << "0 0 0 0 0 0" << endl;
            int r;
            cin >> r;
            if (r == -1)
                break;
            continue;
        }
        vector<ll> v;
        REP(w, W)
        {
            cout << 2 + w << endl;
            ll n = 0;
            // REP(i, 6)
            // {
            //     ll k = pow(2LL, (2 + w) / (i + 1)) * t[i];
            //     cout << k << " ";
            //     n += k;
            // }
            //cout << endl;
            cin >> n;
            v.push_back(n);
        }

        ll p1, p2, p3, p4, p5, p6;
        p1 = (v[5] - v[4]) / 64;
        p3 = (v[1] - v[0]) - 4 * p1;
        p5 = (v[3] - v[2]) - 16 * p1;
        ll p26 = (v[4] - v[3]) - 2 * p3 - 32 * p1;
        ll p24 = (v[2] - v[1]) - 8 * p1;
        p2 = (p26 + p24 - v[0] + 4 * p1 + p3 + p5) / 4;
        p4 = p24 - 2 * p2;
        p6 = p26 - 4 * p2;
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << endl;
        int r;
        cin >> r;
        if (r == -1)
            break;
    }
    return 0;
}