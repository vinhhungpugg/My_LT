#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

class Chuyen_bay
{
private:
    string macb,noi_di,noi_den;
    int ngay_bay,tg_bay;
public:
    Chuyen_bay() : ngay_bay(0), tg_bay(0), macb(""), noi_di(""), noi_den("") {}

    string get_mcb(){
        return macb;
    }

    int get_ngay_bay(){
        return ngay_bay;
    }

    void nhap()
    {
        cout<<"Ma chuyen bay: "; cin>>macb;
        cout<<"Ngay bay: "; cin>>ngay_bay;
        cout<<"Gio bay: "; cin>>tg_bay;
        cin.ignore();
        cout<<"Noi di: "; 
        getline(cin,noi_di);
        cout<<"Noi den: "; 
        getline(cin,noi_den);
    }


    void xuat()
    {
        cout<<"Ma chuyen bay: "<<macb<<'\n';
        cout<<"Ngay bay: "<<ngay_bay<<'\n';
        cout<<"Gio bay: "<<tg_bay<<'\n';
        cout<<"Noi di: "<<noi_di<<'\n';
        cout<<"Noi den: "<<noi_den<<'\n';
        cout<<"#\n";
    }
};

void nhapds(Chuyen_bay *&chuyenbay, int &n)
{
    cout<<"Nhap so luong chuyen bay: ";
    cin>>n;

    chuyenbay = new Chuyen_bay[n];

    for (int i=0; i<n; i++)
    {
        cout<<"Nhap thong tin chuyen bay thu "<<i+1<<" la:\n";
        chuyenbay[i].nhap();
    }
}

void xuatds(Chuyen_bay *chuyenbay, int n)
{
    for (int i=0; i<n; i++)
    {
        chuyenbay[i].xuat();
    }
}

int find_date(Chuyen_bay *chuyenbay, int n)
{
    vector<int> dem(32, 0); // Giả định rằng ngày bay trong khoảng từ 1 đến 31
    for (int i = 0; i < n; i++)
    {
        dem[chuyenbay[i].get_ngay_bay()]++;
    }
    int max_count = 0;
    int max_day = -1;
    for (int i = 1; i < dem.size(); i++) // Bắt đầu từ 1 để tránh ngày 0 không hợp lệ
    {
        if (dem[i] > max_count)
        {
            max_count = dem[i];
            max_day = i;
        }
    }
    return max_day;
}

void find_cb(Chuyen_bay *chuyenbay, int n, string &s)
{
    cout<<"Nhap ma chuyen bay ban muon tim kiem: "; cin>>s;
    cout<<"Chueyn bay can tim la:\n";
    for (int i=0; i<n; i++)
        if (s==chuyenbay[i].get_mcb())
            {
                chuyenbay[i].xuat();
                break;
            }
}

int main()
{
    Chuyen_bay *chuyenbay;
    int n;
    string s;
    nhapds(chuyenbay,n);
    cout<<"================================\n";
    cout<<"Thong tin cac chuyen bay !!!\n#\n";
    xuatds(chuyenbay,n);
    cout<<"================================\n";
    cout<<"Ngay co nhieu chuyen bay nhat la ngay: "<<find_date(chuyenbay,n)<<'\n';
    cout<<"================================\n";
    find_cb(chuyenbay,n,s);
    ////////////////
    delete[] chuyenbay;
    return 0;
} 