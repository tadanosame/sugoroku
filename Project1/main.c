#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define E_NUM 50

typedef struct _event {
	int num;
	char station_name[50];
	int stopevent;
} EVENT;

void delay(int milliseconds) {
	clock_t start_time = clock();
	while (clock() < start_time + milliseconds);
}

void event01(int Romance_Car_nextstops, int* player_dice, int* skip_turn, int* d) {
	int n;
	int i;
	int success_rate;

	// 成功率の計算
	success_rate = rand() % 100 + 1;
	//チャレンジ選択
	printf("ロマンスカーマスに止まりました。追加でマスを進めるチャンスです。(+%d駅分進めます。)\n", Romance_Car_nextstops);
	printf("失敗するとマスが戻るか一回休みになります。\n");
	printf("成功率は%d%%です。チャレンジしますか？チャレンジする場合は1を、しない場合は2を選択してください: ", success_rate);
	scanf("%d", &n);

	if (n == 2) {
		// チャレンジを見送る場合
		printf("チャレンジを見送りました。\n");
		*d = 0;
		return;
	}
	else {
		// チャレンジする場合
		i = rand() % 100 + 1; // 成功判定用の乱数
		if (i <= success_rate) {
			n = 0; // 成功時
		}
		else {
			n = rand() % 2 + 1; // 失敗時は1は休み。2はマス戻り
		}
		switch (n) {
		case 0: // 成功
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("成功！追加で%d駅進みます。\n", Romance_Car_nextstops);
			*player_dice += Romance_Car_nextstops; // プレイヤーを進める
			*d = 0;
			break;
		case 1: // 一回休み
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("失敗...一回休みです。\n");
			*skip_turn = 1; // スキップフラグを立てる
			d = 0;
			break;
		case 2: // マス戻り
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("失敗...サイコロで出たマス分戻ります。\n");
			i = rand() % 6 + 1; // 戻るマス数を決定
			printf("サイコロを振っています");
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("%d！", i);
			*player_dice -= i; // プレイヤーを戻す
			printf("%d駅戻ります。\n", i);
			*d = 0;
			break;
		}
	}
}


void event02(int* skip_turn, int* d) {
	int n;
	n = rand() % 5 + 1;
	switch (n) {
	case 1:
		printf("何もなかった。\n");
		break;
	case 2:
		printf("腹痛で途中下車！一回休み...\n");
		*skip_turn = 1;
		d = 0;
		break;
	case 3:
		printf("のどの渇きが限界！途中下車して飲み物を買う。一回休み...\n");
		*skip_turn = 1;
		d = 0;
		break;
	case 4:
		printf("何もなかった。\n");
		break;
	case 5:
		printf("乗り換えするべきだったのに寝過ごした！一回休み...\n");
		*skip_turn = 1;
		d = 0;
		break;
	}
}

void event03(int Romance_Car_nextstops, int* player_dice, int* skip_turn, int* d) {
	int n;
	int i;
	int success_rate;

	// 成功率の計算
	success_rate = rand() % 100 + 1;
	printf("NPCがロマンスカーマスに止まりました。追加でマスを進めるチャンスです。(+%d駅分進めます。)\n", Romance_Car_nextstops);
	printf("成功率は%d%%です。\n", success_rate);
	n = rand() % 2 + 1;
	if (success_rate >= 50) {
		n = 1;
	}
	if (n == 2) {
		// チャレンジを見送る場合
		printf("NPCはチャレンジを見送りました。\n");
		return;
	}
	else {
		// チャレンジする場合
		printf("NPCはチャレンジを選択しました。\n");
		i = rand() % 100 + 1; // 成功判定用の乱数
		if (i <= success_rate) {
			n = 0; // 成功時
		}
		else {
			n = rand() % 2 + 1; // 失敗時は1は休み。2はマス戻り
		}
		switch (n) {
		case 0: // 成功
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("成功！追加で%d駅進みます。\n", Romance_Car_nextstops);
			*player_dice += Romance_Car_nextstops; // プレイヤーを進める
			break;
		case 1: // 一回休み
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("失敗...一回休みです。\n");
			*skip_turn = 1; // スキップフラグを立てる
			break;
		case 2: // マス戻り
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("失敗...サイコロで出たマス分戻ります。\n");
			i = rand() % 6 + 1; // 戻るマス数を決定
			printf("サイコロを振っています");
			for (int i = 0; i < 3; i++) {
				printf(".");
				fflush(stdout);
				delay(500);
			}
			printf("%d！", i);
			*player_dice -= i; // プレイヤーを戻す
			if (*player_dice < 0) *player_dice = 0; // 負の値を防ぐ
			printf("%d駅戻ります。\n", i);
			break;
		}
	}
}

main() {
	int i;

	int d;							// (getchar調整用)

	int dice = 1;					// ダイス(一位がどこまで行っているか)

	int provisional_dice;			// メインダイス(毎ターン振る)

	char* win_player;				// 勝者

	int players_number;				// ゲームの合計人数

	char player1_name[50];			// プレイヤー名前

	int player1_dice = 0;			// プレイヤーダイス(合計数)

	char playerNPC_name[] = "NPC";	// NPC名前

	int playerNPC_dice = 0;			// NPCダイス(合計数)

	int Romance_Car_nextstops;		// 次のロマンスカー停車駅カウント

	int goal_count;					// ゴールまであと何マスか

	int player1_skip_turn = 0;		// プレイヤー1のスキップフラグ

	int playerNPC_skip_turn = 0;	// NPCのスキップフラグ


	FILE* fp;
	EVENT event[50];

	srand((int)time(NULL));
	fp = fopen("stations.txt", "r");

	for (i = 0; i < E_NUM; i++) {
		fscanf(fp, "%d %s %d", &event[i].num, event[i].station_name, &event[i].stopevent);
	}

	// ゲームプレイ説明
	printf("このゲームは小田急線を使い、新宿駅から箱根湯本駅まで一番早くたどり着いた人が勝ちのゲームです。\n");
	printf("このゲームは1人プレイゲームです。\n");
	printf("\n");
	// NPC対戦ゲーム設定
		players_number = 2;
		printf("NPCを追加しました。\n合計%d人でゲームを開始します。\n", players_number);
		printf("プレイヤー名を入力してください。:");
		scanf("%s", &player1_name);
		printf("プレイヤー名を%sに設定しました。\n",player1_name);
		printf("%s vs %s ゲームスタート！\n", &player1_name, &playerNPC_name);
		printf("\n");
		d = 0;

		// NPC対戦ゲーム開始
		while (1) {
			// プレイヤー1のターン
			if (d == 0) {
				getchar();
				d = d + 1;
			}
			if (!player1_skip_turn) {
				printf("%sのターンです。(現在地:%s) Enterキーを押してサイコロを振ってください。\n", &player1_name, event[player1_dice].station_name);
				getchar();

				provisional_dice = rand() % 6 + 1;
				player1_dice += provisional_dice;

				printf("サイコロを振っています");
				for (int i = 0; i < 3; i++) {
					printf(".");
					fflush(stdout);
					delay(500);
				}
				printf("%d！", provisional_dice);
				printf("%d駅進みます！\n", provisional_dice);

				goal_count = 50 - player1_dice;

				if (player1_dice >= 50) {
					player1_dice = 50; 
					win_player = player1_name; // 勝者を設定
					break;
				}

				printf("ただいまは%s(あと%d駅でゴール)\n", event[player1_dice].station_name, goal_count);

				if (event[playerNPC_dice].num < 46) {
					while (1) {
						i = player1_dice;
						while (1) {
							i++;
							if (event[i].stopevent == 1) {
								Romance_Car_nextstops = i - player1_dice;
								break;
							}
						}
						break;
					}
				}
				// イベント判定
				switch (event[player1_dice].stopevent) {
				case 1:
					// 小田原駅(次のロマンスカー終着がない)でバグるのを防ぐ
					if (event[player1_dice].num < 46) {
						event01(Romance_Car_nextstops, &player1_dice, &player1_skip_turn, &d);
						break;
					}
					else {
						break;
					}
				case 2:
					event02(&player1_skip_turn,&d);
					break;
				default:
					printf("何もなかった。\n");
				}
			}
			else {
				//一回休みの場合
				printf("%sは一回休みです。\n", player1_name);
				player1_skip_turn = 0; // スキップフラグをリセット
			}

			delay(500);
			printf("\n\n");
			//NPCのターン
			if (!playerNPC_skip_turn) {
				printf("%sのターンです。(現在地:%s)\n", &playerNPC_name, event[playerNPC_dice].station_name);
				printf("サイコロを振っています");

				provisional_dice = 0;
				provisional_dice = rand() % 6 + 1;
				playerNPC_dice = playerNPC_dice + provisional_dice;

				for (int i = 0; i < 3; i++) {
					printf(".");
					fflush(stdout);
					delay(500);
				}
				printf("%d！", provisional_dice);
				printf("%d駅進みます！\n", provisional_dice);

				goal_count = 50 - playerNPC_dice;

				if (playerNPC_dice >= 50) {
					playerNPC_dice = 50;
					win_player = playerNPC_name; // 勝者を設定
					break;
				}

				printf("ただいまは%s(あと%d駅でゴール)\n", event[playerNPC_dice].station_name, goal_count);

				if (event[playerNPC_dice].num < 46) {
					while (1) {
						i = playerNPC_dice;
						while (1) {
							i++;
							if (event[i].stopevent == 1) {
								Romance_Car_nextstops = i - playerNPC_dice;
								break;
							}
						}
						break;
					}
				}

				switch (event[playerNPC_dice].stopevent) {
				case 1:
					if (event[playerNPC_dice].num < 46) {
						event03(Romance_Car_nextstops, &playerNPC_dice, &playerNPC_skip_turn, &d);
						printf("\n\n");
						break;
					}
					else {
						printf("\n\n");
						break;
					}
				case 2:
					event02(&playerNPC_skip_turn, &d);
					printf("\n\n");
					break;
				default:
					printf("何もなかった。\n");
					printf("\n\n");
				}
			}
			else {
				printf("%sは一回休みです。\n", playerNPC_name);
				playerNPC_skip_turn = 0; // スキップフラグをリセット
				printf("\n\n");
			}
		}
		//勝者確定
		printf("%sが箱根湯本に到着！",win_player);
		printf("%sの勝利！", win_player);
}
