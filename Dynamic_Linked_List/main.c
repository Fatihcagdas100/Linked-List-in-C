#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
	int data;
	struct Node* next;// baþka bir düðümü point ediyor.
};

Node* createNode(Node* previousNode){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node -> next = NULL;
	if(previousNode != NULL){
		previousNode -> next = new_node;
	}
	return new_node;
}

void deleteNode(Node* previousNode){
	Node* current_node = previousNode -> next;
	previousNode -> next = current_node -> next;
	free(current_node);
}

Node* searchNode(Node* head_node, int index){
	int i = 0;
	Node* node = head_node;
	while(node != NULL){
		if(i == index){
			return node;
		}
		node = node -> next;
	}
	return NULL;
}

void changeNodeValue(Node* head, int index, int value){   //farklýlýklar var(kontrol et)
	Node* searched_node = searchNode(head,index);
	if(searched_node == NULL){
		printf("Out of range\n");
	}
	else{
		searched_node -> data = value;
	}
}

void displayNodes(Node* head){
	Node* node = head;
	int i = 0;
	while(node != NULL){
		printf("%d. node: %d\n",i,node -> data);
		node = node -> next;
		i++;
	}
}

		
int main(){
	printf("hello world\n");
	
	Node* head_node = createNode(NULL);
	head_node -> data = 0;
	
	printf("How many node do you want?");
	int node_count = 0;
	scanf("%d",&node_count);
	
	Node* previousNode = head_node;   
	int i;         //Burdaki node count deðerlerini kontrol et
	for(i = 0; i<node_count; i++){
		createNode(previousNode);
		previousNode = previousNode -> next;
		previousNode -> data = i+1;
	}
	
	displayNodes(head_node);
	
	printf("Which index you want to reach?\n");
	int index = 0;
	scanf("%d",&index);
	
	
	printf("Which node do you want to be deleted?\n");
	int delete_index = 0;
	scanf("%d",&delete_index);
	if(delete_index == 0){
		Node* head_node_will_be_deleted = head_node;
		head_node = head_node -> next;
		free(head_node_will_be_deleted);
	}
	else{
		void* searched_previous_void = searchNode(head_node, delete_index-1);//void olayýný sor
		if(searched_previous_void == NULL){
			printf("Out of range \n");
			return -1;
		}
		else{
			Node* searched_previous = searched_previous_void;
			if(searched_previous -> next != NULL){
				deleteNode(searched_previous);
				printf("Deleted\n");
			}
			else{
				printf("Out of range\n");
				return -1;
			}
			
		}
	}
	
	displayNodes(head_node);
	
	
	return 0;
}
