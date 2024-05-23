#include "Kho.h"

using namespace std;

int main()
{
    Kho *kho=nullptr;
    int n,c;
    do
    {
        cout<<"1. Nhap danh sach kho\n";
        cout<<"2. Xuat ra danh sach kho\n";
        cout<<"3. Tim kho theo size<=8 va chu dau='B'\n";
        cout<<"4. Tim kho co dia chi o TPHCM xuat ra file\n";
        cout<<"0. Thoat chuong trinh\n";
        cout<<"Lua chon cua ban: "; cin>>c;
        system("cls");
        switch (c)
        {
        case 1:
            nhapdskho(kho,n);
            break;
        case 2:
            cout<<"Thong tin cac kho:\n";
            xuatdskho(kho,n);
            break;
        case 3:
        {
            cout<<"Thon tin cac kho tim duoc la:\n";
            vector<Kho> s=timkho(kho,n);
            for (auto &x:s)
                x.xuat1kho();
            break;
        }
        case 4:
        {
            cout<<"Da xuat ra file\n";
            kho_TPHCM_file(kho,n);
            break;
        }
        case 0:
            cout<<"Ban da thoat chuong trinh\n";
            delete[] kho;
            break;
        
        default:
            cout<<"Khong hop le.Nhap lai!\n";
            break;
        }
    } while (c != 0);
    return 0;
}
