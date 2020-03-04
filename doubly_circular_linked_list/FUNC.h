#pragma once
#include"ALL.h"

#ifndef __FUNC_H__
#define __FUNC_H__
Node* Add_new_doubly_C_node();
void Add_doubly_c_node_right_tail(Node *head_node, int item);
void SI_doubly_c_node(Node *head_node, int mode, int search, int item);//찾는 항목이 있을때(왼,오) 없을때(왼,오)
void SI_doubly_c_node_sub_func_right(Node *pointing_node, Node *temp);
void SI_doubly_c_node_sub_func_left(Node *pointing_node, Node *temp);
void Print_doubly_c_node(Node *head_node, int mode, int times);
void Delete_doubly_c_node(Node *head_node, int search);
void Add_doubly_c_node_right_tail_new_ver(Node *head_node, int item);
/*GAME_FUNCTION*/
int Search_doubly_c_node_GAME_1(Node* head_node, int item);
int Make_randnum_alphabet_GAME_1(Node *head_node);
void Add_doubly_c_node_GAME_1(Node* head_node, int item);
int Count_doubly_c_node_GAME_1(Node* head_node, int direction);
void Print_doubly_c_node_GAME_1(Node* head_node, int direction);
void Print_doubly_c_node_LR_GAME1(Node *head_node, int direction, int mode, int times);
void Order_GAME_1(Node *head_node);
#endif
