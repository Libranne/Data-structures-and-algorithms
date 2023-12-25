
#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    string masv, tensv, lop;
    float diemlt, diemth, diemt, diemtb;

};
struct node
{
    SinhVien info;
    struct node*next;
};
node *sp;
void khoitao()
{
    sp = NULL;
}

int Push (node *&sp)
{
    SinhVien info;
    node *p;
    p = (node*) calloc (1, sizeof (node));
    if (p == NULL) return 0;
    p -> info = info;
    p -> next = sp;
    sp = p;
    return 1;
}
void Nhap(SinhVien &x)
{
        cout << "\n Masv: "; getline(cin.ignore(),x.masv);
        cout << "\n Ten sv: "; getline(cin.ignore(),x.tensv);
        cout << "\n Diem LT: "; cin >> x.diemlt;
        cout << "\n Diem TH: "; cin >> x.diemth;
        cout << "\n Diem Thi: "; cin >> x.diemt;
        cout << "\n Diem TB: "; cin >> x.diemtb;
}

void Nhapchitiet (node *&sp)
{
    node *p;
    int n;
    SinhVien x;
    cout << "\n So sinh vien: "; cin >> n;
    for (int i=0; i<n; i++)
    {
        Nhap(x);
            cout << "\n ------------------\n";
            khoitao();
               Push (sp);
    }
}
int main(){
    node *sp;
    khoitao();
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
				Nhapchitiet(sp);
				break;
			/*case 2:
				cout<<"Danh sach Sinh Vien: ";
				Xuatchitiet(Q);
				break;
           /* case 3:
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
				break;*/
            case 0: exit(0);
			}
	}while (chon!=0);
}
