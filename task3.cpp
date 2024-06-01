#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>

using namespace std;

// Hàm so sánh 2 số
bool compare(int a, int b) {
    return a < b;
}

// Hàm sinh số ngẫu nhiên
void sinhSoNgauNhien(int* numbers) {
    set<int> nums;
    while (nums.size() < 6) {
        int num = rand() % 45 + 1;
        nums.insert(num);
    }
    copy(nums.begin(), nums.end(), numbers);
    sort(numbers, numbers + 6, compare);
}

void nhapSoThuCong(int* numbers) {
    set<int> nums;
    while (nums.size() < 6) {
        int num;
        cout << "Nhap so thu " << nums.size() + 1 << " (tu 1 den 45, khong trung lap): ";
        cin >> num;
        if (num < 1 || num > 45) {
            cout << "So khong hop le. Vui long nhap lai." << endl;
        }
        else if (nums.find(num) != nums.end()) {
            cout << "So da bi trung. Vui long nhap lai." << endl;
        }
        else {
            nums.insert(num);
        }
    }
    copy(nums.begin(), nums.end(), numbers);
    sort(numbers, numbers + 6, compare);
}

void kiemTraKetQua(int* veSo, int* ketQua) {
    int soTrung = 0;
    for (int i = 0; i < 6; i++) {
        if (find(ketQua, ketQua + 6, veSo[i]) != ketQua + 6) {
            soTrung++;
        }
    }
    cout << "Ban da trung " << soTrung << " so." << endl;
    switch (soTrung) {
    case 6:
        cout << "Xep hang: Hang 1!" << endl;
        break;
    case 5:
        cout << "Xep hang: Hang 2!" << endl;
        break;
    case 4:
        cout << "Xep hang: Hang 3!" << endl;
        break;
    case 3:
        cout << "Xep hang: Hang 4!" << endl;
        break;
    case 2:
        cout << "Xep hang: Hang 5!" << endl;
        break;
    default:
        cout << "Khong trung giai nao." << endl;
        break;
    }
}

static void hienThiKetQua()
{
    srand(static_cast<unsigned int>(time(0)));

    int* veSo = new int[6];
    int* ketQua = new int[6];
    int choice;
    cout << "Chon cach chon so (1 - Tu dong, 2 - Thu cong): ";
    cin >> choice;

    if (choice == 1) {
        sinhSoNgauNhien(veSo);
    }
    else if (choice == 2) {
        nhapSoThuCong(veSo);
    }
    else {
        cout << "Lua chon khong hop le." << endl;
        delete[] veSo;
        delete[] ketQua;
        return;
    }

    cout << "So ve cua ban (theo thu tu tang dan): ";
    for (int i = 0; i < 6; i++) {
        cout << veSo[i] << " ";
    }
    cout << endl;

    sinhSoNgauNhien(ketQua);
    cout << "Ket qua xo so: ";
    for (int i = 0; i < 6; i++) {
        cout << ketQua[i] << " ";
    }
    cout << endl;

    kiemTraKetQua(veSo, ketQua);

    delete[] veSo;
    delete[] ketQua;
}

int main() {
    hienThiKetQua();
    return 0;
}
