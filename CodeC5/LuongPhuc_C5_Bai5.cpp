// bai 5, chuong 5:do thi
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

// DSLK su dung cho STACK vs QUEUE, va DS KE
struct Node {
	int info;
	Node *link;
};
Node *First[MAX]; // DS cac DSK
int n; // so dinh cua do thi
char vertex[MAX];

Node *sp;
Node *front, *rear;

// STACK
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
///end STACK

// QUEUE
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear ==NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
//end QUEUE
void InitGraph()
{
	n=0;
}
void InsertLast(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node * q = first;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link = p;
	}
}
void inputGraphFromText()
{
	string line;
	ifstream mylife ("danhsachke1.txt");
	if (mylife.is_open())
	{
		mylife >> n;
		for(int i=0;i<n;i++)
			mylife>>vertex[i];
		string str;
		int i = 0;
		while(getline(mylife, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				//dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1],p);
			}
			i++;
		}
	}
}
	
void inputGraph()
{
	cout<<"Nhap so dinh do thi n: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for (int i=0;i<n;i++)
		cin>>vertex[i];
	
	for(int i=0; i<n+1;i++)
	{
		if(i>0)
			cout<<"nhap DSK cua dinh thu "<<i-1<<"  ("<<vertex[i-1]<<") : ";
		int u;
		string str;
		while(getline(cin,str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1],p);
			}
			break;
		}
	}
}

void outputGraph()
{
	for(int i=0;i<n;i++)
	{
		cout << " Dinh "<<i<<" ("<<vertex[i]<<") : ";
		Node *p = First[i];
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->link;
		}
		cout<<endl;
	}
}
void output (int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<vertex[a[i]]<<" ";
}
//BFS
int C[100], bfs[100];
int nbfs=0;
void InitC()
{
	for(int i=0; i<n; i++)
		C[i]=1;
}
void BFS(int v)/// v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		w= First[p];
		nbfs++;
		while(w!=NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info]=0;
			}
			w=w->link;
		}
	}
}
//DFS
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int u=s;
	Node * v = NULL;
	while (isEmptyS()==0)
	{
		if(v==NULL)
			PopS(u);
		v = First[u];
		while(v!=NULL)
		{
			if(C[v->info]==1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs]=v->info;
				ndfs++;
				C[v->info] = 0;
				u=v->info;
				break;
			}
			v=v->link;

		}
	
	}
}
// dung BFS tim x tren do thi
void Search_by_BFS(int x, int v) /// v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout<<"Tim Thay x"<<x<<endl;
			return;
		}
		w = First[p];
		while(w!=NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info]=0;
			}
			w=w->link;

		}
	}
}

int main()
{
	
	int choice, x, i;
	system("cls");
	cout<<"--------- Bai tap 5, chuong 5, do thi---------"<<endl;
	cout<<"1. Khoi tao Danh Sach KE rong"<<endl;
	cout<<"2. Nhap Danh Sach ke tu file text"<<endl;
	cout<<"3. Nhap Danh Sach "<<endl;
	cout<<"4. Xuat Danh Sach"<<endl;
	cout<<"5. Duyet do thi theo chieu rong BFS - DSLK"<<endl;
	cout<<"6. Duyet do thi theo chieu sau DFS - DSLK"<<endl;
	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. Goodbye"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao Danh Sach ke rong thanh cong ! \n";
			break;
		case 2:
			inputGraphFromText();
			cout <<"Ban vua nhap Danh Sach ke tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin>>x;
			ndfs = 0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
			output(dfs,n);
			break;
		case 7:
			cout << "Vui long nhap gia tri x can tim: ";
			cin>>x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout << "GoodBye...."<<endl;
			break;
		default:
			break;

		}
	}while(choice!=8);
	system("pause");
	return 0;
}

