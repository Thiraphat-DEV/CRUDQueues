#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//create data node
typedef struct datanode
{
	int id;
	char name[25];
	struct datanode *next;
} datanode;
//crate Head Node
typedef struct headnode
{
	datanode *front;
	datanode *rear;
	int count;
} headnode;

headnode *createQueue(void); //apply headnode pass createQueue
headnode *destroyQueue(headnode *queue, int id, char *name); //apply headnode pass destroyQueue

//apply headnode pass destroyQueue
bool enqueue(headnode *queue, int id, char *name);
bool dequeue(headnode *queue, int id, char *name);
bool queueFront(headnode *queue, int id, char *name);
bool queueRear(headnode *queue, int id, char *name);
int queueCount(headnode *queue);
void printQueue(headnode *queue);

//default headNode is null
headnode *MyQueue = NULL;

//build createQueue
headnode *createQueue(void)
{
	headnode *queue;
	queue = new headnode;
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	return (queue);
}

//build enqueue and
bool enqueue(headnode *queue, int id, char *name)
{
	datanode *newPtr;
	if (!(newPtr = new datanode))
		return (false);

	newPtr->id = id;
	strcpy(newPtr->name, name);
	newPtr->next = NULL;

	if (queue->count == 0)
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

	(queue->count)++;
	queue->rear = newPtr;
	return (true);
}

//build dequeue

bool dequeue(headnode *queue, int id, char *name)
{
	datanode *deleteData;
	printf("\n Dequeue Success \n\n");
	printf(" ID\tName\n");
	printf(" ---\t-----\n");
	printf(" %d\t%s\n\n", MyQueue->front->id, MyQueue->front->name);

	if (!queue->count)
		return (false);

	id = queue->front->id;
	strcpy(queue->front->name, name);
	deleteData = queue->front;
	if (queue->count == 1)
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->next;
	(queue->count)--;
	free(deleteData);
	return (true);
}
//build enqueue and return front
bool queueFront(headnode *queue, int id, char *name)
{
	if (!queue->count)
	{
		return (false);
	}
	else
	{
		id = queue->front->id;
		return (true);
	}
}
//build enqueue and return 0, 1
bool queueRear(headnode *queue, int id, char *name)
{
	if (!queue->count)
	{
		return (false);
	}
	else
	{
		id = queue->rear->id;
		strcpy(queue->rear->name, name);
		return (true);
	}
}
//build Count and return Count in Queue
int queueCount(headnode *queue)
{
	printf("%d\n", queue->count); //get count in headnode
	return (queue->count); //return Count
}
//build destroyQueue
headnode *destroyQueue(headnode *queue, int id, char *name)
{
	datanode *deletePtr;
	if (queue) // queue is true
	{
		while (queue->front != NULL) //loop queuefront is not null
		{
			deletePtr = queue->front; //del from queue front
			queue->front = queue->front->next; //increase queue front
			free(deletePtr);		   //return delqueue to memory
		}
		free(queue); //return queue to memory
	}
	return (NULL);
}
//build printQueue and print in  function is not return
void printQueue(headnode *queue)
{
	datanode *node = queue->front; //reach node default equal queue front
	printf("\tData in Queue\n\n");
	printf(" \tID\t\tName\n");
	printf(" \t---\t\t-----\n");
	printf("Front=>");
	while (node) //node is true
	{
		printf("\t%d", (int *)node->id); //show id in node
		printf("\t\t%s \n", node->name); //show name in node
		node = node->next;		 //increase node
	}
	printf("\b<=Rear\n"); //new line
}
//function main
int main()
{
	//create name, id and switch check ch is not 0
	char name[20];
	int id, ch = 1;
	struct datanode *ptr;

	while (ch != 0)
	{
		//selection Menu
		system("cls");//clear screen import from stdlib
		printf(" \n**Struct Queue Program Test** \n");
		printf(" \n 1 Create Queue \n");
		printf(" 2 Enqueue \n");
		printf(" 3 Dequeue \n");
		printf(" 4 Queue Front \n");
		printf(" 5 Queue Rear \n");
		printf(" 6 Queue Count \n");
		printf(" 7 Destroy Queue \n");
		printf(" 8 Print List Queue \n");
		printf(" 0 Quit \n");

		printf("\n Please Select Your Function Number...");

		scanf("%d", &ch);
		//generate case By Option
		switch (ch)
		{
		case 1:
			system("cls"); //clear screen import from stdlib
			MyQueue = createQueue();
			if (MyQueue != NULL) //myqueue is not null
			{
				printf("\n Create Queue Complete \n\n");
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't Create Queue \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;

		case 2:
			system("cls");
			printf("\n Enter Your ID : ");
			scanf("%d", &id); //get id
			printf(" Enter Your name : ");
			scanf("%s", name); //get name

			if (enqueue(MyQueue, id, name)) //apply function enqueue and get global parameter  in int main
			{
				printf("\n Enqueue Success \n\n");
				printf(" ID\tName\n");
				printf(" ---\t-----\n");
				printf(" %d\t%s\n\n", MyQueue->rear->id, MyQueue->rear->name); //reach in myQueue and reach last id and last name  in queue  for show QueueRear
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't Enqueue \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;
		case 3:
			system("cls");
			if (dequeue(MyQueue, id, name)) //dequeue is true
			{
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't Dequeue, because it's underflow \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;
		case 4:
			system("cls");
			if (queueFront(MyQueue, id, name))
			{
				printf("\nQueueFront Success\n\n");
				printf(" ID\tName\n");
				printf(" ---\t-----\n");
				printf(" %d\t%s\n\n", MyQueue->front->id, MyQueue->front->name); //reach in myQueue and reach first id and last name  in queue
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't QueueFornt \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;
		case 5:
			system("cls");
			if (queueRear(MyQueue, id, name)) //apply function queueRear and get parameter in function int main
			{
				printf("\nQueueRear Success \n\n");
				printf(" ID\tName\n");
				printf(" ---\t-----\n");
				printf(" %d\t%s\n\n", MyQueue->rear->id, MyQueue->rear->name); //reach in myQueue and reach first id and last name  in queue
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't QueueRear \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;
		case 6:
			system("cls");
			printf("\nData in Queue count : ");
			queueCount(MyQueue); //apply function Count and show count
			printf(" \n\nPlease any key to continue...");
			getch();
			break;
		case 7:
			system("cls");
			destroyQueue(MyQueue, id, name); //apply function destroyQueue
			if (MyQueue != NULL) //myqueue is not null
			{
				printf("\n Destroy Queue Complete \n\n");
				printf(" Please any key to continue...");
			}
			else
			{
				printf("\n Can't Destroy Queue \n\n");
				printf(" Please any key to continue...");
			}
			getch();
			break;
		case 8:
			system("cls");
			printQueue(MyQueue);//show all queue 
			getch();
			break;
		default :
			printf("thiraphat Chorakhe\n");
			break;
			
		}
	}
	return (0);
}