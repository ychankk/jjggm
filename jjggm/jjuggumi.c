// ���� �Լ�

// 2023-2 ������α׷��� ����: �޲ٹ� ����

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);
void intro(void);

// low �̻� high ���� ������ �߻���Ű�� �Լ�
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("�÷��̾� ��: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true; // ��������� true���� �־��־� ǥ��
	}

	return 0;
}

void intro() {
	system("cls");
	// ASCII ��Ʈ ���
	printf(
		"     ___    ___  _   _  _____  _____  _   _ ___  ___ _____\n"
		"   | _  |  |_  || | | ||  __ | | __ || | | ||  |/  ||_   _|\n"
		"      | |    | || | | || |  |/| |  |/| | | || .  . |  | |\n"
		"      | |    | || | | || | __ | | __ | | | || ||/| |  | |\n"
		" /|__ / //|__/ /| |_| || |_| || |_| || |_| || |  | | _| |_\n"
		"|_____ /|_____ /|____ /|____ /|____ /|____ /|_|  |_|/ ___ /\n"
	);
	Sleep(5000); //5�� ����
	system("cls"); // �ܼ�ȭ�� �����

}

void ending() {
	system("cls"); // �ܼ�ȭ�� �����
	printf(" _____    ___  ___  ___ _____   _____  _   _  _____ ______\n");
	printf("| __  |  / _ ||  |/  ||  ___| |  _  || | | ||  ___ |  ___ |\n");
	printf("| | |/  / /_||| .  . || |__   | | | || | | || |__  | |_/ /\n");
	printf("| | __ | ___||| | /| ||  __|  | | | || | | ||  __| |  _  |\n");
	printf("| |_  || |  ||| |  | || |___  | |/ / | |/ / | |___ | | | |_\n");
	printf("|____/ |_|  |||_|  |_||_____| | __/  |___/  |____ /|_| |__/\n");
	printf("\n");

	/* // ����ڰ� 1���϶� (�⸻���� �� ���� �ڵ�)
	int winner = 0;for (int i = 0; i < n_player; i++) {
		if (player[i] == 1) {
			winner = i;
		}
	}
	*/


	Sleep(2000);
	printf("����ڴ� �ٷιٷ�~~~~~~\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("�����մϴ�!!\n");
	Sleep(1000);
	printf("456���� ���ΰ���!!\n");
	Sleep(1000);
	// printf("%d!!!!!!\n", winner);
	for (int i = 0; i < n_player; i++) if (player[i] == 1) printf("%d ", i);
	printf("!!!!!!\n");
}

int main(void) {
	jjuggumi_init();
	intro();
	//sample();
	mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	ending();



	return 0;
}


