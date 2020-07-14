#include <iostream>
#include <string>
#include <stack>
#define max 5

using namespace std;

stack <string> token;

struct kandidat{
	string nama;
	string visi;
	string misi;
	string noUrut;
	int suara;
};

// Stack
void stackToken(stack <string> token) {
	while(!token.empty()) {
		cout << " " << token.top();
		token.pop();
	}

	cout << endl;
}

kandidat kdt[100];
int a,b,c,jml,temp;

// *****************************************PROTOTYPE FUNGSI************************************* //
// Menu
void mainMenu();
void mainAdmin();
void login();
// Kandidat
void createKandidat();
void readKandidat();
void updateKandidat();
void deleteKandidat();
// Token
void createToken();
void readToken();
void deleteToken();
void cekToken();
// Voting
void voting();
void doVoting();
// Shorting
void shorting();
// ***************************************END PROTOTYPE FUNGSI*********************************** //


// Main Program
int main(){
	mainMenu();
}



// ********************************************FUNGSI******************************************** //
// Menu Utama
void mainMenu(){
	int plh;
	awal:
	cout << "Evoting #DariRumah" << endl;
	cout << "=================================" << endl;
	cout << "1.Login(admin)"    << endl;
	cout << "2.Voting"		    << endl;
	cout << "3.Lihat Kandidat"  << endl;
	cout << "4.Pentujuk Voting" << endl;
	cout << "=================================" << endl;
	cout << "pilih menu: ";
	cin >> plh;

	enum option {LOGIN = 1, VOTING, LIHAT, PETUNJUK};

		switch(plh) {
			case LOGIN:
				login();
			break;
			case VOTING:
				voting();
			break;
			case LIHAT:
				readKandidat();
			break;
			case PETUNJUK:
				// petunjuk();
			break;
		}
}

// Login
void login() {
	string usr,pass;
	cout << "Login" << endl;
	cout << "====================" << endl;
	cout << "Username: ";
	cin >> usr;
	cout << "Password: ";
	cin >> pass;

		if(usr == "admin" && pass == "admin123"){
			mainAdmin();
		}else {
			cout << "Maaf Anda bukan admin!" << endl;
		}

}

// Halaman Admin
void mainAdmin() {
	stack <string> token;
	int plh;
	char is_continue;
	lanjut:
	cout << "Menu" << endl;
	cout << "=================" << endl;
	cout << "1.Tambah Kandidat" << endl;
	cout << "2.Lihat Kandidat"  << endl;
	cout << "3.Edit Kandidat"   << endl;
	cout << "4.Hapus Kandidat"	<< endl;
	cout << "5.Buat Token"	    << endl;
	cout << "6.Lihat Token"	    << endl;
	cout << "7.Hapus Token"	    << endl;
	cout << "8.Hasil Akhir"	    << endl;
	cout << "9.Logout"	        << endl;
	cout << "Pilih menu :";
	cin >> plh;

	enum option {CREATE = 1, READ, UPDATE, DELETE, TOKEN, rTOKEN, dTOKEN, HASIL, LOGOUT};

		switch(plh) {
			case CREATE:
				createKandidat();
			break;
			case READ:
				readKandidat();
			break;
			case UPDATE:
				updateKandidat();
			break;
			case DELETE:
				deleteKandidat();
			break;
			case TOKEN:
				createToken();
			break;
			case rTOKEN:
				readToken();
			break;
			case dTOKEN:
				deleteToken();
			break;
			case HASIL:
				shorting();
			break;
			case LOGOUT:
				cout << "Anda telah logout" << endl;
				mainMenu();
			break;
		}

	label_continue:
	cout << endl;
	cout << "Lanjutkan?(Y/N) : ";
	cin >> is_continue;

	if (is_continue == 'y' || is_continue == 'Y') {
		goto lanjut;
	}else if (is_continue == 'n' || is_continue == 'N') {
		cout << "Anda telah logout!" << endl;
		mainMenu();
	}else {
		goto label_continue;
	}
}

// Tambah Kandidat
void createKandidat() {

	cout << "Masukan berapa kandidat: ";
	cin >> jml;

	b = 0;
	for(int i = 0; i < jml; i++) {
		b += 1;
		cout << "Masukan kandidat ke-" << b << endl;
		cout << "Nama: ";
		cin >> kdt[a].nama;
		cout << "Visi: ";
		cin >> kdt[a].visi;
		cout << "Misi: ";
		cin >> kdt[a].misi;
		cout << "Nomor urut: ";
		cin >> kdt[a].noUrut;
		a++;
	} 
}

// Lihat Kandidat
void readKandidat() {

	cout << endl;
 	cout << "                                           Kandidat                                      " << endl;
 	cout << "=========================================================================================" << endl;
 	cout << "No \tNama \t\tVisi \t\tMisi \t\t\tNo.Urut \tSuara \t" 	<< endl;
    cout << "=========================================================================================" << endl;
    int j = 0;
	for(int i = 0; i < a; i++) {
		j+=1;
		cout << j << "\t";
		cout << kdt[i].nama 	<< "\t\t";
		cout << kdt[i].visi 	<< "\t\t";
		cout << kdt[i].misi 	<< "\t\t";
		cout << kdt[i].noUrut 	<< "\t\t";
		cout << kdt[i].suara 	<< "\t\t";
		cout << endl;
	}
	cout << "=========================================================================================" << endl;

}

void updateKandidat(){
	int j,k,l;
	readKandidat();
	cout << "Edit Kandidat No: ";
	cin >> k;

	l = k - 1;
	cout << "data yang akan di edit" << endl;
	cout << "=========================================" << endl;
	cout << "Nama 		: " << kdt[l].nama << endl;
	cout << "Visi 		: " << kdt[l].visi << endl;
	cout << "Misi 		: " << kdt[l].misi << endl;
	cout << "No.Urut 	: " << kdt[l].noUrut << endl;
	cout << "=========================================" << endl;
	cout <<  endl;
	cout << "Silahkan edit" << endl;
	cout << "=========================================" << endl;
	cout << "Nama: ";
	cin >> kdt[l].nama;
	cout << "Visi: ";
	cin >> kdt[l].visi;
	cout << "Misi: ";
	cin >> kdt[l].misi;
	cout << "No.Urut: ";
	cin >> kdt[l].noUrut;
}

void deleteKandidat() {
	int w,x,y;
	char z;
	awal:
	readKandidat();
	cout << "Hapus Kandidat No: ";
	cin >> x;

	y = x - 1;
	cout << "data yang akan di edit" << endl;
	cout << "=========================================" << endl;
	cout << "Nama 		: " << kdt[y].nama << endl;
	cout << "Visi 		: " << kdt[y].visi << endl;
	cout << "Misi 		: " << kdt[y].misi << endl;
	cout << "No.Urut 	: " << kdt[y].noUrut << endl;
	cout << "=========================================" << endl;
	cout << "Yakin ingin hapus? (Y/N): ";
	cin >> z;

		yakin:
		if(z == 'y' || z == 'Y') {
			a--;
			for(int i = y; i < a; i++) {
				kdt[i] = kdt[i + 1];
			}
			cout << "Kandidat berhasil dihapus" << endl;
		}else if(z == 'n' || z == 'N') {
			goto awal;
		}else {
			goto yakin;
		}

}

// Buat Token
void createToken() {
    string tkn;
    int jml;
    cout << "Berapa Token: ";
    cin >> jml;
        for(int i = 0; i < jml; i++) {
            cout << "Masukan token ke-" << i + 1 << endl;
            cout << "Token: ";
            cin >> tkn;
            token.push(tkn);
        }

       cout << "Token yang dibuat: ";
       stackToken(token);
}

// Lihat Token
void readToken() {
	cout << "Token dalam stack:" << endl;
	stackToken(token);
}

// Hapus Token
void deleteToken() {
	token.pop();

	cout << "Token dihapus" << endl;
	mainAdmin();

}

// Validasi Token
void cekToken() {
	string tkn;

	cout << "Masukan token: ";
	cin >> tkn;

		if(tkn == token.top()) {
			cout << "Berhasil" << endl;
			token.pop();
			doVoting();
		}else {
			cout << "Token tidak ada" << endl;
		}
		
}

void doVoting() {
	int plh;
	readKandidat();
	cout << "Pilih kandidat: ";
	cin >> plh;
		if(plh == 1) {
			kdt[0].suara++;
		}else if(plh == 2) {
			kdt[1].suara++;
		}else if(plh == 3){
			kdt[2].suara++;
		}else if(plh == 4){
			kdt[3].suara++;
		}else if(plh == 5){
			kdt[4].suara++;
		}else if(plh == 6){
			kdt[5].suara++;
		}else {
			cout << "Salah nomorurut" << endl;
		}

	cout << "Hasil suara" << endl;
	readKandidat();
	mainMenu();
}

void voting() {
	cekToken();
}

void shorting() {
	for(int i = 1; i < a; i++) {
		for(int j = a - 1; j >= i; j--) {
			if(kdt[j].suara < kdt[j-1].suara) {
				temp = kdt[j].suara;
				kdt[j].suara = kdt[j-1].suara;
				kdt[j-1].suara = temp;
			}
		}
	}

	cout << "Hasil Akhir" << endl;
	cout << "========================================" << endl;
	readKandidat();

}




// *****************************************END FUNGSI***************************************** //