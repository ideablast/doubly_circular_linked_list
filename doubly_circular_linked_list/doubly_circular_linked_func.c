#include"ALL.h"

Node* Add_new_doubly_C_node()
{
	Node *temp;

	temp = (Node *)malloc(sizeof(Node));
	temp->L_Next = NULL;
	temp->R_Next = NULL;
	temp->nData = 0;

	return temp;
}

void Add_doubly_c_node_right_tail(Node *head_node, int item)
{//while ������ ���� ����
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 ���� ����Ʈ�� ù���� �����߽��ϴ�.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ

		while (pointing_node->R_Next != head_node->R_Next)
		{
			pointing_node = pointing_node->R_Next;
		}

		pointing_node->R_Next = temp;
		temp->L_Next = pointing_node;

		temp->R_Next = head_node->R_Next;
		head_node->R_Next->L_Next = temp;
	}

}
void Add_doubly_c_node_right_tail_new_ver(Node *head_node, int item)
{
	//while ������ ���� ����
	//�� ������ ���� ã�� �ʿ䰡 ����
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 ���� ����Ʈ�� ù���� �����߽��ϴ�.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		SI_doubly_c_node_sub_func_left(pointing_node, temp);
	}

}


void SI_doubly_c_node(Node *head_node, int mode, int search, int item)//ã�� �׸��� ������(��,��) ������(��,��)
{
	//�̹� ������ ģ���� �����ϴ� ģ���� ������ �ٴѴ�.
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 ���� ����Ʈ�� ù���� �����߽��ϴ�.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		while (pointing_node->R_Next != head_node->R_Next)
		{
			
			if (pointing_node->nData == search)
			{
				if (mode == RIGHT)
					SI_doubly_c_node_sub_func_right(pointing_node, temp);
				else
					SI_doubly_c_node_sub_func_left(pointing_node, temp);
			}
			pointing_node = pointing_node->R_Next;
		}
		//������ ��尡 ã�� �� �϶�
		if (pointing_node->nData == search)
		{
			if (mode == RIGHT)
				SI_doubly_c_node_sub_func_right(pointing_node, temp);
			else
				SI_doubly_c_node_sub_func_left(pointing_node, temp);
		}
	}
}

void SI_doubly_c_node_sub_func_right(Node *pointing_node, Node *temp)
{
	temp->R_Next = pointing_node->R_Next;
	pointing_node->R_Next->L_Next = temp;
	pointing_node->R_Next = temp;
	temp->L_Next = pointing_node;
}

void SI_doubly_c_node_sub_func_left(Node *pointing_node, Node *temp)
{
	temp->L_Next = pointing_node->L_Next;
	pointing_node->L_Next->R_Next = temp;
	pointing_node->L_Next = temp;
	temp->R_Next = pointing_node;
}

void Print_doubly_c_node(Node *head_node, int mode, int times)
{
	Node *pointing_node = head_node;
	int cnt=0;
	
	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 �����ϴ�.");
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		for (cnt = 0; cnt < times; cnt++)
		{
			printf("%d��°\n", cnt + 1);
			if (mode == RIGHT)
			{
				while (pointing_node->R_Next != head_node->R_Next)
				{
					printf("%d ", pointing_node->nData);
					pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
				}
				printf("%d ", pointing_node->nData);
				printf("\n");
				pointing_node = pointing_node->R_Next;
			}
			else
			{
				while (pointing_node->L_Next != head_node->R_Next)
				{
					printf("%d ", pointing_node->nData);
					pointing_node = pointing_node->L_Next;//pointing_node�� ù��° ��带 ����Ŵ
				}
				printf("%d ", pointing_node->nData);
				printf("\n");
				pointing_node = pointing_node->L_Next;
			}
		}
	}
}
void Delete_doubly_c_node(Node *head_node, int search)
{
	Node *pointing_node = head_node;
	
	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 �����ϴ�.");
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		while (pointing_node->R_Next != head_node->R_Next)
		{

			if (pointing_node->nData == search)
			{
				if (pointing_node == head_node->R_Next)
					head_node->R_Next = pointing_node->R_Next;// ù��° ��尡 ���� ����̸� ������ ��带 ������ ù��° ����
				pointing_node->L_Next->R_Next = pointing_node->R_Next;
				pointing_node->R_Next->L_Next = pointing_node->L_Next;
				free(pointing_node);
				break;
			}
			pointing_node = pointing_node->R_Next;
		}
		//������ ��尡 ã�� �� �϶�
		if (pointing_node->nData == search)
		{
			pointing_node->L_Next->R_Next = pointing_node->R_Next;
			pointing_node->R_Next->L_Next = pointing_node->L_Next;
			free(pointing_node);
		}
	}
}
/*-------------------------GAME_1-------------------------*/

int Search_doubly_c_node_GAME_1(Node* head_node, int item)
{
	Node* pointing_node = head_node;
	int result = FAIL;
	int idx = 0;

	if (item >= 65 && item <= 90)//�빮�� 65~90
	{
		if (pointing_node->R_Next == NULL)
			result = FAIL;
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->R_Next;//��� ���������� �̵�
			while (pointing_node->L_Next != head_node->R_Next)//����Ʈ ���η� ����
			{
				idx++;
				if (pointing_node->nData == item)
					result = idx;
				pointing_node = pointing_node->L_Next;
			}
			if (pointing_node->nData == item)
				result = idx;
		}

	}
	else//�ҹ��� 97~122
	{
		if (pointing_node->L_Next == NULL)
			result = FAIL;
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->L_Next;//��� �������� �̵�
			while (pointing_node->R_Next != head_node->L_Next)//����Ʈ ���η� ����
			{
				if (pointing_node->nData == item)
					result = idx;
				pointing_node = pointing_node->R_Next;
			}
			if (pointing_node->nData == item)
				result = idx;

		}
	}
	return result;
}

int Make_randnum_alphabet_GAME_1(Node *head_node)
{
	int rand_num;
	int result = 0;

	while (1)
	{
		while (1)
		{
			rand_num = rand() % 58 + 65;//65~122
			if (rand_num <= 90 || rand_num >= 97)
				break;
		}

		result = Search_doubly_c_node_GAME_1(head_node, rand_num);
		if (result == FAIL)
			break;
	}
	return rand_num;
}

void Add_doubly_c_node_GAME_1(Node* head_node, int item)
{
	Node* pointing_node = head_node;
	Node* temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (item >= 65 && item <= 90)//�빮�� 65~90
	{
		if (pointing_node->R_Next == NULL)
		{
			pointing_node->R_Next = temp;
			pointing_node->R_Next->L_Next = temp;
			pointing_node->R_Next->R_Next = temp;
		}
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->R_Next;//��� ���������� �̵�
			SI_doubly_c_node_sub_func_right(pointing_node, temp);
		}
	}
	else//�ҹ��� 97~122
	{
		if (pointing_node->L_Next == NULL)
		{
			pointing_node->L_Next = temp;
			pointing_node->L_Next->R_Next = temp;
			pointing_node->L_Next->L_Next = temp;
		}
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->L_Next;//��� �������� �̵�
			SI_doubly_c_node_sub_func_left(pointing_node, temp);//����Ʈ�� �� �������� �߰�
		}
	}
	
}

int Count_doubly_c_node_GAME_1(Node* head_node, int direction)
{
	Node *pointing_node = head_node;
	int cnt = 0;
	int result = FAIL;

	if (direction == RIGHT)
	{
		if (pointing_node->R_Next == NULL)
			result = FAIL;
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			
			pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
			cnt++;
			while (pointing_node->L_Next != head_node->R_Next)
			{
				pointing_node = pointing_node->L_Next;//pointing_node�� ù��° ��带 ����Ŵ
				cnt++;
			}
		}
		result = cnt;
	}
	else
	{
		if (pointing_node->L_Next == NULL)
			result = FAIL;
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->L_Next;
			cnt++;
			while (pointing_node->R_Next != head_node->L_Next)
			{
				pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
				cnt++;
			}
		}
		result = cnt;
	}

	return result;
}

void Print_doubly_c_node_GAME_1(Node* head_node, int direction)
{
	Node *pointing_node = head_node;
	
	if (direction == RIGHT)
	{
		if (pointing_node->R_Next == NULL)
			puts("�빮�� 0��");
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
			printf("%c ", pointing_node->nData);
			while (pointing_node->L_Next != head_node->R_Next)
			{
				pointing_node = pointing_node->L_Next;//pointing_node�� ù��° ��带 ����Ŵ
				printf("%c ", pointing_node->nData);
			}
		}
		printf("\n");
	}
	else
	{
		if (pointing_node->L_Next == NULL)
			puts("�ҹ��� 0��");
		else//����Ʈ ���ο� ��尡 �ִ� ���
		{
			pointing_node = pointing_node->L_Next;
			printf("%c ", pointing_node->nData);
			while (pointing_node->R_Next != head_node->L_Next)
			{
				pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
				printf("%c ", pointing_node->nData);
			}
		}
		printf("\n");
	}
}

#ifdef NOTYET

int get_keyboard()//Ű ���� �޾Ƽ� ��ȯ �Ѵ�
{
	int point;

	while (1)
	{
		point = _getch();
		if (point != 224)
			break;
	}

	return point;
}

Node* point_con(Node*pointing_node)
{
	Node *temp = pointing_node;
	int point;

	point = get_keyboard();//Ű���忡�� ���� �Է� �޴´�

	switch (point)
	{
	case 75://����
		temp = temp->L_Next;
		break;
	case 77://������
		temp = temp->R_Next;
		break;
	case 72://���� 
			//������ ���
		break;
	case 80://�Ʒ���
			//���� ���
		break;
	case 13://����
			//�ش� ��� ��� ����
		break;

	}

	return temp;
}
#endif
