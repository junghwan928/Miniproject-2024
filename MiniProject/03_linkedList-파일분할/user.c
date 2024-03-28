/*
	   File: linkedList.c - 파일분할

	   Created: 24-03-27
	   Author: 이정환
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

struct User *userList = NULL; // 사용자 목록을 가리키는 전역 변수

void registerUser() {
    // 사용자 등록 코드
    struct User *newUser = (struct User *)malloc(sizeof(struct User)); // 새로운 사용자를 위한 메모리 할당
    if (newUser == NULL) { // 메모리 할당 실패 시 오류 메시지 출력 후 종료
         printf("메모리 할당 오류\n");
         return;
     }

     printf("사용자 이름: ");
     scanf("%s", newUser->username);
     printf("비밀번호: ");
     scanf("%s", newUser->password);

     newUser->next = userList; // 새로운 사용자를 목록의 맨 앞에 추가
     userList = newUser;
     printf("회원가입이 완료되었습니다.\n");
}

int login() {
    // 로그인 코드
    char username[50];
    char password[50];
    printf("사용자 이름: ");
    scanf("%s", username);
    printf("비밀번호: ");
    scanf("%s", password);

   struct User *current = userList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            printf("로그인 성공!\n");
            return 1; // 로그인 성공 시 1 반환
        }
        current = current->next;
    }
    printf("잘못된 사용자 이름 또는 비밀번호입니다.\n");
    return 0; // 로그인 실패 시 0 반환
}
