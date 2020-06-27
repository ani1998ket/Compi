#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while( T-- ){
        long long TS;
        cin >> TS;
        TS = (TS) / ( TS & (-TS) );
        // while( TS % 2 == 0 ){
        //     TS /= 2;
        // } 
        cout << TS / 2 << endl;
    }
	return 0;
}

