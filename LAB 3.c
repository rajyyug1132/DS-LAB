#include <stdio.h>
#include <stdlib.h>

#define CAP 5

int QUEUE_ARR[CAP];
int head = -1;
int tail = -1;

void enqueue(int val) {
if (tail == CAP - 1) {
printf("\nError: Queue limits reached (Overflow)\n");
} else {
if (head == -1) {
head = 0;
}
tail++;
QUEUE_ARR[tail] = val;
printf("%d added to the queue.\n", val);
}
}

int dequeue() {
if (head == -1) {
printf("\nError: Queue contains no elements (Underflow)\n");
return -1;
}

int removed_val = QUEUE_ARR[head];

if (head == tail) {
head = -1;
tail = -1;
} else {
head++;
}

return removed_val;
}

void printQueue() {
if (head == -1) {
printf("\nNotice: Queue is currently empty.\n");
} else {
printf("\nCurrent Queue contents:\n");
for (int idx = head; idx <= tail; idx++) {
printf("%d ", QUEUE_ARR[idx]);
}
printf("\n");
}
}

int main() {
int user_option, data_element, result;

do {
printf("\n=== QUEUE MENU ===\n");
printf("1. Enqueue Item\n");
printf("2. Dequeue Item\n");
printf("3. Show Queue\n");
printf("4. Terminate Program\n");
printf("Enter option (1-4): ");
scanf("%d", &user_option);

switch (user_option) {
case 1:
printf("Enter integer to enqueue: ");
scanf("%d", &data_element);
enqueue(data_element);
break;
case 2:
result = dequeue();
if (result != -1) {
printf("Removed value: %d\n", result);
}
break;
case 3:
printQueue();
break;
case 4:
printf("Shutting down program...\n");
break;
default:
printf("Selection invalid. Try again.\n");
}
} while (user_option != 4);

return 0;
}