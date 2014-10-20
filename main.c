#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
	int *elements;
	int length;
} Vector_Int;

Vector_Int *new_Vector_Int (int length) {
	Vector_Int *v = (Vector_Int*)calloc(1, sizeof(Vector_Int));
	v->length = length;
	v->elements = (int*)calloc(v->length, sizeof(int));
	for (int i = 0; i < v->length; i++) {
		v->elements[i] = 0;
	}
	return v;
}

void delete_Vector_Int (Vector_Int *v) {
	free(v->elements);
	free(v);
}

void stretch_Vector_Int (Vector_Int **v, int constant) {
	Vector_Int *w = new_Vector_Int((*v)->length + constant);
	for (int i = 0; i < (*v)->length; i++) {
		w->elements[i] = (*v)->elements[i];
	}
	delete_Vector_Int(*v);
	*v = w;
}

void push_Vector_Int (Vector_Int **v, int element) {
	stretch_Vector_Int(v, 1);
	(*v)->elements[(*v)->length - 1] = element;
}

void shrink_Vector_Int (Vector_Int **v, int constant) {
	Vector_Int *w = new_Vector_Int((*v)->length - constant);
	for (int i = 0; i < w->length; i++) {
		w->elements[i] = (*v)->elements[i];
	}
	delete_Vector_Int(*v);
	*v = w;
}

int pop_Vector_Int (Vector_Int **v) {
	int popped;
	if ((*v)->length > 0) {
		popped = (*v)->elements[(*v)->length - 1];
		shrink_Vector_Int(v, 1);
	}
	else {
		popped = 0;
	}
	return popped;
}

void print_Vector_Int (Vector_Int *v) {
	printf("[ ");
	for (int i = 0; i < v->length; i++) {
		printf("%d ", v->elements[i]);
	}
	printf("]");
}

bool equals_Vector_Int (Vector_Int *v, Vector_Int *w) {
	bool equals = true;
	if (v->length != w->length) {
		equals = false;
	}
	else {
		for (int i = 0; i < v->length; i++) {
			if (v->elements[i] != w->elements[i]) {
				equals = false;
			}
		}
	}
	return equals;
}

int main () {
	Vector_Int *v = new_Vector_Int(0);
	assert(v->length == 0 && "Vectors are not long as they're meant at init.");
	for (int i = 0; v->length < 10; i++) {
		push_Vector_Int(&v, i);
	}
	assert(v->length == 10 && "Vectors are not long as they're meant at init.");
	for (int i = 0; i < v->length; i++) {
		assert(v->elements[i] == i && "Elements are not pushed as they're meant.");
	}
	for (int i = 0; v->length > 0; i++) {
		pop_Vector_Int(&v);
	}
	assert(v->length == 0 && "Elements are not pop'd as they're meant.");
	delete_Vector_Int(v);
	return 0;
}
