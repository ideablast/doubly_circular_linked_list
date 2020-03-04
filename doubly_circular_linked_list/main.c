#include"ALL.h"
#define GAME_1
//#define TEST

int main()
{
	Node *head_node = Add_new_doubly_C_node();
#ifdef GAME_1
	int Right, Left;
	srand((unsigned int)time(NULL));

	while ((Count_doubly_c_node_GAME_1(head_node, RIGHT) != 26) || (Count_doubly_c_node_GAME_1(head_node, LEFT) != 26))
		//중복이 없기 떄문에26개씩 뽑으면 딱 맞음
	{
		Add_doubly_c_node_GAME_1(head_node, Make_randnum_alphabet_GAME_1(head_node));
	}
	puts("대문자 출력");
	Right = Count_doubly_c_node_GAME_1(head_node, RIGHT);
	Print_doubly_c_node_GAME_1(head_node, RIGHT);
	Print_doubly_c_node_LR_GAME1(head_node, RIGHT, LEFT, 1);
	Print_doubly_c_node_LR_GAME1(head_node, RIGHT, RIGHT, 1);

	puts("소문자 출력");
	Left = Count_doubly_c_node_GAME_1(head_node, LEFT);
	Print_doubly_c_node_GAME_1(head_node, LEFT);
	Print_doubly_c_node_LR_GAME1(head_node, LEFT, RIGHT, 1);
	Print_doubly_c_node_LR_GAME1(head_node, LEFT, LEFT, 1);


	puts("");
	puts("");
	puts("알파벳 짝맞추기 게임");
	puts("정렬전 알파벳");
	printf("대문자:"); Print_doubly_c_node_GAME_1(head_node, RIGHT);
	printf("소문자:"); Print_doubly_c_node_GAME_1(head_node, LEFT);
	puts("");
	puts("");
	puts("정렬후 알파벳");
	Order_GAME_1(head_node);
	printf("대문자:"); Print_doubly_c_node_GAME_1(head_node, RIGHT);
	printf("소문자:"); Print_doubly_c_node_GAME_1(head_node, LEFT);
	system("pause");

#endif
#ifdef TEST
	Add_doubly_c_node_right_tail_new_ver(head_node, 10);
	Add_doubly_c_node_right_tail_new_ver(head_node, 20);
	Add_doubly_c_node_right_tail_new_ver(head_node, 30);
	Add_doubly_c_node_right_tail_new_ver(head_node, 40);
	Add_doubly_c_node_right_tail_new_ver(head_node, 50);
	Add_doubly_c_node_right_tail_new_ver(head_node, 60);
	Print_doubly_c_node(head_node, RIGHT, 1);
	puts("삽입 기능 확인");
	SI_doubly_c_node(head_node, RIGHT, 40, 200);
	puts("40오른쪽 200삽입");
	Print_doubly_c_node(head_node, RIGHT, 1);
	SI_doubly_c_node(head_node, RIGHT, 60, 500);
	puts("60오른쪽 500삽입");
	Print_doubly_c_node(head_node, RIGHT, 1);
	Print_doubly_c_node(head_node, LEFT, 2);
	SI_doubly_c_node(head_node, LEFT, 40, 2000);
	puts("40왼쪽 2000삽입");
	Print_doubly_c_node(head_node, RIGHT, 1);
	SI_doubly_c_node(head_node, LEFT, 60, 4000);
	puts("오른쪽2번");
	Print_doubly_c_node(head_node, RIGHT, 2);
	puts("오른쪽4번");
	Print_doubly_c_node(head_node, RIGHT, 4);
	puts("왼쪽2번");
	Print_doubly_c_node(head_node, LEFT, 2);
	puts("40삭제");
	puts("40삭제");
	puts("40삭제");
	Delete_doubly_c_node(head_node, 40);
	Print_doubly_c_node(head_node, RIGHT, 1);
	Delete_doubly_c_node(head_node, 10);
	Print_doubly_c_node(head_node, RIGHT, 1);
	Delete_doubly_c_node(head_node, 500);
	Print_doubly_c_node(head_node, RIGHT, 1);
	system("pause");
#endif 
}