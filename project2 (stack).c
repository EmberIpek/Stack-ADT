#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
	int *array;
	int length;
	int allocationSize;
} ArrayList_t;

/*
• Allocate memory on the heap for the stack data structure.
• Allocate memory on the heap for an array containing four integers.
• Initialize the length of the stack to zero.
• Initialize the allocation size (i.e. the capacity) of the stack to four.
• Return the address of the stack data structure.
*/
ArrayList_t* CreateAndInitStack() {
	ArrayList_t *stack = (ArrayList_t*)malloc(sizeof(ArrayList_t));
	stack->array = (int*)malloc(sizeof(int) * 4);
	stack->length = 0;
	stack->allocationSize = 4;
	
	return stack;
}

/*
• Allocate memory on the heap for an array that is twice the size of the current array.
• Copy all values from the current array to the new array.
• Update the allocation size (i.e. the capacity) of the array.
• Free up the memory that had been allocated for the current array.
*/
void Resize(ArrayList_t *stk) {
	int* newArr = (int*)malloc(sizeof(int) * stk->allocationSize * 2);
	for(int i = 0; i < stk->length; i++) {
		newArr[i] = stk->array[i];
	}
	free(stk->array);
	stk->array = newArr;
	stk->allocationSize *= 2;
	
	return;
}

/*
• Call the Resize function if the array is full.
• Insert the new value onto the top of the stack.
*/
void Push(ArrayList_t *stk, int value) {
	if(stk->length == stk->allocationSize) {
		Resize(stk);
	}
	stk->array[stk->length] = value;
	stk->length++;
	
	return;
}

/*
• Remove the value from the top of the stack.
• Return the value.
*/
int Pop(ArrayList_t *stk) {
	if(stk->length == 0) {
		return 0;
	}
	stk->length--;
	
	return stk->array[stk->length];
}

/*
• Return the value that is at the top of the stack.
• Do NOT remove the value from the stack.
*/
int Peek(ArrayList_t *stk) {
	if(stk->length == 0) {
		return 0;
	}
	
	return stk->array[stk->length - 1];
}

/*
• Return 1 (true) if the stack is empty (i.e. has no values in it); return 0 (false) otherwise.
*/
int IsEmpty(ArrayList_t *stk) {
	if(stk->length == 0) {
		return 1;
	}
	
	return 0;
}

/*
• Return the size of the stack (i.e. the number of values on the stack).
*/
int GetLength(ArrayList_t *stk) {
	return stk->length;
}

/*
• Print the values that are on the stack, starting with the value at the top of the stack.
*/
void PrintStack(ArrayList_t *stk) {
	for(int i = stk->length - 1; i >= 0; i--) {
		printf("%d ", stk->array[i]);
	}
	printf("\n");
	
	return;
}

int main() {
	
	return 0;
}