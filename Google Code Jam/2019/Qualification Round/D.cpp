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
    int T;
    cin >> T;
    REP(time, T)
    {
        int N, B, F;
        cin >> N >> B >> F;
        vector<string> back;
        ll q = 1;
        for (int f = 0; f < F; ++f)
        {
            q <<= 1;
            string p;
            p.clear();
            REP(i, N)
            {
                int num = (i % q) / (q / 2);
                p.push_back((char)(num + '0'));
            }
            cout << p << endl;
            string b;
            cin >> b;
            back.push_back(b);
        }

        vector<ll> v;
        REP(i, N - B)
        {
            ll s = 0;
            REP(j, back.size())
            {
                s += ((ll)(back[j][i] - '0') << j);
            }
            v.push_back(s);
        }

        vector<bool> u(N + 1, false);
        int vi = 0;
        ll d = 1 << F;
        REP(i, N)
        {
            if ((i % d) != v[vi])
                continue;
            u[i] = true;
            vi++;
        }
        string ans = "";
        REP(i, N)
        {
            if (!u[i])
            {
                string s = to_string(i);
                ans += s;
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        cout << ans << endl;
    }
    return 0;
}