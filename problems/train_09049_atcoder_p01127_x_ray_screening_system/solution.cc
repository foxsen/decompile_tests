
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void solve(){

	string strs[] = { "SAFE", "SUSPICIOUS" };

	int h, w;
	cin >> h >> w;

	vector< string > screen( h );
	vector< bool > flg( 26, false );

	for( int i = 0; i < h; i++ )
		cin >> screen[ i ];
	
	bool fig = true;

	while( fig ) {

		fig = false;

		for( int x = 0; x < w; x++ ) {
			for( int y = 0; y < h; y++ ) {
				char ch = screen[ y ][ x ];
				if( ch == '.' || ch == '*' ) continue;
				int stx = w, sty = h, edx = -1, edy = -1;
				for( int tx = 0; tx < w; tx ++ ) {
					for( int ty = 0; ty < h; ty ++ ) {
						if( screen[ty][tx] == ch ) {
							stx = min( stx, tx );
							sty = min( sty, ty );
							edx = max( edx, tx );
							edy = max( edy, ty );
						}
					}
				}
				//長方形判定
				bool fillflg = true;
				for( int tx = stx; tx <= edx && fillflg; tx ++ ) {
					for( int ty = sty; ty <= edy && fillflg; ty ++ ) {
						fillflg &= ( screen[ ty ][ tx ] == ch || screen[ ty ][ tx ] == '*' );
					}
				}
				fig |= fillflg;
				if( fillflg ) {
					flg[ ch - 'A' ] = false;
					for( int tx = stx; tx <= edx && fillflg; tx ++ ) {
						for( int ty = sty; ty <= edy && fillflg; ty ++ ) {
							screen[ ty ][ tx ] = '*';
						}
					}
				}

			}
		}

		
		
	}

	bool b = false;
	for( int x = 0; x < w; x++ ) {
		for( int y = 0; y < h; y++ ) {
			b |= ( screen[ y ][ x ] != '.' && screen[ y ][ x ] != '*' );
		}
	}
	cout << strs[ b ] << endl;


}

int main( void ) {


	int n;
	cin >> n;

	for( int i = 0; i < n; i++ )
		solve();

	return 0;

}