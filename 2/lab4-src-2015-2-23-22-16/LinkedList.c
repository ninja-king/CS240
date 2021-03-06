
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	ListNode *e;
	e = list->head;
	while(e != NULL){
		if(e->value == value){
			return 1;
		}
		e = e->next;
	}
	return 0;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	ListNode *pre;
	ListNode *e;
	e = list->head;
	pre = NULL;
	while(e != NULL){
		if(e->value == value && e==list->head){
			pre=e->next;
			free(e);
			list->head=pre;
			return 1;
		}else if(e->value == value){
			pre->next = e->next;
			free(e);
			e = NULL;
			return 1;
		}
		pre=e;
		e=e->next;
	}
	return 0;
}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	ListNode *e;
	e = list->head;
	int count = 0;
	while(e != NULL){
		for(count;count != ith; count ++){
		//check if list does not has ith elements, then return 0;
			if(e->next == NULL){
				return 0;
			}else{
				e = e->next;
			}
		}
		//store value to *value
		*value = e->value;
		return 1;
	}
}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode *e;
	ListNode *pre;
	e = list->head;
	pre = NULL;
	int count = 0;
	
	while(e != NULL){
		//if ith = 0, then remove head
		if(ith == 0){
			list->head = e->next;
			return 1;
		}

		for(count;count != ith; count++){
			//check if list does not has ith elements, then return 0;
			if(e->next == NULL){
				return 0;
			}else{ 
			//if ith element does exist, then let e move to ith node
				pre = e;
				e = e->next;
			}
		}
		//remove ith entry
		pre->next = e->next;
		free(e);
		e = NULL;
		return 1;
	}
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	ListNode * e;
	e = list->head;
	int count = 0;;
	
	while(e != NULL){
		e = e->next;
		count ++;
	}
	return count;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
	ListNode *e;
	e = list->head;
	int position = 0;

	while (e != NULL){
		file_name[position] = e->value;
		file_name[position + 1] = '\n';
		position = position +2;
		e = e->next;
	}
	return 1;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	return 1;
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	return 0;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
  return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list)
{
}
