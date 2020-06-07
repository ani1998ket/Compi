/* 
 * Needle in the haystack
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len;
    while( cin >> len ){
        cin.ignore();
        string needle;
        string haystack;
        getline( cin, needle );
        while( len-- ){
            char c;
            cin.get( c ); 
            if( c == '\n' )
                break;
            haystack.push_back( c );
        }
        if( haystack.length() < needle.length() ){
            cout << endl;
            continue;
        }

        int index = 0;
        while( cin ){
            if( haystack == needle ){
                cout << index << endl;
            }
            char c;
            index++;
            cin.get(c);
            if( c == '\n' ){
                break;
            }
            haystack.erase(0, 1);
            haystack.push_back(c);
        } 
        cout << "\n";
    }
    return 0;
}

