#pragma once

#define KART_MAX 8
#define TEAM_MAX 2
#define LAP_MAX 3
#define OPPONENT_DATA_MAX 100
#define GHOST_LIST_MAX (1 + 2 + 20)   // 1 player ghost + 2 staff ghosts + 20 ranking (SpotPass / StreetPass) ghosts
#define NUM_RACE_COURSES 32
#define NUM_BATTLE_COURSES 6
#define NUM_COURSES (NUM_RACE_COURSES + NUM_BATTLE_COURSES + 2)
#define NUM_CUPS 8
#define NUM_COURSES_PER_CUP (NUM_RACE_COURSES / NUM_CUPS)