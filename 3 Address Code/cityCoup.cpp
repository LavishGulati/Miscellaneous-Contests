#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        pll *points = new pll[n];
        for(ll i = 0; i < n; i++){
            cin >> points[i].f >> points[i].s;
        }

        ll K[n];
        for(ll i = 0; i < n; i++) cin >> K[i];
        sort(K, K+n);

        vector<ll> sumDistance;

        for(ll i = 0; i < n; i++){
            ll sum = 0;
            for(ll j = 0; j < n; j++){
                sum += abs(points[i].f-points[j].f)+abs(points[i].s-points[j].s);
            }
            sumDistance.pb(sum);
        }

        sort(all(sumDistance));
        ll total = 0;
        for(ll i = 0; i < n; i++){
            total += K[i]*sumDistance[n-1-i];
        }

        cout << total << endl;
    }
}
