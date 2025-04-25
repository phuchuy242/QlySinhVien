#include <bits/stdc++.h>
using namespace std;
class HocSinh {
protected:
    string ten;
    int tuoi;
    string mahocsinh;

public:
    HocSinh() {}

    HocSinh(string ten, int tuoi, string mahocsinh)
        : ten(ten), tuoi(tuoi), mahocsinh(mahocsinh) {}

    virtual void nhap() {}
    virtual void xuat() {}
    virtual double DiemTB() { return 0; }
    virtual void ghiVaoFile(ofstream &file) {
        file << mahocsinh << endl;
        file << ten << endl;
        file << tuoi << endl;
    }

    virtual void docTuFile(ifstream &file) {
        getline(file, mahocsinh);
        getline(file, ten);
        file >> tuoi;
        file.ignore();
    }
};

class HocSinhCMU : public HocSinh {
private:
    double CS311;
    double ENG311;
    double XIS311;

public:
    HocSinhCMU() {}

    void nhap() {
        HocSinh::nhap();
        cout << "Nhap ma hoc sinh : ";
        cin.ignore();
        getline(cin, mahocsinh);
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap diem mon CS311 : ";
        cin >> CS311;
        cout << "Nhap diem mon ENG311 : ";
        cin >> ENG311;
        cout << "Nhap diem mon XIS311 : ";
        cin >> XIS311;
    }

    void xuat() {
        cout << "--------------CMU--------------" << endl;
        cout << "Ma hoc sinh : " << mahocsinh << endl;
        cout << "Ten: " << ten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Diem mon CS311 : " << CS311 << endl;
        cout << "Diem mon ENG311 : " << ENG311 << endl;
        cout << "Diem mon XIS311 : " << XIS311 << endl;
    }

    double DiemTB() { return (CS311 + ENG311 + XIS311) / 3; }

    void ghiVaoFile(ofstream &file) {
        file << "1" << endl; 
        HocSinh::ghiVaoFile(file);
        file << CS311 << endl;
        file << ENG311 << endl;
        file << XIS311 << endl;
    }

    void docTuFile(ifstream &file) {
        HocSinh::docTuFile(file);
        file >> CS311;
        file >> ENG311;
        file >> XIS311;
        file.ignore();}
};

class HocSinhPSU : public HocSinh {
private:
    double A201;
    double QA300;
    double QA214;

public:
    HocSinhPSU() {}

    void nhap() {
        HocSinh::nhap();
        cout << "Nhap ma hoc sinh : ";
		cin.ignore();
        getline(cin, mahocsinh);
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap diem mon A201: ";
        cin >> A201;
        cout << "Nhap diem mon QA300: ";
        cin >> QA300;
        cout << "Nhap diem mon QA214: ";
        cin >> QA214;
    }

    void xuat() {
        cout << "--------------PSU--------------" << endl;
        cout << "Ma hoc sinh : " << mahocsinh << endl;
        cout << "Ten: " << ten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Diem mon A201: " << A201 << endl;
        cout << "Diem mon QA300: " << QA300 << endl;
        cout << "Diem mon QA214: " << QA214 << endl;
    }

    double DiemTB() { return (A201 + QA300 + QA214) / 3; }

    void ghiVaoFile(ofstream &file) {
        file << "2" << endl; 
        HocSinh::ghiVaoFile(file);
        file << A201 << endl;
        file << QA300 << endl;
        file << QA214 << endl;
    }

    void docTuFile(ifstream &file) {
        HocSinh::docTuFile(file);
        file >> A201;
        file >> QA300;
        file >> QA214;
        file.ignore();
    }
};

class DanhSachHocSinh {
private:
    HocSinh **danhSachHS;
    int kichThuocMang;
    int soLuongHS;

public:
    DanhSachHocSinh(int kichThuoc = 10) : kichThuocMang(kichThuoc), soLuongHS(0) {
        danhSachHS = new HocSinh *[kichThuocMang];
        for (int i = 0; i < kichThuocMang; ++i) {
            danhSachHS[i] = nullptr;
        }
    }

    ~DanhSachHocSinh() {
        for (int i = 0; i < soLuongHS; ++i) {
            delete danhSachHS[i];
        }
        delete[] danhSachHS;
    }
    void xoaDanhSachHocSinh() {
        for (int i = 0; i < soLuongHS; ++i) {
            delete danhSachHS[i];
        }
        soLuongHS = 0;
    }
    void themHocSinh(HocSinh *hs) {
        if (soLuongHS >= kichThuocMang) {
            kichThuocMang *= 2;
            HocSinh **temp = new HocSinh *[kichThuocMang];
            for (int i = 0; i < soLuongHS; ++i) {
                temp[i] = danhSachHS[i];
            }
            delete[] danhSachHS;
            danhSachHS = temp;
        }
        danhSachHS[soLuongHS++] = hs;
    }
    void xoaHocSinh(int index) {
    if (index < 0 || index >= soLuongHS) {
        cout << "Index khong hop le!" << endl;
        return;
    }
    delete danhSachHS[index];
    for (int i = index; i < soLuongHS - 1; ++i) {
        danhSachHS[i] = danhSachHS[i + 1];
    }
    danhSachHS[soLuongHS - 1] = nullptr;
    soLuongHS--;
}


    void xuatDanhSach() {
        for (int i = 0; i < soLuongHS; ++i) {
            cout << "--------Hoc sinh thu " << i + 1 << "--------" << endl;
            danhSachHS[i]->xuat();
            cout << endl;
        }
    }
    void ghiDanhSachVaoFile(const string &tenFile) {
        ofstream file(tenFile);
        file << soLuongHS << endl;
        for (int i = 0; i < soLuongHS; ++i) {
            danhSachHS[i]->ghiVaoFile(file);
        }
        file.close();
    }
void docDanhSachTuFile(const string &tenFile) {
    ifstream file(tenFile);
	xoaDanhSachHocSinh();
    int soLuong;
    file >> soLuong;
    file.ignore();
    for (int i = 0; i < soLuong; ++i) {
        int loai;
        file >> loai;
        file.ignore();

        HocSinh *hs;
        if (loai == 1) {
            hs = new HocSinhCMU();
        } else if (loai == 2) {
            hs = new HocSinhPSU();
        } else {
            cout << "Loai hoc sinh khong hop le!" << endl;
            continue;
        }

        hs->docTuFile(file);
        themHocSinh(hs);
    }

    file.close();
    xuatDanhSach();
}
};

int main() {
    DanhSachHocSinh danhSachHS;

    int chon;

    do {
        cout << "1. Them hoc sinh" << endl;
        cout << "2. Xoa hoc sinh" << endl;
        cout << "3. Hien thi thong tin hoc sinh" << endl;
        cout << "0. De thoat" << endl;

        cin >> chon;

        switch (chon) {
        case 1: {
        	system("cls");
            cin.ignore();
            int loaiHS;
            cout << "Chon loai hoc sinh (1: CMU, 2: PSU): ";
            cin >> loaiHS;

            HocSinh *hs;
            if (loaiHS == 1) {
                hs = new HocSinhCMU();
            } else if (loaiHS == 2) {
                hs = new HocSinhPSU();
            } else {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
            hs->nhap();
            danhSachHS.themHocSinh(hs);
            danhSachHS.ghiDanhSachVaoFile("data.txt");
            break;
        }
        case 2: {
        	system("cls");
            int viTriXoa;
            cout << "Nhap vi tri cua hoc sinh can xoa: ";
            cin >> viTriXoa;
            danhSachHS.xoaHocSinh(viTriXoa);
            danhSachHS.ghiDanhSachVaoFile("data.txt");
            break;
        }
        case 3: {
        	system("cls");
            danhSachHS.docDanhSachTuFile("data.txt");
            break;
        }
        }
    } while (chon != 0);

    return 0;
}
