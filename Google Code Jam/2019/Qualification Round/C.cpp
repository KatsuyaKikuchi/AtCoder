#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main()
{
    int T;
    cin >> T;
    REP(t, T)
    {
        ll N;
        ll L;
        cin >> N >> L;
        vector<ll> S;
        REP(i, L)
        {
            ll s;
            cin >> s;
            S.push_back(s);
        }

        //! 1番目の素数だけ求める
        ll tmp = 2;
        FOR(i, N + 1, 2)
        {
            if (S[0] % i == 0)
            {
                tmp = i;
                break;
            }
        }
        //! 1番目の素数はt,S[0]/tのどちらか
        ll K[2] = {tmp, S[0] / tmp};
        REP(k, 2)
        {
            ll d = K[k];
            vector<ll> ans;
            vector<ll> T;
            ans.push_back(d);
            T.push_back(d);
            bool e = true;
            REP(i, L)
            {
                if (S[i] % d != 0)
                {
                    e = false;
                    break;
                }
                ll n = S[i] / d;
                T.push_back(n);
                ans.push_back(n);
                d = n;
            }
            if (!e)
                continue;
            sort(T.begin(), T.end());
            unique(T.begin(), T.end());

            cout << "Case #" << t + 1 << ": ";
            REP(i, ans.size())
            {
                REP(j, T.size())
                {
                    if (ans[i] != T[j])
                        continue;
                    cout << (char)('A' + j);
                    break;
                }
            }
            cout << endl;
            break;
        }
    }
    return 0;
}