#include "MLL.h"

// --------- DOKTER ---------- //
void createListDokter(listDokter &LD){
    first(LD) = nil;
}
adr_dokter createElemenDokter(infotype_dokter x){
    adr_dokter p = new elemenDokter;
    info(p).id_dokter = x.id_dokter;
    info(p).nama = x.nama;
    info(p).jam_kerja = x.jam_kerja;
    info(p).penanganan = 0;
    next(p) = nil;
    createListRelasi(child(p));
    return p;
}
void insertLastD(listDokter &LD, adr_dokter P){
    if (first(LD) == nil){
        first(LD) = P;
    } else {
        adr_dokter Q = first(LD);
        while (next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = nil;
    }
    cout << "Dokter " << info(P).nama << " berhasil ditambahkan." << endl;
}
void showDokter(listDokter LD){
    adr_dokter P = first(LD);
    int n = 1;
    cout << "=============== DOKTER ===============" << endl;
    if (first(LD) == nil){
        cout << "List dokter kosong";
    } else {
        while (P != nil){
            cout << "List Dokter ke-" << n << endl;
            cout << "ID dokter: " << info(P).id_dokter << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Kuota jam kerja: " << info(P).jam_kerja << " jam" << endl;
            cout << "penanganan: " << info(P).penanganan << endl;
            cout << "--------------------------------------------" << endl;
            n++;
            P = next(P);
        }
    }
    cout << endl;
}
void showIdDokter(listDokter LD){
    adr_dokter P = first(LD);
    int i = 1;
    cout << "--------------- List ID Dokter ---------------" << endl;
    while (P != nil){
        cout << "dokter " << i << ", " << info(P).nama << " - " << info(P).id_dokter << endl;
        i++;
        P = next(P);
    }
    cout << endl;
}
void deleteFirstD(listDokter &LD, adr_dokter &P){
    if (first(LD) == nil){
        cout << "List kosong" << endl;
    } else if (next(first(LD)) == nil){
        P = first(LD);
        first(LD) = nil;
    } else {
        P = first(LD);
        first(LD) = next(P);
        next(P) = nil;
    }
}
void deleteAfterD(listDokter &LD, adr_dokter temp, adr_dokter &P){
    P = next(temp);
    next(temp) = next(P);
    next(P) = nil;
}
adr_dokter searchD(listDokter LD, string id){
    adr_dokter P = first(LD);
    while (P != nil){
        if (info(P).id_dokter == id){
            return P;
        }
        P = next(P);
    }
    return nil;
}
void deleteDokter(listDokter &LD, string id_dokter){
    adr_dokter P = searchD(LD, id_dokter);
    if (P != nil){
        if (first(LD) == P){
            deleteFirstD(LD, P);
        } else {
            adr_dokter temp = first(LD);
            while (next(temp) != P ){
                temp = next(temp);
            }
            deleteAfterD(LD, temp, P);
        }
        cout << "Dokter " << info(P).nama << " sudah dihapus." << endl;
    }else {
        cout << "ID dokter tidak ditemukan." << endl;
    }
}
// ---------- PASIEN --------- //
void createListPasien(listPasien &LP){
    first(LP) = nil;
}
adr_pasien createElemenPasien(infotype_pasien x){
    adr_pasien p = new elemenPasien;
    info(p).id_pasien = x.id_pasien;
    info(p).nama = x.nama;
    info(p).umur = x.umur;
    info(p).jk = x.jk;
    info(p).status = "belum";
    info(p).ditangani = "";
    next(p) = nil;
    return p;
}
void insertLastP(listPasien &LP, adr_pasien P){
    if (first(LP) == nil){
        first(LP) = P;
    } else {
        adr_pasien Q = first(LP);
        while (next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = nil;
    }
    cout << "Pasien " << info(P).nama << " berhasil ditambahkan." << endl;
}
void showPasien(listPasien LP){
    adr_pasien P = first(LP);
    int i = 1;
    cout << "=============== PASIEN ===============" << endl;
    if (first(LP) == nil){
        cout << "List pasien kosong";
    } else {
        while (P != nil){
            cout << "List pasien ke-" << i << endl;
            cout << "ID pasien: " << info(P).id_pasien << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Jenis Kelamin: " << info(P).jk << endl;
            cout << "Umur: " << info(P).umur << endl;
            if (info(P).ditangani != ""){
                cout << "Kondisi cek: " << info(P).status << " ditangani oleh dokter " << info(P).ditangani << endl;
            } else {
                cout << "Kondisi cek: " << info(P).status << endl;
            }
            cout << "--------------------------------------------" << endl;
            i++;
            P = next(P);
        }
    }
    cout << endl;
}
void showIdPasien(listPasien LP){
    adr_pasien P = first(LP);
    int i = 1;
    cout << "--------------- List ID Pasien ---------------" << endl;
    while (P != nil){
        cout << "Pasien " << i << ", " << info(P).nama << " - " << info(P).id_pasien << endl;
        i++;
        P = next(P);
    }
    cout << endl;
}
void deleteFirstP(listPasien &LP, adr_pasien &P){
    if (first(LP) == nil){
        cout << "List kosong" << endl;
    } else if (next(first(LP)) == nil){
        P = first(LP);
        first(LP) = nil;
    } else {
        P = first(LP);
        first(LP) = next(P);
        next(P) = nil;
    }
}
void deletePasien(listDokter LD,listPasien &LP, string id_pasien){
adr_pasien P=searchP(LP,id_pasien);
    if (P != nil){
        delRelasiDokter(LD, P);
        if (first(LP) == P){
            deleteFirstP(LP, P);
        } else {
            adr_pasien temp = first(LP);
            while (next(temp) != P ){
                temp = next(temp);
            }
            deleteAfterP(LP, temp, P);
            }
            cout << "Pasien " << info(P).nama << " sudah dihapus.\n";
        }else {
        cout << "ID pasien tidak ditemukan.\n";
    }
}
void deleteAfterP(listPasien &LP, adr_pasien temp, adr_pasien &P){
    P = next(temp);
    next(temp) = next(P);
    next(P) = nil;
}
adr_pasien searchP(listPasien LP, string id){
    adr_pasien P = first(LP);
    while (P != nil){
        if (info(P).id_pasien == id){
            return P;
        }
        P = next(P);
    }
    return nil;
}


// --------------- RELASI --------------- //

void createListRelasi(listRelasi &LR){
    head(LR) = nil;
    tail(LR) = nil;
}
adr_relasi createELemenRelasi(adr_pasien x){
    adr_relasi p = new elemenRelasi;
    nextP(p) = x;
    next(p) = nil;
    return p;
}
void addRelasiLast(adr_dokter &PD, adr_relasi PR){ //insert last queue
    if (head(PD->child) == nil){
        head(PD->child) = PR;
        tail(PD->child) = PR;
    } else {
        next(tail(PD->child)) = PR;
        tail(PD->child) = PR;
    }
    info(PD).penanganan++;
}
void delRelasiFirst(adr_dokter &PD, adr_relasi &PR){ // delete first queue
    if (head(PD->child) != nil){
        PR = head(PD->child);
        if (head(PD->child) == tail(PD->child)){
            head(PD->child) = nil;
            tail(PD->child) = nil;
        } else {
            head(PD->child) = next(PR);
            next(PR) = nil;
        }
        info(PD).penanganan--;
    } else {
        cout << "antrian sudah kosong" << endl;
    }
}
void delRelasiAfter(adr_dokter &PD, adr_relasi &temp, adr_relasi &PR){
    adr_relasi R=head(PD->child);
    temp=PR;
    while(next(R)!=NULL && next(R)!=PR){
        R=next(R);
    }
    next(R)=next(temp);
    next(temp)=NULL;
    info(PD).penanganan--;
}
void delRelasiLast(adr_dokter &PD, adr_relasi &PR){
    if (head(PD->child) != nil){
        adr_relasi Q = head(PD->child);
        if (head(PD->child) == tail(PD->child)){
            head(PD->child) = nil;
            tail(PD->child) = nil;
        } else {
            while (next(next(Q)) != nil){
                Q = next(Q);
            }
            PR = tail(PD->child);
            tail(PD->child) = Q;
            next(Q) = nil;
        }
    }
    info(PD).penanganan--;
}
void delRelasiDokter(listDokter &LD, adr_pasien PP){
    adr_dokter PD = first(LD);
    adr_relasi temp = nil;
    while (PD != nil){
        adr_relasi PR = head(PD->child);
        while (PR != nil){
            if (nextP(PR) == PP){
                if (PR == head(PD->child)){
                    delRelasiFirst(PD, PR);
                } else if (PR == tail(PD->child)){
                    delRelasiLast(PD, PR);
                } else {
                    delRelasiAfter(PD, temp, PR);
                }
            }
            PR = next(PR);
        }
        PD = next(PD);
    }
}
void hubungPasienDokter(listPasien LP, listDokter LD, string id_dokter, string id_pasien){
    adr_pasien PP = searchP(LP,id_pasien);
    adr_dokter PD = searchD(LD, id_dokter);
    adr_relasi R = createELemenRelasi(PP);
    if(cekRelasi(PD->child, PP)){
        cout<<"Maaf data relasi sudah ada."<<endl;
    }else{
        if (info(PP).ditangani != ""){
            cout << "Maaf, pasien " << info(PP).nama << " sudah ditangani oleh dokter " << info(PP).ditangani << endl;
        } else {
            addRelasiLast(PD,R);
            cout << "Berhasil menghubungkan dokter " << info(PD).nama << " dengan pasien " << info(PP).nama << endl;
        }
    }
}
bool cekRelasi(listRelasi LR, adr_pasien PP){
    adr_relasi P = head(LR);
    while (P != nil){
        if (nextP(P) == PP){
            return true;
        }
        P = next(P);
    }
    return false;
}
bool cekChildIsNULL(adr_dokter PD){
    return head(PD->child) == NULL;
}

// ---------------- MISC -------------- //
void showAllList(listDokter LD, listPasien LP){
    showDokter(LD);
    showPasien(LP);
}
void showDokterTanganiPasien(listDokter LD){
    adr_dokter PD = first(LD);
    int i = 1;

    if (first(LD) == nil){
        cout << "List masih kosong." << endl;
    } else {
        while (PD != nil){
            cout << "Dokter ke-" << i << endl;
            cout << "Nama: " << info(PD).nama << ". ";
            if (cekChildIsNULL(PD)){
                cout << "Tidak ada pasien";
            } else {
                adr_relasi PR = head(PD->child);
                cout << "Menangani ";
                while (PR != nil){
                    cout << info(nextP(PR)).nama;
                    if (next(PR) != nil){
                        cout << ", ";
                    }
                    PR = next(PR);
                }
            }
            i++;
            PD = next(PD);
            cout << endl;
        }
    }
    cout << endl;
}
void showPasienDitanganiDokter(listDokter LD, listPasien LP){
    adr_pasien PP = first(LP);
    int i = 1;

    if (first(LD) == nil){
        cout << "List masih kosong. " << endl;
    } else {
        while (PP != nil){
            cout << "pasien ke-" << i << endl;
            cout << "Nama: " << info(PP).nama << ". ";
            adr_dokter PD = first(LD);
            while (PD != nil){
                 adr_relasi PR = head(PD->child);
                 while (PR != nil){
                    if (nextP(PR) == PP){
                        cout << info(PD).nama << ", ";
                    }
                    PR = next(PR);
                 }
                 PD = next(PD);
            }
            i++;
            PP = next(PP);
            cout << endl;
        }
    }
    cout << endl;
}
void showDokterMostBusy(listDokter LD){
    adr_dokter PD = first(LD);
    adr_dokter PMostBusy = nil;
    adr_dokter PLeastBusy = nil;
    int maxP = -999;
    int minP = 999;

    while (PD != nil){
        if (!cekChildIsNULL(PD)){
            int penanganan = info(PD).penanganan;
            if (penanganan > maxP){
                maxP = penanganan;
                PMostBusy = PD;
            }
            if (penanganan < minP){
                minP = penanganan;
                PLeastBusy = PD;
            }
        }
        PD = next(PD);
    }
    cout << "Dokter yang paling sibuk: ";
    if (PMostBusy != nil && maxP > 0) {
        cout << info(PMostBusy).nama << " (menangani " << maxP << " pasien)" << endl;
    } else {
        cout << "Tidak ada dokter yang sibuk." << endl;
    }

    cout << "Dokter yang tidak sibuk: ";
    if (PLeastBusy != nil && minP > 0) {
        cout << info(PLeastBusy).nama << " (menangani " << minP << " pasien)" << endl;
    } else {
        cout << "Tidak ada dokter yang tidak sibuk." << endl;
    }
}
void showAntrian(listDokter &LD, string id_dokter){
    adr_dokter PD = searchD(LD, id_dokter);
    if (PD == nil){
        cout << "Dokter yang anda cari tidak ada." << endl;
    } else {
        if (cekChildIsNULL(PD)){
            cout << "Jam kerja dokter " << info(PD).nama << " tersisa " << info(PD).jam_kerja << " jam." << endl;
            cout << "====== ANTRIAN ======" << endl;
            cout << "Tidak ada antrian pasien untuk dokter " << info(PD).nama << endl;
            cout << "---------------------------------" << endl;
            if (info(PD).jam_kerja == 0){
                cout << "Jam kerja dokter " << info(PD).nama << " sudah habis." << endl;
                cout << "Maka dokter sudah tidak menerima pasien lagi dan dihapus dari list dokter." << endl;
                deleteDokter(LD, info(PD).id_dokter);
            }
        } else {
            if (info(PD).jam_kerja > 0){
                cout << "Jam kerja dokter " << info(PD).nama << " tersisa " << info(PD).jam_kerja << " jam." << endl;
                cout << "====== ANTRIAN ======" << endl;
                cout << "---------------------------------" << endl;
                adr_relasi PR = head(PD->child);
                int antrian = 1;
                while (PR != nil){
                    cout << "Antrian pasien ke-" << antrian << endl;
                    cout << "Nama: "<<info(PR->nextP).nama << endl;
                    cout << "Jenis kelamin: " << info(PR->nextP).jk << endl;
                    cout << "Umur: " << info(PR->nextP).umur << endl;
                    cout << "Status: " << info(PR->nextP).status << endl;
                    cout << "----------------------------------" << endl;
                    antrian++;
                    PR = next(PR);
                }
                string question;
                cout << "Mulai antrian? Ketik '1' untuk iya atau ketik apapun untuk tidak: ";
                cin >> question;
                if (question == "1"){
                    startAntrian(LD, PD);
                }
            } else {
                cout << "Jam kerja dokter " << info(PD).nama << " sudah habis." << endl;
                cout << " Maka dokter sudah tidak menerima pasien lagi dan dihapus dari list dokter." << endl;
                deleteDokter(LD, info(PD).id_dokter);
            }
        }
    }
}
void startAntrian(listDokter &LD, adr_dokter &PD){
    adr_relasi PR;
    PR = head(PD->child);
    if (head(PD->child) != nil && tail(PD->child) != nil){
        if(info(PR->nextP).status == "belum"){
            info(PR->nextP).status = "sudah";
            info(PR->nextP).ditangani = info(PD).nama;
            info(PD).jam_kerja--;
            delRelasiFirst(PD, PR);
            cout << "berhasil cek pasien " << info(PR->nextP).nama << " dan dikeluarkan dari antrian." << endl;
        } else {
            cout << "pasien " << info(PR->nextP).nama << " sudah dicek oleh dokter " << info(PR->nextP).ditangani << endl;
            cout << "Maka dikeluarkan dari antrian tanpa mengurangi sisa jam kerja dokter." << endl;
            delRelasiFirst(PD, PR);
        }
        cout << endl;
    }
    showAntrian(LD, info(PD).id_dokter);
}
void menu(){
    cout << endl;
    cout << "===============================================" << endl;
    cout << "|           ===   Data Berobat    ===          |" << endl;
    cout << "|        ===    BY AYDIN & DAENG     ===       |" << endl;
    cout << "===============================================" << endl;
    cout << "|1. Tambah Data Dokter.                         " << endl;
    cout << "|2. Tambah Data Pasien.                       " << endl;
    cout << "|3. Hapus Data Dokter.                         " << endl;
    cout << "|4. Hapus Data Pasien.                        " << endl;
    cout << "|5. Tampil semua Data Dokter.                   " << endl;
    cout << "|6. Tampil Semua Data Pasien.                 " << endl;
    cout << "|7. Tampil semua data dokter dan pasien. " << endl;
    cout << "|8. Relasi Dokter dan Pasien.                   " << endl;
    cout << "|9. Tampil Data Pasien yang ditangani oleh Dokter Tertentu.     " << endl;
    cout << "|10. Tampil data dokter yang menangani pasien tertentu. " << endl;
    cout << "|11. Tampil data dokter yang tidak sibuk dan yang paling sibuk. " << endl;
    cout << "|12. Tampil antrian dari dokter tertentu yang akan menangani pasien nya. " << endl;
    cout << "|0. Keluar.                                   " << endl;
    cout << "===============================================" << endl;
    cout << "Pilihan anda: ";
}
