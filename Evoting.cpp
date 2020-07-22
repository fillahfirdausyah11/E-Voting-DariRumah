#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <string> token;

//=== struct ===//
struct kandidat{
	string nama;
	string visi;
	string misi;
	string noUrut;
	int suara;
};
//=== end struct ===//

//=== stack ===//
void stackToken(stack <string> token) {
	while(!token.empty()) {
		cout << " " << token.top();
		token.pop();
	}

	cout << endl;
}
//=== end stack ===//

//=== array ===//
kandidat kdt[100];
//=== end array ===//
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
// sorting & searching
void sorting();
void searching();
// ***************************************END PROTOTYPE FUNGSI*********************************** //


// Main Program
int main(){
	// system("cls");
	system("clear");
	mainMenu();
}


// ********************************************FUNGSI******************************************** //
// Menu Utama
void mainMenu(){
	int plh;
	awal:

	cout << " ============================================ "<< endl;
	cout << " |            Evoting #DariRumah            | "<< endl;
	cout << " ============================================ "<< endl;
	cout << " |1.|Login(admin)                           | "<< endl;
	cout << " |2.|Voting                                 | "<< endl;
	cout << " |3.|Lihat Kandidat                         | "<< endl;
	cout << " |4.|Cari Kandidat                          | "<< endl;
	cout << " |5.|Pentujuk Voting                        | "<< endl;
	cout << " ============================================ "<< endl;
	cout << " Pilih menu: ";
	cin >> plh;

	enum option {LOGIN = 1, VOTING, LIHAT, CARI, PETUNJUK};

		switch(plh) {
			case LOGIN:
				login();
			break;
			case VOTING:
				voting();
				cout << endl;
				cout << endl;
				goto awal;
			break;
			case LIHAT:
				readKandidat();
				cout <<  endl;
				cout <<  endl;
				goto awal;
			break;
			case CARI:
			// system("cls");
			system("clear");
				searching();
			break;
			case PETUNJUK:
				 cout << "Manual Guide" << endl;
				 cout << endl;
				 cout << endl;
				 goto awal;
			break;
		}
}

// Login
void login() {
	// system("cls");
	system("clear");
	string usr,pass;
	
	cout << " ==================== " << endl;
	cout << " |      Login       | " << endl;
	cout << " ==================== " << endl;
	cout << " Username: ";
	cin >> usr;
	cout << " Password: ";
	cin >> pass;
	cout << " ==================== " << endl;

		if(usr == "admin" && pass == "admin123"){
			mainAdmin();
		}else {
			cout << " Maaf Anda bukan admin! " << endl;
		}
}

// Halaman Admin
void mainAdmin() {
	// system("cls");
	system("clear");
	stack <string> token;
	int plh;
	char is_continue;
	
	lanjut:

	cout << " ============================================ "<< endl;
	cout << " |                  Menu                    | "<< endl;
	cout << " ============================================ "<< endl;
	cout << " |1.|Tambah Kandidat                        | "<< endl;
	cout << " |2.|Lihat Kandidat                         | "<< endl;
	cout << " |3.|Edit Kandidat                          | "<< endl;
	cout << " |4.|Hapus Kandidat                         | "<< endl;
	cout << " |5.|Buat Token                             | "<< endl;
	cout << " |6.|Lihat Token                            | "<< endl;
	cout << " |7.|Hapus Token                            | "<< endl;
	cout << " |8.|Hasil Akhir                            | "<< endl;
	cout << " |9.|Logout                                 | "<< endl;
	cout << " ============================================ "<< endl;
	cout << " Pilih menu : ";

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
				sorting();
			break;
			case LOGOUT:
			// system("cls");
			system("clear");
				cout << " Anda telah logout " << endl;
				mainMenu();
			break;
		}
	label_continue:
	cout << endl;
	cout << " Lanjutkan?(Y/N) : ";
	cin >> is_continue;
	// system("cls");
	system("clear");
	if (is_continue == 'y' || is_continue == 'Y') {
		goto lanjut;
	}else if (is_continue == 'n' || is_continue == 'N') {
		cout << " Anda telah logout!" << endl;
		mainMenu();
	}else {
		goto label_continue;
	}
}

// Tambah Kandidat
void createKandidat() {
	// system("cls");
	system("clear");
	cout << " Masukan berapa kandidat: ";
	cin >> jml;

	b = 0;
	for(int i = 0; i < jml; i++) {
		b += 1;
		cout << "\n Masukan kandidat ke-" << b << endl;
		cout << " Nama	  : ";
		getline(cin >> ws, kdt[a].nama);
		cout << " Visi	  : ";
		getline(cin >> ws, kdt[a].visi);
		cout << " Misi	  : ";
		getline(cin >> ws, kdt[a].misi);
		cout << " Nomor urut: ";
		getline(cin >> ws, kdt[a].noUrut);
		a++;
	} 
}

// Lihat Kandidat
void readKandidat() {
	// system("cls");
	system("clear");
	cout << endl;
	cout << " ========================================= " << endl;
	cout << " |               Kandidat                 | " << endl;
	cout << " ========================================= " << endl;
	for(int i = 0; i < a; i++) {
		cout << " |Kandidat ke-" << i + 1 << endl;
		cout << " |Nama 		: " << kdt[i].nama <<endl;
		cout << " |Visi 		: " << kdt[i].visi <<endl;
		cout << " |Misi 		: " << kdt[i].misi <<endl;
		cout << " |No.Urut: 	: " << kdt[i].noUrut << endl;
		cout << " |Suara		: " << kdt[i].suara << endl;		
	}
	cout << " ========================================= " << endl;
}

void updateKandidat(){
	// system("cls");
	system("clear");
	int j,k,l;
	readKandidat();
	cout << " Edit Kandidat No: ";
	cin >> k;
	// system("cls");
	system("clear");
	l = k - 1;
	cout << " ========================================= " << endl;
	cout << " |         data yang akan di edit        | " << endl;
	cout << " ========================================= " << endl;
	cout << " |Nama 		: " << kdt[l].nama <<endl;
	cout << " |Visi 		: " << kdt[l].visi <<endl;
	cout << " |Misi 		: " << kdt[l].misi <<endl;
	cout << " |No.Urut 		: " << kdt[l].noUrut << endl;
	cout << " ========================================= " << endl;
	cout <<  endl;
	cout << " Silahkan edit " << endl;
	cout << " ========================================= " << endl;
	cout << " Nama: ";
	getline(cin >> ws, kdt[l].nama);
	cout << " Visi: ";
	getline(cin >> ws, kdt[l].visi);
	cout << " Misi: ";
	getline(cin >> ws, kdt[l].misi);
	cout << " No.Urut: ";
	getline(cin >> ws, kdt[l].noUrut);
}

void deleteKandidat() {

	int w,x,y;
	char z;

	awal:
	readKandidat();
	cout << " Hapus Kandidat No: ";
	cin >> x;

	y = x - 1;
	cout << " Data yang akan dihapus " << endl;
	cout << " ========================================= " << endl;
	cout << " Nama 		: " << kdt[y].nama << endl;
	cout << " Visi 		: " << kdt[y].visi << endl;
	cout << " Misi 		: " << kdt[y].misi << endl;
	cout << " No.Urut 	: " << kdt[y].noUrut << endl;
	cout << " ========================================= " << endl;
	cout << " Yakin ingin hapus? (Y/N): ";
	cin >> z;

		yakin:
		if(z == 'y' || z == 'Y') {
			a--;
			for(int i = y; i < a; i++) {
				kdt[i] = kdt[i + 1];
			}
			cout << " Kandidat berhasil dihapus" << endl;
		}
		else if(z == 'n' || z == 'N') {
			mainAdmin();
		}
		else {
			goto yakin;
		}
}

// Buat Token
void createToken() {
	// system("cls");
	system("clear");
    string tkn;
    int jml;
    cout << " Berapa Token: ";
    cin >> jml;
        for(int i = 0; i < jml; i++) {
            cout << " Masukan token ke-" << i + 1 << endl;
            cout << " Token: ";
            cin >> tkn;
            token.push(tkn);
        }

       cout << " Token yang dibuat: ";
       stackToken(token);
}

// Lihat Token
void readToken() {
	// system("cls");
	system("clear");
	cout << " Token dalam stack: " << endl;
	stackToken(token);
}

// Hapus Token
void deleteToken() {
	// system("cls");
	system("clear");
	token.pop();
	cout << " Token dihapus " << endl;
	mainAdmin();
}

// Validasi Token
void cekToken() {
	// system("cls");
	system("clear");
	string tkn;

	cout << " Masukan token: ";
	cin >> tkn;

		if(tkn == token.top()) {
			cout << " Berhasil " << endl;
			token.pop();
			doVoting();
		}else {
			cout << " Token tidak ada " << endl;
		}
		
}

void doVoting() {
	int plh;
	readKandidat();
	cout << " Pilih kandidat: ";
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
			cout << " Salah nomor urut " << endl;
		}
	// system("cls");
	system("clear");
	cout << "Voting Berhasil" << endl;
	mainMenu();
}

void voting() {
	cekToken();
}

//=== sorting ===//
void sorting() {
	for(int i = 1; i < a; i++) {
		for(int j = a - 1; j >= i; j--) {
			if(kdt[j].suara > kdt[j-1].suara) {
				temp = kdt[j].suara;
				kdt[j].suara = kdt[j-1].suara;
				kdt[j-1].suara = temp;
			}
		}
	}

	cout << " Hasil Akhir " << endl;
	cout << " ========================================" << endl;
	readKandidat();

}
//=== end sorting ===//


//=== searching ===//
void searching() {
	int noUrutKandidat,tmp;
	char z;
	awal:
	cout << " Masukan No.  Urut Kandidat yang dicari: ";
	cin >> noUrutKandidat;
	tmp = noUrutKandidat - 1;
		
		cout << " Hasil Cari " << endl;
		cout << " ========================================== " << endl;
		cout << " Nama 		: " << kdt[tmp].nama << endl;
		cout << " Visi 		: " << kdt[tmp].visi << endl;
		cout << " Misi 		: " << kdt[tmp].misi << endl;
		cout << " No.Urut 	: " << kdt[tmp].noUrut << endl;
		cout << " ========================================= " << endl;
	l:
	cout << "Kembali Ke Menu Utama (Y/N): ";
	cin >> z;
		if(z == 'y' || z == 'Y') {
			// system("cls");
			system("clear");
			mainMenu();
		}else if(z == 'n' || z == 'N') {
			// system("cls");
			system("clear");
			goto awal;
		}else {
			goto l;
		}
	}
//=== end searching ===//

// *****************************************END FUNGSI***************************************** //
