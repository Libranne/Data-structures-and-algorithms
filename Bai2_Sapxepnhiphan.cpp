
//chuong trinh tim kiem nhi phan
#include <bits/stdc++.h>
using namespace std;
void nhap(int a[], int &n)
{
    cout << "Nhap n: "; cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << " "; cin >> a[i];
    }
}
void xuat(int a[], int n)
{
    cout << "\n Day so: ";
    for(int i=0;i<n;i++)
        cout << setw(5)<< a[i];
}
void sapxep( int a[], int &n)
{
    int tg;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] > a[j])
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }

    cout << "\n Day so sap xep: ";
    for(int i=0;i<n;i++)
        cout << setw(5)<< a[i];
}
int timkiem(int a[], int n, int x)
{
    int left = 0, right = n-1;
    int middle;
    do
    {
        middle = (left + right) /2;
        if(x==a[middle]) break;
        else
            if (x< a[middle]) right = middle-1;
            else  left = middle+1;
    } while(left <= right);
    if(left <= right ) return middle;
    else return -1;
}
int main()
{
    int a[100],n,x;
    nhap(a,n);
    xuat(a,n);
    sapxep(a,n);
    cout << "\n So tim: "; cin >> x;
    int middle = timkiem(a,n,x);
    if(middle == -1) cout << "\n Khong tim thay gia tri "<<x<<"";
    else cout << "\n Tim thay gia tri "<<x<<" tai: " << middle;
}
