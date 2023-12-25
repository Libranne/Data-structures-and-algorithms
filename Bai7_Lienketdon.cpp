
#include <iostream>
using namespace std;

typedef struct node
{
	int info;
	node *next;
};

typedef struct list
{
	node *head;
	node *tail;
};
struct list Q;

void KhoiTao( list &Q )
{
	Q.head = NULL;
	Q.tail = NULL;
}
node* get_node(int x)
{
	node *p;
	p = (node*) calloc (1,sizeof(node));
	if (p==NULL)
    {
        cout<< "khong du bo nho";
        exit(1);
    }
	p->info = x;
	p->next = NULL;
	return p;
}
void insertFirst(list &Q, node *p)
{
	int x;
	cout<<"Gia tri chen: ";cin>>x;
	p = get_node(x);
	if ( Q.head == NULL )
    {
		Q.head = p;
		Q.tail = Q.head;
	}
    else
    {
		p-> next = Q.head;
		Q.head = p;
	}

}
void insertLast(list &Q, node *p)
{
	if ( Q.head == NULL )
    {
		Q.head = p;
		Q.tail = Q.head;
	}
	else
	{
		Q.tail->next = p;
		Q.tail=p;
	}

}
void insertAfter(list &Q, node *p, node *q)
{
	if( q!=NULL)
    {
		p -> next = q -> next;
		q -> next = p;
		if (q == Q.tail)
			Q.tail = p;
	}
}

void Nhap(list &Q, int n)
{
    cout << "So luong phan tu: "; cin >> n;
	for (int i=0;i<n;i++)
    {
		int x;
		cout<<"A"<<i<<": ";cin>>x;
		node *p = new node;
		p = get_node(x);
		insertLast(Q,p);

	}
}

void Xuat(list Q)
{
	node *p = new node;
	for(p = Q.head; p!= NULL; p=p->next)
    {
        cout<<"\t"<<p->info;
    }
}

int main()
{
	int n,x,chon;
	list Q;
	KhoiTao(Q);
	node *p,*q;
	do {
		cout <<"\n"<<"============Menu============\n";
		cout<<"\n 1.Nhap danh sach ";
		cout<<"\n 2.Xuat danh sach ";
    	cout<<"\n 3.Chen vao dau danh sach ";
    	cout<<"\n 4.Chen vao cuoi danh sach ";
    	cout<<"\n 5.Chen vao giua danh sach";
    	cout<<"\n 0.Dung chuong trinh";
    	cout <<"\n"<<"----------------------------\n";
    	cout<<"\n Moi ban chon: ";
    	cin>>chon;
		switch(chon)
		{
			case 1:
				Nhap(Q,n);
				break;
			case 2:
				cout<<"Danh sach la: ";
				Xuat(Q);
				break;
			case 3:
				insertFirst(Q,p);
				cout<<"Danh sach sau chen: ";
				Xuat(Q);
				break;
			case 4:
			    cout<<"Gia tri chen: ";
				cin>>x;
				p = get_node(x);
				insertLast(Q,p);
				cout<<"Danh sach sau chen: ";
				Xuat(Q);
				break;
            /*case 5:
                cout<<"Gia tri chen: ";
				cin>>x;
				p = get_node(x);
				insertAfter(Q,p,q);
                cout<<"Danh sach sau chen: ";
				Xuat(Q);
				break;*/
			 case 0: exit(0);

			}
	}while (chon!=0);
}
