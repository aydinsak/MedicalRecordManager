#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

#define nil NULL
#define next(P) P->next
#define nextP(P) P->nextP
#define info(P) P->info
#define child(R) R->child
#define head(Q) Q.head
#define tail(Q) Q.tail
#define first(L) L.first
using namespace std;

struct dokter {
    string id_dokter;
    string nama;
    int jam_kerja;
    int penanganan;
};
struct pasien {
    string id_pasien;
    string nama;
    string jk;
    int umur;
    string status;
    string ditangani;
};
typedef struct dokter infotype_dokter;
typedef struct pasien infotype_pasien;
typedef struct elemenDokter *adr_dokter;
typedef struct elemenPasien *adr_pasien;
typedef struct elemenRelasi *adr_relasi;
struct listRelasi{
    adr_relasi head, tail;
};
struct listDokter {
    adr_dokter first;
};
struct listPasien {
    adr_pasien first;
};
struct elemenRelasi{
    adr_relasi next;
    adr_pasien nextP;
};
struct elemenDokter{
    infotype_dokter info;
    listRelasi child;
    adr_dokter next;
};
struct elemenPasien{
    infotype_pasien info;
    adr_pasien next;
};


// --------- DOKTER ---------- //
void createListDokter(listDokter &LD);
adr_dokter createElemenDokter(infotype_dokter x);
void insertLastD(listDokter &LD, adr_dokter P);
void showDokter(listDokter LD);
void showIdDokter(listDokter LD);
void deleteFirstD(listDokter &LD, adr_dokter &P);
void deleteAfterD(listDokter &LD, adr_dokter temp, adr_dokter &P);
void deleteDokter(listDokter &LD, string id_dokter);
adr_dokter searchD(listDokter LD, string id);

// ---------- PASIEN --------- //
void createListPasien(listPasien &LP);
adr_pasien createElemenPasien(infotype_pasien x);
void insertLastP(listPasien &LP, adr_pasien P);
void showPasien(listPasien LP);
void showIdPasien(listPasien LD);
void deleteFirstP(listPasien &LP, adr_pasien &P);
void deleteAfterP(listPasien &LP, adr_pasien temp, adr_pasien &P);
void deletePasien(listDokter LD,listPasien &LP, string id_pasien);
adr_pasien searchP(listPasien LP, string id);

// ----------- RELASI -------------- //
void createListRelasi(listRelasi &LR);
adr_relasi createELemenRelasi(adr_pasien x);
void addRelasiLast(adr_dokter &PD, adr_relasi PR); //enqueue
void delRelasiFirst(adr_dokter &PD, adr_relasi &PR); //dequeue
void delRelasiLast(adr_dokter &PD, adr_relasi &PR);
void delRelasiAfter(adr_dokter &PD, adr_relasi &temp, adr_relasi &PR);
void delRelasiDokter(listDokter &LD, adr_pasien PP);
void hubungPasienDokter(listPasien LP, listDokter LD, string id_dokter, string id_pasien);
bool cekRelasi(listRelasi LR, adr_pasien PP);
bool cekChildIsNULL(adr_dokter PD);

// -------------- MISC ---------------- //
void showDokterTanganiPasien(listDokter LD);
void showPasienDitanganiDokter(listDokter LD, listPasien LP);
void showAllList(listDokter LD, listPasien LP);
void showAntrian(listDokter &LD, string id_dokter);
void startAntrian(listDokter &LD, adr_dokter &PD);
void showDokterMostBusy(listDokter LD);
void menu();



#endif // MLL_H_INCLUDED
