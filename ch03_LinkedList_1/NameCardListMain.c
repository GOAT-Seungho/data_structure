#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {

    List list;
    NameCard * pcard;
    ListInit(&list);

    // �� 3���� ��ȭ���� ������, �ռ� ������ ����Ʈ�� �����Ѵ�.
    pcard = MakeNameCard("�����", "010-1111-2222");
    LInsert(&list, pcard);
    pcard = MakeNameCard("������", "010-3333-4444");
    LInsert(&list, pcard);
    pcard = MakeNameCard("�赵ȯ", "010-5555-6666");
    LInsert(&list, pcard);

    // Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "������")) ShowNameCardInfo(pcard);
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "������")) {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    printf("\n");
    
    // Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ �����Ѵ�.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "�赵ȯ")) ChangePhoneNum(pcard, "052-241-4264");
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "�赵ȯ")) {
                    ChangePhoneNum(pcard, "052-241-4264");
                    break;
                }
            }
        }
    }

    // Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.
    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "������")) {
            pcard = LRemove(&list);
            free(pcard);
        }
        else {
            while (LNext(&list, &pcard)) {
                if (!NameCompare(pcard, "������")) {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    // ��� �����ִ� ������� ��ȭ��ȣ ���� ���
    if(LFirst(&list, &pcard)) {
        ShowNameCardInfo(pcard);
        while (LNext(&list, &pcard)) ShowNameCardInfo(pcard);
    }

    return 0;
}