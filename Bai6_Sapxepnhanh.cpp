// chuong trinh sap xep nhanh
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

void sapxep(int a[], int L, int R)
{
    int i,j,x;
    x=a[(L+R)/2];
    i=L; j=R;
    do
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i<=j)
        {
           int tg = a[i];
			a[i] = a[j];
			a[j] = tg;
            i++; j--;
        }
     } while(i<=j);

    if(L<j) sapxep(a,L,j);
    if(i<R) sapxep(a,i,R);


}

int main()
{
    int a[100],n;
    nhap(a,n);
    xuat(a,n);
    sapxep(a, 0, n-1);
    cout << "\n Day so sau sap xep: ";
    for(int i=0;i<n;i++)
        cout << setw(5)<< a[i];

}
