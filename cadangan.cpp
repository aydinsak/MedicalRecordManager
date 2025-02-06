#include "MLL.h"

/*int main()
{
    listDokter ld;
    listPasien lp;
    adr_dokter pd;
    adr_pasien pp;
    infotype_dokter xd;
    infotype_pasien xp;
    int inputan;
    createListDokter(ld);
    int i;
    int j = 1;
    string IDDokter, IDPasien;
    Menu();
    cin >> inputan;
    while (inputan != 9){
        if (inputan == 1){
            cout << "Tambahkan berapa dokter? " << endl;
            cin >> i;
            while (j<=i){
                cout << "masukkan ID dokter ke-" << j << endl;
                cin >> xd.id_dokter;
                cout << "masukkan Nama dokter ke-" << j << endl;
                cin >> xd.nama;
                cout << "masukkan Jam Kerja dokter ke-" << j << endl;
                cin >> xd.jam_kerja;
                pd = createElemenDokter(xd);
                insertLastD(ld, pd);
                j++;
            }
            Menu();
        }else if (inputan == 2){
            cout << "Tambahkan berapa Pasien?"<< endl;
            cin >> j;
            for (int i = 1; i<=j; i++){
                cout << "masukkan ID pasien ke-" << i << endl;
                cin >> xp.id_pasien;
                cout << "masukkan Nama pasien ke-" << i << endl;
                cin >> xp.nama;
                cout << "masukkan Jenis Kelamin pasien ke-" << i << endl;
                cin >> xp.jk;
                cout << "masukkan Umur pasien ke-" << i << endl;
                cin >> xp.umur;
                pp = createElemenPasien(xp);
                insertLastP(lp, pp);
            }
            cout << "Seluruh data" << endl;
            showAllList(ld, lp);
        }else if (inputan == 3){
            cout << "Masukan ID Dokter Yang ingin Dihapus"<< endl;
            cin >> IDDokter;
            deleteDokter(ld, IDDokter);
        }else if (inputan == 4){
            cout << "Masukan ID Pasien yang ingin Dihapus"<< endl;
            cin >> IDPasien;
            deletePasien(lp, IDPasien);

        }
        Menu();
        cin >> inputan;
    }

    string namaD;
    cout << "masukkan id dokter yang akan dihapus: ";
    cin >> namaD;
    deleteDokter(ld, namaD);
    showDokter(ld);

    listRelasi lr;
    createListRelasi(lr);
    string idP;
    string idD;
    cout << "masukan id dokter dan id pasien yang akan dihubungkan" << endl;
    cout << "id dokter:";
    cin >> idD;
    cout << "id pasien:";
    cin >> idP;
    adr_dokter sD = searchD(ld, idD);
    hubungPasienDokter(lp, sD, idP);
    cout << "masukan id dokter dan id pasien yang akan dihubungkan" << endl;
    cout << "id dokter:";
    cin >> idD;
    cout << "id pasien:";
    cin >> idP;
    sD = searchD(ld, idD);
    hubungPasienDokter(lp, sD, idP);
    //showPasienDitanganiDokter(ld, lp);
    return 0;
}
    */
