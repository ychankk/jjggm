// ȭ�� ��°� ����� �ڵ�

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "jjuggumi.h"
#include "canvas.h"

#define DIALOG_DURATION_SEC		2

void draw(void);
void print_status(void);

// (zero-base) row��, col���� Ŀ�� �̵�
void gotoxy(int row, int col) {
	COORD pos = { col,row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// row��, col���� ch ���
void printxy(char ch, int row, int col) {
	gotoxy(row, col);
	printf("%c", ch);
}

void printxy_str(char* ch, int row, int col) {
	gotoxy(row, col);
	printf("%s", ch);
}

void map_init(int n_row, int n_col) {
	// �� ���۸��� ������ ����
	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			back_buf[i][j] = front_buf[i][j] = ' ';
		}
	}

	N_ROW = n_row;
	N_COL = n_col;
	for (int i = 0; i < N_ROW; i++) {
		// ���Թ� �̷��� �� �� �ִµ� �Ϻη� �� ����������
		back_buf[i][0] = back_buf[i][N_COL - 1] = '#';

		for (int j = 1; j < N_COL - 1; j++) {
			back_buf[i][j] = (i == 0 || i == N_ROW - 1) ? '#' : ' ';
		}
	}
}

// back_buf[row][col]�� �̵��� �� �ִ� �ڸ����� Ȯ���ϴ� �Լ�
bool placable(int row, int col) {
	if (row < 0 || row >= N_ROW ||
		col < 0 || col >= N_COL ||
		back_buf[row][col] != ' ') {
		return false;
	}
	return true;
}

// ��ܿ� ����, �ϴܿ��� ���� ���¸� ���
void display(void) {
	draw();
	gotoxy(N_ROW + 4, 0);  // �߰��� ǥ���� ������ ������ �ʰ� ����â ������ �� ������ ���
	print_status();
}

void draw(void) {
	for (int row = 0; row < N_ROW; row++) {
		for (int col = 0; col < N_COL; col++) {
			if (front_buf[row][col] != back_buf[row][col]) {
				front_buf[row][col] = back_buf[row][col];
				printxy(front_buf[row][col], row, col);
			}
		}
	}
}

void print_status(void) {
	printf("no. of players left: %d   \n", n_alive);
	for (int p = 0; p < n_player; p++) {
		printf("player %2d: %5s\n", p, player[p] ? "alive" : "DEAD");
	}
}

void dialog(char message[]) {
	int temp_time = DIALOG_DURATION_SEC;
	char temp_time_char[5] = { 0,0,0,0,0 };
	int message_len = strlen(message);
	int x, y;
	while (1) {

		if (temp_time == 0) break;

		for (int i = 0; i < message_len + 4; i++) {
			x = N_ROW / 2 - 1;
			y = N_COL / 2 - message_len / 2 - 2 + i;
			if (placable(x, y)) back_buf[x][y] = '*';
		}

		x = N_ROW / 2; y = N_COL / 2 - message_len / 2 - 2;
		if (placable(x, y)) back_buf[x][y] = '*';
		x = N_ROW / 2; y = N_COL / 2 - message_len / 2 - 1;
		if (temp_time == DIALOG_DURATION_SEC) back_buf[x][y] = temp_time + '0';
		else if (back_buf[x][y] == ((temp_time + 1) + '0')) back_buf[x][y] = temp_time + '0';
		x = N_ROW / 2; y = N_COL / 2 + message_len / 2 + 1;
		if (placable(x, y)) back_buf[x][y] = '*';

		for (int i = 0; i < message_len; i++) { // �޽��� �ֱ�
			x = N_ROW / 2;
			y = N_COL / 2 - message_len / 2 + 1 + i;
			if (placable(x, y)) back_buf[x][y] = message[i];
		}
		for (int i = 0; i < message_len + 4; i++) {
			x = N_ROW / 2 + 1;
			y = N_COL / 2 - message_len / 2 - 2 + i;
			if (placable(x, y)) back_buf[x][y] = '*';
		}



		display();
		Sleep(1000);

		temp_time -= 1;
	}

	for (int i = 0; i < message_len + 4; i++) {
		x = N_ROW / 2 - 1;
		y = N_COL / 2 - message_len / 2 - 2 + i;
		if (back_buf[x][y] == '*') back_buf[x][y] = ' ';
	}

	x = N_ROW / 2; y = N_COL / 2 - message_len / 2 - 2;
	if (back_buf[x][y] == '*') back_buf[x][y] = ' ';
	x = N_ROW / 2; y = N_COL / 2 - message_len / 2 - 1;
	if (back_buf[x][y] == ((temp_time + 1) + '0')) back_buf[x][y] = ' ';
	x = N_ROW / 2; y = N_COL / 2 + message_len / 2 + 1;
	if (back_buf[x][y] == '*') back_buf[x][y] = ' ';

	for (int i = 0; i < message_len; i++) { // �޽��� �ֱ�
		x = N_ROW / 2;
		y = N_COL / 2 - message_len / 2 + 1 + i;
		if (back_buf[x][y] == message[i]) back_buf[x][y] = ' ';
	}
	for (int i = 0; i < message_len + 4; i++) {
		x = N_ROW / 2 + 1;
		y = N_COL / 2 - message_len / 2 - 2 + i;
		if (back_buf[x][y] == '*') back_buf[x][y] = ' ';
	}


}


