#include "talentContest.h"
#include <string>

void createListJuri(listJuri &LJ){ // SLL
    first(LJ) = NULL;
};

void createListPeserta(listPeserta &LP){ // SLL
    first(LP) = NULL;
};

void createListRelasi(listRelasi &LR) { // DLL
    first(LR) = NULL;
    last(LR) = NULL;
};

adrJuri cariJuriID(listJuri LJ, string idJuri) { // fungsi mencari juri berdasarkan id dan mengembalikan alamat juri
    adrJuri P = first(LJ);
    while(P!=NULL && info(P).idJuri != idJuri) {
        P = next(P);
    }
    return P;
};

adrPeserta cariPesertaID(listPeserta LP, string idPeserta) { // fungsi mencari peserta berdasarkan id dan mengembalikan alamat peserta
    adrPeserta P = first(LP);
    while(P!=NULL && info(P).idPeserta != idPeserta) {
        P = next(P);
    }
    return P;
};

adrPeserta cariPesertaNama(listPeserta LP, string namaPeserta) { // fungsi mencari peserta berdasarkan nama dan mengembalikan alamat peserta
    adrPeserta P = first(LP);
    while(P!=NULL && info(P).nama != namaPeserta) {
        P = next(P);
    }
    return P;
};

adrJuri firstElementJuri(listJuri LJ){ // fungsi untuk mencari elemen pertama dari juri
    return first(LJ);
};
adrPeserta lastElementPeserta(listPeserta LP){ // fungsi untuk mencari elemen terakhir dari peserta
    adrPeserta P = first(LP);
    while(next(P) != NULL) {
        P = next(P);
    }
    return P;
};

string generateID(string x) { // fungsi untuk generate ID otomatis
    string angka = "";
    int i = 0;

    while(x[i]) {
        if(x[i] >= '0' && x[i] <='9') {
            angka += x[i];
        }
        i++;
    }
    int tambahAngka = stoi(angka) + 1;
    return to_string(tambahAngka);
};

bool cekUsernameJuri(listJuri LJ, string username) { // fungsi mengecek apakah username juri telah digunakan (unique)
    bool ketemu;
    adrJuri P = first(LJ);
    while(P!=NULL && info(P).username != username) {
        P = next(P);
    }

    if(P==NULL){
        ketemu = false;
    } else {
        ketemu = true;
    }

    return ketemu;

};

int countJuri(listJuri LJ) { // fungsi untuk menghitung jumlah juri
    adrJuri P = first(LJ);
    int jumlah = 0;
    while(P != NULL) {
        jumlah++;
        P = next(P);
    }
    return jumlah;
};

int countPeserta(listPeserta LP) { // fungsi untuk menghitung jumlah peserta
    adrPeserta P = first(LP);
    int jumlah = 0;
    while(P != NULL) {
        jumlah++;
        P = next(P);
    }
    return jumlah;
};

infotypeJuri inputDataJuri(listJuri LJ) { // fungsi untuk mengisi infotype elemen juri
    system("cls");

    infotypeJuri dataJuri;

    int jumlahJuri = countJuri(LJ);

    cout<<"=================TAMBAH JURI==============="<<endl;
    cout<<"==========================================="<<endl;

    // Kode program untuk mengisi idJuri secara otomatis
    if(jumlahJuri == 0) {
        dataJuri.idJuri = "J"+to_string(1);
    } else {
        adrJuri juriTerakhir = firstElementJuri(LJ);
        dataJuri.idJuri = "J"+generateID(info(juriTerakhir).idJuri);
    }

    // Kode program untuk memulai input data juri
    cout<<"Nama: ";
    cin>>dataJuri.nama;
    cout<<"Username: ";
    cin>>dataJuri.username;

    // Kode program untuk validasi keunikan dari username
    bool ada = cekUsernameJuri(LJ,dataJuri.username);
    while(ada) {
        cout<<"Maaf username telah digunakan."<<endl;
        cout<<"Username: ";
        cin>>dataJuri.username;
        ada = cekUsernameJuri(LJ,dataJuri.username);
    }

    cout<<"Password: ";
    cin>>dataJuri.password;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;

    return dataJuri;
};

infotypePeserta inputDataPeserta(listPeserta LP) { // fungsi untuk mengisi infotype elemen peserta
    system("cls");

    infotypePeserta dataPeserta;

    int jumlahPeserta = countPeserta(LP);

    cout<<"==============TAMBAH PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;

    // Kode program untuk mengisi idPeserta secara otomatis
    if(jumlahPeserta == 0) {
        dataPeserta.idPeserta = "P"+to_string(1);
    } else {
        adrPeserta pesertaTerakhir = lastElementPeserta(LP);
        dataPeserta.idPeserta = "P"+generateID(info(pesertaTerakhir).idPeserta);
    }

    // Kode program untuk memulai input data peserta
    cout<<"Nama: ";
    cin>>dataPeserta.nama;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;

    return dataPeserta;
};

adrJuri createElementJuri(infotypeJuri x){ // fungsi untuk membuat elemen juri dan mengembalikan alamat baru (SLL)
    adrJuri J = new elmJuri;

    info(J).idJuri = x.idJuri;
    info(J).nama = x.nama;
    info(J).username = x.username;
    info(J).password = x.password;
    next(J) = NULL;

    return J;

};

adrPeserta createElementPeserta(infotypePeserta x){ // fungsi untuk membuat elemen peserta dan mengembalikan alamat baru (SLL)
    adrPeserta P = new elmPeserta;

    info(P).idPeserta = x.idPeserta;
    info(P).nama = x.nama;
    next(P) = NULL;

    return P;

};

adrRelasi createElementRelasi(infotypeRelasi x, adrJuri J, adrPeserta P) { // fungsi untuk membuat elemen relasi dan mengembalikan alamat baru (DLL)
    adrRelasi R = new elmRelasi;

    prev(R) = NULL;
    adrParent(R) = J;
    nilai(R) = x;
    adrChild(R) = P;
    next(R)=NULL;

    return R;
};

void insertFirstJuri(listJuri &LJ, adrJuri J) { // prosedur untuk insertFirst juri
    if(first(LJ)==NULL) {
        first(LJ)=J;
    } else {
        next(J) = first(LJ);
        first(LJ) = J;
    }
};

void insertLastPeserta(listPeserta &LP, adrPeserta P) { // prosedur untuk insertLast peserta
    adrPeserta Q;
    if(first(LP)==NULL) {
        first(LP)=P;
    } else {
        Q = first(LP);
        while(next(Q)!=NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
};


void showJuri(listJuri LJ) { // prosedur untuk menampilkan semua data juri
    int jumlahJuri = countJuri(LJ);
    adrJuri J = first(LJ);
    cout<<"Jumlah juri: "<<jumlahJuri<<endl;
    cout<<"Daftar semua juri: "<<endl;
    while(J!=NULL){
        cout<<info(J).idJuri<<" "<<info(J).nama<<" "<<info(J).username<<" "<<info(J).password<<endl;
        J = next(J);
    }
    cout<<endl;
};

void showPeserta(listPeserta LP) { // prosedur untuk menampilkan semua data peserta
    int jumlahPeserta = countPeserta(LP);
    adrPeserta P = first(LP);
    cout<<"Jumlah Peserta: "<<jumlahPeserta<<endl;
    cout<<"Daftar semua peserta: "<<endl;
    while(P!=NULL) {
        cout<<info(P).idPeserta<<" "<<info(P).nama<<endl;
        P = next(P);
    }
    cout<<endl;
};

void updateJuri(listJuri &LJ){ // prosedur untuk memperbarui data juri berdasarkan id
    system("cls");
    string idJuri;

    // Kode program untuk memulai input id juri
    cout<<"=================PERBARUI JURI==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Juri: ";
    cin>>idJuri;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    // Mencari juri berdasarkan id
    adrJuri J = cariJuriID(LJ,idJuri);
    system("cls");

    if(J==NULL) {
        cout<<"Maaf juri tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data juri gagal diperbarui."<<endl;
        cout<<"==========================================="<<endl;
    } else {
        int inputPerbaruiJuri;

        // Kode program untuk memilih dan memulai input data yang diperbarui dari juri
        cout<<"==========================================="<<endl;
        cout<<"Silahkan pilih data yang ingin diperbarui: "<<endl;
        cout<<"1. Nama"<<endl;
        cout<<"2. Username"<<endl;
        cout<<"3. Password"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan masukkan pilihan anda: ";
        cin>>inputPerbaruiJuri;
        if(inputPerbaruiJuri == 1) {
            string nama;
            cout<<"Nama baru: ";
            cin>>nama;
            info(J).nama = nama;
        } else if(inputPerbaruiJuri == 2) {
            string username;
            cout<<"Username baru: ";
            cin>>username;

            // Kode program untuk validasi keunikan username juri
            bool ada = cekUsernameJuri(LJ,username);
            while(ada) {
                cout<<"Maaf username sudah digunakan."<<endl;
                cout<<"Username baru: ";
                cin>>username;
                ada = cekUsernameJuri(LJ,username);
            }

            info(J).username = username;
        } else if(inputPerbaruiJuri == 3) {
            string password;
            cout<<"Password baru: ";
            cin>>password;
            info(J).password = password;
        }
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"Data juri berhasil diperbarui"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;

};

void updatePeserta(listPeserta &LP){ // prosedur untuk memperbarui data peserta berdasarkan id
    system("cls");
    string idPeserta;

    // Kode program untuk memulai input id peserta
    cout<<"=================PERBARUI PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID PESERTA: ";
    cin>>idPeserta;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    // Mencari peserta berdasarkan id
    adrPeserta P = cariPesertaID(LP,idPeserta);
    system("cls");

    if(P==NULL) {
        cout<<"Maaf peserta tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data peserta gagal diperbarui."<<endl;
        cout<<"==========================================="<<endl;
    } else {

         // Kode program untuk memilih dan memulai input data yang diperbarui dari juri
        int inputPerbaruiPeserta;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan pilih data yang ingin diperbarui: "<<endl;
        cout<<"1. Nama"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan masukkan pilihan anda: ";
        cin>>inputPerbaruiPeserta;
        if(inputPerbaruiPeserta == 1) {
            string nama;
            cout<<"Nama baru: ";
            cin>>nama;
            info(P).nama = nama;
        }
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"     Data peserta berhasil diperbarui"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;

};

void deleteFirstJuri(listJuri &LJ, adrJuri &J) { // prosedur parsial dari deleteRelasi untuk deleteFirst juri (SLL)
    if(first(LJ)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LJ))==NULL) {
        J = first(LJ);
        first(LJ) = NULL;
    } else {
        J = first(LJ);
        first(LJ) = next(J);
        next(J) = NULL;
    }
};

void deleteLastJuri(listJuri &LJ, adrJuri &J) { // prosedur parsial dari deleteRelasi untuk deleteLast juri (SLL)
    adrJuri Q;
     if(first(LJ)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LJ))==NULL) {
        J = first(LJ);
        first(LJ) = NULL;
    } else {
        Q = first(LJ);
        while(next(next(Q))!=NULL) {
            Q = next(Q);
        }
        J = next(Q);
        next(Q) = NULL;
    }
};

void deleteAfterJuri(listJuri &LJ, adrJuri prec, adrJuri &J){ // prosedur parsial dari deleteRelasi untuk deleteAfter juri (SLL)
     if(first(LJ)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LJ))==NULL) {
        J = first(LJ);
        first(LJ) = NULL;
    } else {
        J = next(prec);
        next(prec) = next(J);
        next(J) = NULL;
    }
};

void deleteJuri(listJuri &LJ, adrJuri &J){ // prosedur untuk menghapus data juri (first,last dan after) (SLL)
    system("cls");
    string idJuri;

    // Kode program untuk memasukkan id juri
    cout<<"==================HAPUS JURI==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Juri: ";
    cin>>idJuri;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    // Mencari juri berdasarkan id
    adrJuri Q = cariJuriID(LJ,idJuri);
    system("cls");

    if(Q==NULL) {
        cout<<"Maaf juri tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data juri gagal dihapus."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
    } else {

        // Kode progam untuk menghapus data juri

        if(first(LJ) == Q) {        // Jika data berada pada bagian pertama
            deleteFirstJuri(LJ,J);
        } else if(next(Q)==NULL) {  // Jika data berada pada bagian terakhir
            deleteLastJuri(LJ,J);
        } else {                    // Jika data berada pada bagian tengah
            adrJuri prec = first(LJ);
            while(info(next(prec)).idJuri != info(Q).idJuri) {
                prec = next(prec);
            }
            deleteAfterJuri(LJ,prec,J);
        }
        cout<<"==========================================="<<endl;
        cout<<"Data juri berhasil dihapus."<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};

void deleteFirstPeserta(listPeserta &LP, adrPeserta &P) { // prosedur parsial dari deletePeserta untuk deleteFirst dari peserta
    if(first(LP)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LP))==NULL) {
        P = first(LP);
        first(LP) = NULL;
    } else {
        P = first(LP);
        first(LP)=next(P);
        next(P)=NULL;
    }
};

void deleteLastPeserta(listPeserta &LP, adrPeserta &P) { // prosedur parsial dari deletePeserta untuk deleteLast dari peserta
    adrPeserta R;
     if(first(LP)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LP))==NULL) {
        P = first(LP);
        first(LP) = NULL;
    } else {
        R = first(LP);
        while(next(next(R))!=NULL) {
            R = next(R);
        }
        P = next(R);
        next(R) = NULL;
    }
};

void deleteAfterPeserta(listPeserta &LP, adrPeserta prec, adrPeserta &P){ // prosedur parsial dari deletePeserta untuk deleteAfter dari peserta
     if(first(LP)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(LP))==NULL) {
        P = first(LP);
        first(LP) = NULL;
    } else {
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
    }
};

void deletePeserta(listPeserta &LP, adrPeserta &P){ // prosedur untuk menghapus peserta (first, last dan after) (SLL)
    system("cls");
    string idPeserta;

    // Kode program untuk memasukkan id peserta
    cout<<"==================HAPUS PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Peserta: ";
    cin>>idPeserta;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    // Mencari peserta berdasarkan id
    adrPeserta R = cariPesertaID(LP,idPeserta);
    system("cls");

    if(R==NULL) {
        cout<<"Maaf peserta tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data peserta gagal dihapus."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
    } else {

        // Kode progam untuk menghapus data peserta

        if(first(LP) == R) {             // Jika data berada di bagian pertama
            deleteFirstPeserta(LP,P);
        } else if(next(R)==NULL) {      // Jika data berada di bagian terakhir
            deleteLastPeserta(LP,P);
        } else {                        // Jika data berada di bagian tengah
            adrPeserta prec = first(LP);
            while(info(next(prec)).idPeserta != info(R).idPeserta) {
                prec = next(prec);
            }
            deleteAfterPeserta(LP,prec,P);
        }
        cout<<"==========================================="<<endl;
        cout<<"Data peserta berhasil dihapus."<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};

int menuAplikasiAdmin(){ // fungsi untuk memilih menu di admin dan mengembalikan pilhan admin dalam bentuk integer
    int inputPilihan;
    cout<<"==================MENU ADMIN==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"1. Tambah Data Juri"<<endl;
    cout<<"2. Lihat Data Juri"<<endl;
    cout<<"3. Perbarui Data Juri"<<endl;
    cout<<"4. Hapus Data Juri"<<endl;
    cout<<"5. Tambah Data Peserta"<<endl;
    cout<<"6. Lihat Data Peserta"<<endl;
    cout<<"7. Perbarui Data Peserta"<<endl;
    cout<<"8. Hapus Data Peserta"<<endl;
    cout<<"9. Lihat Nilai Peserta"<<endl;
    cout<<"10.Lihat Penilaian Juri"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan pilihan anda: ";
    cin>>inputPilihan;
    cout<<endl;

    return inputPilihan;
};

int menuUtama() { // fungsi untuk memilih menu utama dan mengembalikan pilhan pengguna dalam bentuk integer
    int inputPengguna;
    cout<<"===============TALENT CONTEST=============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan pilih posisi anda :"<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. Juri"<<endl;
    cout<<"3. Pengunjung"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan input: ";
    cin>>inputPengguna;
    cout<<endl;
    return inputPengguna;
};

bool loginAdmin() { // fungsi untuk autentikasi admin dengan username dan password statis serta mengembalikan nilai dalam bentuk boolean
    string username, password;
    string defaultUsername = "admin";
    string defaultPassword = "@dm1n123";
    cout<<"=================LOGIN ADMIN==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;
    return defaultUsername == username && defaultPassword == password;
};

adrJuri loginJuri(listJuri LJ) { // fungsi untuk autentikasi juri dan mengembalikan nilai dalam bentuk alamat elemen juri
    bool cekPassword;
    string username, password;
    adrJuri P = first(LJ);
    cout<<"=================LOGIN JURI================"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;

    while(P!=NULL && info(P).username != username) {
        P = next(P);
    }
    if(P == NULL) {
        return NULL;
    } else {
        cekPassword = info(P).password == password;
        if(cekPassword) {
            return P;
        } else {
            return NULL;
        }
    }
};

void insertFirstRelasi(listRelasi &LR, adrRelasi R) { // prosedur insertFirst untuk data relasi
    if(first(LR)==NULL) {
        first(LR) = R;
        last(LR) = R;
    } else {
        next(R) = first(LR);
        prev(first(LR))=R;
        first(LR) = R;

    }
};

bool cariJuriPeserta(listRelasi LR, adrJuri J, string namaPeserta) { // fungsi untuk mengecek apakah juri x yang sudah pernah menilai peserta y
    bool ketemu = false;                                             // dan mengembalikan nilai dalam bentuk boolean
    adrRelasi Q = first(LR);
    while(Q != NULL && !ketemu) {
        if (info(adrParent(Q)).nama == info(J).nama && info(adrChild(Q)).nama == namaPeserta) {
            ketemu = true;
        }
        Q = next(Q);
    }
    return ketemu;
};

adrRelasi cariRelasi(listRelasi LR, adrJuri J, string namaPeserta) { // fungsi untuk mencari relasi juri x dan peserta y
    adrRelasi Q = first(LR);                                         // dan mengembalikan nilai dalam bentuk alamat elemen relasi
    while(Q != NULL) {
        if (info(adrParent(Q)).nama == info(J).nama && info(adrChild(Q)).nama == namaPeserta) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
};

void inputPenilaianPeserta(listRelasi &LR, listPeserta P, adrJuri J){ // prosedur untuk memasukkan nilai peserta oleh juri
    string namaPeserta;
    int nilai;

    // Untuk memasukkan nama dan nilai peserta
    cout<<"================NILAI PESERTA=============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan nama peserta: ";
    cin>>namaPeserta;
    cout<<"Silahkian masukkan nilai peserta: ";
    cin>>nilai;

    // Untuk validasi agar juri hanya bisa satu kali saja dalam menilai peserta
    bool R = cariJuriPeserta(LR,J,namaPeserta);

    // Untuk mencari apakah peserta yang akan dinilai oleh juri itu ada
    adrPeserta S = cariPesertaNama(P,namaPeserta);
    system("cls");

    if(R!=NULL) {
        cout<<"       Maaf peserta sudah dinilai."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
    } else {
        if(S==NULL) {
            cout<<"       Maaf peserta tidak ditemukan."<<endl;
            cout<<"==========================================="<<endl;
            cout<<"==========================================="<<endl;
        } else { // Kode program untuk menambahkan nilai dengan juri x dan peserta y
            adrRelasi Q = createElementRelasi(nilai,J,S);
            insertFirstRelasi(LR,Q);
            cout<<"     Nilai peserta berhasil diinputkan."<<endl;
            cout<<"==========================================="<<endl;
            cout<<"==========================================="<<endl;
        }
    }
    cout<<endl;
};

int menuJuri() { // fungsi untuk memasukkan pilihan juri dan mengembalikannya dalam bentuk integer
    int inputJuri;
    cout<<"==================MENU JURI================"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"1. Input nilai"<<endl;
    cout<<"2. Lihat peserta yang sudah dinilai"<<endl;
    cout<<"3. Lihat peserta yang belum dinilai"<<endl;
    cout<<"4. Hapus nilai peserta"<<endl;
    cout<<"5. Ubah nilai peserta"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan menu yang anda pilih: ";
    cin>>inputJuri;
    return inputJuri;
};

void pesertaSudahDinilai(listRelasi LR, adrJuri J) { // prosedur untuk menampilkan peserta yang sudah dinilai oleh juri x
    adrRelasi G = first(LR);
    while(G!=NULL) {
        if(info(adrParent(G)).nama == info(J).nama) {
            cout<<info(adrChild(G)).idPeserta<<" "<<info(adrChild(G)).nama<<" "<<nilai(G)<<endl;
        }
        G = next(G);
    }
    cout<<endl;
};


void pesertaBelumDinilai(listRelasi LR, listPeserta P, adrJuri J){ // prosedur untuk menampilkan peserta yang belum dinilai oleh juri x
    adrRelasi Q = first(LR);
    adrPeserta Z = first(P);
    while(Z!=NULL) {
        bool cek = cariJuriPeserta(LR,J,info(Z).nama);
        if(!cek) {
           cout<<info(Z).idPeserta<<" "<<info(Z).nama<<endl;
        }
        Z=next(Z);
    }
    cout<<endl;
};

void deleteRelasiFirst(listRelasi &LR, adrRelasi &R) { // prosedur parsial untuk deleteRelasi untuk deleteFirst data relasi
    if(first(LR)==NULL) {
        cout<<"Maaf relasi kosong"<<endl;
    } else if (next(first(LR))==NULL) {
        R = first(LR);
        first(LR) = NULL;
        last(LR)  = NULL;
    } else {
        R = first(LR);
        prev(R) = NULL;
        first(LR) = next(R);
        next(R) = NULL;
    }
};

void deleteRelasiLast(listRelasi &LR, adrRelasi &R) { // prosedur parsial untuk deleteRelasi untuk deleteLast data relasi
    if (first(LR) == NULL) {
        cout << "Maaf relasi kosong" << endl;
    } else if (next(first(LR)) == NULL) {
        R = first(LR);
        first(LR) = NULL;
        last(LR)  = NULL;
    } else {
        R = last(LR);
        last(LR) = prev(R);
        next(last(LR)) = NULL;
        prev(R) = NULL;
    }
};

void deleteRelasiAfter(listRelasi &LR, adrRelasi prec, adrRelasi &R) { // prosedur parsial untuk deleteRelasi untuk deleteAfter data relasi
    if(first(LR)==NULL) {
        cout<<"Maaf relasi kosong"<<endl;
    } else if (next(first(LR))==NULL) {
        R = first(LR);
        first(LR) = NULL;
        last(LR)  = NULL;
    } else {
        R = next(prec);
        next(prec) = next(R);
        prev(next(prec)) = prec;
        prev(R) = NULL;
        next(R) = NULL;
    }
};

void deleteRelasi(listRelasi &LR, adrJuri J, adrRelasi &R) { // prosedur untuk menghapus data relasi (first, last dan after) (DLL)
    string namaPeserta;
    // Untuk memasukkan nama peserta
    cout<<"===============HAPUS PENILAIAN============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan nama peserta: ";
    cin>>namaPeserta;

    // Untuk mencari peserta y yang pernah dinilai oleh juri x
    adrRelasi cariRelasiJuriPeserta = cariRelasi(LR,J,namaPeserta);
    system("cls");

    if(cariRelasiJuriPeserta == NULL) {
        cout<<"==========================================="<<endl;
        cout<<"     Maaf peserta belum pernah dinilai"<<endl;
        cout<<"==========================================="<<endl;
    } else {
        // Kode program untuk menghapus data relasi

        if(first(LR)==cariRelasiJuriPeserta) {              // Jika data ditemukan pada bagian pertama
            deleteRelasiFirst(LR,R);
        } else if (next(cariRelasiJuriPeserta) == NULL) {   // Jika data ditemukan pada bagian terakhir
            deleteRelasiLast(LR,R);
        } else {                                            // Jika data ditemukan pada bagian tengah
            adrRelasi prec = first(LR);
            while(next(prec)!=cariRelasiJuriPeserta) {
                prec = next(prec);
            }
            deleteRelasiAfter(LR,prec,R);
        }
        cout<<"==========================================="<<endl;
        cout<<"     Nilai peserta berhasil dihapus"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};

void updateRelasi(listRelasi &LR, adrJuri J) { // prosedur untuk memperbarui data relasi
    system("cls");
    string namaPeserta;

    // Untuk memasukkan nama peserta
    cout<<"=============PERBARUI PENILAIAN============"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan nama peserta: ";
    cin>>namaPeserta;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    // Untuk mencari peserta y yang pernah dinilai oleh juri x
    adrRelasi Q = cariRelasi(LR,J,namaPeserta);

    if(Q==NULL) {
        cout<<"Maaf peserta belum dinilai."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Nilai peserta gagal diperbarui."<<endl;
        cout<<"==========================================="<<endl;
    } else {
        // Untuk memperbarui dan memasukkan nilai baru dari peserta y yang pernah dinilai oleh juri x
        int nilai;
        cout<<"Silahkan masukkan nilai yang baru: ";
        cin>>nilai;
        nilai(Q) = nilai;
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"     Nilai peserta berhasil diperbarui"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};
