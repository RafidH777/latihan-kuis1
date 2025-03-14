#include <iostream>
#include <cstring>
using namespace std;

struct penduduk
{
    char NIK[20];
    char nama[20];
    char alamat[20];
    char jenis_kelamin[10];
}; 

penduduk data[100];
int jumlah_data = 0;
int jumlah_input;

void simpan_kefile() {
    FILE *ptr = fopen("data.txt", "a");
    if (ptr == NULL) {
        cout << "Gagal membuka file" << endl;
        return;
    }
    for (int i = 0; i < jumlah_data; i++) {
        fprintf(ptr, "%s\n%s\n%s\n%s\n", data[i].NIK, data[i].nama, data[i].alamat, data[i].jenis_kelamin);
    }
    fclose(ptr);    
}

void simpan_data_edit() {
    FILE *ptr = fopen("data.txt", "w");
    if (ptr == NULL) {
        cout << "Gagal membuka file" << endl;
        return;
    }
    for (int i = 0; i < jumlah_data; i++) {
        fprintf(ptr, "%s\n%s\n%s\n%s\n", data[i].NIK, data[i].nama, data[i].alamat, data[i].jenis_kelamin);
    }
    fclose(ptr);
}

void baca_file() {
    FILE *ptr = fopen("data.txt", "r");
    if (ptr == NULL) {
        cout << "Gagal membuka file" << endl;
        return;
    }
    jumlah_data = 0;
    while (fscanf(ptr, " %[^\n] %[^\n] %[^\n] %[^\n]", data[jumlah_data].NIK, data[jumlah_data].nama, data[jumlah_data].alamat, data[jumlah_data].jenis_kelamin) != EOF) {
        jumlah_data++;
    }  
    fclose(ptr);
}

void inputData() {
    int jumlah_input;
    cout << "INPUT DATA" << endl;
    cout << "Berapa data yang ingin di Input? : ";
    cin >> jumlah_input;
    for (int i = 0; i < jumlah_input; i++) {
        cin.ignore();
        cout << "NIK           : "; cin.getline(data[jumlah_data + i].NIK, 20);
        cout << "Nama          : "; cin.getline(data[jumlah_data + i].nama, 20);
        cout << "Alamat        : "; cin.getline(data[jumlah_data + i].alamat, 20);
        cout << "Jenis Kelamin : "; cin.getline(data[jumlah_data + i].jenis_kelamin, 10);
    }
    jumlah_data += jumlah_input;
    simpan_kefile();
}

void bubblesort() {
    for (int i = 0; i < jumlah_data - 1; i++) {
        for (int j = 0; j < jumlah_data - i - 1; j++) {
            if (strcmp(data[j].NIK, data[j + 1].NIK) > 0) {
                penduduk temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
}

void ouput() {
    cout << "TAMPILAN DATA" << endl;
    if (jumlah_data == 0) {
        cout << "Data belum ada" << endl;
        return;
    }
    bubblesort();
    cout << "NIK\t Nama\tAlamat\tJenis Kelamin" << endl;
    for (int i = 0; i < jumlah_data; i++) {
        cout << data[i].NIK << "\t" << data[i].nama << "\t" << data[i].alamat << "\t" << data[i].jenis_kelamin << endl;
    }
}

void searchData() {
    char cari[20];
    bool found = false;
    cout << "CARI DATA" << endl;
    cout << "Masukkan NIK yang ingin dicari : ";
    cin.ignore();
    cin.getline(cari, 20);
    for (int i = 0; i < jumlah_data; i++) {
        if (strcmp(data[i].NIK, cari) == 0) {
            found = true;
            cout << "NIK\t:" << data[i].NIK << endl;
            cout << "Nama\t:" << data[i].nama << endl;
            cout << "Alamat\t:" << data[i].alamat << endl;
            cout << "Jenis Kelamin:" << data[i].jenis_kelamin << endl;
            break; 
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan" << endl;
    }
}
void edit(){
    char cari[20];
    cout << "EDIT DATA" << endl;
    cout << "Masukkan NIK yang ingin diedit : ";
    cin.ignore();
    cin.getline(cari, 20);
    for (int i = 0; i < jumlah_data; i++) {
        if (strcmp(data[i].NIK, cari) == 0) {
            cout << "NIK           : "; cin.getline(data[i].NIK, 20);
            cout << "Nama          : "; cin.getline(data[i].nama, 20);
            cout << "Alamat        : "; cin.getline(data[i].alamat, 20);
            cout << "Jenis Kelamin : "; cin.getline(data[i].jenis_kelamin, 10);
            simpan_data_edit(); 
            cout << "Data berhasil diedit." << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan." << endl;
}
void hapus(){
    char cari[20];
    cout << "HAPUS DATA" << endl;
    cout << "Masukkan NIK yang ingin dihapus : ";
    cin.ignore();
    cin.getline(cari, 20);
    
    bool found = false;
    for (int i = 0; i < jumlah_data; i++) {
        if (strcmp(data[i].NIK, cari) == 0) {
            found = true;
            for (int j = i; j < jumlah_data - 1; j++) {
                data[j] = data[j + 1];
            }
            jumlah_data--; 
            cout << "Data berhasil dihapus." << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    } else {
        simpan_data_edit(); 
    }
}
int main(){
    baca_file();
    int menu;
    do
    {
        cout << "Menu Pilihan" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Output Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            inputData();
            break;
        case 2:
            ouput();
            break;
        case 3:
            searchData();
            break;
        case 4:
            edit();
            break;
        case 5:
            hapus();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    } while (menu != 6);
}