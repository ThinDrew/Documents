#include "lab1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    if (data->head != NULL)
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
    if (data->tail != NULL)
        data->tail->next = NULL;
    free(tmp);
    return val;
}

int GetElement(int index, struct List *data){
    struct Element *tmp = data->head;
    int start = 0;
    while(start != index){
        start++;
        tmp = tmp->next;
    }
    return tmp->data;
}

void Clean(struct List *data){
    struct Element *first = data->head;
    struct Element *second;
    while (data->head == NULL){
        second = first->next;
        free(first);
        first = second;
    }
}

void PopByInd(struct List *data, int index){
    struct Element *tmp = data->head;
    int start = 0;
    while(start != index && tmp->next != NULL){
        start++;
        tmp = tmp->next;
    }

    if (tmp->next != NULL && tmp->prev != NULL){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
    }
    else {
        if (tmp->next != NULL && tmp == data->head){
            data->head = tmp->next;
            tmp->next->prev = NULL;
        }
        else if(tmp->prev != NULL && tmp == data->tail){
            data->tail = tmp->prev;
            data->tail->next = NULL;
        }
        else {
            data->head = NULL;
            data->tail = NULL;
        }

    }
    free(tmp);
}

int ReadFromFile(struct List *data, char* name){
    FILE *fp;
    if ((fp = fopen(name, "rb")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }

    fread(data, sizeof(struct List), 1, fp);
    fclose(fp);
    return 1;
}

int WriteToFile(struct List *data, char* name){
    FILE *fp;
    if ((fp = fopen(name, "wb")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }


    fwrite(data, sizeof(struct List), 1, fp);
    fclose(fp);
    return 1;
}

void Print(struct List *data) 
{
    if (data->head == NULL){
        printf("Список пустой\n");
    }

    struct Element *tmp = data->head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}