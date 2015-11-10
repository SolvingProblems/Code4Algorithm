#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#define DEBUG 0

using namespace std;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int M = 0, N = 0;
	unsigned int R = 0;

	cin >> M >> N >> R;

	int smallValue = M<N ? M : N;
	unsigned int mat[M][N] = {};
	unsigned int pat[M][N] = {};

	int xPt[4] = { 1, 0, -1, 0 };
	int yPt[4] = { 0, 1, 0, -1 };

	for (int i = 0; i<M; i++){
		for (int j = 0; j<N; j++){
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i<M; i++){
		for (int j = 0; j<N; j++){
			pat[i][j] = 0;
		}
	}

#if DEBUG
	for (int i = 0; i<M; i++){
		for (int j = 0; j<N; j++){
			cout << pat[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

#endif

	//R array make real;

	int arrR[smallValue / 2] = { 0, };

	for (int i = 0; i<M / 2; i++){
		if ((2 * (M + N - 2) - 8 * i) == 0){
			arrR[i] = 0;
		}
		else{
			arrR[i] = R % (2 * (M + N - 2) - 8 * i);
		}

#if DEBUG
		cout << arrR[i] << endl;
#endif

	}
#if DEBUG
	cout << endl;
#endif

	for (int i = 0; i<smallValue / 2; i++){
		int forcnt = 0;
		int size = 2 * (M + N - 2) - 8 * i;
		int stack[size] = {};
		int x = i, y = i;
		int st_X = 0, st_Y = 0, st_XY = 0;;
		int cnt = 0;
		int xy = 0;
#if DEBUG
		cout << endl << "0===========================" << endl;
#endif
		while (1){
#if DEBUG
			cout << "x: " << x << " y : " << y << endl;
#endif
			stack[cnt] = mat[x][y];
			if ((x == i      &&y == i      && cnt != 0)
				|| (x == (M - 1 - i) && y == i)
				|| (x == (M - 1 - i) && y == (N - 1 - i))
				|| (x == i      &&y == (N - 1 - i))){
#if DEBUG
				cout << "^" << endl;
#endif
				xy++;
				xy = xy % 4;
			}
			x += xPt[xy];
			y += yPt[xy];

			if (x == i && y == i){
				break;
			}
			cnt++;
			if (cnt == arrR[i]){
				st_X = x, st_Y = y, st_XY = xy;
#if DEBUG
				cout << "##################" << endl;
				cout << "st_X : " << st_X << endl;
				cout << "st_Y : " << st_Y << endl;
				cout << "st_XY : " << st_XY << endl;
				cout << "##################" << endl;
#endif
			}
		}

		cnt = 0;
#if DEBUG
		cout << endl << "1===========================" << endl;
#endif
		int tempx = st_X, tempy = st_Y;
		while (1){
#if DEBUG
			//cout << "st_X: " << st_X << " st_Y : " << st_Y << endl;
#endif
			pat[st_X][st_Y] = stack[cnt];
			if ((st_X == i      &&st_Y == i      && cnt != 0)
				|| (st_X == (M - 1 - i) && st_Y == i)
				|| (st_X == (M - 1 - i) && st_Y == (N - 1 - i))
				|| (st_X == i      &&st_Y == (N - 1 - i))){
#if DEBUG
				cout << "^" << endl;
#endif
				st_XY++;
				st_XY = st_XY % 4;
			}
			st_X += xPt[st_XY];
			st_Y += yPt[st_XY];

			if (st_X == tempx && st_Y == tempy){
				break;
			}
			cnt++;

		}
#if DEBUG
		cout << endl << "2===========================" << endl;
#endif
		forcnt++;
#if DEBUG
		cout << "forcnt : " << forcnt << endl;
#endif
	}

	// odd odd case:

	if (M % 2 == 1 && N % 2 == 1){
		mat[M / 2][N / 2] = pat[M / 2][N / 2];
	}

#if DEBUG
	cout << endl;
#endif

	for (int i = 0; i<M; i++){
		for (int j = 0; j<N; j++){
			cout << pat[i][j] << " ";
		}
		cout << endl;
	}







	return 0;
}
