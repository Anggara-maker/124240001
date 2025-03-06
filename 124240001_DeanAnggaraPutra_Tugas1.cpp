#include <iostream>

using namespace std;

void inputdata();
void tampildata();
void sorting();
void searching();

struct Kendaraan {
    string namapemilik;
    int nokendaraan;
    string jeniskendaraan;
    string merkkendaraan;
    string modelkendaraan;
    int tahunproduksi;
} kendaraan[100];

int jumlahdata;

int main () {
    int pilihan;

    do {
        cout << "<=== MENU ===>" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Tampilkan Seluruh Data Kendaraan" << endl;
        cout << "3. Urutkan Data Kendaraan Berdasarkan Tahun Produksi (Bubble Sort)" << endl;
        cout << "4. Cari Data Kendaraan Berdasarkan Nama Pemilik (Squential Search)" << endl;
        cout << "5. Keluar" << endl;
        cout << "==========================" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            inputdata();
            break;
            case 2:
            tampildata();
            break;
            case 3:
            sorting();
            break;
            case 4:
            searching();
            break;
            case 5:
            cout << "Terima Kasih Sudah Menggunakan Program!" << endl;
            break;
            default:
            cout << "Pilihan Tidak Valid, Silahkan Pilih Opsi Lain!" << endl;
            break;
        }
    } while (pilihan != 5);
    return 0;
}

void inputdata() {
    cout << "Masukkan Jumlah Data Kendaraan: ";
    cin >> jumlahdata;

    for (int i = 0; i < jumlahdata; i++) {
        cout << "Data Kendaraan Ke- " << i + 1 << endl;
        cout << "=====================" << endl;
        cout << "Nama Pemilik Kendaraan: ";
        cin >> kendaraan[i].namapemilik;
        cout << "No Kendaraan: " ;
        cin >> kendaraan[i].nokendaraan;
        cout << "Jenis Kendaraan: ";
        cin >> kendaraan[i].jeniskendaraan;
        cout << "Merk Kendaraan: ";
        cin >> kendaraan[i].merkkendaraan;
        cout << "Model Kendaraan: ";
        cin >> kendaraan[i].modelkendaraan;
        cout << "Tahun Produksi Kendaraan: ";
        cin >> kendaraan[i].tahunproduksi;
    }
}

void tampildata () {
    if (jumlahdata == 0) {
        cout << "Belum Ada Data Kendaraan Yang Terisimpan" << endl;
    } else {
        cout << "Data Kendaraan: " << endl;
        for (int i=0; i < jumlahdata; i++) {
            cout << "=====================" << endl;
            cout << "Data Kendaraan Ke-" << i + 1 << ": " << endl;
            cout << "Nama Pemilik Kendaraan: " << kendaraan[i].namapemilik << endl;
            cout << "No Kendaraan: " << kendaraan[i].nokendaraan << endl;
            cout << "Jenis Kendaraan: " << kendaraan[i].jeniskendaraan << endl;
            cout << "Merk Kendaraan: " << kendaraan[i].merkkendaraan << endl;
            cout << "Model Kendaraan: " << kendaraan[i].modelkendaraan << endl;
            cout << "Tahun Produksi Kendaraan: " << kendaraan[i].tahunproduksi << endl;
        }
    }
}

void sorting() {
    bool swapped;
    for (int i = 0; i < jumlahdata - 1; i++) {
        swapped = false;
        for (int j = 0; j < jumlahdata - i - 1; j++) {
            if (kendaraan[j].tahunproduksi > kendaraan[j + 1].tahunproduksi) {
                swap(kendaraan[j], kendaraan[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "Data berhasil diurutkan berdasarkan tahun produksi." << endl;
}


void searching() {
    string nama;
    cout << "Masukkan Nama Pemilik Kendaraan Yang Ingin Dicari: ";
    cin >> nama;
    bool ditemukan = false;

    for (int i = 0; i < jumlahdata; i++) {
        if (kendaraan[i].namapemilik == nama) {
            cout << "=====================" << endl;
            cout << "Data Kendaraan Ditemukan: " << endl;
            cout << "Nama Pemilik Kendaraan: " << kendaraan[i].namapemilik << endl;
            cout << "No Kendaraan: " << kendaraan[i].nokendaraan << endl;
            cout << "Jenis Kendaraan: " << kendaraan[i].jeniskendaraan << endl;
            cout << "Merk Kendaraan: " << kendaraan[i].merkkendaraan << endl;
            cout << "Model Kendaraan: " << kendaraan[i].modelkendaraan << endl;
            cout << "Tahun Produksi Kendaraan: " << kendaraan[i].tahunproduksi << endl;
            ditemukan = true;
            break;
        }
    }if (!ditemukan) {
        cout << "Data Kendaraan Dengan Nama Pemilik: " << nama << "Tidak Ditemukan" << endl;
    }
}

