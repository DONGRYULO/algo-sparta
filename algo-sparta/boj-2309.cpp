/*
	로직)
	1. 9개의 값이 주어지는데 그 중에서 7개 조합으로 100이 될때의 7개 조합을 오름차순으로 출력
	- 단, 7개로 조합이 100이 되는 경우가 여러개인 경우 아무거나 출력
*/

#include <iostream>
#include <algorithm>
using namespace std;

void boj_2309()
{
	int arr[9];
	int res[7]; // 100이 될 때의 모든 요소가 들어있는 배열
	int total = 0; // 7개의 수를 합쳐서 100이 되는 값	

	// 1. 입력 
	for (int i = 0;i < 9;i++) {
		cin >> arr[i];
	}
	
	// 2. 로직 
	// ex) 3명 중에서 2명을 제외한다고 가정
	// A, B, C -> (A,B), (A,C), (B,C) -> C, B, A 순으로 하나씩 체크
	bool flag = false;
	for (int i = 0;i < 7 && !flag;i++) { // n명 중에서 n-2명을 제외한 모든 경우의 수(제외될 [i] 요소를 기준으로 잡음)		
		for (int j = i + 1;j < 9;j++) { // n-2명을 제외하기 때문에 [i]를 제외한 나머지 요소들을 제외기준으로 잡음
			total = 0;
			// 나머지 n-2명 저장
			for (int a = 0, idx = 0;a < 9;a++) {
				if (a != i && a != j) {
					res[idx++] = arr[a];
					total += arr[a];
				}
			}
			// 7개의 합이 100인 경우
			if (total == 100) {
				flag = true;
				break;
			}
		}
	}	

	// 3. res 오름차순 정렬
	sort(res, res + 7);
	for (int i = 0;i < 7;i++) {
		cout << res[i] << endl;
	}
}