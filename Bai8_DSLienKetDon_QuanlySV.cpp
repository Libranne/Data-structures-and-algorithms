#include <bits/stdc++.h>
using namespace std;

typedef struct SinhVien
{
    string MaSV,lop,hoten;
    float DLT, DTH, DT, DTB;
};
typedef struct nodeSinhVien
{
    SinhVien info;
    nodeSinhVien *next;
};
typedef struct listSinhVien
{
    nodeSinhVien*head;
    nodeSinhVien*tail;
};
struct listSinhVien Q;
void KhoiTao(listSinhVien &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}
nodeSinhVien * get_nodeSinhVien(SinhVien x)
{
    nodeSinhVien*p;
    p = (nodeSinhVien*) calloc (1,sizeof(nodeSinhVien));
    if (p == NULL)
    {
        cout << "\n Khong du bo nho";
        exit(1);
    }
    p ->info = x;
    p ->next = NULL;
    return p;
}
void ChenDau(listSinhVien &Q, nodeSinhVien *p)
{
    if (Q.head==NULL) {
        Q.head=p;
        Q.tail=Q.head;
    }
    else {
        p->next = Q.head;
        Q.head = p;
    }
}
void Nhap(SinhVien &x)
{
        cout << "\n Masv: "; cin.ignore(); getline(cin,x.MaSV);
        cout << "\n Ten sv: "; getline(cin,x.hoten);
        cout << "\n Lop: "; getline(cin,x.lop);
        cout << "\n DLT: "; cin >> x.DLT;
        cout << "\n DTH: "; cin >> x.DTH;
        cout << "\n DT: "; cin >> x.DT;
        cout << "\n DTB: "; cin >> x.DTB;
}
void Nhapchitiet(listSinhVien &Q)
{
    int n;
    SinhVien x;
    cout << "\n So sinh vien: "; cin >> n;
        for(int i=0;i<n;i++)
        {
            Nhap(x);
            cout << "\n ------------------\n";
            nodeSinhVien *p = new nodeSinhVien;
              p = get_nodeSinhVien(x);
                ChenDau(Q,p);
        }
}
void Xuatchitiet(listSinhVien Q)
{
    nodeSinhVien *p;
    for(nodeSinhVien *p = Q.head;p!=NULL;p=p->next)
    {
        cout<<"\t""\n"<<p -> info.MaSV<<"\t"<<p -> info.hoten<<"\t"<<p -> info.lop<<"\t"<<p -> info.DLT<<"\t"<<p -> info.DTH<<"\t"<<p -> info.DT<<"\t"<<p -> info.DT;
            cout << endl;
    }
}
void Sapxep(listSinhVien &Q)
{
	SinhVien tg;
	nodeSinhVien *min;
	for(nodeSinhVien *i=Q.head;i!=NULL;i=i->next)
     {
		min=i;
		for(nodeSinhVien *j=i-> next;j!=NULL;j=j->next)
			if(j -> info.MaSV < min->info.MaSV) min=j;
        if (min!= i)
        {
            tg=min->info;
		    min->info = i->info;
		    i->info=tg;
		}
     }
}

nodeSinhVien *Timkiem (listSinhVien &Q, SinhVien k , nodeSinhVien *&q)
{
    nodeSinhVien *p;
    q = NULL;
    p = Q.head;
    while ((p != NULL) && (p -> info.MaSV != k.MaSV))
    {
        q = p;
        p = p -> next;
    }
    return p;
}
int XoaKhoaK(listSinhVien &Q, SinhVien k)
{
    nodeSinhVien *p, *q;
    p = Timkiem(Q,k,q);
    if(p == NULL)
        return 0;
    if(q != NULL)
    {
        if(p == Q.tail)
        {
            Q.tail = q;
            q ->next = NULL;
        }
        else
        {
            q ->next = p ->next;
        }
        delete(p);
    }
    else
    {
        Q.head = p -> next ;
        delete (p);
    if (Q.head == NULL)
		Q.tail = NULL;
	}
	return 1;
}
void ChenCuoi(listSinhVien &Q, nodeSinhVien *p)
{
	if ( Q.head == NULL ) {
		Q.head = p;
		Q.tail = Q.head;
	}
	else{
		Q.tail->next = p;
		Q.tail=p;
	}

}
void them(listSinhVien &Q)
{
	nodeSinhVien *p,*q,*r;
	SinhVien x;
	cout<<"\n --Thong tin sinh vien can them--";
		Nhap(x);
	p=get_nodeSinhVien(x);
	if(Q.head->info.MaSV >x.MaSV){
		ChenDau(Q,p);
		Xuatchitiet(Q);
		return;
	}
	if(Q.tail->info.MaSV < x.MaSV){
		ChenCuoi(Q,p);
		Xuatchitiet(Q);
		return;
	}
	r=Q.head;
	q=Q.head->next;
	while(q!=NULL){
		if(q->info.MaSV < x.MaSV){
			r=q;
			q=q->next;
		}
		else{
			r->next = p;
			p->next=q;
			Xuatchitiet(Q);
			return;
		}
	}
}
int main(){
    listSinhVien Q;
    SinhVien k;
    KhoiTao(Q);
    nodeSinhVien *p;
    int chon;
    do {
		cout<<"================MENU===============";
		cout<<"\n 1.Nhap danh sach ";
		cout<<"\n 2.Xuat danh sach ";
		cout<<"\n 3.Xoa sinh vien co khoa k ";
		cout<<"\n 4.Sap xep danh sach theo masv";
		cout<<"\n 5.Them sinh vien";
    	cout<<"\n 0.Dung chuong trinh";
    	cout<<"\n MOI BAN CHON: ";
    	cin>>chon;
		switch(chon){
			case 1:
				Nhapchitiet(Q);
				break;
			case 2:
				cout<<"Danh sach Sinh Vien: ";
				Xuatchitiet(Q);
				break;
            case 3:
				cout<<"\n Nhap khoa K: "; cin >> k.MaSV;
				cout << "\n Danh sach sau khi xoa ma sv:";
				XoaKhoaK(Q,k);
				Xuatchitiet(Q);
				break;
            case 4:
				cout<<"Danh sach sau sap xep: ";
				Sapxep(Q);
				Xuatchitiet(Q);
				break;
            case 5:
				cout<<"Them sinh vien: ";
				them(Q);
				break;
            case 0: exit(0);
			}
	}while (chon!=0);
}
