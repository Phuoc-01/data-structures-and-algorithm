#include <bits/stdc++.h>
using namespace std;

struct SinhVien{
	string maSV;
	string HoTen;
	float diemBT, diemGK, diemCK, diemHP;
};

bool check (SinhVien ds[], int n, string macheck){
	for (int i=0; i<n; i++){
		if (ds[i].maSV == macheck){
			return true;
		}
	}
	return false;
}

void nhap (SinhVien ds[],int &n){
	cout<<"So luong Sinh Vien: ";
	cin>>n;
	cin.ignore();
	for (int i=0; i<n; i++){
		cout<<"Sinh Vien "<<i+1<<endl;
		string ma;
		do{
			cout<<"Ma SV: ";
			getline(cin,ma);
			if (check(ds,i,ma)) cout<<"Nhap lai:"<<endl;
		}while (check(ds,i,ma));
		ds[i].maSV=ma;
		cout<<"Ho Ten: ";
		getline(cin,ds[i].HoTen);
	}
}

void nhapvatinhdiem(SinhVien ds[],int n){
	for (int i=0; i<n; i++){
		cout<<"Nhap diem cho "<<ds[i].HoTen<<endl;
		cout<<"Diem Bai Tap: "; cin>>ds[i].diemBT;
		cout<<"Diem Giua Ki: "; cin>>ds[i].diemGK;
		cout<<"Diem Cuoi ki: "; cin>>ds[i].diemCK;
		cin.ignore(); 
		
		ds[i].diemHP= ds[i].diemBT*0.2 + ds[i].diemGK*0.3 + ds[i].diemCK*0.5;		
	}
}

void sapxep(SinhVien ds[], int n){
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (ds[i].diemHP<ds[j].diemHP){
				swap(ds[i],ds[j]);
			}
		}
	}
}


void in(SinhVien ds[], int n){
	for (int i=0; i<n; i++){
		cout<<i+1<<": "<<ds[i].maSV<<" - "<<ds[i].HoTen<<"	"<<endl;
		cout<<"Diem Bai Tap: "<<ds[i].diemBT<<endl;
		cout<<"Diem giua ki: "<<ds[i].diemGK<<endl;
		cout<<"Diem Cuoi Ki: "<<ds[i].diemCK<<endl;
		cout<<"Diem Hoc Phan: "<<ds[i].diemHP<<endl;
		cout<<endl;
	}
}

void find(SinhVien ds[], int n) {
    string ten;
    cout << "Nhap ten can tim: ";
    getline(cin, ten);
    for (int i = 0; i < ten.length(); i++) {
        ten[i] = tolower(ten[i]);
    }
    for (int i = 0; i < n; i++) {
        string tencheck = ds[i].HoTen;
        for (int k = 0; k < tencheck.length(); k++) {
            tencheck[k] = tolower(tencheck[k]);
        }
        if (tencheck.find(ten) != string::npos) {
            cout << "-----------------------" << endl;
            cout << "Ma Sinh Vien: " << ds[i].maSV << endl;
            cout << "Ho Ten: " << ds[i].HoTen << endl;
            cout << "Diem: " << ds[i].diemHP << endl;
        }
    }
}
int main(){
	SinhVien ds[20];
	int n=0;
	nhap(ds,n);
	nhapvatinhdiem(ds,n);
	sapxep(ds,n);
	in(ds,n);
	find(ds,n);
	return 0;
}