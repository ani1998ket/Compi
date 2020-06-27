// Cutting Out
#include <bits/stdc++.h>
using namespace std;

class myelem{
    public:
    int elem;
    int count;
    int priority;

    myelem( int e, int p ){
        elem = e;
        priority = p;
        count = 1;
    }

    friend bool operator< ( const myelem& e1, const myelem& e2 ){
        return e1.priority < e2.priority;
    }
};
void solve(){
    int N, K;
    cin >> N >> K;
    unordered_map<int, int> count_map;
    count_map.reserve( 2 * N + 1 );
    for( int i = 0; i < N; i++ ){
        int e;
        cin >> e;
        count_map[ e ]++;
    }
    priority_queue< myelem > pq;
    for( auto i = count_map.begin(); i != count_map.end(); i++ ){
       myelem elem( i->first, i->second ); 
       pq.push( elem );
    }

    vector<int> result(K, 0);
    for( auto& e: result ){
        auto high = pq.top();
        pq.pop(); 
        e = high.elem;
        high.count++;
        high.priority = count_map[ e ] / high.count;
        pq.push( high );
    }

    for( auto e : result ){
        cout << e << " ";
    }
    cout << endl;

}   
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;

	while( T-- ){
	    solve();
	}
	return 0;
}
