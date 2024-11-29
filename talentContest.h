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

void createListJuri(listJuri &LJ);
void createListPeserta(listPeserta &LP);
void createListRelasi(listRelasi &LR);
adrJuri cariJuriID(listJuri LJ,string idJuri);
adrPeserta cariPesertaID(listPeserta LP, string idPeserta);
adrPeserta cariPesertaNama(listPeserta LP, string namaPeserta);
adrJuri firstElementJuri(listJuri LJ);
adrPeserta lastElementPeserta(listPeserta LP);
string generateID(string x);
bool cekUsernameJuri(listJuri LJ, string username);
int countJuri(listJuri LJ);
int countPeserta(listPeserta LP);
infotypeJuri inputDataJuri(listJuri LJ);
infotypePeserta inputDataPeserta(listPeserta LP);
adrJuri createElementJuri(infotypeJuri x);
adrPeserta createElementPeserta(infotypePeserta x);
adrRelasi createElementRelasi(infotypeRelasi x, adrJuri J, adrPeserta P);
void insertFirstJuri(listJuri &LJ, adrJuri J);
void insertLastPeserta(listPeserta &LP, adrPeserta P);
void showJuri(listJuri LJ);
void showPeserta(listPeserta LP);
void updateJuri(listJuri &LJ);
void updatePeserta(listPeserta &LP);
void deleteFirstJuri(listJuri &LJ, adrJuri &J);
void deleteLastJuri(listJuri &LJ, adrJuri &J);
void deleteAfterJuri(listJuri &LJ, adrJuri prec, adrJuri &J);
void deleteJuri(listJuri &LJ, adrJuri &J);
void deleteFirstPeserta(listPeserta &LP, adrPeserta &P);
void deleteLastPeserta(listPeserta &LP, adrPeserta &P);
void deleteAfterPeserta(listPeserta &LP, adrPeserta prec, adrPeserta &P);
void deletePeserta(listPeserta &LP, adrPeserta &P);
int menuAplikasiAdmin();
int menuUtama();
bool loginAdmin();
adrJuri loginJuri(listJuri LJ);
void insertFirstRelasi(listRelasi &LR, adrRelasi R);
bool cariJuriPeserta(listRelasi LR, adrJuri J, string namaPeserta);
adrRelasi cariRelasi(listRelasi LR, adrJuri J, string namaPeserta);
void inputPenilaianPeserta(listRelasi &LR, listPeserta LP, adrJuri J);
int menuJuri();
void pesertaSudahDinilai(listRelasi LR, adrJuri J);
void pesertaBelumDinilai(listRelasi LR, listPeserta LP, adrJuri J);
void deleteRelasiFirst(listRelasi &LR, adrRelasi &R);
void deleteRelasiLast(listRelasi &LR, adrRelasi &R);
void deleteRelasiAfter(listRelasi &LR, adrRelasi prec, adrRelasi &R);
void deleteRelasi(listRelasi &LR, adrJuri J, adrRelasi &R);
void updateRelasi(listRelasi &LR, adrJuri J);

#endif // TALENTCONTEST_H_INCLUDED
