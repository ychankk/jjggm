// 메인 함수

// 2023-2 고급프로그래밍 과제: 쭈꾸미 게임

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);
void intro(void);

// low 이상 high 이하 난수를 발생시키는 함수
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("플레이어 수: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true; // 살아있음을 true값을 넣어주어 표기
	}

	return 0;
}

void intro() {
	system("cls");
	// ASCII 아트 출력
	printf(
		"     ___    ___  _   _  _____  _____  _   _ ___  ___ _____\n"
		"   | _  |  |_  || | | ||  __ | | __ || | | ||  |/  ||_   _|\n"
		"      | |    | || | | || |  |/| |  |/| | | || .  . |  | |\n"
		"      | |    | || | | || | __ | | __ | | | || ||/| |  | |\n"
		" /|__ / //|__/ /| |_| || |_| || |_| || |_| || |  | | _| |_\n"
		"|_____ /|_____ /|____ /|____ /|____ /|____ /|_|  |_|/ ___ /\n"
	);
	Sleep(5000); //5초 지연
	system("cls"); // 콘솔화면 지우기

}

void ending() {
	system("cls"); // 콘솔화면 지우기
	printf(" _____    ___  ___  ___ _____   _____  _   _  _____ ______\n");
	printf("| __  |  / _ ||  |/  ||  ___| |  _  || | | ||  ___ |  ___ |\n");
	printf("| | |/  / /_||| .  . || |__   | | | || | | || |__  | |_/ /\n");
	printf("| | __ | ___||| | /| ||  __|  | | | || | | ||  __| |  _  |\n");
	printf("| |_  || |  ||| |  | || |___  | |/ / | |/ / | |___ | | | |_\n");
	printf("|____/ |_|  |||_|  |_||_____| | __/  |___/  |____ /|_| |__/\n");
	printf("\n");

	/* // 우승자가 1명일때 (기말과제 때 쓰일 코드)
	int winner = 0;for (int i = 0; i < n_player; i++) {
		if (player[i] == 1) {
			winner = i;
		}
	}
	*/


	Sleep(2000);
	printf("우승자는 바로바로~~~~~~\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("...........\n");
	Sleep(1000);
	printf("축하합니다!!\n");
	Sleep(1000);
	printf("456억의 주인공은!!\n");
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


