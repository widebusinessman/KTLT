#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include <cstring>
#include <windows.h>
using namespace std;
#define MAX 12345

/*Tạo struct Ngày*/
struct Ngay
{
	int ngay, thang, nam;
};
/*Tạo struct Điểm môn học*/
struct DiemMonHoc
{
	float Diem;
	Ngay NgayVaoDiem;
};
/*Tạo struct Môn học*/
struct MonHoc
{
	char TenMH[50];
	int  SoTietLT;
	int  SoTietTH;
	int  SoLanHoc;
	DiemMonHoc DiemMH[14]; // Gia đình sinh viên có thể học 1 môn tối đa 14 lần 
};
/*Tạo struct Sinh viên*/
struct SINHVIEN
{
	char MaSV[9];
	char TenSV[30];
	char GioiTinh[5];
	Ngay NgaySinh;
	char SoCMND[13];
	char DiaChi[90];
	char Email[40];
	char SoDT[12];
	char NganhHoc[30];
	int  SoMonDaHoc;
	MonHoc Mon[50];
};

struct DanhSachSV
{
	SINHVIEN *sv;
	int n; // Số sinh viên thực sự
	int size; // Kích thước tối đa hiện tại của mảng (Số phần tử được cấp phát trong Heap)
};
void ThemSVvaolist(SINHVIEN X, string line) {
	int d = 0, i = 0;
	string tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.MaSV[0] = 0;
	strcat_s(X.MaSV, (char*)tach.c_str());
	//cout << X.MaSV;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.TenSV[0] = 0;
	strcat_s(X.TenSV, (char*)tach.c_str());
	//cout << X.TenSV;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.GioiTinh[0] = 0;
	strcat_s(X.GioiTinh, (char*)tach.c_str());
	//cout << X.GioiTinh;
	tach = "";
	while (line[i] != '/') {
		tach += line[i];
		i++;
	}
	i++;
	X.NgaySinh.ngay = atoi( tach.c_str());
	//cout << X.NgaySinh.ngay;
	tach = "";
	while (line[i] != '/') {
		tach += line[i];
		i++;
	}
	i++;
	X.NgaySinh.thang = atoi(tach.c_str());
	//cout << X.NgaySinh.thang;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.NgaySinh.nam = atoi(tach.c_str());
	//cout << X.NgaySinh.nam;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.SoCMND[0] = 0;
	strcat_s(X.SoCMND, (char*)tach.c_str());
	//cout << X.SoCMND;
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.DiaChi[0] = 0;
	strcat_s(X.DiaChi, (char*)tach.c_str());
	//cout << X.DiaChi;
	
	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.Email[0] = 0;
	strcat_s(X.Email, (char*)tach.c_str());

	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	strcat_s(X.Email, "@");
	strcat_s(X.Email, (char*)tach.c_str());
	//cout << X.Email;

	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.SoDT[0] = 0;
	strcat_s(X.SoDT, (char*)tach.c_str());
	//cout << X.SoDT;

	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.NganhHoc[0] = 0;
	strcat_s(X.NganhHoc, (char*)tach.c_str());
	//cout << X.NganhHoc;

	tach = "";
	while (line[i] != '@') {
		tach += line[i];
		i++;
	}
	i++;
	X.SoMonDaHoc = atoi( tach.c_str());
	//cout << X.SoMonDaHoc;

	for (int j = 0; j < X.SoMonDaHoc; j++)
	{
		tach = "";
		while (line[i] != '$') {
			tach += line[i];
			i++;
		}
		i++;
		X.Mon[j].TenMH[0] = 0;
		tach = "";
		while (line[i] != '$') {
			tach += line[i];
			i++;
		}
		i++;
		X.Mon[j].SoTietLT = atoi(tach.c_str());
		tach = "";
		while (line[i] != '$') {
			tach += line[i];
			i++;
		}
		i++;
		X.Mon[j].SoTietTH = atoi(tach.c_str());
		tach = "";
		while (line[i] != '$') {
			tach += line[i];
			i++;
		}
		i++;
		X.Mon[j].SoLanHoc = atoi(tach.c_str());
		if (X.Mon[j].SoLanHoc == 1)
		{
			tach = "";
			while (line[i] != '?') {
				tach += line[i];
				i++;
			}
			i++;
			X.Mon[j].DiemMH[0].Diem= atof(tach.c_str());
			tach = "";
			while (line[i] != '/') {
				tach += line[i];
				i++;
			}
			i++;
			X.Mon[j].DiemMH[0].NgayVaoDiem.ngay = atoi(tach.c_str());
			tach = "";
			while (line[i] != '/') {
				tach += line[i];
				i++;
			}
			i++;
			X.Mon[j].DiemMH[0].NgayVaoDiem.thang = atoi(tach.c_str());
			tach = "";
			while (line[i] != '?') {
				tach += line[i];
				i++;
			}
			i++;
			X.Mon[j].DiemMH[0].NgayVaoDiem.nam = atoi(tach.c_str());

		}
		else
		{
			for (int k = 0; k < X.Mon[j].SoLanHoc; k++)
			{
				tach = "";
				while (line[i] != '?') {
					tach += line[i];
					i++;
				}
				i++;
				X.Mon[j].DiemMH[k].Diem = atof(tach.c_str());
				tach = "";
				while (line[i] != '/') {
					tach += line[i];
					i++;
				}
				i++;
				X.Mon[j].DiemMH[k].NgayVaoDiem.ngay = atoi(tach.c_str());
				tach = "";
				while (line[i] != '/') {
					tach += line[i];
					i++;
				}
				i++;
				X.Mon[j].DiemMH[k].NgayVaoDiem.thang = atoi(tach.c_str());
				tach = "";
				while (line[i] != '?') {
					tach += line[i];
					i++;
				}
				i++;
				X.Mon[j].DiemMH[k].NgayVaoDiem.nam = atoi(tach.c_str());
			}
		}

	}
	//cout << X.Mon[2].DiemMH[0].Diem;
	//cout << endl;

}
bool docfile(DanhSachSV listSV, int num) {

	if (num < MAX) listSV.size = MAX;
	else listSV.size = num + 100;
	listSV.sv = new SINHVIEN[listSV.size];
	if (listSV.sv == NULL) return false;
	listSV.n = num;
	ifstream fi("outputIP.txt");
	string line;
	for (int i = 0; i < num; i++)
	{
		getline(fi, line);
		ThemSVvaolist(listSV.sv[i], line);
	}
	//if (fi.is_open()) {
	//	while (getline(fi, line)) {
	//		themsinhvien(listSV, line);
	//	}
	//	fi.close();
	//}
	fi.close();


}
int main(){


	//if (fi.is_open()) {
	//	while (getline(fi, line)) {
	//		themsinhvien(listSV, line);
	//	}
	//	fi.close();
	//}
	DanhSachSV ListSV;
	cout << " Chuong trinh Quan Ly Sinh Vien * Phong Dao Tao * DHKHTN " << endl;
	//if (!TaoNgauNhien(ListSV, 5, 5)) // dung mang dong thi 10000 sv hoac tham chi nhieu hon han van thuong ok
	//	return 0;
	int n;
	cout << "Nhap vao so sinh vien can tao: n = ";
	cin >> n;
	ListSV.sv = new SINHVIEN[n];
	if (docfile(ListSV, n)) {
		/*for (int i = 0; i < n; i++) {
			Xuat(ListSV.sv[i], i + 1);
		}*/
	}
	
	system("pause");
}