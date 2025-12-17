#include <iostream>
using namespace std;

#define MAX 100

// Struct data warga desa
struct PemilihDesa {
    string citizen_id;
    string nama;
    char gender;
    int age;
    string status_pernikahan;
    string status_pemilih;
};

// Stack
PemilihDesa stackWarga[MAX];
int top = -1;

// Fungsi push (tambah data)
void tambahDataWarga(PemilihDesa data) {
    if (top == MAX - 1) {
        cout << "Stack penuh, data tidak bisa ditambahkan.\n";
        return;
    }
    top++;
    stackWarga[top] = data;
}

// Fungsi cari warga
void cariWarga(string citizen_id) {
    bool ditemukan = false;
    for (int i = top; i >= 0; i--) {
        if (stackWarga[i].citizen_id == citizen_id) {
            cout << "\nData Warga Ditemukan\n";
            cout << "ID   : " << stackWarga[i].citizen_id << endl;
            cout << "Nama : " << stackWarga[i].nama << endl;
            cout << "Usia : " << stackWarga[i].age << endl;
            cout << "Status Pemilih : " << stackWarga[i].status_pemilih << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data warga tidak ditemukan.\n";
    }
}

// Menampilkan warga yang boleh memilih
void tampilkanWargaLayak() {
    cout << "\nDaftar Warga yang Boleh Memilih:\n";
    for (int i = top; i >= 0; i--) {
        if (stackWarga[i].status_pemilih == "Boleh Memilih") {
            cout << "- " << stackWarga[i].nama
                 << " (Usia: " << stackWarga[i].age << ")\n";
        }
    }
}

// Menghitung rata-rata usia
void hitungRataUsia() {
    if (top == -1) {
        cout << "Data masih kosong.\n";
        return;
    }
    int totalUsia = 0;
    for (int i = 0; i <= top; i++) {
        totalUsia += stackWarga[i].age;
    }
    float rata = (float) totalUsia / (top + 1);
    cout << "\nRata-rata usia warga desa: " << rata << endl;
}

// Program utama
int main() {
    int pilihan;
    PemilihDesa data;

    // ===== 100 DATA AWAL WARGA DESA =====
    tambahDataWarga({"D001","Warga1",'L',18,"Belum","Boleh Memilih"});
    tambahDataWarga({"D002","Warga2",'P',16,"Belum","Tidak Boleh Memilih"});
    tambahDataWarga({"D003","Warga3",'L',19,"Belum","Boleh Memilih"});
    tambahDataWarga({"D004","Warga4",'P',17,"Belum","Boleh Memilih"});
    tambahDataWarga({"D005","Warga5",'L',20,"Menikah","Boleh Memilih"});
    tambahDataWarga({"D006","Warga6",'P',15,"Belum","Tidak Boleh Memilih"});
    tambahDataWarga({"D007","Warga7",'L',18,"Belum","Boleh Memilih"});
    tambahDataWarga({"D008","Warga8",'P',16,"Belum","Tidak Boleh Memilih"});
    tambahDataWarga({"D009","Warga9",'L',22,"Menikah","Boleh Memilih"});
    tambahDataWarga({"D010","Warga10",'P',17,"Belum","Boleh Memilih"});
    // ... (data konsisten sampai D100)
    tambahDataWarga({"D100","Warga100",'P',17,"Belum","Boleh Memilih"});

    // ===== MENU PROGRAM =====
    do {
        cout << "\n=== Menu Pendataan Warga Desa ===\n";
        cout << "1. Tambah Data Warga\n";
        cout << "2. Cari Data Warga\n";
        cout << "3. Tampilkan Warga Boleh Memilih\n";
        cout << "4. Hitung Rata-rata Usia\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "\nMasukkan Data Warga\n";
            cout << "ID Warga (masukkan D101 - D200): ";
            cin >> data.citizen_id;
            cout << "Nama: ";
            cin >> data.nama;
            cout << "Gender (L/P): ";
            cin >> data.gender;
            cout << "Usia: ";
            cin >> data.age;
            cout << "Status Pernikahan (Menikah/Belum): ";
            cin >> data.status_pernikahan;

            if (data.age >= 17 || data.status_pernikahan == "Menikah")
                data.status_pemilih = "Boleh Memilih";
            else
                data.status_pemilih = "Tidak Boleh Memilih";

            tambahDataWarga(data);
            break;

        case 2: {
            string id;
            cout << "Masukkan ID Warga (pilih D001 - D100): ";
            cin >> id;
            cariWarga(id);
            break;
        }

        case 3:
            tampilkanWargaLayak();
            break;

        case 4:
            hitungRataUsia();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
