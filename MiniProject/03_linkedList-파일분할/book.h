/*
	   File: linkedList.c - 파일분할

	   Created: 24-03-27
	   Author: 이정환
*/ 

#ifndef BOOK_H
#define BOOK_H

// 도서 정보를 담는 구조체
struct Book {
    char title[50];    // 도서 제목
    char author[50];   // 저자
    int year;          // 출판년도
    int rented;        // 대여 여부 (0: 대여 가능, 1: 대여 중)
    int price;         // 가격
    struct Book *next; // 다음 도서를 가리키는 포인터
};

void addBook();
void searchBook();
void returnBook();
void deleteBook();
void printBooks();

#endif // BOOK_H
