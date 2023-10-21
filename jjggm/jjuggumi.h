#pragma once
// 공용 설정
#ifndef _JJUGGUMI_H_
#define _JJUGGUMI_H_

#include <Windows.h>
#include <stdbool.h>

#define PLAYER_MAX	10 // 플레이어 최대인원 선언

bool player[PLAYER_MAX];  // 기본값 true, 탈락하면 false
int n_player, n_alive; // 플레이어수, 살아있는 플레이어수
int tick;  // 시계

// 미니게임
void sample(void);
void mugunghwa(void);
//void mugunghwa(void);
//void nightgame(void);
//void juldarigi(void);
//void jebi(void);

int randint(int low, int high);

#endif
