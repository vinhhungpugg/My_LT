#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Kho
{
private:
    string makho,tenkho,diachi;
public:
    Kho(): makho(""), tenkho(""), diachi("") {}

    string get_makho(){
        return makho;
    }

    string get_tenkho(){
        return tenkho;
    }
    
    string get_diachi(){
        return diachi;
    }

    void set_makho(string a){
        makho=a;
    }

    void set_tenkho(string a){
        tenkho=a;
    }

    void set_diachi(string a){
        diachi=a;
    }

    void nhap1kho()
    {
        cout<<"Ma kho: "; cin>>makho;
        cout<<"Ten kho: ";
        cin.ignore();
        getline(cin,tenkho);
        cout<<"Dia chi: ";
        getline(cin,diachi);
    }

    void xuat1kho()
    {
        cout<<"#\n";
        cout<<"Ma kho: "<<makho<<'\n';
        cout<<"Ten kho: "<<tenkho<<'\n';
        cout<<"Dia chi: "<<diachi<<'\n';
    }
    
};

void nhapdskho(Kho *&kho, int &n)
{
    cout<<"Nhap so luong kho: "; cin>>n;
    kho=new Kho[n];

    for (int i=0; i<n; i++)
    {
        cout<<"Thong tin kho thu "<<i+1<<" la:\n";
        kho[i].nhap1kho();
    }
}

void xuatdskho(Kho *kho, int n)
{
    for (int i=0; i<n; i++)
        kho[i].xuat1kho();
}

vector<Kho> timkho(Kho *kho, int n)
{
    vector<Kho> dskho_timduoc;
    for (int i=0; i<n; i++)
        if (kho[i].get_tenkho().size()<=8 && kho[i].get_tenkho()[0]=='B')
            dskho_timduoc.push_back(kho[i]);
    return dskho_timduoc;
}

// vector<Kho> timkho_TPHCM(Kho *kho, int n)
// {
//     vector<Kho> dskho;
//     for (int i=0; i<n; i++)
//         if (kho[i].get_diachi()=="TPHCM")
//             dskho.push_back(kho[i]);
//     return dskho;
// }

void kho_TPHCM_file(Kho *kho, int n)
{
    ofstream outfile("DATA_TPHCM.txt");
    for (int i=0; i<n; i++)
        if (kho[i].get_diachi()=="TPHCM")
            {
                outfile<<"#\n";
                outfile<<"Ma kho: "<<kho[i].get_makho()<<'\n';
                outfile<<"Ten kho: "<<kho[i].get_tenkho()<<'\n';
                outfile<<"Dia chi: "<<kho[i].get_diachi()<<'\n';
            }
    outfile.close();
}