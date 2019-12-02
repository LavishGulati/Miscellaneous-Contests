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

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX 100001
ll tree[4*MAX], lazy[4*MAX];

void update(ll si, ll ei, ll start, ll end, ll id, ll key){
    if(si > ei) return;

    if(lazy[id] != 0){
        tree[id] = lazy[id];

        if(si != ei){
            lazy[2*id] = lazy[id];
            lazy[2*id+1] = lazy[id];
        }

        lazy[id] = 0;
    }

    if(start > ei || end < si) return;
    else if(start <= si && ei <= end){
        tree[id] = key;
        if(si != ei){
            lazy[2*id] = key;
            lazy[2*id+1] = key;
        }
        return;
    }

    ll mid = (si+ei)/2;
    update(si, mid, start, end, 2*id, key);
    update(mid+1, ei, start, end, 2*id+1, key);
    tree[id] = max(tree[2*id], tree[2*id+1]);
}

ll query(ll si, ll ei, ll start, ll end, ll id){
    if(si > ei) return 0;

    if(lazy[id] != 0){
        tree[id] = lazy[id];

        if(si != ei){
            lazy[2*id] = lazy[id];
            lazy[2*id+1] = lazy[id];
        }

        lazy[id] = 0;
    }

    if(start > ei || end < si) return 0;
    else if(start <= si && ei <= end) return tree[id];

    ll mid = (si+ei)/2;
    ll x = query(si, mid, start, end, 2*id);
    ll y = query(mid+1, ei, start, end, 2*id+1);
    return max(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        for(int i = 0; i < 4*MAX; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }

        int response, l, r, p, k;
        while(q--){
            cin >> response;
            if(response == 1){
                cin >> p >> k;
                int maxHeight = query(0, n-1, p-1, p-1+k, 1);
                update(0, n-1, p-1, p-1+k, 1, maxHeight+k);
            }
            else{
                cin >> l >> r;
                cout << query(0, n-1, l-1, r-1, 1) << endl;
            }
        }
    }
}
