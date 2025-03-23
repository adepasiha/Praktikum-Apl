#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SONGS = 100; // Maksimal jumlah lagu
const int MAX_USERS = 100; // Maksimal jumlah pengguna

// Struktur untuk menyimpan informasi lagu
struct Song {
    string title;  // Judul lagu
    string artist; // Nama artis
};

// Struktur untuk menyimpan informasi pengguna
struct User {
    string username; // Nama pengguna
    string nim;      // Nomor Induk Mahasiswa
    int isAdmin;     // Menandakan apakah pengguna adalah admin (1 untuk admin, 0 untuk pengguna biasa)
};

int main() {
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

    // Menambahkan tiga array satu dimensi untuk genre, tahun rilis, dan durasi
    string genres[MAX_SONGS] = {
        "Pop", "Dance", "Rock", "Pop", "Rock", "Pop", "Pop", "Rock", "Alternative"
    };
    int releaseYears[MAX_SONGS] = {
        2020, 1999, 2000, 2001, 1999, 2017, 2004, 2000, 2000
    };
    int durations[MAX_SONGS] = {
        210, 180, 240, 200, 220, 210, 240, 180, 210
    };

    int songCount = 9; // Jumlah lagu yang sudah ada
    int userCount = 0; // Jumlah pengguna terdaftar
    User users[MAX_USERS]; // Array untuk menyimpan pengguna

    // Proses pendaftaran pengguna
    char registerChoice;
    cout << "Apakah Anda ingin mendaftar? (y/n): ";
    cin >> registerChoice;
    cin.ignore(); // Mengabaikan newline dari input sebelumnya

    while (registerChoice == 'y' && userCount < MAX_USERS) {
        cout << "Masukkan Username: ";
        getline(cin, users[userCount].username);
        cout << "Masukkan NIM: ";
        getline(cin, users[userCount].nim);
        
        // Menentukan apakah pengguna adalah admin
        if (users[userCount].username == "adeganteng" && users[userCount].nim == "109") {
            users[userCount].isAdmin = 1; // Admin
        } else {
            users[userCount].isAdmin = 0; // Pengguna biasa
        }
        
        userCount++;
        cout << "Pendaftaran berhasil! Pengguna terdaftar: " << users[userCount - 1].username << endl;
        cout << "Apakah Anda ingin mendaftar pengguna lain? (y/n): ";
        cin >> registerChoice;
        cin.ignore(); // Mengabaikan newline dari input sebelumnya
    }

    // Proses login
    string username, nim;
    int loginAttempts = 0;
    const int MAX_ATTEMPTS = 3; // Maksimal percobaan login
    int isLoggedIn = 0; // Menandakan apakah pengguna berhasil login
    int isAdmin = 0; // Menandakan apakah pengguna adalah admin

    // Loop untuk login
    while (loginAttempts < MAX_ATTEMPTS) {
        cout << "\n=== Login ===" << endl;
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        // Validasi login
        for (int i = 0; i < userCount; i++) {
            if (users[i].username == username && users[i].nim == nim) {
                cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
                isLoggedIn = 1; // Login berhasil
                isAdmin = users[i].isAdmin; // Menentukan apakah pengguna adalah admin
                break;
            }
        }

        if (isLoggedIn == 1) {
            break; // Keluar dari loop jika login berhasil
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

    // Menampilkan menu
    int opsi = 0; // Pilihan menu
    while (opsi != 5) {
        cout << "\n=== Menu Playlist ===" << endl;
        if (isAdmin == 1) {
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
            if (isAdmin == 1) {
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
            if (isAdmin == 1) {
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
            if (isAdmin == 1) {
                int indexToEdit;
                cout << "Masukkan nomor lagu yang ingin diubah (1-" << songCount << "): ";
                cin >> indexToEdit;
                if (indexToEdit > 0 && indexToEdit <= songCount) {
                    cout << "Masukkan Judul Baru: ";
                    cin.ignore(); // Mengabaikan newline dari input sebelumnya
                    getline(cin, songs[indexToEdit - 1].title);
                    cout << "Masukkan Nama Artis Baru: ";
                    getline(cin, songs[indexToEdit - 1].artist);
                    
                    // Mengubah genre, tahun rilis, dan durasiy
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
