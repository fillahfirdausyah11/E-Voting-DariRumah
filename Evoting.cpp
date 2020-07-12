#include <iostream>
#include <string>
#include <stack>
#define max 5

using namespace std;

stack <string> token;

struct kandidat{
	string nama,visi,misi,noUrut;
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
int jml;

// *****************************************PROTOTYPE FUNGSI************************************* //
// Menu
void mainMenu();
void mainAdmin();
void login();
// Kandidat
void createKandidat();
void readKandidat();
// Token
void createToken();
void readToken();
void deleteToken();
void cekToken();
// Voting
void voting();
void doVoting();
// ***************************************END PROTOTYPE FUNGSI*********************************** //


// Main Program
int main(){
	mainMenu();
}



// ********************************************FUNGSI******************************************** //
// Menu Utama
void mainMenu(){
	int plh;
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
	cout << "8.Logout"	        << endl;
	cout << "Pilih menu :";
	cin >> plh;

	enum option {CREATE = 1, READ, UPDATE, DELETE, TOKEN, rTOKEN, dTOKEN, LOGOUT};

		switch(plh) {
			case CREATE:
				createKandidat();
			break;
			case READ:
				readKandidat();
			break;
			case UPDATE:
				//updateKandidat();
			break;
			case DELETE:
				// deleteKandidat();
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

	for(int i = 0; i < jml; i++) {
		cout << "Masukan kandidat ke-" << i + 1 << endl;
		cout << "Nama: ";
		cin >> kdt[i].nama;
		cout << "Visi: ";
		cin >> kdt[i].visi;
		cout << "Misi: ";
		cin >> kdt[i].misi;
		cout << "Nomor urut: ";
		cin >> kdt[i].noUrut;
	} 
}

// Lihat Kandidat
void readKandidat() {

	cout << "Data yang dimasukan" << endl;
	cout << "==========================" << endl;

	for(int i = 0; i < jml; i++) {
		cout << "kandidat ke-" << i + 1 << endl;
		cout << kdt[i].nama << endl;;
		cout << kdt[i].visi << endl;
		cout << kdt[i].misi << endl;
		cout << kdt[i].noUrut << endl;;
		cout << kdt[i].suara << endl;
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




// *****************************************END FUNGSI***************************************** //