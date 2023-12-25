
// chuong trinh sap xep chèn truc tiep
#include <bits/stdc++.h>
using namespace std;

void nhap(int a[], int &n)
{
    cout << "Nhap n: "; cin >>n;
    for(int i=0;i<n;i++)
    {
        cout<< "a["<<i<<"] "; cin >>a[i];
    }
}
void xuat(int a[], int n)
{
    cout << "Day so: ";
    for(int i=0;i<n;i++)
        cout << setw(5)<< a[i];
}
void sapxep(int a[], int n)
{
	int pos, i;
	int x;
	for(i=1; i<n; i++)
        {
		x = a[i]; pos = i-1;
		while((pos>=0)&&(a[pos]>x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;//chèn x vào danh sách
	}
	cout<<"\n Mang sau khi sap xep:";
	for(int i=0;i<n;i++)
		cout<< setw(5) << a[i];
}
int main()
{
	int a[100],n;
	nhap(a,n);
	xuat(a,n);
	sapxep(a, n);

}
