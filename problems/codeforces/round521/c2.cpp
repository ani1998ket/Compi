//Good array 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i, start, end, d) for( int i = (start); i < (end); i += (d) )
 
void solve(){
    int N;
    cin >> N;
    vector<int> arr( N, 0 );
    map< int, vector<int> > pos_map;
    set<int> result;
    long long sum = 0;
    int index = 0;
    for( auto& e : arr ){
        cin >> e;
        sum += e;
        pos_map[ e ].push_back( index );
        index++;
    }
    index = 0;
    for( auto& e : arr ){
        long long to_find = sum - 2 * e;
        if( to_find > INT_MAX ){
            continue;
        } 
        for( auto i : pos_map[ to_find ] ){
            if( i != index ){
                result.insert( i + 1 );
            }
        }
        index++;
    }
    cout << result.size() << endl;
    for( auto e : result ){
        cout << e << " ";
    }
     
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
 
	while( T-- ){
	    solve();
	}
	return 0;
}
