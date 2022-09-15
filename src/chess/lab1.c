#include "lab1.h"
#include <stdlib.h>
#include <stdio.h>

void Init(struct List *data){
    data->head = NULL;
    data->tail = NULL;
}

void Push(struct List *data, int value) {
    struct Element *tmp = (struct Element*) malloc(sizeof(struct Element));
    tmp->data = value;
    if(data->head == NULL){
        data->head = tmp;
        data->tail = tmp;
    }

    else {
        tmp->next = data->head;
        data->head->prev = tmp;
        data->head = tmp;
        tmp->prev = NULL;
    }
 
}

void PushBack(struct List *data, int value) {
    struct Element *tmp = (struct Element*) malloc(sizeof(struct Element));
    tmp->data = value;
    if(data->tail == NULL){
        data->head = tmp;
        data->tail = tmp;
    }

    else {
        tmp->prev = data->tail;
        data->tail->next = tmp;
        data->tail = tmp;
        tmp->next = NULL;
    }

}

int Pop(struct List *data){
    struct Element *tmp;
    int val;
    if (data->head == NULL) {
        exit(-1);
    }

    tmp = data->head;
    val = tmp->data;
    data->head = data->head->next;
    data->head->prev = NULL;
    free(tmp);
    return val;
}

int PopBack(struct List *data){
    struct Element *tmp;
    int val;
    if (data->head == NULL) {
        exit(-1);
    }

    tmp = data->tail;
    val = tmp->data;
    data->tail = tmp->prev;
    data->tail->next = NULL;
    free(tmp);
    return val;
}

void Print(struct List *data) 
{
    struct Element *tmp = data->head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}