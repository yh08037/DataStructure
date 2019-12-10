
//#ifndef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
//#endif


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MAX_STR_LEN 256


typedef struct StackheadType {
	int top;
	char* data;
} StackHead;

typedef struct NodeType {
	StackHead stackhead;
	struct NodeType *next;
} QueueNode;

struct QueueHeadType {
	int count;
	QueueNode* queuenode;
} Queue;


int createQueue() {
	Queue.count = 0;
	Queue.queuenode = NULL;
	return 1;
}

QueueNode* createNode(char *str);
int addQueue(char *str);
void push(char *sn, char c);
char pop(char *sn);
int deleteQueue();
char* searchQueue();
void traverseQueue(); // printout queue
void printStack(StackHead* stackhead);
void printReverse(char* arr, int top);


/*================================================================*/


int main() {

	int input;
	unsigned int i;
	char str[MAX_STR_LEN];
	char* found = NULL;
	

	createQueue();

	
	while (1) {
		input = -1;
		printf("Add (0), Delete (1), Last_In Search (2), Exit (3) : ");
		scanf("%d", &input);
		while (getchar() != '\n');

		if (input == 0) {
			printf("add : ");
			scanf("%s", str);
			if ( !addQueue(str) ) 
				printf("addQueue failed.\n");
		}
		else if (input == 1) {
			if ( !deleteQueue() )
				printf("deleteQueue failed.\n");
		}
		else if (input == 2) {
			found = searchQueue();
			if ( found != NULL ) {
				printf("Last inserted element : ");
				printReverse(found, strlen(found));
				printf("\n");				
			}
		}
		else if (input == 3) {
			return 0;
		}
		else {
			printf("invalid input. try again.\n");
		}

		printf("Current Stat :");
		traverseQueue();
		printf("\n");
	}


	return 0;
}


/*================================================================*/


QueueNode* createNode(char *str) {
	QueueNode* newNode = NULL;
	char* newString = (char*)malloc(sizeof(MAX_STR_LEN));
	
	if ( str == NULL )
		return NULL;

	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	strcpy(newString, str);
	newNode->stackhead.top = strlen(str);
	newNode->stackhead.data = newString;
	newNode->next = NULL;

	return newNode;
}

int addQueue(char *str) {
	QueueNode* newNode = NULL;
	QueueNode* tmp = NULL;
	
	if ( (newNode = createNode(str)) != NULL ) {
		if ( Queue.queuenode == NULL )  {
			Queue.queuenode = newNode;
			Queue.count++;
		}
		else {
			tmp = Queue.queuenode;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = newNode;
			Queue.count++;
		}
	}

	return 1;
}


void push(char *sn, char c) {
	int i = -1;

	while (sn[++i] != '\0');

	sn[i] = c;
}


char pop(char* sn) {
	int i = -1;
	char result;

	while (sn[++i] != '\0');
	result = sn[i-1];
	sn[i-1] = '\0';

	return result;
}



int deleteQueue() {
	QueueNode* node = Queue.queuenode;

	if (Queue.count < 1) 
		return 0;

	Queue.queuenode = Queue.queuenode->next;
	free(node);
	Queue.count--;

	return 1;
}


char* searchQueue() {
	QueueNode* tmp = Queue.queuenode;
	
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	return tmp->stackhead.data;
}



void traverseQueue() { // printout queue
	QueueNode* tmp = Queue.queuenode;
	while (tmp != NULL) {
		printStack(&(tmp->stackhead));
		printf(" ");
		tmp = tmp->next;
	}

	printf("(%d)\n", Queue.count);
}


void printStack(StackHead* stackhead) {
	int i = 0;
	int save_top = stackhead->top;
	char tmp[MAX_STR_LEN] = {0};

	for (i = 0; i < save_top; i++)
		push(tmp, stackhead->data[i]);
	
	while (save_top-- > 0)
		printf("%c", pop(tmp));
}

void printReverse(char* arr, int top) {
	int i;
	char tmp[MAX_STR_LEN] = {0};


	for (i = 0; i < top; i++)
		push(tmp, arr[i]);

	while (top-- > 0)
		printf("%c", pop(tmp));
}
