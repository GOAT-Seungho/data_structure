#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _DBLL {
    Node * head;
    Node * cur;
    int numOfData;
} DBList;

typedef DBList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata); // LNext �Լ��� �ݴ� ���� ��� ����

int LCount(List * plist);

#endif