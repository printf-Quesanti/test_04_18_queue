#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int queuedatatype;

typedef struct queuenode
{
	queuenode* next;
	queuedatatype data;
}qlist;

typedef struct queue
{
	qlist* head;
	qlist* tail;
};

void queueinit(queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

bool queueempty(queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

void queuedestroy(queue* pq)
{
	assert(pq);
	assert(!queueempty(pq));
	qlist* cur = pq->head;
	while (cur)
	{
		qlist* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void queuepush(queue* pq,queuedatatype x)
{
	assert(pq);
	qlist* newnode = (qlist*)malloc(sizeof(qlist));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void queuepop(queue* pq)
{
	assert(pq);
	assert(!queueempty(pq));
	qlist* next = pq->head->next;
	free(pq->head);
	pq->head = next;
}

queuedatatype queueback(queue* pq)
{
	assert(pq);
	return pq->tail->data;
}    

queuedatatype queuefront(queue* pq)
{
	assert(pq);
	return pq->head->data;
}

int queuesize(queue* pq)
{
	assert(pq);
	qlist* cur = pq->head;
	int n = 0;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

void queueinit(queue* pq);
void queuepush(queue* pq, queuedatatype x);
void queuepop(queue* pq);
void queuedestroy(queue* pq);
bool queueempty(queue* pq);
queuedatatype queueback(queue* pq);
queuedatatype queuefront(queue* pq);
int queuesize(queue* pq);