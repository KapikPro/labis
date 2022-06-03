﻿#ifndef LINKED_DEQUE_
#define LINKED_DEQUE_

#include <cstdlib>
#include <cstdint> 
#include <stdexcept> 
#include <math.h> 
#include <string>
#include <algoriths>

struct NodeInfo
{
	int number;
	char final_point[64];
	char start_point[64];
	double start_time;
	double travel_time;
	int cost;
};

struct DequeNode
{
	NodeInfo info;
	DequeNode* next = nullptr;
	DequeNode* prev = nullptr;
};

struct LinkedDeque
{
	DequeNode* first = nullptr;
	DequeNode* last = nullptr;
};

void init(LinkedDeque& ld, const NodeInfo& info)
{
	auto new_node = (DequeNode*)calloc(1, sizeof(DequeNode));
	new_node->info = info;

	ld.first = ld.last = new_node;
}

bool empty(const LinkedDeque& ld)
{
	if (ld.first != nullptr && ld.last != nullptr)
		return false;
	return true;
}

void push_back(LinkedDeque& ld, const NodeInfo& info)
{
	auto new_node = (DequeNode*)calloc(1, sizeof(DequeNode));
	new_node->info = info;

	if (empty(ld))
	{
		ld.first = ld.last = new_node;
	}
	else
	{
		new_node->prev = ld.last;
		ld.last->next = new_node;
		ld.last = new_node;
	}
}

void pop_back(LinkedDeque& ld)
{
	if (empty(ld))
		throw std::logic_error("erorr: пустой дек");

	auto new_last = ld.last->prev;
	free(ld.last);
	ld.last = new_last;
}

void push_front(LinkedDeque& ld, const NodeInfo& info)
{
	auto new_node = (DequeNode*)calloc(1, sizeof(DequeNode));
	new_node->info = info;

	if (empty(ld))
	{
		ld.first = ld.last = new_node;
	}
	else
	{
		new_node->next = ld.first;
		ld.first->prev = new_node;
		ld.first = new_node;
	}
}
void pop_front(LinkedDeque& ld)
{
	if (empty(ld))
		throw std::logic_error("erorr: пустой дек");

	auto new_first = ld.first->next;
	free(ld.first);
	ld.first = new_first;
}

void time_check(double& time)
{
	if (fmod(time, 1.0) > 0.60)
		time -= fmod(time, 1.0);
	if (time > 24)
	{
		time = fmod(time, 1.0);
	}
	if (time < 0)
		time = 0;
}

void clear(LinkedDeque& ld)
{
	while (!empty(ld))
		pop_back(ld);

	ld.first = nullptr;
	ld.last = nullptr;
}

void fread_info(NodeInfo& info, FILE* f)
{
	fscanf(f, "%d", &info.number);
	fscanf(f, "%s", info.start_point);
	fscanf(f, "%s", info.final_point);
	fscanf(f, "%lf", &info.start_time);
	fscanf(f, "%lf", &info.travel_time);
	fscanf(f, "%d", &info.cost);
	time_check(info.start_time);
	time_check(info.travel_time);
}

void read_info(NodeInfo& info)
{
	scanf("%d", &info.number);
	scanf("%s", info.start_point);
	scanf("%s", info.final_point);
	scanf("%lf", &info.start_time);
	scanf("%lf", &info.travel_time);
	scanf("%d", &info.cost);
	time_check(info.start_time);
	time_check(info.travel_time);

}

void log(LinkedDeque& ld)
{
	FILE* f;
	if ((f = fopen("log.txt", "w")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}

	printf("%p %p\n", ld.first, ld.last);
}

void reverse(LinkedDeque& ld)
{

}

void print(const LinkedDeque& ld)
{
	if (empty(ld))
	{
		printf("вы не создали стек или не заполнили..\n");
		return;
	}

	int c = 0;
	auto cur_node = ld.first;
	printf("\n", c);
	while (cur_node != nullptr)
	{
		printf("--------------------------------------------\n");
		printf("%dый элемент\n", c);
		c++;
		printf("%d\n", cur_node->info.number);
		printf("%s\n", cur_node->info.start_point);
		printf("%s\n", cur_node->info.final_point);
		printf("%4.2lf\n", cur_node->info.start_time);
		printf("%4.2lf\n", cur_node->info.travel_time);
		printf("%d\n", cur_node->info.cost);
		printf("--------------------------------------------\n");
		cur_node = cur_node->next;
	}
	printf("\n", c);
}

char* uppercase(char* s)
{
	static char S[64];
	strcpy(S, s);
	char* ch = S;
	while (*ch) {
		if (*ch >= 'a' && *ch <= 'z' || *ch >= 'а' && *ch <= 'я')
			*ch = *ch - 32;
		ch++;
	}
	return S;
}

void solve(const LinkedDeque& ld1, LinkedDeque& ld2)
{
	if (empty(ld1))
	{
		printf("вы не создали стек или не заполнили, пойдите и исправьте..\n");
		return;
	}
	auto cur_node1 = ld1.first;
	auto cur_node2 = ld2.first;
	while (cur_node1 != nullptr)
	{
		if (strcmp(uppercase(cur_node1->info.start_point), "МОСКВА") == 0 &&
			strcmp(uppercase(cur_node1->info.final_point), "САНКТ-ПЕТЕРБУРГ") == 0 &&
			cur_node1->info.start_time >= 7.00 && cur_node1->info.start_time <= 9.00)
			push_back(ld2, cur_node1->info);
		cur_node1 = cur_node1->next;
	}
	printf("второй стэк был заполнен походящими элементами\n");
}
#endif // LINKED_DEQUE_