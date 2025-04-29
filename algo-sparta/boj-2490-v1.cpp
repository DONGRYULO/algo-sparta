
#include <iostream>
using namespace std;


void boj_2490_v1()
{
	int backCnt;
	string res = "DCBAE"; // D -> [0, µî 1°³]

	// 1	
	for (int cnt = 0; cnt < 3; cnt++) {
		backCnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int input;
			cin >> input;
			backCnt += input;			
		}
		cout << res[backCnt] << endl;
	}

}