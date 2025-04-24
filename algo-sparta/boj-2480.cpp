/*
	����)
	1. 3�� �ֻ����� ���� ���� �迭�� �Է¹��� (O)
	2. ���� ���� üũ �ϴ� ������ ���� 3ȸ �ݺ��� ���� ���� �� ���� üũ (O)
	- ���� ���� üũ�ϴ� ����
	3. ���� �� ���� üũ�� ���� ��� ��� (O)

	�ɸ��ð�)
	1�ð� 30
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
	// [0] ~ [2]�� �ֻ����� �������� �����ؼ� 3*3�� �ݺ��� ���鼭 ���� ���� ���� ū ���� ���
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

	// ��� �ٸ� ���� ��� ���� ū �� ����
	if (maxSameDice == 1) {
		int maxDice = dices[0];
		for (int i = 1;i < 3;i++) {
			if (dices[i] > maxDice) maxDice = dices[i];
		}
		sameDiceInfo = maxDice;
	}

	// ������ ����, ������ ���� ���� ��(������ or ���� ū ��) -> 2���� �� �迭�� ����
	// Q. ����ü�� return�� �ǰ� �迭�� return ������ ����� �� ���� ���� ��Ȯ�� ���� �Ѿ��
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


