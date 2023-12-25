
// chuong trinh sap xep chon truc tiep
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
    int min, i, j, tg;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n;j++)
            if(a[j] < a[min]) min =j;
        if(min != i)
        {
            tg = a[min];
            a[min] = a[i];
            a[i] = tg;
        }
    }
    cout<<"\n Mang sau khi sap xep:";
	for(int i=0;i<n;i++)
		cout<< setw(5) << a[i];
}
int main()
{
    int a[100], n;
    nhap(a,n);
    xuat(a,n);
    sapxep(a, n);
}
