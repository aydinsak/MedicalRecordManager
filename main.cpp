#include "MLL.h"

int main()
{
    listDokter ld;
    listPasien lp;
    adr_dokter pd;
    adr_pasien pp;
    infotype_dokter xd;
    infotype_pasien xp;
    createListDokter(ld);
    createListPasien(lp);
    string idP, idD, namaD, namaP;
    int opsi;

    menu();
    cin >> opsi;
    while (opsi < 0 || opsi > 12){
        cout << "opsi yang anda masukkan tidak ada! pilihan anda: ";
        cin >> opsi;
    }
    cout << endl;
    while (opsi != 0){
        if (opsi == 1){ // tambah data dokter
            int nDokter = 0;
            cout << "masukkan N dokter: ";
            cin >> nDokter;
            for (int i = 1; i<=nDokter; i++){
                cout << "Isi dokter ke-" << i << endl;
                cout << "Masukkan ID dokter: ";
                cin >> xd.id_dokter;
                cout << "Masukkan nama dokter: ";
                cin >> xd.nama;
                cout << "Masukkan jam kerja dokter: ";
                cin >> xd.jam_kerja;
                pd = createElemenDokter(xd);
                insertLastD(ld, pd);
            }
        } else if (opsi == 2){ //tambah data pasien
            int nPasien = 0;
            cout << "Masukkan N pasien: ";
            cin >> nPasien;
            for (int j = 1; j<=nPasien; j++){
                cout << "Isi pasien ke-" << j << endl;
                cout << "Masukkan ID pasien: ";
                cin >> xp.id_pasien;
                cout << "Masukkan nama pasien: ";
                cin >> xp.nama;
                cout << "Masukkan jenis kelamin pasien: ";
                cin >> xp.jk;
                cout << "Masukkan umur pasien: ";
                cin >> xp.umur;
                pp = createElemenPasien(xp);
                insertLastP(lp, pp);
            }
        } else if (opsi == 3){ //hapus data dokter
            if (first(ld) != nil){
                showIdDokter(ld);
                cout << "masukkan id dokter yang akan dihapus: ";
                cin >> namaD;
                deleteDokter(ld, namaD);
            } else {
                cout << "List dokter masih kosong." << endl;
            }
        } else if (opsi == 4){ //hapus data pasien
            if (first(lp) != nil){
                showIdPasien(lp);
                cout << "masukan id pasien yang akan dihapus: ";
                cin >> namaP;
                deletePasien(ld,lp, namaP);
            } else {
                cout << "List pasien masih kosong." << endl;
            }
        } else if (opsi == 5){ // show dokter
            showDokter(ld);
        } else if (opsi == 6){ //show pasien
            showPasien(lp);
        } else if (opsi == 7){ // show seluruh data pasien dan dokter
            cout << "========= Seluruh data ========" << endl;
            showAllList(ld, lp);
        } else if (opsi == 8){ //gabung relasi dokter dan pasien
            if (first(ld) == nil || first(lp) == nil){
                cout << "Salah satu list masih kosong." << endl;
            } else {
                showIdDokter(ld);
                showIdPasien(lp);
                cout << "masukan id dokter dan id pasien yang akan dihubungkan" << endl;
                cout << "id dokter:";
                cin >> idD;
                cout << "id pasien:";
                cin >> idP;
                if (searchD(ld, idD) != nil && searchP(lp, idP) != nil){
                    hubungPasienDokter(lp, ld, idD, idP);
                } else {
                    cout << "Maaf, salah satu atau kedua id yang anda masukkan tidak ada." << endl;
                }
            }
        } else if (opsi == 9){ //show pasien ditangani dokter
            showPasienDitanganiDokter(ld, lp);
        } else if (opsi == 10){ //show dokter menangani pasien
            showDokterTanganiPasien(ld);
        } else if (opsi == 11){ //show dokter paling sibuk dan tidak sibuk
            showDokterMostBusy(ld);
        } else if (opsi == 12){ // antrian
            if (first(ld) != nil){
                showIdDokter(ld);
                cout << "masukan id dokter yang akan ditampilkan antriannya: ";
                cin >> idD;
                showAntrian(ld, idD);
            } else {
                cout << "List dokter masih kosong." << endl;
            }
        }
        menu();
        cin >> opsi;
        while (opsi < 0 || opsi > 12){
        cout << "opsi yang anda masukkan tidak ada! pilihan anda: ";
        cin >> opsi;
        }
        cout << endl;
    }
    cout << "PROGRAM SELESAI" << endl;
}
