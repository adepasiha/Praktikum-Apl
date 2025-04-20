#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SONGS = 100;
const int MAX_USERS = 100;

struct Song {
    string title;
    string artist;
};

struct User {
    string username;
    string nim;
    int isAdmin;
};

// Prosedur untuk menampilkan lagu secara rekursif dengan pointer
    void tampilkanLaguRekursif(Song* songs, string* genres, int* releaseYears, int* durations, int index, int total) {
        if (index >= total) return;
        cout << left << setw(30) << songs[index].title
            << setw(30) << songs[index].artist
            << setw(20) << genres[index]
            << setw(15) << releaseYears[index]
            << setw(10) << durations[index] << endl;
        tampilkanLaguRekursif(songs, genres, releaseYears, durations, index + 1, total);
    }

// Prosedur untuk menampilkan semua lagu
void tampilkanSemuaLagu(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    cout << "\n=== Daftar Lagu ===" << endl;
    cout << left << setw(30) << "Judul" << setw(30) << "Artis" << setw(20) << "Genre" << setw(15) << "Tahun" << setw(10) << "Durasi" << endl;
    cout << string(105, '-') << endl;
    tampilkanLaguRekursif(songs, genres, releaseYears, durations, 0, songCount); // Gunakan rekursi
}

// Prosedur untuk menambah lagu dengan pointer untuk songCount
void tambahLagu(Song* songs, string* genres, int* releaseYears, int* durations, int* songCount) {
    if (*songCount < MAX_SONGS) {
        cout << "Masukkan Judul Lagu: ";
        cin.ignore();
        getline(cin, songs[*songCount].title);
        cout << "Masukkan Nama Artis: ";
        getline(cin, songs[*songCount].artist);
        cout << "Masukkan Genre: ";
        getline(cin, genres[*songCount]);
        cout << "Masukkan Tahun Rilis: ";
        cin >> releaseYears[*songCount];
        cout << "Masukkan Durasi (dalam detik): ";
        cin >> durations[*songCount];

        *songCount = *songCount + 1;
        cout << "Lagu berhasil ditambahkan!!!" << endl;
    } else {
        cout << "Playlist sudah penuh!!!" << endl;
    }
}

// Prosedur untuk menghapus lagu dengan pointer untuk songCount
void hapusLagu(Song* songs, string* genres, int* releaseYears, int* durations, int* songCount) {
    int indexToDelete;
    cout << "Masukkan nomor lagu yang ingin dihapus (1-" << *songCount << "): ";
    cin >> indexToDelete;
    if (indexToDelete > 0 && indexToDelete <= *songCount) {
        for (int i = indexToDelete - 1; i < *songCount - 1; i++) {
            songs[i] = songs[i + 1];
            genres[i] = genres[i + 1];
            releaseYears[i] = releaseYears[i + 1];
            durations[i] = durations[i + 1];
        }
        *songCount = *songCount - 1;
        cout << "Lagu berhasil dihapus!" << endl;
    } else {
        cout << "Nomor lagu tidak valid!" << endl;
    }
}

// Prosedur untuk mengubah lagu dengan pointer
void ubahLagu(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    int indexToEdit;
    cout << "Masukkan nomor lagu yang ingin diubah (1-" << songCount << "): ";
    cin >> indexToEdit;
    if (indexToEdit > 0 && indexToEdit <= songCount) {
        cin.ignore();
        cout << "Masukkan Judul Baru: ";
        getline(cin, songs[indexToEdit - 1].title);
        cout << "Masukkan Nama Artis Baru: ";
        getline(cin, songs[indexToEdit - 1].artist);
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
}

// Fungsi login dengan pointer untuk isAdmin, tanpa bool
int login(User* users, int userCount, string username, string nim, int* isAdmin) {
    int i;
    for (i = 0; i < userCount; i = i + 1) {
        if (users[i].username == username && users[i].nim == nim) {
            *isAdmin = users[i].isAdmin;
            return 1; // berhasil login
        }
    }
    return 0; // gagal login
}

int main() {
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

    string genres[MAX_SONGS] = {
        "Pop", "Dance", "Rock", "Pop", "Rock", "Pop", "Pop", "Rock", "Alternative"
    };
    int releaseYears[MAX_SONGS] = {
        2020, 1999, 2000, 2001, 1999, 2017, 2004, 2000, 2000
    };
    int durations[MAX_SONGS] = {
        210, 180, 240, 200, 220, 210, 240, 180, 210
    };

    int songCount = 9;
    int userCount = 0;
    User users[MAX_USERS];

    char registerChoice;
    cout << "Apakah Anda ingin mendaftar? (y/n): ";
    cin >> registerChoice;
    cin.ignore();

    while (registerChoice == 'y' && userCount < MAX_USERS) {
        cout << "Masukkan Username: ";
        getline(cin, users[userCount].username);
        cout << "Masukkan NIM: ";
        getline(cin, users[userCount].nim);
        if (users[userCount].username == "adeganteng" && users[userCount].nim == "109") {
            users[userCount].isAdmin = 1;
        } else {
            users[userCount].isAdmin = 0;
        }
        userCount = userCount + 1;
        cout << "Pendaftaran berhasil! Pengguna terdaftar: " << users[userCount - 1].username << endl;
        cout << "Apakah Anda ingin mendaftar pengguna lain? (y/n): ";
        cin >> registerChoice;
        cin.ignore();
    }

    string username, nim;
    int loginAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    int isAdmin = 0;
    int isLoggedIn = 0;

        while (loginAttempts < MAX_ATTEMPTS) {
            cout << "\n=== Login ===" << endl;
            cout << "Masukkan Username: ";
            getline(cin, username);
            cout << "Masukkan NIM: ";
            getline(cin, nim);

            if (login(users, userCount, username, nim, &isAdmin) == 1) {
                cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
                isLoggedIn = 1;
                break;
            } else {
                cout << "Username atau NIM salah. Coba lagi." << endl;
                loginAttempts = loginAttempts + 1;
            }
        }

        if (isLoggedIn == 0) {
            cout << "Terlalu banyak percobaan. Program dihentikan." << endl;
            return 0;
        }

    int opsi = 0;
    while (opsi != 5) {
        cout << "\n=== Menu Playlist ===" << endl;
        if (isAdmin == 1) {
            cout << "1. Tambah Lagu" << endl;
            cout << "2. Tampilkan Semua Lagu" << endl;
            cout << "3. Hapus Lagu" << endl;
            cout << "4. Ubah Lagu" << endl;
        } else {
            cout << "2. Tampilkan Semua Lagu" << endl;
        }
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> opsi;

        if (opsi == 1 && isAdmin == 1) {
            tambahLagu(songs, genres, releaseYears, durations, &songCount);
        } else if (opsi == 2) {
            tampilkanSemuaLagu(songs, genres, releaseYears, durations, songCount);
        } else if (opsi == 3 && isAdmin == 1) {
            hapusLagu(songs, genres, releaseYears, durations, &songCount);
        } else if (opsi == 4 && isAdmin == 1) {
            ubahLagu(songs, genres, releaseYears, durations, songCount);
        } else if (opsi == 5) {
            cout << "Terima kasih! Program dihentikan." << endl;
        } else {
            cout << "Pilihan tidak valid atau Anda tidak memiliki akses!" << endl;
        }
    }

    return 0;
}
