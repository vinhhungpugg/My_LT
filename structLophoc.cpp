#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct NTN
{
    int dd,mm,yy;
};

struct Lop
{
    char ma_lop[5], ten_lop[9];
    string ten_khoa;
    int sosv;
    NTN ngay_kg;
    int getsosv(){
        return sosv;
    }
    void xuat1Lop() 
    {
	    cout << "=================\n";
	    cout << "Ma lop: " << ma_lop << '\n';
	    cout << "Ten lop: " << ten_lop << '\n';
	    cout << "Ten khoa: " << ten_khoa << '\n';
	    cout << "So sv: " << sosv << '\n';
	    cout << "Ngay khai giang: " << ngay_kg.dd << "/" << ngay_kg.mm << "/" << ngay_kg.yy << '\n';
	    cout << "==================\n";
    }
};

struct DS_Lop
{
    vector<Lop> ds;
};

bool isNamNhuan(int nNam) 
{
	if (nNam % 400 == 0 || (nNam % 4 == 0 && nNam % 100 != 0))
		return true;
	return false;
}

int tinhSoNgay(int nThang, int nNam) 
{
	int soNgay = 0;
	switch (nThang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		soNgay = 31;
		break;
	case 4: case 6: case 9: case 11:
		soNgay = 30;
		break;
	case 2:
		if (isNamNhuan(nNam))
			soNgay = 29;
		else
			soNgay = 28;
		break;
	}
	return soNgay;
}

bool check_ntn(NTN ntn) {
	if (ntn.yy <= 0)
		return false;
	if (ntn.mm <= 0 || ntn.mm > 12)
		return false;
	if (ntn.dd <= 0 || ntn.dd > tinhSoNgay(ntn.mm, ntn.yy))
		return false;
	return true;
}


void doc_file(DS_Lop &ds_lop)
{
    ifstream infile("DSLOP.txt");
    while (!infile.eof())
    {
        Lop lop;
        infile.getline(lop.ma_lop,5,'#');
        infile.getline(lop.ten_lop,9,'#');
        getline(infile,lop.ten_khoa,'#');
        infile>>lop.sosv;       
        infile.ignore(1);
        infile>>lop.ngay_kg.dd;
        infile.ignore(1);
        infile>>lop.ngay_kg.mm;
        infile.ignore(1);
        infile>>lop.ngay_kg.yy;
        infile.ignore(1);
        if (check_ntn(lop.ngay_kg))
            ds_lop.ds.push_back(lop);
        else 
        {
            cout<<"Ngay khong hop le !!!\n";
            break;
        }
    }
    infile.close();
}

void xuat_dslop(const DS_Lop ds_lop)
{
    for (auto x:ds_lop.ds)
        x.xuat1Lop();
}

int sum_sv(const DS_Lop ds_lop, string tenkhoa)
{
    int sum=0;
    for (auto x:ds_lop.ds)
        if (x.ten_khoa.find(tenkhoa) != string::npos)
            sum += x.getsosv();
    return sum; 
}

void xoa_lop(DS_Lop &ds_lop, char *malop)
{
    for (int i=0; i<ds_lop.ds.size(); i++)
        if (strcmp(ds_lop.ds[i].ma_lop,malop) == 0)
        {
            ds_lop.ds.erase(ds_lop.ds.begin()+i);
            break;
        }
}

int main()
{
    DS_Lop ds_lop;
    doc_file(ds_lop);
    xuat_dslop(ds_lop);
    int s=sum_sv(ds_lop,"CNTT");
    cout<<"Tong sinh vien khoa CNTT la: "<<s<<'\n';
    cout<<"Xoa lop CB31\n";
    xoa_lop(ds_lop,(char*) "CB31");
    xuat_dslop(ds_lop);
    return 0;
}

