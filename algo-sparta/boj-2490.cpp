/*
	����)	
	1. ��(0) or ��(1) ������ �־��� �� -> A, B, C, D �� �ϳ� ���
	- case 1 : 0�� 4�� -> E
	- case 2 : 0�� 3�� 1�� 1�� -> D
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

			// ���� �������� üũ
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