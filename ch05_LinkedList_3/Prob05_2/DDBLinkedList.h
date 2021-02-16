#ifndef __DDB_LINKED_LIST_H__
#define __DDB_LINKED_LIST_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _DDBLL {
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DDBLList;

typedef DDBLList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);  // ������ ��� �߰�

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist); // �ռ� ������ �̷��� ��带 �����Ѵ�.
int LCount(List * plist);

#endif