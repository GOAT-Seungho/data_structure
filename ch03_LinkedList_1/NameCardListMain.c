#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {

    List list;
    NameCard * pcard;
    ListInit(&list);

    // 총 3명의 전화정보 정보를, 앞서 구현한 리스트에 저장한다.
    pcard = MakeNameCard("김대현", "010-1111-2222");
    LInsert(&list, pcard);
    pcard = MakeNameCard("김현수", "010-3333-4444");
    LInsert(&list, pcard);
    pcard = MakeNameCard("김도환", "010-5555-6666");
    LInsert(&list, pcard);

    // 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "김현수")) ShowNameCardInfo(pcard);
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "김현수")) {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    printf("\n");
    
    // 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "김도환")) ChangePhoneNum(pcard, "052-241-4264");
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "김도환")) {
                    ChangePhoneNum(pcard, "052-241-4264");
                    break;
                }
            }
        }
    }

    // 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "김현수")) {
            pcard = LRemove(&list);
            free(pcard);
        }
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "김현수")) {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    // 모든 남아있는 사람들의 전화번호 정보 출력
    if(LFirst(&list, &pcard)) {
        ShowNameCardInfo(pcard);
        while (LNext(&list, &pcard)) ShowNameCardInfo(pcard);
    }

    return 0;
}