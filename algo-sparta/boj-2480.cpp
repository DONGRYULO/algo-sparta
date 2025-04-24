/*
	로직)
	1. 3개 주사위를 던진 눈을 배열에 입력받음 (O)
	2. 같은 눈을 체크 하는 변수를 만들어서 3회 반복문 이후 같은 눈 여부 체크 (O)
	- 같은 눈을 체크하는 로직
	3. 같은 눈 여부 체크에 따른 상금 계산 (O)

	걸린시간)
	1시간 30
*/

#include <iostream>
using namespace std;

struct DiceResult {
	int sameDiceCnt;
	int sameDiceInfo;
};

DiceResult sameDiceCheck(int* dices) {
	int maxSameDice = 1;
	int sameDiceInfo;
	// [0] ~ [2]의 주사위를 기준으로 지정해서 3*3의 반복문 돌면서 같은 눈이 가장 큰 수를 출력
	for (int i = 0;i < 3;i++) {
		int sameCnt = 1;
		for (int j = 0;j < 3;j++) {
			if (i == j) continue;

			if (dices[i] == dices[j]) {
				sameCnt++;
			}
		}
		if (sameCnt > maxSameDice) {
			maxSameDice = sameCnt;
			sameDiceInfo = dices[i];
		}
	}

	// 모두 다른 눈일 경우 가장 큰 눈 추출
	if (maxSameDice == 1) {
		int maxDice = dices[0];
		for (int i = 1;i < 3;i++) {
			if (dices[i] > maxDice) maxDice = dices[i];
		}
		sameDiceInfo = maxDice;
	}

	// 같은눈 개수, 개수에 따른 같은 눈(같은눈 or 가장 큰 눈) -> 2가지 값 배열로 리턴
	// Q. 구조체는 return이 되고 배열은 return 값으로 사용할 수 없는 이유 정확히 집고 넘어가기
	DiceResult diceResult;
	diceResult.sameDiceCnt = maxSameDice;
	diceResult.sameDiceInfo = sameDiceInfo;

	return diceResult;
}

int prizeCalculation(const DiceResult* diceResult) {
	int prizeCash = 0;
	if (diceResult->sameDiceCnt == 3) {
		prizeCash = 10000 + (diceResult->sameDiceInfo * 1000);
	}
	else if (diceResult->sameDiceCnt == 2) {
		prizeCash = 1000 + (diceResult->sameDiceInfo * 100);
	}
	else {
		prizeCash = diceResult->sameDiceInfo * 100;
	}
	return prizeCash;
}

void boj_2480()
{
	// 1
	int dices[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> dices[i];
	}

	// 2
	DiceResult diceResult = sameDiceCheck(dices);

	// 3
	int prizeCash = prizeCalculation(&diceResult);

	cout << prizeCash;	
}


