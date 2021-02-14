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
void LInsert(List * plist, Data data);  // 꼬리에 노드 추가

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist); // 앞서 참조가 이뤄진 노드를 삭제한다.
int LCount(List * plist);

#endif