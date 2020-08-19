#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next,* prev;
}soldier;

soldier* create_soldier(int sequence);
soldier* create_reverse_circle(int n);
soldier* rearrange_circle(soldier* head);
void display(soldier* head);
int kill(soldier* head, int n, int k);

int main() {
    int n, k;
		soldier* head = NULL;

    scanf("%d %d", &n, &k);

		head = create_reverse_circle(n);

		display(head);

		printf("\nSurvived: %d\n", kill(head, n, k));

    return 0; 
}

soldier* create_soldier(int sequence){
	soldier* newSoldier = malloc(sizeof(soldier));
	newSoldier->data = sequence;
	newSoldier->prev = NULL;
	newSoldier->next = NULL;

	return newSoldier;
}

soldier* create_reverse_circle(int n){
	soldier* head = NULL;
	soldier* iter;
	soldier* soldier;
	
	for(int i = 1; i <= n; i++){
		soldier = create_soldier(i);
		soldier->next = head;
		head = soldier;
		head->prev = NULL;

		if(head->next)
			head->next->prev = head;
		
	}

	while(soldier->next != NULL) soldier = soldier->next;
	head->prev = soldier;
	soldier->next = head;

	return head;
}

void display(soldier* iter){

	printf("List: ");

	while(iter->data != 1){
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("%d ", iter->data);

	// 1 2 3 4 5
	printf("\nAfter ordering: ");

	while(iter->prev->data != 1){
		printf("%d ", iter->data);
		iter = iter->prev;
	}
	printf("%d ", iter->data);

}

int kill(soldier* iter, int size, int k){

	while(iter->prev != iter){
		for(int i = 0; i < k; i++)
			iter = iter->prev;
		
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
	}

	return iter->data;
}

