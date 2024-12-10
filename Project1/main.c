#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define E_NUM 50

typedef struct _event {
	int num;
	char station_name[50];
	int f_flag;
} EVENT;

void event01(void) {
	int n;
	n = rand() % 6;
	printf("%d\n",n);
	switch (n) {
	case 0:
		printf("何もなかった\n");
		break;
	case 1:
		printf("名前を呼ばれなかった\n");
		break;
	case 2:
		printf("隣のやつに絡まれた\n");
		break;
	case 3:
		printf("車に轢かれた\n");
		break;
	case 4:
		printf("寝坊した\n");
		break;
	}

}


void event04(void) {
	int n;
	n = rand() % 6;
	printf("%d\n", n);
	switch (n) {
	case 0:
		printf("何もなかった\n");
		break;
	case 1:
		printf("居眠りして指導された\n");
		break;
	case 2:
		printf("隣のやつと喧嘩した\n");
		break;
	case 3:
		printf("友達ができた\n");
		break;
	case 4:
		printf("寝坊した\n");
		break;
	}
}

main() {
	int i;
	int d;
	int players_setting;
	int players_number;
	FILE* fp;
	EVENT event[50];

	srand((int)time(NULL));
	fp = fopen("stations.txt", "r");

	for (i = 0; i < E_NUM; i++) {
		fscanf(fp, "%d %s %d", &event[i].num, event[i].station_name, &event[i].f_flag);
	}

	/*ゲームプレイ設定*/
	printf("このゲームは小田急線を使い、新宿駅から箱根湯本駅まで一番早くたどり着いた人が勝ちのゲームです。\n");
	printf("1～2人でプレイすることができます。\n");
	printf("何人でプレイしますか？一人でプレイ(対戦相手にNPCが追加されます)の場合は1を、二人でプレイする場合は2を押してください。");
	scanf("%d", &players_setting);
	printf("\n");
	if (players_setting == 1) {
		players_number = 2;
		printf("NPCを追加しました。\n合計%d人でゲームを開始します。\n",players_number);
		/*NPCプレイ(2人)*/
		d = 1;
		while (1) {
			d = d + rand() % 6 + 1;
			if (d >= 50) {
				break;
			}
			printf("ただいまは%s\n", event[d].station_name);
			printf("%d\n", event[d].f_flag);

			switch (event[d].f_flag) {
			case 1:
				event01();
				break;
			case 4:
				event04();
				break;
			default:
				printf("何もなかった\n");
			}

			getchar();

		}
		printf("箱根到着！");
	}
	else if (players_setting == 2) {
			players_number = 2;
			printf("合計%d人でゲームを開始します。\n",players_number);
			/*対人プレイ(2人)*/
			d = 1;
			while (1) {
				d = d + rand() % 6 + 1;
				if (d >= 50) {
					break;
				}
				printf("ただいまは%s\n", event[d].station_name);
				printf("%d\n", event[d].f_flag);

				switch (event[d].f_flag) {
				case 1:
					event01();
					break;
				case 4:
					event04();
					break;
				default:
					printf("何もなかった\n");
				}

				getchar();

			}
			printf("箱根到着！");
	}
	else {
		printf("ちゃんと文読んでください。\n");
		exit(0);
	}
}