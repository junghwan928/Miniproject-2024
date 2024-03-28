/*
	   File: linkedList.c - 파일분할

	   Created: 24-03-27
	   Author: 이정환
*/ 

#ifndef USER_H
#define USER_H

// 사용자 정보를 담는 구조체
struct User {
    char username[50]; // 사용자 이름
    char password[50]; // 비밀번호
    struct User *next; // 다음 사용자를 가리키는 포인터
};

void registerUser();
int login();

#endif // USER_H
