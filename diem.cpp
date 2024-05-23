#include <iostream>
#include <math.h>

using namespace std;

class Diem
{
private:
    int x,y;
public:
    Diem(): x(0), y(0) {}
    
    int getx(){
        return x;
    }

    int gety(){
        return y;
    }

    void setx(int a){
        x=a;
    }

    void sety(int b){
        y=b;
    }

    void nhap()
    {
        cout<<"Toa do X: "; cin>>x;
        cout<<"Toa do Y: "; cin>>y;
    }

};

float tinh_kc(Diem &diema,Diem &diemb)
{
    float s=sqrt(pow(diema.getx()-diemb.getx(),2) + pow(diema.gety()-diemb.gety(),2));
    return s;
}

void nhap_2d(Diem &diema,Diem &diemb)
{
    cout<<"Diem A:\n";
    diema.nhap();
    cout<<"Diem B:\n";
    diemb.nhap();
}

void nhap_C(Diem &diemi, int &r)
{
    cout<<"Diem I:\n";
    diemi.nhap();
    cout<<"Ban kinh: "; cin>>r;
}

int main()
{
    Diem diema,diemb,diemi,diemo;
    diemo.setx(0);
    diemo.sety(0);
    int r;
    float x;
    for (int i=0; i<2; i++)
    {
        nhap_C(diemi,r);
        x=tinh_kc(diemi,diemo);
        diemo=diemi;
    }

    cout<<x;
    return 0;
}