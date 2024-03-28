/*
	   File: linkedList.c - 파일분할

	   Created: 24-03-27
	   Author: 이정환
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

struct Book *head = NULL; // 도서 목록의 시작을 가리키는 전역 변수

void addBook() {
    // 도서 추가 코드
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book)); // 새로운 도서를 위한 메모리 할당
    if (newBook == NULL) { // 메모리 할당 실패 시 오류 메시지 출력 후 종료
        printf("메모리 할당 오류\n");
        return;
    }

    printf("도서 제목: ");
    scanf("%s", newBook->title);
    printf("저자: ");
    scanf("%s", newBook->author);
    printf("출판년도: ");
    scanf("%d", &newBook->year);
    printf("가격: ");
    scanf("%d", &newBook->price);
    newBook->rented = 0; // 초기값은 대여 가능

    newBook->next = head; // 새로운 도서를 목록의 맨 앞에 추가
    head = newBook;
}

void searchBook() {
    // 도서 검색 코드
    char title[50];
    printf("검색할 도서 제목: ");
    scanf("%s", title);

    struct Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            printf("도서가 존재합니다.\n");
            if (current->rented == 0) {
                printf("도서를 대여합니다.\n");
                current->rented = 1; // 도서를 대여 중으로 변경
            } else {
                printf("죄송합니다. 해당 도서는 이미 대여 중입니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("도서가 존재하지 않습니다.\n");
}

void returnBook() {
    // 도서 반납 코드
    char title[50];
    printf("반납할 도서 제목: ");
    scanf("%s", title);

    struct Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            if (current->rented == 1) {
                current->rented = 0; // 도서를 대여 가능으로 변경
                printf("도서를 반납했습니다.\n");
            } else {
                printf("이 도서는 대여 중이 아닙니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("도서를 찾을 수 없습니다.\n");
}

// 도서 삭제 함수
void deleteBook() {
    char title[50];
    printf("삭제할 도서 제목: ");
    scanf("%s", title);

    struct Book *prev = NULL;
    struct Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) { // 입력한 도서 제목과 일치하는 도서를 찾았을 때
            if (prev == NULL) {
                head = current->next; // 첫 번째 도서를 삭제할 때
            } else {
                prev->next = current->next;
            }
            free(current); // 메모리 해제
            printf("도서를 삭제했습니다.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("해당 도서를 찾을 수 없습니다.\n");
}

// 도서 목록 출력 함수
void printBooks() {
    printf("도서 목록:\n");
    struct Book *current = head;
    while (current != NULL) {
        printf("제목: %s (저자: %s, 출판년도: %d, 출판가격: %d 원) - %s\n", current->title, current->author, current->year, current->price,  current->rented == 0 ? "대여 가능" : "대여 중");
        current = current->next;
    }
}