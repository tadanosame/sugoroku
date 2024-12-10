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
		printf("�����Ȃ�����\n");
		break;
	case 1:
		printf("���O���Ă΂�Ȃ�����\n");
		break;
	case 2:
		printf("�ׂ̂�ɗ��܂ꂽ\n");
		break;
	case 3:
		printf("�Ԃ�瀂��ꂽ\n");
		break;
	case 4:
		printf("�Q�V����\n");
		break;
	}

}


void event04(void) {
	int n;
	n = rand() % 6;
	printf("%d\n", n);
	switch (n) {
	case 0:
		printf("�����Ȃ�����\n");
		break;
	case 1:
		printf("�����肵�Ďw�����ꂽ\n");
		break;
	case 2:
		printf("�ׂ̂�ƌ��܂���\n");
		break;
	case 3:
		printf("�F�B���ł���\n");
		break;
	case 4:
		printf("�Q�V����\n");
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

	/*�Q�[���v���C�ݒ�*/
	printf("���̃Q�[���͏��c�}�����g���A�V�h�w���甠�����{�w�܂ň�ԑ������ǂ蒅�����l�������̃Q�[���ł��B\n");
	printf("1�`2�l�Ńv���C���邱�Ƃ��ł��܂��B\n");
	printf("���l�Ńv���C���܂����H��l�Ńv���C(�ΐ푊���NPC���ǉ�����܂�)�̏ꍇ��1���A��l�Ńv���C����ꍇ��2�������Ă��������B");
	scanf("%d", &players_setting);
	printf("\n");
	if (players_setting == 1) {
		players_number = 2;
		printf("NPC��ǉ����܂����B\n���v%d�l�ŃQ�[�����J�n���܂��B\n",players_number);
		/*NPC�v���C(2�l)*/
		d = 1;
		while (1) {
			d = d + rand() % 6 + 1;
			if (d >= 50) {
				break;
			}
			printf("�������܂�%s\n", event[d].station_name);
			printf("%d\n", event[d].f_flag);

			switch (event[d].f_flag) {
			case 1:
				event01();
				break;
			case 4:
				event04();
				break;
			default:
				printf("�����Ȃ�����\n");
			}

			getchar();

		}
		printf("���������I");
	}
	else if (players_setting == 2) {
			players_number = 2;
			printf("���v%d�l�ŃQ�[�����J�n���܂��B\n",players_number);
			/*�ΐl�v���C(2�l)*/
			d = 1;
			while (1) {
				d = d + rand() % 6 + 1;
				if (d >= 50) {
					break;
				}
				printf("�������܂�%s\n", event[d].station_name);
				printf("%d\n", event[d].f_flag);

				switch (event[d].f_flag) {
				case 1:
					event01();
					break;
				case 4:
					event04();
					break;
				default:
					printf("�����Ȃ�����\n");
				}

				getchar();

			}
			printf("���������I");
	}
	else {
		printf("�����ƕ��ǂ�ł��������B\n");
		exit(0);
	}
}