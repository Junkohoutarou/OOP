#include <iostream>
#include <string>
using namespace std;

class HS {
    string ten;
    string MSHS;
    string SDT;
    float DIEM;
public:
    void nhap()
    {
        cout << "Nhap ho va ten: ";
        getline(cin, ten);
        cout << "Nhap ma so hoc sinh: ";
        getline(cin, MSHS);
        cout << "Nhap SDT: ";
        getline(cin, SDT);
        cout << "Nhap Diem: ";
        cin >> DIEM;
    }
    void xuat()
    {
        cout << "\nHo va ten: " << ten;
        cout << endl << "Ma so hoc sinh: " << MSHS;
        cout << endl << "So dien thoai: " << SDT;
        cout << endl << "Diem TB: " << DIEM;
    }

    bool checkname()
    {

        for (int i = 0; i < ten.size(); i++)
        {
            if (ten[i] == ' ') continue;
            else
                if (ten[i] < 65 || ten[i] > 90 && ten[i] < 97 || ten[i] > 122)
                {
                    return false;
                }
        }
        return true;
    }
    void checktt()
    {
        if (ten[ten.size() - 1] == ' ') ten.erase(ten.size() - 1, 1);
        if (MSHS[MSHS.size() - 1] == ' ') MSHS.erase(MSHS.size() - 1, 1);
    }
    bool checksdt()
    {
        int tam = SDT.size() ;
        if (tam >=9&&tam<=11) return true;
        else return false;
    }
    bool checkMSvaDiem()
    {
        int tam = MSHS.size();
        if (tam != 8)
        {
            cout << "\n\t\tMa so hoc sinh khong dung vui long nhap lai!(Ma so hoc sinh gom 8 ki tu)" << endl;
            return false;
        }
        float tam2 = DIEM;
        if (tam2 >= 0 && tam2<= 10)return true;
        else
        {
            cout << "\n\t\tDiem trung binh khong dung vui long nhap lai!" << endl;
            return false;
        }

    }
};

int main()
{
    bool check=true;
    bool ktsdt = true;
    bool kt = true;
    HS a;
    a.nhap();
    a.checktt();
    kt = a.checkname();
    while (kt == false)
    {
        cout << "\n\t\tHo va ten nhap chua dung dinh dang vui long nhap lai !" << endl;
        cin.ignore();
        a.nhap();
        a.checktt();
        kt = a.checkname();
    }
    ktsdt = a.checksdt();
    if (ktsdt == false)
    {
        cout << "\n\t\tSo dien thoai nhap chua dung vui long nhap lai !(So dien thoai dung gom 9 den 11 chu so)" << endl;
        cin.ignore();
        a.nhap();
    }
    check = a.checkMSvaDiem();
    if (check == false)
    {
        cin.ignore();
        a.nhap();
    }
    cout << endl;
    a.xuat();

}
