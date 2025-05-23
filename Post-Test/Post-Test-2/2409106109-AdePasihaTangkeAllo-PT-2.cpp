#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SONGS = 100; // Maksimal jumlah lagu

// Struktur untuk menyimpan informasi lagu
struct Song {
    string title;  // Judul lagu
    string artist; // Nama artis
};

int main() {
    string username, nim;
    int loginAttempts = 0;
    const int MAX_ATTEMPTS = 3; // Maksimal percobaan login
    bool isAdmin = false; // Menandakan apakah pengguna adalah admin

    // Menampilkan pilihan login
    cout << "=== Pilihan Login ===" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai Pengguna" << endl;
    cout << "Pilih jenis login (1/2): ";
    int loginChoice;
    cin >> loginChoice;

    // Proses login
    while (loginAttempts < MAX_ATTEMPTS) {
        cout << "Masukkan Username: ";
        cin.ignore(); // Mengabaikan newline dari input sebelumnya
        getline(cin, username); // Menggunakan getline untuk username
        cout << "Masukkan NIM: ";
        cin >> nim;

        // Validasi login
        if (loginChoice == 1 && username == "adeganteng" && nim == "109") {
            cout << "Login sebagai Admin berhasil!" << endl;
            isAdmin = true; // Menandakan bahwa pengguna adalah admin
            break;
        } else if (loginChoice == 2) {
            cout << "Login sebagai Pengguna berhasil!" << endl;
            break; // Pengguna biasa dapat login dengan username dan NIM apa saja
        } else {
            cout << "Username atau NIM salah. Coba lagi." << endl;
            loginAttempts++;
        }
    }

    // Jika terlalu banyak percobaan login
    if (loginAttempts == MAX_ATTEMPTS) {
        cout << "Terlalu banyak percobaan. Program dihentikan." << endl;
        return 0;
    }

    // Daftar lagu awal
    Song songs[MAX_SONGS] = {
        {"Kaulah hatiku", "Pashmina"},
        {"Blue", "Eiffel 65"},
        {"Sempurna", "Gigi"},
        {"Pica Pica", "Krisdayanti"},
        {"Kangen", "Dewa 19"},
        {"Cold", "Maroon 5"},
        {"Cry", "James Blunt"},
        {"December", "Gigi"},
        {"Yellow", "ColdPlay"},
    };
    
    // Menambahkan tiga array satu dimensi
    string genres[MAX_SONGS] = {
        "Pop", "Dance", "Rock", "Pop", "Rock", "Pop", "Pop", "Rock", "Alternative"
    };
    int releaseYears[MAX_SONGS] = {
        2020, 1999, 2000, 2001, 1999, 2017, 2004, 2000, 2000
    };
    int durations[MAX_SONGS] = {
        210, 180, 240, 200, 220, 210, 240, 180, 210
    };

    int songCount = 8; // Jumlah lagu yang sudah ada
    int opsi = 0; // Pilihan menu

    // Menampilkan menu
    while (opsi != 5) {
        cout << "\n=== Menu Playlist ===" << endl;
        if (isAdmin) {
            cout << "1. Tambah Lagu" << endl;
            cout << "2. Tampilkan Semua Lagu" << endl;
            cout << "3. Hapus Lagu" << endl;
            cout << "4. Ubah Lagu" << endl;
        } else {
            cout << "2. Tampilkan Semua Lagu" << endl; // Pengguna hanya bisa melihat
        }
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> opsi;

        // Menangani pilihan menu
        if (opsi == 1) { // Tambah Lagu (hanya untuk admin)
            if (isAdmin) {
                if (songCount < MAX_SONGS) {
                    cout << "Masukkan Judul Lagu: ";
                    cin.ignore(); // Mengabaikan newline dari input sebelumnya
                    getline(cin, songs[songCount].title);
                    cout << "Masukkan Nama Artis: ";
                    getline(cin, songs[songCount].artist);
                    
                    // Menambahkan input untuk genre, tahun rilis, dan durasi
                    cout << "Masukkan Genre: ";
                    getline(cin, genres[songCount]);
                    cout << "Masukkan Tahun Rilis: ";
                    cin >> releaseYears[songCount];
                    cout << "Masukkan Durasi (dalam detik): ";
                    cin >> durations[songCount];
                    
                    songCount++;
                    cout << "Lagu berhasil ditambahkan!" << endl;
                } else {
                    cout << "Playlist sudah penuh!" << endl;
                }
            } else {
                cout << "Akses ditolak! Hanya admin yang dapat menambah lagu." << endl;
            }
        } else if (opsi == 2) { // Tampilkan Semua Lagu
            cout << "\n=== Daftar Lagu ===" << endl;
            cout << left << setw(30) << "Judul" << setw(30) << "Artis" << setw(20) << "Genre" << setw(15) << "Tahun" << setw(10) << "Durasi" << endl;
            cout << string(105, '-') << endl;
            for (int i = 0; i < songCount; i++) {
                cout << left << setw(30) << songs[i].title 
                     << setw(30) << songs[i].artist 
                     << setw(20) << genres[i] 
                     << setw(15) << releaseYears[i] 
                     << setw(10) << durations[i] << endl;
            }
        } else if (opsi == 3) { // Hapus Lagu (hanya untuk admin)
            if (isAdmin) {
                int indexToDelete;
                cout << "Masukkan nomor lagu yang ingin dihapus (1-" << songCount << "): ";
                cin >> indexToDelete;
                if (indexToDelete > 0 && indexToDelete <= songCount) {
                    for (int i = indexToDelete - 1; i < songCount - 1; i++) {
                        songs[i] = songs[i + 1];
                        genres[i] = genres[i + 1];
                        releaseYears[i] = releaseYears[i + 1];
                        durations[i] = durations[i + 1];
                    }
                    songCount--;
                    cout << "Lagu berhasil dihapus!" << endl;
                } else {
                    cout << "Nomor lagu tidak valid!" << endl;
                }
            } else {
                cout << "Akses ditolak! Hanya admin yang dapat menghapus lagu." << endl;
            }
        } else if (opsi == 4) { // Ubah Lagu (hanya untuk admin)
            if (isAdmin) {
                int indexToEdit;
                cout << "Masukkan nomor lagu yang ingin diubah (1-" << songCount << "): ";
                cin >> indexToEdit;
                if (indexToEdit > 0 && indexToEdit <= songCount) {
                    cout << "Masukkan Judul Baru: ";
                    cin.ignore(); // Mengabaikan newline dari input sebelumnya
                    getline(cin, songs[indexToEdit - 1].title);
                    cout << "Masukkan Nama Artis Baru: ";
                    getline(cin, songs[indexToEdit - 1].artist);
                    
                    // Mengubah genre, tahun rilis, dan durasi
                    cout << "Masukkan Genre Baru: ";
                    getline(cin, genres[indexToEdit - 1]);
                    cout << "Masukkan Tahun Rilis Baru: ";
                    cin >> releaseYears[indexToEdit - 1];
                    cout << "Masukkan Durasi Baru (dalam detik): ";
                    cin >> durations[indexToEdit - 1];
                    
                    cout << "Lagu berhasil diubah!" << endl;
                } else {
                    cout << "Nomor lagu tidak valid!" << endl;
                }
            } else {
                cout << "Akses ditolak! Hanya admin yang dapat mengubah lagu." << endl;
            }
        } else if (opsi == 5) { // Keluar
            cout << "Terima kasih! Program dihentikan." << endl;
        } else { // Pilihan tidak valid
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    }

    return 0;
}