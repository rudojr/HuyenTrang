#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Hàm tính tổng điểm của một học sinh
int tinhTongDiem(int diemGiuaKy, int diemCuoiKy, int diemBaiTap, int diemChuyenCan) {
    return diemGiuaKy + diemCuoiKy + diemBaiTap + diemChuyenCan;
}

// Hàm xác định xếp hạng của học sinh
int xepHang(int diem, int* danhSachDiem, int soHocSinh) {
    int danhSachDiemCopy[5];
    copy(danhSachDiem, danhSachDiem + soHocSinh, danhSachDiemCopy);
    sort(danhSachDiemCopy, danhSachDiemCopy + soHocSinh, greater<int>());
    for (int i = 0; i < soHocSinh; ++i) {
        if (danhSachDiemCopy[i] == diem)
            return i + 1;
    }
    return -1; 
}

int main() {
    const int SO_HOC_SINH = 5;
    int diemGiuaKy[SO_HOC_SINH];
    int diemCuoiKy[SO_HOC_SINH];
    int diemBaiTap[SO_HOC_SINH];
    int diemChuyenCan[SO_HOC_SINH];
    int danhSachDiem[SO_HOC_SINH];

    // Nhập thông tin điểm số của 5 học sinh
    for (int i = 0; i < SO_HOC_SINH; ++i) {
        cout << "Nhap diem cua hoc sinh thu " << i + 1 << ": ";
        cin >> diemGiuaKy[i] >> diemCuoiKy[i] >> diemBaiTap[i] >> diemChuyenCan[i];
        danhSachDiem[i] = tinhTongDiem(diemGiuaKy[i], diemCuoiKy[i], diemBaiTap[i], diemChuyenCan[i]);
    }

    // In thông tin điểm số và xếp hạng của từng học sinh
    cout << "\nThong tin diem va xep hang cua cac hoc sinh:" << endl;
    for (int i = 0; i < SO_HOC_SINH; ++i) {
        int tongDiem = tinhTongDiem(diemGiuaKy[i], diemCuoiKy[i], diemBaiTap[i], diemChuyenCan[i]);
        int xepHangHocSinh = xepHang(danhSachDiem[i], danhSachDiem, SO_HOC_SINH);
        cout << "Hoc sinh thu " << i + 1 << ": " << diemGiuaKy[i] << " " << diemCuoiKy[i] << " " << diemBaiTap[i] << " " << diemChuyenCan[i] << " ==> Tong diem: " << tongDiem << ", Xep hang = " << xepHangHocSinh << endl;
    }
    return 0;
}