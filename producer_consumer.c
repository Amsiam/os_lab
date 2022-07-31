#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int Wait(int s)
{
	return --s;
}
int Signal(int s)
{
	return ++s;
}

void producer()
{
	mutex = Wait(mutex);
	full = Signal(mutex);
	empty = Wait(empty);
	x++;
	printf("\nProducer produces item %d\n", x);
	mutex = Signal(mutex);
}

void consumer()
{
	mutex = Wait(mutex);
	full = Wait(full);
	empty = Signal(empty);
	printf("\nConsumer Consume item %d\n", x);
	x--;
	mutex = Signal(mutex);
}
int main() {
	int n;
	while (1) {
		printf("Chose Option...\n1.Producer\t2.Consumer\t3.Exit\nEnter Choice : ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if (mutex == 1 && empty != 0)
				producer();
			else
				printf("Buffer is Full\n");
			break;
		case 2:
			if (mutex == 1 && full != 0)
				consumer();
			else
				printf("Buffer is Empty\n");
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}

	return 0;
}
