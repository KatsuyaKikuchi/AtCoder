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
    int R, G, B;
    cin >> R >> G >> B;

    ll min = INF;
    for (int l = -(G + B); l <= G + R; ++l)
    {
        //! Gのとる範囲を決める
        int r = l + G - 1;
        ll m = 0;
        if (r < 0)
        {
            m += G * abs(r) + (G - 1) * G / 2;
        }
        else if (l > 0)
        {
            m += G * abs(l) + (G - 1) * G / 2;
        }
        else
        {
            m = abs(l) * (abs(l) + 1) / 2 + abs(r) * (abs(r) + 1) / 2;
        }

        //ll m = abs(l) * (abs(l) + 1) / 2 + abs(r) * (abs(r) + 1) / 2;
        //! Rの和
        if (l <= -100)
        {
            //! R全部をl-1まで移動して、そこから1こずつ
            m += R * (abs(l) - 99) + R * (R - 1) / 2;
        }
        else
        {
            ll rm = INF;
            //! 右側を-100からl-1までのどれにするか
            REP(j, std::min(l + 100, R))
            {
                ll rn = R - (j + 1);
                ll n = j * (j + 1) / 2 + rn * (rn + 1) / 2;
                rm = std::min(rm, n);
            }
            m += rm;
        }

        //! Bの和
        if (r >= 100)
        {
            m += B * (abs(r) - 99) + B * (B - 1) / 2;
        }
        else
        {
            ll bm = INF;
            REP(j, std::min(B, 100 - r))
            {
                ll bn = B - (j + 1);
                ll n = j * (j + 1) / 2 + bn * (bn + 1) / 2;
                bm = std::min(bm, n);
            }
            m += bm;
        }

        min = std::min(m, min);
    }
    cout << min << endl;
    return 0;
}