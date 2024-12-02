#include <iostream>
#include "talentContest.h"
using namespace std;

int main()
{
    listJuri J;
    listPeserta P;
    listRelasi R;
    createListJuri(J);
    createListPeserta(P);
    createListRelasi(R);
    int inputPengguna = menuUtama();
    while(inputPengguna !=0) {
        if(inputPengguna == 1) {
            system("cls");
            bool autentikasiAdmin = loginAdmin();
            if(autentikasiAdmin) {
                system("cls");
                int pilihan = menuAplikasiAdmin();
                while(pilihan != 0) {
                    system("cls");
                    if(pilihan == 1) {
                        infotypeJuri dataJuri = inputDataJuri(J);
                        adrJuri P = createElementJuri(dataJuri);
                        insertFirstJuri(J,P);
                        system("cls");
                    } else if (pilihan == 2) {
                        system("cls");
                        showJuri(J);
                    } else if (pilihan == 3) {
                        updateJuri(J);
                    } else if (pilihan == 4) {
                        adrJuri P;
                        deleteJuri(J,P);
                    } else if(pilihan == 5) {
                        infotypePeserta dataPeserta = inputDataPeserta(P);
                        adrPeserta Q = createElementPeserta(dataPeserta);
                        insertLastPeserta(P,Q);
                        system("cls");
                    } else if(pilihan == 6) {
                        system("cls");
                        showPeserta(P);
                    } else if(pilihan == 7) {
                        updatePeserta(P);
                    } else if(pilihan == 8) {
                        adrPeserta Q;
                        deletePeserta(P,Q);
                    }else if(pilihan ==9){
                        viewTotalNilaiPeserta(P,R);

                    }else if(pilihan ==10){
                        viewDetailPenilaianJuri(J,R);

                    }

                    pilihan = menuAplikasiAdmin();
                }
            }
        } else if (inputPengguna == 2) {
            system("cls");
            adrJuri autentikasi = loginJuri(J);
            if(autentikasi) {
                system("cls");
                int inputJuri = menuJuri();
                while(inputJuri!=0) {
                    if(inputJuri == 1) {
                        system("cls");
                        cout<<"Juri: "<<info(autentikasi).nama<<endl;
                        inputPenilaianPeserta(R,P,autentikasi);
                    } else if(inputJuri == 2) {
                        system("cls");
                        cout<<"Juri: "<<info(autentikasi).nama<<endl;
                        pesertaSudahDinilai(R,autentikasi);
                    } else if(inputJuri == 3) {
                        system("cls");
                        cout<<"Juri: "<<info(autentikasi).nama<<endl;
                        pesertaBelumDinilai(R,P,autentikasi);
                    } else  if(inputJuri == 4) {
                        adrRelasi X;
                        system("cls");
                        cout<<"Juri: "<<info(autentikasi).nama<<endl;
                        deleteRelasi(R,autentikasi,X);
                    }  else if(inputJuri == 5) {
                        cout<<"Juri: "<<info(autentikasi).nama<<endl;
                        updateRelasi(R,autentikasi);
                    }
                    inputJuri = menuJuri();
                }
            }
        }else if (inputPengguna == 3) {
    system("cls");
    int pilih = -1;
    while (pilih != 0) {
        pilih = menuNonLoginUser ();
        system("cls");

        if (pilih == 1) {
            showAllPeserta(P, R);
        } else if (pilih == 0) {

            cout << "Kembali ke menu utama..." << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}
        system("cls");
        inputPengguna = menuUtama();
    }
    system("cls");
    cout<<"==========================================="<<endl;
    cout<<"TERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI"<<endl;
    cout<<"==========================================="<<endl;
    return 0;
}


