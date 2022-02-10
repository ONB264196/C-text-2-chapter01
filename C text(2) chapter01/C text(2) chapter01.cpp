#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _0108

#ifdef _0100
#define MAX 20
#define MIN 0
#define MAX_STAGE 10

int main(void) {
	int stage = 0;
	int no = 0;
	int ans = 0;
	int num[MAX_STAGE];

	srand(time(NULL));
	ans = rand() % (MAX + 1) + MIN;

	printf("%d～%dの整数を当ててください。\n\n", MIN, MAX);

	do {
		printf("残り%d回。いくつかな : ", MAX_STAGE - stage);
		scanf_s("%d", &no);
		num[stage++] = no;

		if (no > ans) {
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			printf("\aもっと大きいよ。\n");
		}
	} while (!(no == ans || stage == MAX_STAGE));

	if (no != ans) {
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		printf("正解です。\n");
		printf("%d回で当たりました。\n", stage);
	}

	puts("\n--- 入力履歴 ---");
	for (int i = 0; i < stage; i++) {
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
	}

	return 0;
}
#endif

#ifdef _0101 
int main(void) {
	int luck = 0;

	srand(time(NULL));
	luck = rand() % 7;

	switch (luck) {
	case 0:
		puts(" ┌───┐");
		puts(" │ 大│");
		puts(" │ 吉│");
		puts(" └───┘");
		break;
	case 1:
		puts(" ┌───┐");
		puts(" │ 中│");
		puts(" │ 吉│");
		puts(" └───┘");
		break;
	case 2:
		puts(" ┌───┐");
		puts(" │ 小│");
		puts(" │ 吉│");
		puts(" └───┘");
		break;
	case 3:
		puts(" ┌───┐");
		puts(" │ 吉│");
		puts(" └───┘");
		break;
	case 4:
		puts(" ┌───┐");
		puts(" │ 末│");
		puts(" │ 吉│");
		puts(" └───┘");
		break;
	case 5:
		puts(" ┌───┐");
		puts(" │ 凶│");
		puts(" └───┘");
		break;
	case 6:
		puts(" ┌───┐");
		puts(" │ 大│");
		puts(" │ 凶│");
		puts(" └───┘");
		break;
	}
	
	return 0;
}
#endif

#ifdef _0102
int main(void) {
	int luck = 0;

	srand(time(NULL));
	luck = rand() % 51;
	if (luck % 23 == 0) {
		puts(" ┌───┐");
		puts(" │ 大│");
		puts(" │ 凶│");
		puts(" └───┘");
	}
	else if (luck % 19 == 0) {
		puts(" ┌───┐");
		puts(" │ 凶│");
		puts(" └───┘");
	}
	else if (luck % 17 == 0) {
		puts(" ┌───┐");
		puts(" │ 大│");
		puts(" │ 吉│");
		puts(" └───┘");
	}
	else if (luck % 13 == 0) {
		puts(" ┌───┐");
		puts(" │ 末│");
		puts(" │ 吉│");
		puts(" └───┘");
	}
	else if (luck % 7 == 0) {
		puts(" ┌───┐");
		puts(" │ 中│");
		puts(" │ 吉│");
		puts(" └───┘");
	}
	else if (luck % 5 == 0) {
		puts(" ┌───┐");
		puts(" │ 小│");
		puts(" │ 吉│");
		puts(" └───┘");
	}
	else {
		puts(" ┌───┐");
		puts(" │ 吉│");
		puts(" └───┘");
	}


	return 0;
}
#endif

#ifdef _0103
#define MAX 999
#define MIN -999
#define DIFFICULTY 5 /*2以上*/
int main(void) {
	int no = 0;
	int ans = 0;
	int max_stage = 0;
	int remain = 0;
	int i = MAX - MIN;
	int over = 0;
	do {
		over = i % 2;
		i /= 2;
		i += over;
		max_stage++;
	} while (i >= DIFFICULTY); 
	remain = max_stage;
	srand(time(NULL));
	ans = rand() % (MAX + 1);

	printf("%d～%dの整数を当ててください。\n\n", MIN, MAX);

	do {
		printf("残り%d回。いくつかな : ", remain);
		scanf_s("%d", & no);
		if(no > ans){
			printf("\aもっと小さいよ。\n");
		}
		else if(no < ans) {
			printf("\aもっと大きいよ。\n");
		}
		remain--;
	} while (!(remain <= 0 || no == ans));

	if (ans != no) {
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		puts("正解です。");
		printf("%d回で当たりました。", max_stage - remain);
	}

	return 0;
}
#endif

#ifdef _0104
#define MAX 999
#define MIN 3
#define DIFFICULTY 5 /*2以上*/
int main(void) {
	int no = 0;
	int ans = 0;
	int max_stage = 0;
	int remain = 0;
	int i = MAX - MIN;
	int over = 0;
	do {
		over = i % 2;
		i /= 2;
		i += over;
		max_stage++;
	} while (i >= DIFFICULTY);
	remain = max_stage;
	srand(time(NULL));
	ans = rand() % (MAX + 1);
	if (ans % 3 != 0) {
		ans += (3 - (ans % 3));
	}

	printf("%d～%dの3の倍数を当ててください。\n\n", MIN, MAX);

	do {
		printf("残り%d回。いくつかな : ", remain);
		scanf_s("%d", &no);
		if (no > ans) {
			if (no % 3 != 0) {
				break;
			}
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			if (no % 3 != 0) {
				break;
			}
			printf("\aもっと大きいよ。\n");
		}
		remain--;
	} while (!(remain <= 0 || no == ans));

	if (ans != no) {
		if (no % 3 != 0) {
			printf("%dは3の倍数ではありません。\n", no);
		}
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		puts("正解です。");
		printf("%d回で当たりました。", max_stage - remain);
	}



	return 0;
}
#endif

#ifdef _0105
#define DIFFICULTY 5 /*2以上*/
int main(void) {
	int max = 0;
	int min = 0;
	int no = 0;
	int ans = 0;
	int max_stage = 0;
	int remain = 0;
	
	srand(time(NULL));
	max = rand() % 10000;
	min = rand() % 10000;
	if (max < min) {
		int n = max;
		max = min;
		min = n;
	}

	int i = max - min;
	int over = 0;
	do {
		over = i % 2;
		i /= 2;
		i += over;
		max_stage++;
	} while (i >= DIFFICULTY);
	remain = max_stage;
	ans = rand() % (max + 1);

	printf("%d～%dの整数を当ててください。\n\n", min, max);

	do {
		printf("残り%d回。いくつかな : ", remain);
		scanf_s("%d", &no);
		if (no > ans) {
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			printf("\aもっと大きいよ。\n");
		}
		remain--;
	} while (!(remain <= 0 || no == ans));

	if (ans != no) {
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		puts("正解です。");
		printf("%d回で当たりました。", max_stage - remain);
	}



	return 0;
}
#endif

#ifdef _0106
int main(void) {
	int difficulty[4][3] = { {1, 9, 3},{1, 81, 4},{1, 729, 8},{1, 6561, 11} };
	int max = 0;
	int min = 0;
	int no = 0;
	int ans = 0;
	int remain = 0;
	int level = 0;

	do {
		puts("レベルを選んでください。");
		for (int i = 0; i < 4; i++) {
			printf("(%d)%d～%d ", i + 1, difficulty[i][0], difficulty[i][1]);
		}
		printf(": ");
		scanf_s("%d", &level);
		if (level < 1 || level > 4) {
			puts("\a1～4でレベルを選択してください。\n");
		}
	} while (level < 1 || level > 4);
	level--;

	max = difficulty[level][1];
	min = difficulty[level][0];

	remain = difficulty[level][2];
	srand(time(NULL));
	ans = rand() % (max + 1);

	printf("%d～%dの整数を当ててください。\n\n", min, max);

	do {
		printf("残り%d回。いくつかな : ", remain);
		scanf_s("%d", &no);
		if (no > ans) {
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			printf("\aもっと大きいよ。\n");
		}
		remain--;
	} while (!(remain <= 0 || no == ans));

	if (ans != no) {
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		puts("正解です。");
		printf("%d回で当たりました。", difficulty[level][2] - remain);
	}

	return 0;
}
#endif

#ifdef _0107
#define MAX_STAGE 10
int main(void) {
	int stage = 0;
	int no = 0;
	int ans = 0;
	int num[MAX_STAGE] = { 0 };

	srand(time(NULL));
	ans = rand() % 1000;

	printf("0～999の整数を当ててください。\n\n");

	do {
		printf("残り%d回。いくつかな : ", MAX_STAGE - stage);
		scanf_s("%d", &no);
		num[stage++] = no;

		if (no > ans) {
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			printf("\aもっと大きいよ。\n");
		}
	} while (no != ans && stage < MAX_STAGE);

	if (no != ans) {
		printf("\a残念。正解は%dでした。\n", ans);
	}
	else {
		printf("正解です。\n");
		printf("%d回で当たりましたね。\n", stage);
	}

	puts("\n--- 入力履歴 ---");
	for (int i = 0; i < stage; i++) {
		if (num[i] - ans != 0) {
			printf("%2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
		}
		else {
			printf("%2d : %4d %4d\n", i + 1, num[i], 0);
		}
	}

	return 0;
}
#endif

#ifdef _0108
#define MAX_STAGE 10
int main(void) {
	int stage = 0;
	int no = 0;
	int ans = 0;
	int num[MAX_STAGE] = { 0 };

	srand(time(NULL));
	ans = rand() % 1000;

	printf("0～999の整数を当ててください。\n\n");

	for(stage = 0; stage < MAX_STAGE; stage++){
		printf("残り%d回。いくつかな : ", MAX_STAGE - stage);
		scanf_s("%d", &no);
		num[stage] = no;

		if (no > ans) {
			printf("\aもっと小さいよ。\n");
		}
		else if (no < ans) {
			printf("\aもっと大きいよ。\n");
		}
		else {
			stage++;
			break;
		}
	}

	if (no != ans) {
		printf("\a残念。正解は%dでした\n", ans);
	}
	else {
		printf("正解です。\n");
		printf("%d回で当たりましたね。\n", stage);
	}

	puts("\n --- 入力履歴 ---");
	for (int i = 0; i < stage; i++) {
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
	}

	return 0;
}
#endif