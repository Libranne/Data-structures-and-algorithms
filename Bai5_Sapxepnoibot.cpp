
// chuong trinh sap xep noi bot

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
void sapxep(int a[],int n)
{
	int i, j, tg;
	for (i=0; i<n-1; i++)
    {
		for (j=n-1; j>i; j--)
        {
			if(a[j]<a[j-1])
			{
				tg = a[j-1];
                a[j-1] = a[j];
                a[j] = tg;
			}

        }
    }
    cout << "\n Day so sau sap xep: ";
    for(int i=0;i<n;i++)
        cout << setw(5)<< a[i];
}
int main ()
{
    int a[100], n;
    nhap(a,n);
    xuat(a,n);
    sapxep(a,n);

}
