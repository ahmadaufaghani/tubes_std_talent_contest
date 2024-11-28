#ifndef TALENTCONTEST_H_INCLUDED
#define TALENTCONTEST_H_INCLUDED
#include <iostream>
#define first(L) (L).first
#define last(L) (L).last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define adrParent(P) P->adrParent
#define adrChild(P) P->adrChild
#define nilai(P) P->nilai

using namespace std;

typedef struct elmJuri *adrJuri;
typedef struct elmPeserta *adrPeserta;
typedef struct elmRelasi *adrRelasi;

struct infotypeJuri {
    string idJuri;
    string username;
    string password;
    string nama;
};

struct infotypePeserta {
    string idPeserta;
    string nama;
};

typedef int infotypeRelasi;

struct elmJuri {
    infotypeJuri info;
    adrJuri next;
};

struct elmPeserta {
    infotypePeserta info;
    adrPeserta next;
};

struct elmRelasi {
    adrRelasi prev;
    adrJuri adrParent;
    infotypeRelasi nilai;
    adrPeserta adrChild;
    adrRelasi next;
};

struct listJuri {
    adrJuri first;
};

struct listPeserta {
    adrPeserta first;
};

struct listRelasi {
    adrRelasi first;
    adrRelasi last;
};

void createListJuri(listJuri &J);
void createListPeserta(listPeserta &P);
void createListRelasi(listRelasi &R);
adrJuri cariJuri(listJuri J,string idJuri);
adrPeserta cariPeserta(listPeserta P, string idPeserta);
bool cekUsername(listJuri J, string username);
int countJuri(listJuri J);
int countPeserta(listPeserta P);
infotypeJuri inputDataJuri(listJuri J);
infotypePeserta inputDataPeserta(listPeserta P);
adrJuri createElementJuri(infotypeJuri x);
adrPeserta createElementPeserta(infotypePeserta x);
adrRelasi createElementRelasi(infotypeRelasi x);
void insertFirstJuri(listJuri &J, adrJuri P);
void insertLastPeserta(listPeserta &P, adrPeserta Q);
void showJuri(listJuri J);
void showPeserta(listPeserta P);
void updateJuri(listJuri &J);
void updatePeserta(listPeserta &P);
void deleteFirst(listJuri &J, adrJuri &P);
void deleteLast(listJuri &J, adrJuri &P);
void deleteAfter(listJuri &J, adrJuri prec, adrJuri &P);
void deleteJuri(listJuri &J, adrJuri &P);
void deleteFirst_Peserta(listPeserta &P, adrPeserta &Q);
void deleteLast_Peserta(listPeserta &P, adrPeserta &Q);
void deleteAfter_Peserta(listPeserta &P, adrPeserta prec, adrPeserta &Q);
void deletePeserta(listPeserta &P, adrPeserta &Q);
int menuAplikasiAdmin();
int menuUtama();
bool loginAdmin();
adrJuri loginJuri(listJuri J);

#endif // TALENTCONTEST_H_INCLUDED
