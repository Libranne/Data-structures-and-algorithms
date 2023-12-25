#include <bits/stdc++.h>
using namespace std;

typedef struct BenhNhan
{
    int soBN;
    char maBN[10];
	char tenBN[20];
	char gioiTinh[10];
	int namSinh;
	char trieuChung[20];
	char tiensuBenhAn[20];
	char soBHYT[10];
	float PTHuongBHYT;

};

typedef struct nodebn
{
    BenhNhan info;
    nodebn * next;
    nodebn * prev;
};

typedef struct Listbn
{
    nodebn *head;
    nodebn *tail;
};
struct Listbn Qbn;

void khoitaobn(Listbn &Qbn)
{
    Qbn.head = NULL;
    Qbn.tail = NULL;
}

nodebn* get_nodebn(BenhNhan bn)
{
	nodebn *p;
	p = new nodebn;
	if (p==NULL)
    {
        cout<< "khong du bo nho";
        exit(1);
    }
	p->info = bn;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void AddFristbn(Listbn &Qbn, nodebn *p)
{
    if(Qbn.head == NULL)
    {
        Qbn.head = p;
        Qbn.tail = Qbn.head;
    }
    else
    {
        p -> next = Qbn.head;
        Qbn.head -> prev = p;
        Qbn.head = p;
    }
}
void AddLastbn(Listbn &Qbn, nodebn *p)
{
    if (Qbn.head == NULL)
    {
        Qbn.head = p;
        Qbn.tail = Qbn.head;
    }
    else
    {
        Qbn.tail ->next = p;
        p ->prev = Qbn.tail;
        Qbn.tail = p;
    }
}
/*void insertInMiddle(Node* &head, int valueToInsert, int afterValue) {
    // Tìm phần tử có giá trị afterValue trong danh sách
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    // Nếu không tìm thấy phần tử có giá trị afterValue, không thực hiện chèn
    if (current == nullptr) {
        std::cout << "Khong tim thay phan tu co gia tri " << afterValue << " trong danh sach.\n";
        return;
    }

    // Tạo một node mới chứa giá trị cần chèn
    Node* newNode = new Node(valueToInsert);

    // Chèn newNode vào giữa danh sách
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}*/
/*void insertInMiddle(Listbn &Qbn, nodebn *valueToInsert, nodebn *afterValue) {
    // Tìm phần tử có giá trị afterValue trong danh sách
    nodebn* p = Qbn.head;
    while (p != NULL && p->info != afterValue) {
        p = p->next;
    }

    // Nếu không tìm thấy phần tử có giá trị afterValue, không thực hiện chèn
    if (p == nullptr) {
        std::cout << "Khong tim thay phan tu co gia tri " << afterValue << " trong danh sach.\n";
        return;
    }

    // Tạo một node mới chứa giá trị cần chèn
    nodebn* newNode = new Node(valueToInsert);

    // Chèn newNode vào giữa danh sách
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
*/
void AddBefore(Listbn &Qbn, nodebn *q, nodebn *ptumoi)
{
        nodebn *p=q->prev;
        if(q!=NULL)
        {
            ptumoi->next=q;}
            if(p!=NULL)
            {
                ptumoi->prev=p;
                p->next=ptumoi;
                q->prev=ptumoi;
                if(q==Qbn.head) Qbn.head=ptumoi;
            }

}

// 1.NHAP DANH SACH BENH NHAN
void Nhapbn(BenhNhan &bn)
{
        cin.ignore();
        cout << "\n Mabn: "; gets(bn.maBN);
        cout << " Ten bn: "; gets(bn.tenBN);
        cout << " Gioitinh: "; gets(bn.gioiTinh);
        cout << " Nam sinh: "; cin >> bn.namSinh;
        cin.ignore();
        cout << " Trieu chung: ";gets(bn.trieuChung);
        cout << " Tien su benh an: "; gets(bn.tiensuBenhAn);
        cout << " So BHYT: "; cin >> bn.soBHYT;
        cout << " PThuongBHYT: ";cin >> bn.PTHuongBHYT;
}

void Nhapchitietbn (Listbn &Qbn, nodebn *p)
{
    BenhNhan bn;
    cout << "\n Nhap so Benh Nhan: "; cin >> bn.soBN;
    for (int i=0; i<bn.soBN; i++)
    {
        Nhapbn(bn);
            cout << "\n ------------------\n";
            nodebn *p = new nodebn;
              p = get_nodebn(bn);
                AddLastbn(Qbn,p);
    }
}
// 2. XUAT DANH SACH BENH NHAN
void Xuatbn (BenhNhan bn)
{
    cout<<setw(10)<<bn.maBN<<setw(20)<<bn.tenBN<<setw(13)<<bn.gioiTinh<<setw(11)<<bn.namSinh<<setw(16)<<bn.trieuChung<<setw(18)<<bn.tiensuBenhAn<<setw(15)<<bn.soBHYT<<setw(10)<<bn.PTHuongBHYT<<"%"<<endl;
}

void Xuatchitietbn (Listbn &Qbn)
{
    nodebn * p = Qbn.head;
    cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;
     while (p != NULL)
    {
        Xuatbn(p->info);
        p = p -> next;
    }
}
// 3. GHI FILE Benh Nhan
void Ghifilebn(Listbn Qbn)
{
    char Tenfile[20];
    cout<<"\n Luu danh sach benh nhan vao File: ";
    cin.ignore();
    gets(Tenfile);
    FILE *f;
    nodebn *p;
    f = fopen(Tenfile,"wb"); //Ghi nhị phân: nếu đã có thì ghi đè, chưa thì tạo mới và ghi
    int n=0;
    for(p =Qbn.head; p!=NULL; p=p->next )
        n++;
    fwrite(&n, sizeof(int),1,f);
    for(p =Qbn.head; p!=NULL; p=p->next )
         {
             fwrite(&p->info , sizeof(BenhNhan),1,f);
         }
    fclose(f);
    cout<<"\n Luu file "<<Tenfile<<" thanh cong!"<<endl;
}
// 4. DOC FILE BENH NHAN
void Docfilebn(Listbn &Qbn)
{
    char Tenfile[20];
    cout<<"\n Doc File Benh Nhan: ";
    cin.ignore();
    gets(Tenfile);
    FILE *f;
    BenhNhan bn;
    nodebn *p;
    int n;
    f = fopen(Tenfile,"rb"); //đọc file nhị phân
    fread(&n , sizeof(int),1,f);
     cout << "\n\t\t\t\t\t                DANH SACH BENH NHAN "<<endl;
     cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;
     for(int i =0; i<n; i++)
    {
       fread(&bn, sizeof(BenhNhan),1,f);
       p= get_nodebn(bn);
       Xuatbn(p->info);
       AddLastbn(Qbn,p);
    }
    fclose(f);
    cout<<"\n Da doc File "<<Tenfile<<" thanh cong!"<<endl;
}
// 5.THEM BENH NHAN VAO CUOI DANH SACH
void Thembnvaocuoi(Listbn &Qbn)
{
    BenhNhan bn;
    cout << "\n Thong tin benh nhan can them";
    Nhapbn(bn);
    nodebn *p = new nodebn;
              p = get_nodebn(bn);
                AddLastbn(Qbn,p);
}
void Thembnvaosau(Listbn &Qbn)
{
    BenhNhan bn;
     cout << "\n Nhap ma can chen sau:";
     cin.ignore();
      gets(bn.maBN);
    cout << "\n Thong tin benh nhan can them";
    Nhapbn(bn);
    nodebn *p = new nodebn;
    nodebn *q = new nodebn;
    nodebn *ptumoi = new nodebn;
              p = get_nodebn(bn);
               q = get_nodebn(bn);
               ptumoi=get_nodebn(bn);
              AddBefore(Qbn,q,ptumoi);
}
// 6. XOA BENH NHAN O DAU DANH SACH
void RemoveHeadbn(Listbn &Qbn)
{
    nodebn *p;
    if(Qbn.head != NULL)
    {
        p =Qbn.head;
        Qbn.head = Qbn.head -> next;
        Qbn.head -> prev = NULL;
        delete p;
    if (Qbn.head == NULL)  Qbn.tail == NULL;
    }
    Xuatchitietbn(Qbn);
}
// 7. TIM KIEM BENH NHAN CO TRIEU CHUNG .....
void TimkiemTrieuchung(Listbn Qbn)
{
    char Trieuchung[20];
    int check = -1;
    nodebn *p;
    p=Qbn.head;
    cout<<"\n Trieu chung can tim: ";
    cin.ignore();
    gets(Trieuchung);
    if(Qbn.head==NULL)
    {
        cout<<"\n Danh sach rong!"<<endl;
    }
    else
    {  cout<<"\n Thong tin trieu chung "<<Trieuchung<<" la:"<<endl;
     cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;

        while(p!=NULL)
        {
            if(strcmp(p->info.trieuChung,Trieuchung)==0)
            {
                        Xuatbn(p->info);
                check=1;
            }
            p=p->next;
        }
    }
    if(check==-1)
        cout<<"\n Khong tim thay benh nhan co trieu chung!"<<endl;
}
// 8. TIM KIEM BENH NHAN CO TEN ....
void TimkiemTenbn(Listbn Qbn)
{
    char Ten[20];
    int check = -1;
    nodebn *p;
    p=Qbn.head;
    cout<<"\n Ten benh nhan can tim: ";
    cin.ignore();
    gets(Ten);
    if(Qbn.head==NULL)
    {
        cout<<"\n Danh sach rong!"<<endl;
    }
    else
    {
        while(p!=NULL)
        {
            if(strcmp(p->info.tenBN,Ten)==0)
            {
                cout<<"\n Thong tin benh nhan ten "<<Ten<<" la:"<<endl;
     cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;
     Xuatbn(p->info);
                check=1;
            }
            p=p->next;
        }
    }
    if(check==-1)
        cout<<"\n Khong tim thay benh nhan co ten!"<<endl;
}
// 9. SAP XEP BENH NHAN THEO HO
void Sapxephobn(Listbn &Qbn)
{
	BenhNhan tg;
	nodebn *min;
    nodebn *p,*q;
	p =Qbn.head;
	while(p != NULL)
    {
		min=p;
		q = p ->next;
		while (q != NULL)
        {
          if(strcmp(q -> info.tenBN, min->info.tenBN)<0) min=q;
          q = q->next;
        }
          if (min!= p)
        {
            tg=min->info;
		    min->info = p->info;
		    p->info=tg;
		}
     p =p->next;
    }
    Xuatchitietbn(Qbn);
}
// 10.Sắp xếp bệnh nhân theo số phần trăm bảo hiểm y tế được hưởng (cao – thấp)
void Sapxepbhyt(Listbn &Qbn)
{
	BenhNhan tg;
	nodebn *max;
    nodebn *p,*q;
	p =Qbn.head;
	while(p != NULL)
    {
		max=p;
		q = p ->next;
		while (q != NULL)
        {
          if(q -> info.PTHuongBHYT > max->info.PTHuongBHYT) max=q;
          q = q->next;
        }
          if (max!= p)
        {
            tg=max->info;
		    max->info = p->info;
		    p->info=tg;
		}
     p =p->next;
    }
    Xuatchitietbn(Qbn);
}
//11.Đếm số lượng bệnh nhân có giới tính nhap vao

void Demgioitinh(Listbn &Qbn)
{
    BenhNhan bn;
    nodebn *p;
    int d = 0;
    int check = -1;
    cin.ignore();
    cout << "\n Nhap gioi tinh can dem: "; gets(bn.gioiTinh);

    p = Qbn.head;
    cout<<"\n Thong tin benh nhan co gioi tinh "<<bn.gioiTinh<<" la:"<<endl;
               cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;

    while(p != NULL)
    {
        if (strcmp(p->info.gioiTinh, bn.gioiTinh) == 0)
        {
                     Xuatbn(p->info);
            d++;
            check =1;
        }
        p = p->next;
    }
    if(check == -1)
    {
        cout << "\n Khong ton tai benh nhan co gioi tinh '"<<bn.gioiTinh<<"' "<<endl;
    }
    cout << "\n So benh nhan '"<<bn.gioiTinh<<"' la: " << d;
}

//12. Thong ke benh nhan > % BHYT
void bnPTBHYT(Listbn &Qbn)
{
    BenhNhan bn;
	nodebn *p;
	 int check = -1;
	cout<<"\nNhap % BHYT muon tim: "; cin>>bn.PTHuongBHYT;
	p = Qbn.head;
	cout<<"\n Benh nhan co BHYT duoc huong cao hon "<<bn.PTHuongBHYT<<" la:"<<endl;
                 cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;

	while (p != NULL)
	{
		if (p -> info.PTHuongBHYT> bn.PTHuongBHYT)
		{
			    Xuatbn(p->info);
			     check =1;
		}
		p = p -> next;
	}
	if(check == -1)
    {
        cout << "\n Khong ton tai benh nhan co PTBHYT > "<<bn.PTHuongBHYT<<" % "<<endl;
    }

}
//13.Thống kê bệnh nhân có tiền sử bệnh án
void Tiensubenhan (Listbn &Qbn)
{
    BenhNhan bn;
	nodebn *p;
	p = Qbn.head;
	cout<<"\nBenh nhan co tien su benh an: \n";
     cout <<"\n"<<setw(10)<< "Ma bn" << setw(16)<< "Ten bn" << setw(18) << "Gioi tinh" << setw(13) << "Nam sinh" << setw(15) << "Trieu chung" << setw(17)<< "Tien su benh an" << setw(13)<< "So BHYT"<<setw(16)<<"PThuongBHYT"<<endl;

	while (p != NULL)
	{
		if (strcmp (p -> info.tiensuBenhAn, "khong") != 0 )
		{
			 Xuatbn(p->info);
		}
		p = p -> next;
	}

}


/*nodebn *Searchnamsinh(Listbn Qbn, int k)
{
    nodebn *p;
    p =Qbn.head;
    while(p != NULL)
        {
            if(p->info.namSinh==k)
            break;
         p = p->next;
        }
    return p;
}*/
nodebn *SearchMabn(Listbn Qbn, char k[10])
{
    nodebn *p;
    p =Qbn.head;
    while(p != NULL)
        {
            if(strcmp(p->info.maBN,k) == 0)
            break;
         p = p->next;
        }
    return p;
}
//14.Sua PThuongBHYT theo ma
void SuaBHYT(Listbn &Qbn, nodebn *p)
{

 char k[10];
    cout<<"\n Nhap ma benh nhan can sua: ";
    cin.ignore();
    cin>>k;
   //gets(bn.maBN);
   p = SearchMabn(Qbn,k);
    if(p==NULL)
    {
        cout << "\n Khong ton tai benh nhan co ma '"<<k<<"'"<<endl;
    }
    else
    {

    p = Qbn.head;
    while(p!=NULL)
    {
         if(strcmp(p->info.maBN,k) == 0)
        {

            cout<<"\n Nhap PThuongBHYT moi: ";
                cin.ignore();
            cin>>(p->info.PTHuongBHYT);
            break;
        }
        p = p->next;
    }
        cout << "\n Thong tin benh nhan sau khi sua: "<<endl;
       Xuatchitietbn(Qbn);
    }
}
//15 them benh nhan vao sau bn co ma x

//16 bn co bhyt x chiem bn %
void PTbn(Listbn &Qbn)
{
    nodebn *p;
    BenhNhan bn;
	int dem1 = 0;
	int dem2 = 0;
	float ketqua;
    int check = -1;
	cout<<"\nNhap % BHYT muon tinh: "; cin>>bn.PTHuongBHYT;
	p = Qbn.head;
	while (p != NULL)
	{
		dem1++;
		if (p -> info.PTHuongBHYT> bn.PTHuongBHYT)
		{
			   dem2++;
			    check =1;
		}
		p = p -> next;
	}
	//cout<<"\nSo luong bn la: "<<dem1<<dem2<<endl;
	ketqua=float(dem2) / float (dem1) *100;
			if(check == -1)
    {
        cout << "\n Khong ton tai benh nhan co PTBHYT > "<<bn.PTHuongBHYT<<" % "<<endl;
    } else
        cout<<"\n So luong benh nhan chiem "<<ketqua<<"%"<<endl;

}

void Menubn(Listbn &Qbn)
{
    khoitaobn(Qbn);
    nodebn *p;
    BenhNhan bn;
    BenhNhan k;
    int chon;
    system("cls");
    do {
		cout<<"\n ==================== MENU BENH NHAN ===================";
		cout<<"\n = 1.Nhap danh sach benh nhan                          =";
		cout<<"\n = 2.Xuat danh sach benh nhan                          =";
		cout<<"\n = 3.Ghi file benh nhan                                =";
		cout<<"\n = 4.Doc file benh nhan                                =";
		cout<<"\n = 5.Them benh nhan vao cuoi danh sach                 =";

		cout<<"\n = 6.Xoa benh nhan o dau danh sach                     =";

		cout<<"\n = 7.Tim kiem benh nhan co trieu chung X               =";
		cout<<"\n = 8.Tim kiem benh nhan co ten X                       =";
		cout<<"\n = 9.Sap xep benh nhan theo ho(a-z)                    =";
		cout<<"\n = 10.Sap xep benh nhan theo so PThuongBHYT            =";
		cout<<"\n = 11.Dem so benh nhan co gioi tinh nhap vao           =";
		cout<<"\n = 12.Thong ke benh nhan co PThuongBHYT cao hon X      =";
		cout<<"\n = 13.Thong ke benh nhan co tien su benh an            =";
		//cout<<"\n = 14. Sua PT huong BHYT theo ma benh nhan             =";
		//cout<<"\n = 15.     =";
        cout<<"\n =======================================================";
        cout<<"\n Chon '0': De thoat chuong trinh quan ly Benh Nhan!"<<endl;
    	do
        {
            cout<<"\n => Ban chon: ";
            cin>>chon;
        }while(chon<0 || chon>20);

		switch(chon){
			case 1:
			    cout<<"\n ----------------------------------------------------------------------------------------------------------";
			    cout << "\n Nhap danh sach benh nhan"<<endl;
				Nhapchitietbn(Qbn,p);
				cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
				break;
			case 2:
			    cout<<"\n ----------------------------------------------------------------------------------------------------------";
				cout<<"\n Danh sach Benh Nhan: "<<endl;
				Xuatchitietbn(Qbn);
				cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
				break;
            case 3:
                Ghifilebn(Qbn);
                break;
            case 4:
                Docfilebn(Qbn);
                break;
            case 5:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                Thembnvaosau(Qbn);
                cout << "\n Danh sach sau them:"<< endl;
                Xuatchitietbn(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 6:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                cout<< "\n Danh sach sau xoa: "<< endl;
                RemoveHeadbn(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
               break;
           case 7:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";

                TimkiemTrieuchung(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 8:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                TimkiemTenbn(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 9:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                cout<<"\n Danh sach benh nhan sau khi sap xep: ";
                Sapxephobn(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 10:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                Sapxepbhyt(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 11:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
               Demgioitinh(Qbn);

                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 12:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                bnPTBHYT(Qbn);
                cout<<"\n -----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 13:
                cout<<"\n ----------------------------------------------------------------------------------------------------------";
                Tiensubenhan(Qbn);
                cout<<"\n ----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            case 14:
                cout<<"\n -----------------------------------------------------------";
                SuaBHYT(Qbn,p);
                cout<<"\n -----------------------------------------------------------"<<endl;
                break;
            case 15:
                cout<<"\n -----------------------------------------------------------";
                Thembnvaosau(Qbn);
                cout<<"\n -----------------------------------------------------------"<<endl;
                break;
            case 16:
                cout<<"\n -----------------------------------------------------------";
                    PTbn(Qbn);
                cout<<"\n -----------------------------------------------------------"<<endl;
                break;
            case 0:
                break;
                 default:
                      break;
			}
	}while (chon!=0);
}

// DANH SACH PHIEU KHAM

typedef struct PhieuKham
{
        int soPK;
        char maPK[10];
        char maBN[10];
        char tenBN[20];
        char gioiTinh[10];
        float PThuongBHYT;
        char ngayKham[11];
        int soPhong;
        char ketQK[30];
        int lePK;
        int tongTK;
};
typedef struct nodepk
{
    PhieuKham info;
    nodepk * next;
    nodepk * prev;
};

typedef struct Listpk
{
    nodepk *head;
    nodepk *tail;
};
struct Listpk Qpk;

void khoitaopk(Listpk &Qpk)
{
    Qpk.head = NULL;
    Qpk.tail = NULL;
}

nodepk* get_nodepk(PhieuKham pk)
{
	nodepk *p;
	p = new nodepk;
	if (p==NULL)
    {
        cout<< "khong du bo nho";
        exit(1);
    }
	p->info = pk;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void AddFristpk(Listpk &Qpk, nodepk *p)
{
    if(Qpk.head == NULL)
    {
        Qpk.head = p;
        Qpk.tail = Qpk.head;
    }
    else
    {
        p -> next = Qpk.head;
        Qpk.head -> prev = p;
        Qpk.head = p;
    }
}
void AddLastpk(Listpk &Qpk, nodepk *p)
{
    if (Qpk.head == NULL)
    {
        Qpk.head = p;
        Qpk.tail = Qpk.head;
    }
    else
    {
        Qpk.tail ->next = p;
        p ->prev = Qpk.tail;
        Qpk.tail = p;
    }
}
nodebn *Searchtenbn(Listbn Qbn, char ten[20])
{
    nodebn *p;
    p =Qbn.head;
    while(p != NULL)
        {
            if(strcmp(p->info.tenBN,ten) == 0)
            break;
         p = p->next;
        }
    return p;
}


nodepk *SearchMapk(Listpk Qpk, char k[10])
{
    nodepk *p;
    p =Qpk.head;
    while(p != NULL)
        {
            if(strcmp(p->info.maPK,k) == 0)
            break;
         p = p->next;
        }
    return p;
}
void Nhappk(PhieuKham &pk)
{
             cin.ignore();
        cout<<"nhap ngay kham (ngay / thang / nam):";gets(pk.ngayKham);
        cout << " So phong kham: "; cin >> pk.soPhong;
            cin.ignore();
        cout << " Ket qua kham: "; gets(pk.ketQK);
        cout << " Le phi kham: "; cin >> pk.lePK;
        pk.tongTK = pk.lePK - pk.lePK * pk.PThuongBHYT * 0.01;
        cout << " Tong tien kham: "; cout<< pk.tongTK;

}

void Nhapchitietpk (Listpk &Qpk, Listbn &Qbn)
{
    PhieuKham pk;
    BenhNhan bn;
    nodebn *q;
    nodepk *p;
    cout << "\n So phieu kham: "; cin >> pk.soPK;
    Docfilebn(Qbn);
    for (int i=0; i<pk.soPK; i++)
    {
        cout << "\n Nhap ma pk: "; cin >> pk.maPK;
        cout << " Nhap ma bn: "; cin >> pk.maBN;
        nodebn *p;
        p = SearchMabn(Qbn,pk.maBN);
        if(p==NULL )
        {
            cout << "\n Khong ton tai benh nhan"<< endl;
        }
        else
        {
            cin.ignore();
            cout<<" Nhap ten bn: ";
			gets(pk.tenBN);
			q = Searchtenbn(Qbn,pk.tenBN);
			if(q==NULL)
            {
                cout << "\n Khong co benh nhan"<< endl;
            }
            else
                {
                    cout<<" Nhap gioi tinh: ";
                    gets(pk.gioiTinh);
                    cout<<" Nhap PThuongBHYT : "; cin>>pk.PThuongBHYT;
                        Nhappk(pk);
                         nodepk *p = new nodepk;
                         p = get_nodepk(pk);
                          AddFristpk(Qpk,p);

                }
        }
    }
}
void Xuatpk(PhieuKham pk)
{
     cout <<"\n"<<setw(8)<< "Ma pk" << setw(10)<< "Ma bn" << setw(20) << "Ten benh nhan" << setw(15) << "Gioi tinh" << setw(15) << "PThuongBHYT" << setw(14)<< "Ngay kham" << setw(19)<< "phong kham"<< setw(17)<<"Ket qua kham" <<setw(15)<<"Le phi kham" <<setw(19)<<"Tong tien kham" <<endl;
     cout<<setw(8)<<pk.maPK<<setw(10)<<pk.maBN<< setw(20)<<pk.tenBN<< setw(15) <<pk.gioiTinh<< setw(13)<<pk.PThuongBHYT<<"%"<<setw(14)<<pk.ngayKham<<setw(16)<<pk.soPhong<<setw(19)<<pk.ketQK<<setw(15)<<pk.lePK<<setw(19)<<pk.tongTK<<endl;
     cout << "\n ----------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void Xuatchitietpk(Listpk Qpk, Listbn Qbn)
{
    nodepk * p;
    if(Qpk.head==NULL)
    {
        cout << "\n Danh sach phieu kham RONG"<< endl;
    }
    else
    {
        p = Qpk.head;
        while (p != NULL)
          {
             Xuatpk(p->info);
             p = p -> next;
          }
    }
}
//GHI FILE PHIEU KHAM
void Ghifilepk(Listpk Qpk,Listbn Qbn)
{
    char Tenfile[20];
    cout<<"\n Luu danh sach Phieu kham vao File: ";
    cin.ignore();
    gets(Tenfile);
    FILE *f;
    nodepk *p;
    f = fopen(Tenfile,"wb");
    int n =0;
    for(p =Qpk.head ;p!=NULL ; p= p->next )
        n = n+1;
    fwrite(&n , sizeof(int),1,f);
    for(p =Qpk.head ;p!=NULL ; p= p->next )
         {
             fwrite(&p->info , sizeof(PhieuKham),1,f);
         }
    fclose(f);
    cout<<"\n =>Luu file '"<<Tenfile<<"' thanh cong!"<<endl;
}
// 4. DOC FILE PHIEU KHAM
void Docfilepk(Listpk &Qpk, Listbn &Qbn)
{
    char Tenfile[20];
    cout<<"\n Doc File Phieu kham: ";
    cin.ignore();
    gets(Tenfile);
    FILE *f;
    PhieuKham pk;
    nodepk *p;
    int n;
    f = fopen(Tenfile,"rb");
    fread(&n , sizeof(int),1,f);
    cout << "\n\t\t\t\t\t                         DANH SACH PHIEU KHAM "<<endl;
    for(int i =0 ;i<n ;i++)
    {
        fread(&pk, sizeof(PhieuKham),1,f);
        p = get_nodepk(pk);
        Xuatpk(p->info);
        AddLastpk(Qpk,p);
    }
    fclose(f);
    cout<<"\n => Doc file '"<<Tenfile<<"' thanh cong!"<<endl;
}
//5. them phieu kham vao dau danh sach
void Thempkvaodau(Listpk &Qpk, Listbn &Qbn)
{
    PhieuKham pk;
    nodepk *p;
    nodebn *q;
    cout << "\n So Phieu kham can them: "; cin >> pk.soPK;
    Docfilebn(Qbn);
    cout << "\n Nhap thong tin phieu kham can them"<<endl;
    for (int i=0; i<pk.soPK; i++)
    {
        cout << "\n Nhap ma pk: "; cin >> pk.maPK;
        cout << " Nhap ma bn: "; cin >> pk.maBN;
        nodebn *p;
        p = SearchMabn(Qbn,pk.maBN);
        if(p==NULL )
        {
            cout << "\n Khong co benh nhan"<< endl;
        }
        else
        {
            cin.ignore();
            cout<<" Nhap ten bn: ";
			gets(pk.tenBN);
			q = Searchtenbn(Qbn,pk.tenBN);
			if(q==NULL)
            {
                cout << "\n Khong co benh nhan"<< endl;
            }
            else
                {
                    cout<<" Nhap gioi tinh: ";
                    gets(pk.gioiTinh);
                    cout<<" Nhap PThuongBHYT : "; cin>>pk.PThuongBHYT;
                        Nhappk(pk);
                         nodepk *p = new nodepk;
                         p = get_nodepk(pk);
                          AddFristpk(Qpk,p);
                }
        }
    }
}
//6. xoa phieu kham theo ma nhap vao
void RemoveMapk(Listpk &Qpk ,PhieuKham pk)
{
    char k[10];
    nodepk *p;
    cout << "\n So luong phieu kham can xoa: "; cin >> pk.soPK;
    cin.ignore();
    for(int i=0;i<pk.soPK;i++)
    {
    cout << "\n Ma phieu kham can xoa: ";cin>> k;
    p = SearchMapk(Qpk,k); //Tìm kiếm phần tử để xóa
    if ( p == NULL )
      {
         cout<<"\n Khong co ma phieu kham trong danh sach "<< endl;
      }
    else
      {
        if ( ( p == Qpk.head ) && ( p == Qpk.tail) ) // danh sách chỉ có 1 nút
          {
              Qpk.head = NULL;
              Qpk.tail = NULL;
          }
            else if ( p == Qpk.head ) Qpk.head = p->next; // p là nút đầu danh sách
            else if ( p == Qpk.tail ) //p là nút cuối danh sách
                    {
                       p -> prev -> next = NULL;
                       Qpk.tail = p -> prev;
                    }
           else //p là nút giữa
           { p -> prev -> next = p -> next;
             p -> next -> prev = p -> prev;
           }
           delete(p);
      }
   }
}
// 7.TIM KIEM BENH NHAN CO TONG TIEN KHAM MAX
void MaxTongtienkham(Listpk &Qpk)
{
    int Tongtienmax;
    nodepk* p;
    p =Qpk.head;
    Tongtienmax = p->info.tongTK;
    for(p =Qpk.head -> next; p !=NULL; p = p->next)
    {
        if(Tongtienmax < p->info.tongTK)
         Tongtienmax= p->info.tongTK;
    }
    cout<< "\n Phieu kham co benh nhan co tong tien kham cao nhat: "<< Tongtienmax<< endl<<endl;
      for(p=Qpk.head; p!=NULL; p=p->next)
            {
                 if(p->info.tongTK == Tongtienmax)
                 Xuatpk(p->info);
            }
}
// 8. TIM KIEM phieu kham CO ma ....
void Timkiemmapk(Listpk Qpk)
{
    char ma[10];
    int check = -1;
    nodepk *p;
    p=Qpk.head;
    cout<<"\n Ma phieu kham can tim: ";
    cin.ignore();
    gets(ma);
    if(Qpk.head==NULL)
    {
        cout<<"\n Danh sach rong!"<<endl;
    }
    else
    {
        while(p!=NULL)
        {
            if(strcmp(p->info.maPK,ma)==0)
            {
                cout<<"\n Thong tin Phieu kham "<<ma<<" la:"<<endl;
        Xuatpk(p->info);
                check=1;
            }
            p=p->next;
        }
    }
    if(check==-1)
        cout<<"\n Khong tim thay phieu kham!"<<endl;
}
//9.Sap xep phieu kham(benh nhan) theo so phong kham
void sapXepPK (Listpk &Qpk)
{
	PhieuKham temp;
	nodepk *min;
	nodepk *p, *q;
	p = Qpk.head;
	while (p != NULL)
	{
		min=p;
		q = p ->next;
		while (q != NULL)
        {
          if(q -> info.soPhong < min -> info.soPhong) min=q;
          q = q->next;
        }
          if (min!= p)
        {
            temp = min -> info;
		    min -> info = p -> info;
		    p -> info = temp;
		}
        p = p -> next;
	}
	cout<<"\nDanh sach sau khi sap xep: \n";
   Xuatchitietpk(Qpk,Qbn);

}
// 10.Sắp xếp bệnh nhân theo số phần trăm bảo hiểm y tế được hưởng (thap - cao)
void Sapxepbhytpk(Listpk &Qpk)
{
	PhieuKham tg;
	nodepk *min;
    nodepk *p,*q;
	p =Qpk.head;
	while(p != NULL)
    {
		min=p;
		q = p ->next;
		while (q != NULL)
        {
          if(q -> info.PThuongBHYT < min->info.PThuongBHYT) min=q;
          q = q->next;
        }
          if (min!= p)
        {
            tg=min->info;
		    min->info = p->info;
		    p->info=tg;
		}
     p =p->next;
    }
    cout<<"Danh sach sau khi sap xep: \n ";
   Xuatchitietpk(Qpk,Qbn);
}
//11. Tinh tbc tong tien kham phong kham bat ki
void tbcPK (Listpk &Qpk)
{
	nodepk *p;
	int x, dem = 0, tong = 0;
	int tbc;
	p = Qpk.head;
	cout<<"\nNhap phong kham can tinh: "; cin>>x;
	while (p != NULL)
	{
		if (p -> info.soPhong == x)
		{
			tong += p -> info.tongTK;
			dem++;
		}
		p = p -> next;
	}
	tbc = tong/dem;
	cout<<"\nTrung binh cong phong kham so "<<x<<" la: "<<tbc<<endl;
	cout<<"\n-------------------------------------------"<<endl;
}
//12. Tong tien kham benh nhan co gioi tinh bat ki
void Tongtiengioitinh(Listpk &Qpk)
{
    PhieuKham pk;
    nodepk *p;
    int tong = 0;
    int check = -1;
    p = Qpk.head;
    cin.ignore();
    cout << "\n Nhap gioi tinh can tinh tong tien kham: "; gets(pk.gioiTinh);
    while(p != NULL)
    {
        if (strcmp(p->info.gioiTinh, pk.gioiTinh) == 0)
        {
                    tong += p -> info.tongTK;

            check =1;
        }
        p = p->next;
    }
    if(check == -1)
    {
        cout << "\n Khong ton tai benh nhan co gioi tinh '"<<pk.gioiTinh<<"' "<<endl;
    }else
    cout << "\n Tong tien kham benh nhan co gioi tinh '"<<pk.gioiTinh<<"' la: " << tong;
}
//13.Tong tien kham cac benh nhan co ngay kham X o phong Y
void tongXY (Listpk &Qpk)
{
	char ngayX [11];
	int phongY;
	int tong1 = 0;
    int check = -1;
	nodepk *p;
	p = Qpk.head;
	cin.ignore();
	cout<<"\nNhap ngay kham can tim: "; gets (ngayX);

	cout<<"\nNhap phong kham can tim: "; cin>>phongY;
	while (p != NULL)
	{
		if (strcmp(p -> info.ngayKham, ngayX) == 0 && p -> info.soPhong == phongY)
		{
			tong1 += p -> info.tongTK;
			 check =1;
		}
		p = p -> next;
	}

	 if(check == -1)
    {
        cout << "\n Khong ton tai benh nhan co kham ngay "<<ngayX<<" so phong "<<phongY<<endl;
    }else
   cout<<"\nTong tien kham cua cac benh nhan kham ngay "<<ngayX<<" co so phong "<<phongY<<" la: "<<tong1<<endl;
}
//14.Dem so luong phieu kham
void dempk (Listpk &Qpk)
{
	nodepk *p;
	int dem = 0;
	p = Qpk.head;
	while (p != NULL)
	{
		dem++;
		p = p -> next;
	}
	cout<<"\nSo luong phieu kham la: "<<dem<<endl;

}

// dem so luong phieu kham > X% BHYT
void dempkbhyt(Listpk &Qpk)
{
    PhieuKham pk;
	nodepk *p;
	int dem = 0;
    int check = -1;
    p = Qpk.head;
	cout<<"\nNhap % BHYT muon dem: "; cin>>pk.PThuongBHYT;

	while (p != NULL)
	{
		if (p -> info.PThuongBHYT> pk.PThuongBHYT)
		{
			   dem++;
			     check =1;
		}
		p = p -> next;
	}
	if(check == -1)
    {
        cout << "\n Khong ton tai phieu kham co PTBHYT > "<<pk.PThuongBHYT<<" % "<<endl;
    } else
        cout<<"\n So phieu kham duoc huong BHYT cao hon "<<pk.PThuongBHYT<<"% la: "<<dem<<endl;
}
//15.Dem so luong benh nhan co le phi kham tren X vnd
void dembntk(Listpk &Qpk)
{
    PhieuKham pk;
	nodepk *p;
	int dem = 0;
    int check = -1;
    p = Qpk.head;
	cout<<"\nNhap dieu kien le phi kham can dem: "; cin>>pk.lePK;

	while (p != NULL)
	{
		if (p -> info.lePK> pk.lePK)
		{
			   dem++;
			     check =1;
		}
		p = p -> next;
	}
	if(check == -1)
    {
        cout << "\n Khong ton tai phieu kham co le phi kham > "<<pk.lePK<<" VND "<<endl;
    } else
        cout<<"\n So phieu kham co le phi cao hon "<<pk.lePK<<"VND la: "<<dem<<endl;
}
//16.Thong ke cac benh nhan co cung phong kham bat ki
void bncungPhong (Listpk &Qpk)
{
	nodepk *p;
	int pkCanTK;
	p = Qpk.head;
    int check = -1;
	cout<<"\nNhap phong kham can thong ke: "; cin>>pkCanTK;
    cout<<"\nDanh sach can tim: \n";
	while (p != NULL)
	{
		if (p -> info.soPhong == pkCanTK)
		{
			Xuatpk(p -> info);
			check = 1;
		}
		p = p -> next;
	}
	if(check == -1)
    {
        cout << "\n Khong ton tai phong kham so "<<pkCanTK<<endl;
    }
}
//17. Tong tien kham benh nhan co phong bat ki
void Tongtiengphong(Listpk &Qpk)
{
    PhieuKham pk;
    nodepk *p;
    int tong = 0;
    int check = -1;
    p = Qpk.head;
    cin.ignore();
    cout << "\n Nhap Phong can tinh tong tien kham: "; cin>>pk.soPhong;
    while(p != NULL)
    {
        if (p->info.soPhong == pk.soPhong)
        {
                    tong += p -> info.tongTK;
                    Xuatpk(p -> info);

            check =1;
        }
        p = p->next;
    }
    if(check == -1)
    {
        cout << "\n Khong ton tai so Phong '"<<pk.soPhong<<"' "<<endl;
    }else
    cout << "\n Tong tien kham  cua cac benh nhan co Phong '"<<pk.soPhong<<"' la: " << tong;
}
//18 Sua ket qua kham theo ma pk
void SuaKQK(Listpk &Qpk, nodepk *p)
{

 char k[10];
    cout<<"\n Nhap ma pk can sua: ";
    cin.ignore();
    cin>>k;
   p = SearchMapk(Qpk,k);
    if(p==NULL)
    {
        cout << "\n Khong ton tai phieu kham co ma '"<<k<<"'"<<endl;
    }
    else
    {

    p = Qpk.head;
    while(p!=NULL)
    {
         if(strcmp(p->info.maPK,k) == 0)// bo strcmp neu khong phai chuoi
        {

            cout<<"\n Nhap ket qua kham moi: ";
            cin.ignore();
           gets(p->info.ketQK);
            break;
        }
        p = p->next;
    }
        cout << "\n Thong tin phieu kham sau khi sua: "<<endl;
      Xuatchitietpk(Qpk,Qbn);
    }
}
void Menupk(Listpk Qpk, Listbn Qbn)
{
    khoitaopk(Qpk);
    nodepk *p;
    nodepk *q;
    nodepk *new_element;
    PhieuKham pk;
    int chon;
    int check = -1;
    system("cls");
    do {
		cout<<"\n ========================== MENU PHIEU KHAM ==========================";
		cout<<"\n = 1.Nhap danh sach phieu kham                                        =";
		cout<<"\n = 2.Xuat danh sach phieu kham                                        =";
		cout<<"\n = 3.Ghi File danh sach phieu kham                                    =";
		cout<<"\n = 4.Doc File danh sach phieu kham                                    =";
		cout<<"\n = 5.Them phieu kham  vao dau danh sach                               =";

		cout<<"\n = 6.Xoa phieu kham theo ma nhap vao                                  =";
		cout<<"\n = 7.Tim kiem benh nhan(phieu kham) co tong tien kham lon nhat        =";
		cout<<"\n = 8.Tim kiem phieu kham co ma bat ki                                 =";
		cout<<"\n = 9.Sap xep benh nhan(phieu kham) theo so phong kham                 =";
		cout<<"\n = 10.Sap xep benh nhan theo PTHuongBHYT (thap-> cao)                 =";
		cout<<"\n = 11.Tinh TBC tong tien kham cua phong kham X                        =";
		cout<<"\n = 12.Tong tien kham cua cac benh nhan co gioi tinh bat ki            =";
		cout<<"\n = 13.Tong tien kham cua cac benh nhan co ngay kham X o phong Y       =";
		cout<<"\n = 14.Dem so luong phieu kham                                         =";
		cout<<"\n = 15.Dem so luong benh nhan(phieu kham) co le phi kham tren X vnd    =";
		cout<<"\n = 16.Thong ke cac benh nhan co cung phong kham bat ki                =";
        cout<<"\n = 17. Tong tien kham cua cac benh nhan co phong X                    =";
		cout<<"\n ======================================================================";
    	cout<<"\n Chon '0': De thoat chuong trinh quan ly PHIEU KHAM!"<<endl;
    	do
        {
            cout<<"\n => Ban chon: ";
            cin>>chon;
        }while(chon<0 || chon>20);

		switch(chon){
			case 1:
			    cout << "\n Nhap danh sach phieu kham"<<endl;
				Nhapchitietpk(Qpk,Qbn);
				break;
            case 2:
                cout << "\n Danh sach phieu kham"<<endl;
                Xuatchitietpk(Qpk,Qbn);
                break;
            case 3:
                Ghifilepk(Qpk,Qbn);
                break;
            case 4:
                Docfilepk(Qpk,Qbn);
                break;
            case 5:
                Thempkvaodau(Qpk,Qbn);
                cout << "\n Danh sach phieu kham sau khi them : "<<endl;
                Xuatchitietpk(Qpk,Qbn);
                break;
            case 6:
                RemoveMapk(Qpk,pk);
                cout << "\n Danh sach phieu kham sau xoa"<<endl;
                Xuatchitietpk(Qpk,Qbn);
                break;
            case 7:
               MaxTongtienkham(Qpk);
                break;
            case 8:
                Timkiemmapk(Qpk);
                break;
            case 9:
               sapXepPK(Qpk);
                break;
            case 10:
                Sapxepbhytpk(Qpk);
                break;
            case 11:
                tbcPK(Qpk);
                break;
           case 12:
              Tongtiengioitinh(Qpk);
                break;
            case 13:
                tongXY(Qpk);
                break;
            case 14:
                dempk(Qpk);
                //dempkbhyt(Qpk);
                break;
            case 15:
                dembntk(Qpk);
                break;
            case 16:
                bncungPhong(Qpk);
                break;
            case 17:
                Tongtiengphong(Qpk);
                break;
            case 18:
             SuaKQK(Qpk,p);
                break;
            case 0:
                break;
                 default:
                      break;
			}
	}while (chon!=0);
}

int main()
{
    int chon;
    do {
        system("cls");
        cout<<"\n\t\t\t\tDanh Sach Lien Ket Doi "<<endl;
        cout<<"\n ================== QUAN LY KHAM BENH TAI PHONG KHAM  ==================";
		cout<<"\n =  1.Danh sach quan ly benh nhan                                      =";
		cout<<"\n =  2.Danh sach quan ly phieu kham                                     =";
    	cout<<"\n =======================================================================";
    	cout<<"\n Chon '0' De ket thuc chuong trinh!" << endl;
        do
        {
        cout<<"\n => Ban chon: "; cin >> chon;
        } while (chon <0 || chon>2);
		switch(chon){
			case 1:
                Menubn(Qbn);
				break;
            case 2:
                Menupk(Qpk, Qbn);
                break;
            case 0:
                cout << "\n CHUONG TRINH QUAN LY KHAM BENH TAI PHONG KHAM KET THUC!!";
                exit(0);
			}
	}while (chon!=0);
}
