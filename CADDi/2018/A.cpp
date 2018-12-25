#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<int> primeList;
bool isPrime[1000005];
void calcPrime()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 1000005; i += 1)
    {
        if (isPrime[i])
        {
            continue;
        }
        primeList.push_back(i);
        for (int j = i; j < 1000005; j += i)
        {
            isPrime[j] = true;
        }
    }
}

ll pn[1000005];

int main()
{
    ll N, P;
    cin >> N >> P;
    calcPrime();
    int i = 0;
    while (i < primeList.size())
    {
        ll p = primeList[i];
        if (P % p == 0)
        {
            P /= p;
            pn[p]++;
            continue;
        }
        i++;
        if (P == 1)
        {
            break;
        }
    }
    ll sum = 1;
    if (N == 1)
        sum = P;
    REP(j, 1000005)
    {
        ll n = pn[j] / N;
        sum *= pow(j, n);
    }
    cout << sum << endl;
    return 0;
}