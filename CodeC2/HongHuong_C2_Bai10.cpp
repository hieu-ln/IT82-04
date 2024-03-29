﻿//Bài 10, Chương 2: DS hạn chế, hàng đợi STACK
//STACK sử dụng DSLK ĐƠN
#include <stdio.h>
#include <iostream>
using namespace std;

//Câu 10.1: Khai báo cấu trúc STACK
struct Node
{
	int info;
	Node *link;
};
Node *sp;

//Câu 10.2: Khởi tạo STACK rỗng
void init()
{
	sp=NULL;
}

//Câu 10.3: Kiểm tra STACK rỗng
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

//Câu 10.4: Thêm phần tử vào STACK
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p-> link = sp;
	sp = p;
}

//Câu 10.5: Lấy phần tử ra khỏi STACK
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p -> info;
		sp = p -> link;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat STACK
void Process_stack()
{
	Node *p = sp;
	do
	{
		cout<<p ->info <<" ";
		p=p->link;
	}
	while (p!= NULL);
	cout<<endl;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout<<"------- BAI 10, CHUONG 2: STACK (NGAN XEP - DSLK) -------"<<endl;
	cout<<"1. Khoi tao STACK rong"<<endl;
	cout<<"2. Them phan tu vao STACK"<<endl;
	cout<<"3. Lay phan tu ra khoi STACK"<<endl;
	cout<<"4. Xuat STACK"<<endl;
	cout<<"5. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>> choice;
		switch (choice)
		{
		    case 1:
				init();
				cout<<"Ban vua khoi tao STACK rong thanh cong!\n";
				break;
			case 2:
				cout<<"Vui long nhap gia tri x= ";
				cin>>x;
				Push(x);
				cout<<"STACK sau khi them la: ";
				Process_stack();
				break;
			case 3:
				Pop(x);
				cout<<"Phan tu lay ra tu STACK la x= "<<x;
				cout<<"STACK sau khi lay ra la: ";
				Process_stack();
				break;
			case 4:
				cout<<"STACK hien tai la: ";
				Process_stack();
				break;
			case 5:
				cout << "Goodbye...!"<<endl;
				break;
			default:
				break;
		}
	}
	while (choice !=5);
	system("pause");
	return 0;
}