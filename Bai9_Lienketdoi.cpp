
#include <bits/stdc++.h>
using namespace std;

typedef struct NhanVien
{
    int manv;
    string hoten, ngaysinh;
    int tongluong;
};

typedef struct node
{
    NhanVien info;
    node * next;
    node * prev;
};

typedef struct List
{
    node *head;
    node *tail;
};
struct List Q;

void khoitao(List &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

node* get_node(NhanVien x)
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
	p->prev = NULL;
	return p;
}

void AddFrist(List &Q, node *p)
{
    if(Q.head == NULL)
    {
        Q.head = p;
        Q.tail = Q.head;
    }
    else
    {
        p -> next = Q.head;
        Q.head -> prev = p;
        Q.head = p;
    }
}

void Nhap(NhanVien &x)
{
        cout << "\n Manv: "; cin >> x.manv;
        cout << "\n Ten nv: "; getline(cin.ignore(),x.hoten);
        cout << "\n Ngay sinh: "; getline(cin,x.ngaysinh);
        cout << "\n Tong luong: "; cin >> x.tongluong;
}

void Nhapchitiet (List &Q, node *p)
{
    int n;
    NhanVien x;
    cout << "\n So nhan vien: "; cin >> n;
    for (int i=0; i<n; i++)
    {
        Nhap(x);
            cout << "\n ------------------\n";
            node *p = new node;
              p = get_node(x);
                AddFrist(Q,p);
    }
}

void Xuat (List &Q, node *p)
{
    cout<<"\t""\n"<<p -> info.manv<<"\t"<<p -> info.hoten<<"\t"<<p -> info.ngaysinh<<"\t"<<p -> info.tongluong;
}

void Xuatchitiet (List &Q)
{
    node * p = Q.head;
    while (p != NULL)
    {
        Xuat(Q,p);
        p = p -> next;
    }
}

void Them (List &Q)
{
    NhanVien x;
    cout << "\n Thong tin nhan vien can them";
    Nhap(x);
    node *p = new node;
              p = get_node(x);
                AddFrist(Q,p);
}
void Tongluong (List &Q)
{
    node * p;
    int sum = 0;
    p = Q.head;
    while(p != NULL)
    {
        sum = sum + p->info.tongluong;
        p = p ->next;
    }
    cout << "\n Tong luong nhan vien la: " << sum;
}
void RemoveTail(List &Q)
{
    node *p;
    if (Q.tail != NULL)
    {
        p = Q.tail;
        Q.tail = Q.tail-> prev;
        Q.tail -> next = NULL;
        if (Q.tail == NULL ) Q.head = NULL;
    }
}
void MaxLuong(List &Q)
{
    int max;
    node* p = Q.head;
    while (p != NULL)
    {
        if(max < p->info.tongluong)
         max = p->info.tongluong ;
            p =p->next;
            Xuat(Q,p);
    }
}
void Luongtren2000000(List &Q)
{
    node *p;
    p = Q.head;
    while (p != NULL)
    {
        if(p->info.tongluong > 2000000)
            p = p->next;
            Xuat(Q,p);
    }
}
void Sapxep(List &Q)
{
	NhanVien tg;
	node *min;
    node *p,*q;
	p =Q.head;
	while(p != NULL)
    {
		min=p;
		q = p ->next;
		while (q != NULL)
        {
          if(q -> info.manv < min->info.manv) min=q;
          if (min!= p)
        {
            tg=min->info;
		    min->info = p->info;
		    p->info=tg;
		}
		q = q->next;
      }
     p =p->next;
    }
    Xuatchitiet(Q);
}

/*void Sapxep(List &Q)
{
   node *pos,*x;
   node *p;
   p = Q.head ->next;
   while(p != NULL)
   {
       x->info.manv = p->info.manv;
       pos = p ->prev;
       while ((pos != NULL) && (pos->info.manv > x->info.manv))
       {
           pos-> next->info.manv = pos->info.manv;
           pos -> prev;
       }
       pos -> next ->info.manv = x->info.manv;
       p = p->next;
   }
}*/
int main(){
    List Q;
    khoitao(Q);
    node *p;
    int chon;
    do {
		cout<<"\n ================MENU===============";
		cout<<"\n 1.Nhap danh sach ";
		cout<<"\n 2.Xuat danh sach ";
		cout<<"\n 3.Them nhan vien vao dau ds ";
		cout<<"\n 4.Tinh tong luong nhan vien";
		cout<<"\n 5.Huy nhan vien cuoi khoi danh sach";
		cout<<"\n 6.Nhan vien co luong cao nhat";
		cout<<"\n 7.Danh sach nhan vien co luong tren 2000000";
		cout<<"\n 8.Sap xep nhan vien ";
    	cout<<"\n 0.Dung chuong trinh";
    	cout<<"\n MOI BAN CHON: ";
    	cin>>chon;
		switch(chon){
			case 1:
				Nhapchitiet(Q,p);
				break;
			case 2:
				cout<<"Danh sach Sinh Vien ";
				cout << "\n ---------------------------";
				Xuatchitiet(Q);
				break;
            case 3:
				Them(Q);
				cout << "\n Danh sach sau khi them ";
				Xuatchitiet(Q);
				break;
            case 4:
				Tongluong(Q);
				break;
            case 5:
				cout<<"\n Danh sach sau khi huy nhan vien cuoi ";
				RemoveTail(Q);
				Xuatchitiet(Q);
				break;
            case 6:
                cout << "\n Nhan vien co luong cao nhat ";
                MaxLuong(Q);
                break;
            case 7:
                cout << "\n Nhan vien co luong tren 2000000 ";
                Luongtren2000000(Q);
                break;
            case 8:
                Sapxep(Q);
                break;
            case 0: exit(0);
			}
	}while (chon!=0);
}

