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
{//while 버리기 왼쪽 참조
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("리스트 내부에 노드가 없어 리스트의 첫노드로 삽입했습니다.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴

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
	//while 버리기 왼쪽 참조
	//을 돌려서 끝을 찾을 필요가 없음
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("리스트 내부에 노드가 없어 리스트의 첫노드로 삽입했습니다.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		SI_doubly_c_node_sub_func_left(pointing_node, temp);
	}

}


void SI_doubly_c_node(Node *head_node, int mode, int search, int item)//찾는 항목이 있을때(왼,오) 없을때(왼,오)
{
	//이미 지나간 친구를 복사하는 친구를 가지고 다닌다.
	Node *pointing_node = head_node;
	Node *temp = Add_new_doubly_C_node();
	temp->nData = item;

	if (pointing_node->R_Next == NULL)
	{
		puts("리스트 내부에 노드가 없어 리스트의 첫노드로 삽입했습니다.");
		pointing_node->R_Next = temp;
		pointing_node->R_Next->L_Next = temp;
		pointing_node->R_Next->R_Next = temp;
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
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
		//마지막 노드가 찾는 것 일때
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
		puts("리스트 내부에 노드가 없습니다.");
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		for (cnt = 0; cnt < times; cnt++)
		{
			printf("%d번째\n", cnt + 1);
			if (mode == RIGHT)
			{
				while (pointing_node->R_Next != head_node->R_Next)
				{
					printf("%d ", pointing_node->nData);
					pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
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
					pointing_node = pointing_node->L_Next;//pointing_node가 첫번째 노드를 가리킴
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
		puts("리스트 내부에 노드가 없습니다.");
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		while (pointing_node->R_Next != head_node->R_Next)
		{

			if (pointing_node->nData == search)
			{
				if (pointing_node == head_node->R_Next)
					head_node->R_Next = pointing_node->R_Next;// 첫번째 노드가 지울 대상이면 오른쪽 노드를 삭제후 첫번째 노드로
				pointing_node->L_Next->R_Next = pointing_node->R_Next;
				pointing_node->R_Next->L_Next = pointing_node->L_Next;
				free(pointing_node);
				break;
			}
			pointing_node = pointing_node->R_Next;
		}
		//마지막 노드가 찾는 것 일때
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

	if (item >= 65 && item <= 90)//대문자 65~90
	{
		if (pointing_node->R_Next == NULL)
			result = FAIL;
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->R_Next;//헤드 오른쪽으로 이동
			while (pointing_node->L_Next != head_node->R_Next)//리스트 내부로 진입
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
	else//소문자 97~122
	{
		if (pointing_node->L_Next == NULL)
			result = FAIL;
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->L_Next;//헤드 왼쪽으로 이동
			while (pointing_node->R_Next != head_node->L_Next)//리스트 내부로 진입
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

	if (item >= 65 && item <= 90)//대문자 65~90
	{
		if (pointing_node->R_Next == NULL)
		{
			pointing_node->R_Next = temp;
			pointing_node->R_Next->L_Next = temp;
			pointing_node->R_Next->R_Next = temp;
		}
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->R_Next;//헤드 오른쪽으로 이동
			SI_doubly_c_node_sub_func_right(pointing_node, temp);
		}
	}
	else//소문자 97~122
	{
		if (pointing_node->L_Next == NULL)
		{
			pointing_node->L_Next = temp;
			pointing_node->L_Next->R_Next = temp;
			pointing_node->L_Next->L_Next = temp;
		}
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->L_Next;//헤드 왼쪽으로 이동
			SI_doubly_c_node_sub_func_left(pointing_node, temp);//리스트의 맨 마지막에 추가
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
		else//리스트 내부에 노드가 있는 경우
		{
			
			pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
			cnt++;
			while (pointing_node->L_Next != head_node->R_Next)
			{
				pointing_node = pointing_node->L_Next;//pointing_node가 첫번째 노드를 가리킴
				cnt++;
			}
		}
		result = cnt;
	}
	else
	{
		if (pointing_node->L_Next == NULL)
			result = FAIL;
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->L_Next;
			cnt++;
			while (pointing_node->R_Next != head_node->L_Next)
			{
				pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
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
			puts("대문자 0개");
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
			printf("%c ", pointing_node->nData);
			while (pointing_node->L_Next != head_node->R_Next)
			{
				pointing_node = pointing_node->L_Next;//pointing_node가 첫번째 노드를 가리킴
				printf("%c ", pointing_node->nData);
			}
		}
		printf("\n");
	}
	else
	{
		if (pointing_node->L_Next == NULL)
			puts("소문자 0개");
		else//리스트 내부에 노드가 있는 경우
		{
			pointing_node = pointing_node->L_Next;
			printf("%c ", pointing_node->nData);
			while (pointing_node->R_Next != head_node->L_Next)
			{
				pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
				printf("%c ", pointing_node->nData);
			}
		}
		printf("\n");
	}
}

#ifdef NOTYET

int get_keyboard()//키 값을 받아서 반환 한다
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

	point = get_keyboard();//키보드에서 값을 입력 받는다

	switch (point)
	{
	case 75://왼쪽
		temp = temp->L_Next;
		break;
	case 77://오른쪽
		temp = temp->R_Next;
		break;
	case 72://위쪽 
			//오른쪽 출력
		break;
	case 80://아래쪽
			//왼쪽 출력
		break;
	case 13://엔터
			//해당 노드 헤더 설정
		break;

	}

	return temp;
}
#endif
