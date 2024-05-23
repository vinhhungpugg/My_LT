#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Sinhvien
{
    int mssv;
    string hoten,ma_lop;
    double dtb;
};

struct DSSV
{
    Sinhvien *sv;
    int soluong;
};

void nhapDanhSachSinhVien(DSSV &dssv)
{
    cout<<"Nhap so luong sinh vien: "; cin>>dssv.soluong;

    dssv.sv=new Sinhvien[dssv.soluong];

    for (int i=0; i<dssv.soluong; i++)
    {
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << ":\n";
        cout<<"MSSV: "; cin>>dssv.sv[i].mssv;
        cout<<"Ho va ten: ";
        cin.ignore();
        getline(cin,dssv.sv[i].hoten);
        cout<<"Ma lop: "; cin>>dssv.sv[i].ma_lop;
        cout<<"Diem trung binh: "; cin>>dssv.sv[i].dtb;
    }
}

void xuat_dssv(DSSV &dssv)
{
    cout<< setw(10) << "Ma SV" 
        << setw(20) << "Ho va ten" 
        << setw(10) << "Ma lop" 
        << setw(10) << "Diem TB" 
        << '\n';
    for (int i = 0; i < dssv.soluong; i++) 
    {
        cout<< setw(10) << dssv.sv[i].mssv 
            << setw(20) << dssv.sv[i].hoten 
            << setw(10) << dssv.sv[i].ma_lop 
            << setw(10) << dssv.sv[i].dtb 
            << '\n';
    }
}

void doc_file(DSSV &dssv)
{
    ofstream outfile;
    outfile.open("DANH_SACH_THONG_TIN_SV.txt");
    outfile<<"So luong sinh vien: "<<dssv.soluong<<'\n';
    for (int i = 0; i < dssv.soluong; i++) 
    {
        outfile <<"#\n"
                << "MSSV: "<<dssv.sv[i].mssv<<'\n'
                << "Ho va ten: "<<dssv.sv[i].hoten<<'\n'
                << "Ma lop: "<<dssv.sv[i].ma_lop<<'\n'
                << "Diem trung binh: "<<dssv.sv[i].dtb<<'\n';
    }   
    outfile.close();
}

int dem_ma_lop(DSSV &dssv)
{
    int cnt=0;
    for (int i=0; i<dssv.soluong; i++)
        if (dssv.sv[i].ma_lop=="CS20")
            cnt++;
    return cnt;
}

int dem_dtb(DSSV &dssv)
{
    int dem=0;
    for (int i=0; i<dssv.soluong; i++)
        if (dssv.sv[i].dtb>=8.0)
            dem++;
    return dem;
}

void xoa_sv(DSSV &dssv,int masv)
{
    int vitri=-1;
    for (int i=0; i<dssv.soluong; i++)
        if (masv == dssv.sv[i].mssv)
        {
            vitri=i;
            break;
        }
    if (vitri == -1) 
    {
        cout << "Khong tim thay sinh vien co ma SV " << masv << '\n';
        return;
    }

    DSSV temp;
    temp.soluong=dssv.soluong-1;
    temp.sv=new Sinhvien[temp.soluong];

    for (int i=0,j=0; i<dssv.soluong; i++)
        if (i != vitri)
        {
            temp.sv[j]=dssv.sv[i];
            j++;
        }
    delete[] dssv.sv;
    dssv=temp;
    cout << "Da xoa sinh vien co MSSV: " << masv << '\n';
}

void them_sv(DSSV &dssv)
{
    DSSV temp;
    temp.soluong=dssv.soluong+1;
    temp.sv=new Sinhvien[temp.soluong];

    for (int i = 0; i < dssv.soluong; i++) {
        temp.sv[i] = dssv.sv[i];
    }
    
    cout << "Nhap thong tin cho sinh vien moi:\n";
    cout<<"MSSV: "; cin>>temp.sv[temp.soluong - 1].mssv;
    cout<<"Ho va ten: ";
    cin.ignore();
    getline(cin,temp.sv[temp.soluong - 1].hoten);
    cout<<"Ma lop: "; cin>>temp.sv[temp.soluong - 1].ma_lop;
    cout<<"Diem trung binh: "; cin>>temp.sv[temp.soluong - 1].dtb;

    delete[] dssv.sv;
    dssv=temp;

    cout<<"Da them sinh vien moi !!!\n";
}

void capnhat_info(DSSV &dssv)
{
    int x;
    cout<<"Nhap so thu tu cua sinh vien de cap nhat info: "; cin>>x;

    for (int i=0; i<dssv.soluong; i++)
        if (x == i+1)
        {
            cout<<"MSSV: "; cin>>dssv.sv[i].mssv;
            cout<<"Ho va ten: ";
            cin.ignore();
            getline(cin,dssv.sv[i].hoten);
            cout<<"Ma lop: "; cin>>dssv.sv[i].ma_lop;
            cout<<"Diem trung binh: "; cin>>dssv.sv[i].dtb;
            break;
        }
    cout<<"Da cap nhat thanh cong !!!\n";
}

void sv_hocbong(DSSV &dssv)
{
    DSSV temp;
    temp.soluong=dem_dtb(dssv);
    temp.sv=new Sinhvien[temp.soluong];

    for (int i=0,j=0; i<dssv.soluong; i++)
        if (dssv.sv[i].dtb>=8.0)
        {
            temp.sv[j]=dssv.sv[i];
            j++;
        }

    delete[] dssv.sv;
    dssv=temp;
}

bool cmp(DSSV &dssv, int i, int j)
{
    if (dssv.sv[i].dtb > dssv.sv[j].dtb) return true;
    return false;
}

void sort(DSSV &dssv,bool (*func)(DSSV &dssv,int i,int j))
{
    for (int i=0; i<dssv.soluong-1; i++)
        for (int j=i+1; j<dssv.soluong; j++)
            if (func(dssv,i,j))
                swap(dssv.sv[i],dssv.sv[j]);
}

int main()
{
    DSSV dssv;
    int n;
    do
    {
        cout << "==================== MENU ====================\n";
        cout<<"1. Nhap danh sach sinh vien\n";
        cout<<"2. Xuat ra man hinh DSSV\n";
        cout<<"3. Xuat ra file DSSV\n";
        cout<<"4. Dem sinh vien co ma lop 'CS20'\n";
        cout<<"5. Dem sinh vien co diem TB >= 8.0\n";
        cout<<"6. Sap xep DSSV tang dan theo DTB\n";
        cout<<"7. Xoa sinh vien\n";
        cout<<"8. Them sinh vien\n";
        cout<<"9. Cap nhat info sinh vien\n";
        cout<<"10. Thong tin sinh vien dat hoc bong\n";
        cout<<"0. Thoat chuong trinh !!!\n";
        cout<<"Lua chon cua ban: "; cin>>n;
        system("cls");
        switch (n)
        {
        case 1:
            nhapDanhSachSinhVien(dssv);
            break;
        case 2:
            cout << "Danh sach sinh vien:\n";
            xuat_dssv(dssv);
            break;
        case 3:
            doc_file(dssv);
            cout<<"Da xuat ra file thanh cong !!!\n";
            break;
        case 4:
            cout<<"So luong sinh vien co ma lop 'CS20' la: "<<dem_ma_lop(dssv)<<'\n';
            break;
        case 5:    
            cout<<"So luong sinh vien co diem trung binh >=8.0 la: "<<dem_dtb(dssv)<<'\n';
            break;
        case 6:
            sort(dssv,cmp);
            cout << "Danh sach sinh vien sau khi sap xep theo diem TB giam dan:\n";
            xuat_dssv(dssv);
            break;
        case 7:
            int masv;
            cout<<"Nhap ma so sinh vien can xoa: "; cin>>masv;
            xoa_sv(dssv,masv);
            break;
        case 8:
            them_sv(dssv);
            break;
        case 9:
            capnhat_info(dssv);
            break;
        case 10:
            sv_hocbong(dssv);
            doc_file(dssv);
            cout<<"Da xuat ra file thanh cong !!!\n";
            break;
        case 0:
            cout<<"Ban da thoat chuong trinh !!!\n";
            break;
        default:
            cout<<"Khong hop le !!!\n";
            break;
        }
    } while (n!=0);
    // Đừng quên giải phóng bộ nhớ khi không cần thiết nữa
    delete[] dssv.sv;
    return 0;
}