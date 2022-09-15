struct Element{
    struct Element* next;
    struct Element* prev;
    int data;
};

struct List {
    struct Element* head;
    struct Element* tail;
};
