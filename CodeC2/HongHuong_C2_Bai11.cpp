﻿//Bài 11, Chương 2: DS hạn ch621, hàng đợi. QUEUE
//QUEUE sử dụng DSLK
#include <stdio.h>
#include <iostream>
using namespace std;

//Câu 11.1: Khai báo cấu trúc QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

//Câu 11.2: Khởi tạo QUEUE rỗng
void init()
{
	front = NULL;
	rear = NULL;
}

//Câu 11.3: Kiểm tra QUEUE rỗng
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

//Câu 11.4: Thêm phần tử vào QUEUE
void Push(int x)
{
	Node *p= new Node;
	p ->info = x;
	p ->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear ->link = p;
	rear = p;
}

//Câu 11.5: Xóa phần tử ra khỏi QUEUE
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p ->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

//Xuất QUEUE
void Process_queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout<< "<-- ";
		do
		{
			cout<<p ->info<<" ";
			p=p->link;
		}
		while(p!=NULL);
		cout<<"<-- "<<endl;
	}
}

int main()
{
	int choice,x,i;
	system("cls");
	cout<<"------- Bai 11, Chuong 2: QUEUE (HANG DOI, DSLK) -------"<<endl;
	cout<<"1. Khoi tao QUEUE rong"<<endl;
	cout<<"2. Them phan tu vao QUEUE"<<endl;
	cout<<"3. Xoa phan tu ra khoi QUEUE"<<endl;
	cout<<"4. Kiem tra QUEUE co rong hay khong"<<endl;
	cout<<"5. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		    case 1:
				init();
				cout<<"Ban vua khoi tao QUEUE rong thanh cong!\n";
				break;
			case 2:
				cout<<"Vui long nhap gia tri x= ";
				cin>>x;
				Push(x);
				cout<<"QUEUE sau khi them la: ";
				Process_queue();
				break;
			case 3:
				Pop(x);
				cout<<"Phan tu lay ra tu QUEUE la: ";
				cout<<"QUEUE sau khi lay ra la: ";
				Process_queue();
				break;
			case 4:
				i= isEmpty();
				if (i==0)
					cout<<"QUEUE khong rong!"<<x<<endl;
				else
					cout<<"QUEUE rong!"<<endl;
				break;
			case 5:
				cout<<"QUEUE hien tai la: ";
				Process_queue();
				break;
			case 6:
				cout<<"Goodbye...!"<<endl;
				break;
			default:
				break;
		}
	}
	while(choice!=6);
	system ("pause");
	return 0;
}