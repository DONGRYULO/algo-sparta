/*
	로직)	
	1. 배(0) or 등(1) 정보가 주어질 때 -> A, B, C, D 중 하나 출력
	- case 1 : 0이 4개 -> E
	- case 2 : 0이 3개 1이 1개 -> D
*/


#include <iostream>
using namespace std;

void boj_2490()
{
	// 1	
	for (int cnt = 0; cnt < 3; cnt++) {
		int backCnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int bars[4];
			cin >> bars[i];

			// 등을 기준으로 체크
			if (bars[i] == 1) backCnt++;
		}

		if (backCnt == 3) {
			cout << "A" << endl;
		}
		else if (backCnt == 2) {
			cout << "B" << endl;
		}
		else if (backCnt == 1) {
			cout << "C" << endl;
		}
		else if (backCnt == 0) {
			cout << "D" << endl;
		}
		else {
			cout << "E" << endl;
		}
	}
	
}