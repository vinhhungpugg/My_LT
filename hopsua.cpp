#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct hopsua
{
    string nhan_hieu;
    float tluong;
    int d,m,y;

    void nhap()
    {
        cout<<"Nhan hieu: ";
        cin.ignore();  
        getline(cin, nhan_hieu);
        cout<<"Trong luong: "; cin>>tluong;
        cout<<"Han su dung: "; cin>>d>>m>>y;
    }

    void xuat()
    {
        cout<<"#\n";
        cout<<"Nhan hieu: "<<nhan_hieu<<'\n';
        cout<<"Trong luong: "<<tluong<<'\n';
        cout<<"Han su dung: "<<d<<'/'<<m<<'/'<<y<<'\n';
    }

    bool hsd(hopsua hs)
    {
        if (y != hs.y) return y < hs.y;
        if (m != hs.m) return m < hs.m;
        return d < hs.d;
    }
};

void nhapds(vector<hopsua> &hs, int &n)
{
    ifstream infile("HOPSUA.txt");
    infile>>n;
    hs.resize(n);
    for (int i=0; i<n; i++)
    {
        infile.ignore();
        getline(infile,hs[i].nhan_hieu);
        infile>>hs[i].tluong;
        infile>>hs[i].d>>hs[i].m>>hs[i].y;
    }
}

void xuatds(vector<hopsua> hs, int n)
{
    for (int i=0; i<n; i++)
        hs[i].xuat();
}

int demhs_before2003(vector<hopsua> hs, int n)
{
    int cnt=0;
    for (int i=0; i<n; i++)
        if (hs[i].y<2003)
            cnt++;
    return cnt;
}

void sapxep_hsd(vector<hopsua> &hs, int n)
{
    sort(hs.begin(), hs.begin() + n, [](hopsua &a, hopsua &b) {
        return a.hsd(b);
    });
}

int main()
{
    vector<hopsua> hs;
    int n;
    nhapds(hs,n);
    cout<<"Da nhap thanh cong!!!\n";
    cout<<"===============================\n";
    xuatds(hs,n);
    cout<<"#\n===============================\n";
    cout<<"So luong hop sua truoc 2003 la: "<<demhs_before2003(hs,n)<<'\n';
    cout<<"===============================\n";
    cout<<"Sap xep thong tin hop sua theo hsd\n";
    sapxep_hsd(hs,n);
    xuatds(hs,n);
    return 0;
}
