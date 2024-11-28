#include "talentContest.h"
#include <string>

void createListJuri(listJuri &J){
    first(J) = NULL;
};

void createListPeserta(listPeserta &P){
    first(P) = NULL;
};

void createListRelasi(listRelasi &R) {
    first(R) = NULL;
    last(R) = NULL;
};

adrJuri cariJuri(listJuri J, string idJuri) {
    adrJuri P = first(J);
    while(P!=NULL && info(P).idJuri != idJuri) {
        P = next(P);
    }
    return P;
}

adrPeserta cariPeserta(listPeserta P, string idPeserta) {
    adrPeserta Q = first(P);
    while(Q!=NULL && info(Q).idPeserta != idPeserta) {
        Q = next(Q);
    }
    return Q;
}

bool cekUsername(listJuri J, string username) {
    bool ketemu;
    adrJuri P = first(J);
    while(P!=NULL && info(P).username != username) {
        P = next(P);
    }

    if(P==NULL){
        ketemu = false;
    } else {
        ketemu = true;
    }

    return ketemu;

}

int countJuri(listJuri J) {
    adrJuri P = first(J);
    int jumlah = 0;
    while(P!=NULL) {
        jumlah++;
        P = next(P);
    }
    return jumlah;
};

int countPeserta(listPeserta P) {
    adrPeserta Q = first(P);
    int jumlah = 0;
    while(Q!=NULL) {
        jumlah++;
        Q=next(Q);
    }
    return jumlah;
}


infotypeJuri inputDataJuri(listJuri J) {
    system("cls");
    infotypeJuri dataJuri;
    int jumlahJuri = countJuri(J);
    cout<<"=================TAMBAH JURI==============="<<endl;
    cout<<"==========================================="<<endl;
    if(jumlahJuri == 0) {
        dataJuri.idJuri = "J"+to_string(1);
    } else {
        jumlahJuri++;
        dataJuri.idJuri = "J"+to_string(jumlahJuri);
    }
    cout<<"Nama: ";
    cin>>dataJuri.nama;
    cout<<"Username: ";
    cin>>dataJuri.username;
    bool ada = cekUsername(J,dataJuri.username);
    while(ada) {
        cout<<"Maaf username telah digunakan."<<endl;
        cout<<"Username: ";
        cin>>dataJuri.username;
        ada = cekUsername(J,dataJuri.username);
    }
    cout<<"Password: ";
    cin>>dataJuri.password;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;
    return dataJuri;
}

infotypePeserta inputDataPeserta(listPeserta P) {
    system("cls");
    infotypePeserta dataPeserta;
    int jumlahPeserta = countPeserta(P);
    cout<<"==============TAMBAH PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;
    if(jumlahPeserta == 0) {
        dataPeserta.idPeserta = "P"+to_string(1);
    } else {
        jumlahPeserta++;
        dataPeserta.idPeserta = "P"+to_string(jumlahPeserta);
    }
    cout<<"Nama: ";
    cin>>dataPeserta.nama;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;
    return dataPeserta;
}

adrJuri createElementJuri(infotypeJuri x){
    adrJuri J = new elmJuri;
    info(J).idJuri = x.idJuri;
    info(J).nama = x.nama;
    info(J).username = x.username;
    info(J).password = x.password;
    next(J) = NULL;

    return J;

}

adrPeserta createElementPeserta(infotypePeserta x){
    adrPeserta P = new elmPeserta;
    info(P).idPeserta = x.idPeserta;
    info(P).nama = x.nama;
    next(P) = NULL;

    return P;

}

adrRelasi createElementRelasi(infotypeRelasi x,adrJuri J, adrPeserta P) {
    adrRelasi R = new elmRelasi;
    prev(R) = NULL;
    adrParent(R) = J;
    nilai(R) = x;
    adrChild(R) = P;
    next(R)=NULL;

    return R;

}

void insertFirstJuri(listJuri &J, adrJuri P) {
    if(first(J)==NULL) {
        first(J)=P;
    } else {
        next(P) = first(J);
        first(J) = P;
    }
};

void insertLastPeserta(listPeserta &P, adrPeserta Q) {
    adrPeserta R;
    if(first(P)==NULL) {
        first(P)=Q;
    } else {
        R = first(P);
        while(next(R)!=NULL) {
            R = next(R);
        }
        next(R) = Q;
    }
}


void showJuri(listJuri J) {
    int jumlahJuri = countJuri(J);
    adrJuri P = first(J);
    cout<<"Jumlah juri: "<<jumlahJuri<<endl;
    cout<<"Daftar semua juri: "<<endl;
    while(P!=NULL){
        cout<<info(P).idJuri<<" "<<info(P).nama<<" "<<info(P).username<<" "<<info(P).password<<endl;
        P = next(P);
    }
    cout<<endl;
};

void showPeserta(listPeserta P) {
    int jumlahPeserta = countPeserta(P);
    adrPeserta Q = first(P);
    cout<<"Jumlah Peserta: "<<jumlahPeserta<<endl;
    cout<<"Daftar semua peserta: "<<endl;
    while(Q!=NULL) {
        cout<<info(Q).idPeserta<<" "<<info(Q).nama<<endl;
        Q = next(Q);
    }
    cout<<endl;
}

void updateJuri(listJuri &J){
    system("cls");
    string idJuri;
    cout<<"=================PERBARUI JURI==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Juri: ";
    cin>>idJuri;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    adrJuri P = cariJuri(J,idJuri);
    system("cls");
    if(P==NULL) {
        cout<<"Maaf juri tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data juri gagal diperbarui."<<endl;
        cout<<"==========================================="<<endl;
    } else {
        int inputPerbarui;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan pilih data yang ingin diperbarui: "<<endl;
        cout<<"1. Nama"<<endl;
        cout<<"2. Username"<<endl;
        cout<<"3. Password"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan masukkan pilihan anda: ";
        cin>>inputPerbarui;
        if(inputPerbarui == 1) {
            string nama;
            cout<<"Nama baru: ";
            cin>>nama;
            info(P).nama = nama;
        } else if(inputPerbarui == 2) {
            string username;
            cout<<"Username baru: ";
            cin>>username;
            bool ada = cekUsername(J,username);
            while(ada) {
                cout<<"Maaf username sudah digunakan."<<endl;
                cout<<"Username baru: ";
                cin>>username;
                ada = cekUsername(J,username);
            }
            info(P).username = username;
        } else if(inputPerbarui == 3) {
            string password;
            cout<<"Password baru: ";
            cin>>password;
            info(P).password = password;
        }
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"Data juri berhasil diperbarui"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;

};

void updatePeserta(listPeserta &P){
    system("cls");
    string idPeserta;
    cout<<"=================PERBARUI PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID PESERTA: ";
    cin>>idPeserta;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;

    adrPeserta Q = cariPeserta(P,idPeserta);
    system("cls");
    if(Q==NULL) {
        cout<<"Maaf peserta tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data peserta gagal diperbarui."<<endl;
        cout<<"==========================================="<<endl;
    } else {
        int inputPerbarui;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan pilih data yang ingin diperbarui: "<<endl;
        cout<<"1. Nama"<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Silahkan masukkan pilihan anda: ";
        cin>>inputPerbarui;
        if(inputPerbarui == 1) {
            string nama;
            cout<<"Nama baru: ";
            cin>>nama;
            info(Q).nama = nama;
        }
        system("cls");
        cout<<"==========================================="<<endl;
        cout<<"     Data peserta berhasil diperbarui"<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;

};

void deleteFirst(listJuri &J, adrJuri &P) {
    if(first(J)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(J))==NULL) {
        P = first(J);
        first(J) = NULL;
    } else {
        P = first(J);
        first(J)=next(P);
        next(P)=NULL;
    }
};

void deleteLast(listJuri &J, adrJuri &P) {
    adrJuri Q;
     if(first(J)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(J))==NULL) {
        P = first(J);
        first(J) = NULL;
    } else {
        Q = first(J);
        while(next(next(Q))!=NULL) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
};

void deleteAfter(listJuri &J, adrJuri prec, adrJuri &P){
     if(first(J)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(J))==NULL) {
        P = first(J);
        first(J) = NULL;
    } else {
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
    }
};

void deleteJuri(listJuri &J, adrJuri &P){
    system("cls");
    string idJuri;
    cout<<"==================HAPUS JURI==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Juri: ";
    cin>>idJuri;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    adrJuri Q = cariJuri(J,idJuri);
    system("cls");
    if(Q==NULL) {
        cout<<"Maaf juri tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data juri gagal dihapus."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
    } else {
        if(info(first(J)).idJuri == info(Q).idJuri) {
            deleteFirst(J,P);
        } else if(next(Q)==NULL) {
            deleteLast(J,P);
        } else {
            adrJuri prec = first(J);
            while(info(next(prec)).idJuri != info(Q).idJuri) {
                prec = next(prec);
            }
            deleteAfter(J,prec,P);
        }
        cout<<"==========================================="<<endl;
        cout<<"Data juri berhasil dihapus."<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};

void deleteFirst_Peserta(listPeserta &P, adrPeserta &Q) {
    if(first(P)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(P))==NULL) {
        Q = first(P);
        first(P) = NULL;
    } else {
        Q = first(P);
        first(P)=next(Q);
        next(Q)=NULL;
    }
};

void deleteLast_Peserta(listPeserta &P, adrPeserta &Q) {
    adrPeserta R;
     if(first(P)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(P))==NULL) {
        Q = first(P);
        first(P) = NULL;
    } else {
        R = first(P);
        while(next(next(R))!=NULL) {
            R = next(R);
        }
        Q = next(R);
        next(R) = NULL;
    }
};

void deleteAfter_Peserta(listPeserta &P, adrPeserta prec, adrPeserta &Q){
     if(first(P)==NULL) {
        cout<<"Maaf data kosong"<<endl;
    } else if(next(first(P))==NULL) {
        Q = first(P);
        first(P) = NULL;
    } else {
        Q = next(prec);
        next(prec) = next(Q);
        next(Q) = NULL;
    }
};

void deletePeserta(listPeserta &P, adrPeserta &Q){
    system("cls");
    string idPeserta;
    cout<<"==================HAPUS PESERTA==============="<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Silahkan masukkan ID Peserta: ";
    cin>>idPeserta;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    adrPeserta R = cariPeserta(P,idPeserta);
    system("cls");
    if(R==NULL) {
        cout<<"Maaf peserta tidak ditemukan."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
        cout<<"Data peserta gagal dihapus."<<endl;
        cout<<"==========================================="<<endl;
        cout<<"==========================================="<<endl;
    } else {
        if(info(first(P)).idPeserta == info(R).idPeserta) {
            deleteFirst_Peserta(P,Q);
        } else if(next(R)==NULL) {
            deleteLast_Peserta(P,Q);
        } else {
            adrPeserta prec = first(P);
            while(info(next(prec)).idPeserta != info(Q).idPeserta) {
                prec = next(prec);
            }
            deleteAfter_Peserta(P,prec,Q);
        }
        cout<<"==========================================="<<endl;
        cout<<"Data peserta berhasil dihapus."<<endl;
        cout<<"==========================================="<<endl;
    }
    cout<<endl;
};



int menuAplikasiAdmin(){
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

int menuUtama() {
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
}

bool loginAdmin() {
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
}

adrJuri loginJuri(listJuri J) {
    string username, password;
    adrJuri P = first(J);
    cout<<"=================LOGIN JURI================"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    cout<<"==========================================="<<endl;
    cout<<"==========================================="<<endl;
    cout<<endl;
    while(P!=NULL && info(P).username != username && info(P).password != password) {
        P = next(P);
    }
    return P;
}



