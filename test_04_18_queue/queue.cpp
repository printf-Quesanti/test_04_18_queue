#include"queue.h"

void queuetest1()
{
	queue q;
	queueinit(&q);
	queuepush(&q, 1);
	queuepush(&q, 2);
	queuepush(&q, 3);
	queuepush(&q, 4);
	queuepop(&q);
	printf("%d\n", queueback(&q));
	printf("%d\n", queuefront(&q));
	printf("%d\n", queuesize(&q));
}

int main()
{
	queuetest1();
	return 0;
}