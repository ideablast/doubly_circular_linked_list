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
		//�ߺ��� ���� ������26���� ������ �� ����
	{
		Add_doubly_c_node_GAME_1(head_node, Make_randnum_alphabet_GAME_1(head_node));
	}
	puts("�빮�� ���");
	Right = Count_doubly_c_node_GAME_1(head_node, RIGHT);
	Print_doubly_c_node_GAME_1(head_node, RIGHT);
	Print_doubly_c_node_LR_GAME1(head_node, RIGHT, LEFT, 1);
	Print_doubly_c_node_LR_GAME1(head_node, RIGHT, RIGHT, 1);

	puts("�ҹ��� ���");
	Left = Count_doubly_c_node_GAME_1(head_node, LEFT);
	Print_doubly_c_node_GAME_1(head_node, LEFT);
	Print_doubly_c_node_LR_GAME1(head_node, LEFT, RIGHT, 1);
	Print_doubly_c_node_LR_GAME1(head_node, LEFT, LEFT, 1);


	puts("");
	puts("");
	puts("���ĺ� ¦���߱� ����");
	puts("������ ���ĺ�");
	printf("�빮��:"); Print_doubly_c_node_GAME_1(head_node, RIGHT);
	printf("�ҹ���:"); Print_doubly_c_node_GAME_1(head_node, LEFT);
	puts("");
	puts("");
	puts("������ ���ĺ�");
	Order_GAME_1(head_node);
	printf("�빮��:"); Print_doubly_c_node_GAME_1(head_node, RIGHT);
	printf("�ҹ���:"); Print_doubly_c_node_GAME_1(head_node, LEFT);
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
	puts("���� ��� Ȯ��");
	SI_doubly_c_node(head_node, RIGHT, 40, 200);
	puts("40������ 200����");
	Print_doubly_c_node(head_node, RIGHT, 1);
	SI_doubly_c_node(head_node, RIGHT, 60, 500);
	puts("60������ 500����");
	Print_doubly_c_node(head_node, RIGHT, 1);
	Print_doubly_c_node(head_node, LEFT, 2);
	SI_doubly_c_node(head_node, LEFT, 40, 2000);
	puts("40���� 2000����");
	Print_doubly_c_node(head_node, RIGHT, 1);
	SI_doubly_c_node(head_node, LEFT, 60, 4000);
	puts("������2��");
	Print_doubly_c_node(head_node, RIGHT, 2);
	puts("������4��");
	Print_doubly_c_node(head_node, RIGHT, 4);
	puts("����2��");
	Print_doubly_c_node(head_node, LEFT, 2);
	puts("40����");
	puts("40����");
	puts("40����");
	Delete_doubly_c_node(head_node, 40);
	Print_doubly_c_node(head_node, RIGHT, 1);
	Delete_doubly_c_node(head_node, 10);
	Print_doubly_c_node(head_node, RIGHT, 1);
	Delete_doubly_c_node(head_node, 500);
	Print_doubly_c_node(head_node, RIGHT, 1);
	system("pause");
#endif 
}