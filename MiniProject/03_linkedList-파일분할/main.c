/*
	   File: linkedList.c - 파일분할

	   Created: 24-03-27
	   Author: 이정환
*/ 

#include <stdio.h>
#include "user.h"
#include "book.h"

// 메인메뉴 함수
void mainMenu() {
    int choice;
    do {
        printf("\n----- 도서 관리 메뉴 ----\n");
        printf("1. 도서구입(등록)\n");
        printf("2. 도서검색\n");
        printf("3. 도서반납\n");
        printf("4. 도서삭제\n");
        printf("5. 도서출력\n");
        printf("0. 로그아웃 및 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printBooks();
                break;
            case 0:
                printf("로그아웃합니다.\n");
                return;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    } while (choice != 0);
}

// 메뉴 함수
void menu() {
    int choice;
    do {
        printf("\n------ 메뉴-----\n");
        printf("1. 로그인\n");
        printf("2. 회원가입\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) { 
            case 1: 
                if (login()) mainMenu();
                 break;
            case 2:
                registerUser();
                 break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    } while (choice != 0);
}


// 프로그램 시작점
void main() {
    menu(); // 메뉴 호출
}