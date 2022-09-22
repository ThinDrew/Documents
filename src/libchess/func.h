#include "lab1.h"

void Init(struct List *data);
void Push(struct List *data, int value);
void PushBack(struct List *data, int value);
int Pop(struct List *data);
int PopBack(struct List *data);
void Print(struct List *data);
int GetElement(int index, struct List *data);
int WriteToFile(struct List *data, char* name);
int ReadFromFile(struct List *data, char* name);
void PopByInd(struct List *data, int index);