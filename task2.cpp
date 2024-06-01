#include <iostream>
using namespace std;

double tinhDienTichBeMat(double chieuDai, double chieuRong, double chieuCao)
{
	return 2 * (chieuDai * chieuRong + chieuDai * chieuCao + chieuRong * chieuCao);
}

int main()
{
	double chieuDai, chieuRong, chieuCao;

    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
    cout << "Nhap chieu cao: ";
    cin >> chieuCao;

    double dienTich = tinhDienTichBeMat(chieuDai, chieuRong, chieuCao);
    cout << "Dien tich be mat: " << dienTich << endl;
    return 0;
}