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

// Fungsi login
int login(User* users, int userCount, string username, string nim, int* isAdmin) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].nim == nim) {
            *isAdmin = users[i].isAdmin;
            return 1; // Login berhasil
        }
    }
    return 0; // Login gagal
}

// Swap semua atribut lagu
void swapSongs(Song* songs, string* genres, int* releaseYears, int* durations, int i, int j) {
    Song tempSong = songs[i];
    songs[i] = songs[j];
    songs[j] = tempSong;

    string tempGenre = genres[i];
    genres[i] = genres[j];
    genres[j] = tempGenre;

    int tempYear = releaseYears[i];
    releaseYears[i] = releaseYears[j];
    releaseYears[j] = tempYear;

    int tempDuration = durations[i];
    durations[i] = durations[j];
    durations[j] = tempDuration;
}

// Tampilkan lagu secara rekursif
void tampilkanLaguRekursif(Song* songs, string* genres, int* releaseYears, int* durations, int index, int total) {
    if (index >= total) return;
    cout << left << setw(30) << songs[index].title
         << setw(30) << songs[index].artist
         << setw(20) << genres[index]
         << setw(15) << releaseYears[index]
         << setw(10) << durations[index] << endl;
    tampilkanLaguRekursif(songs, genres, releaseYears, durations, index + 1, total);
}

void tampilkanSemuaLagu(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    cout << "\n=== Daftar Lagu ===" << endl;
    cout << left << setw(30) << "Judul" << setw(30) << "Artis" << setw(20) << "Genre" << setw(15) << "Tahun" << setw(10) << "Durasi" << endl;
    cout << string(105, '-') << endl;
    tampilkanLaguRekursif(songs, genres, releaseYears, durations, 0, songCount);
}

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

        *songCount += 1;
        cout << "Lagu berhasil ditambahkan!!!" << endl;
    } else {
        cout << "Playlist sudah penuh!!!" << endl;
    }
}

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
        *songCount -= 1;
        cout << "Lagu berhasil dihapus!" << endl;
    } else {
        cout << "Nomor lagu tidak valid!" << endl;
    }
}

void ubahLagu(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    int indexToEdit;
    cout << "Masukkan nomor lagu yang ingin diubah (1-" << songCount << "): ";
    cin >> indexToEdit;
    if (indexToEdit > 0 && indexToEdit <= songCount) {
        cin.ignore();
        cout << "Masukkan Judul Baru: ";
        getline(cin, songs[indexToEdit - 1].title);
        cout << "Masukkan Artis Baru: ";
        getline(cin, songs[indexToEdit - 1].artist);
        cout << "Masukkan Genre Baru: ";
        getline(cin, genres[indexToEdit - 1]);
        cout << "Masukkan Tahun Rilis Baru: ";
        cin >> releaseYears[indexToEdit - 1];
        cout << "Masukkan Durasi Baru (detik): ";
        cin >> durations[indexToEdit - 1];
        cout << "Lagu berhasil diubah!" << endl;
    } else {
        cout << "Nomor lagu tidak valid!" << endl;
    }
}

// Sorting
void bubbleSortTitleAsc(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    for (int i = 0; i < songCount - 1; i++) {
        for (int j = 0; j < songCount - i - 1; j++) {
            if (songs[j].title > songs[j + 1].title) {
                swapSongs(songs, genres, releaseYears, durations, j, j + 1);
            }
        }
    }
}

void selectionSortYearDesc(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    for (int i = 0; i < songCount - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < songCount; j++) {
            if (releaseYears[j] > releaseYears[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swapSongs(songs, genres, releaseYears, durations, i, maxIdx);
        }
    }
}

void insertionSortDurationAsc(Song* songs, string* genres, int* releaseYears, int* durations, int songCount) {
    for (int i = 1; i < songCount; i++) {
        Song keySong = songs[i];
        string keyGenre = genres[i];
        int keyYear = releaseYears[i];
        int keyDuration = durations[i];
        int j = i - 1;

        while (j >= 0 && durations[j] > keyDuration) {
            songs[j + 1] = songs[j];
            genres[j + 1] = genres[j];
            releaseYears[j + 1] = releaseYears[j];
            durations[j + 1] = durations[j];
            j--;
        }
        songs[j + 1] = keySong;
        genres[j + 1] = keyGenre;
        releaseYears[j + 1] = keyYear;
        durations[j + 1] = keyDuration;
    }
}

int main() {
    Song songs[MAX_SONGS] = {
        {"Kaulah hatiku", "Pashmina"}, {"Blue", "Eiffel 65"}, {"Sempurna", "Gigi"},
        {"Pica Pica", "Krisdayanti"}, {"Kangen", "Dewa 19"}, {"Cold", "Maroon 5"},
        {"Cry", "James Blunt"}, {"December", "Gigi"}, {"Yellow", "ColdPlay"},
    };

    string genres[MAX_SONGS] = {"Pop", "Dance", "Rock", "Pop", "Rock", "Pop", "Pop", "Rock", "Alternative"};
    int releaseYears[MAX_SONGS] = {2020, 1999, 2000, 2001, 1999, 2017, 2004, 2000, 2000};
    int durations[MAX_SONGS] = {210, 180, 240, 200, 220, 210, 240, 180, 210};

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
        userCount++;
        cout << "Pendaftaran berhasil!" << endl;
        cout << "Apakah Anda ingin mendaftar lagi? (y/n): ";
        cin >> registerChoice;
        cin.ignore();
    }

    string username, nim;
    int isAdmin = 0, isLoggedIn = 0;
    int loginAttempts = 0;

    while (loginAttempts < 3) {
        cout << "\n=== Login ===" << endl;
        cout << "Username: "; getline(cin, username);
        cout << "NIM: "; getline(cin, nim);

        if (login(users, userCount, username, nim, &isAdmin)) {
            cout << "Login berhasil, selamat datang " << username << "!" << endl;
            isLoggedIn = 1;
            break;
        } else {
            cout << "Username atau NIM salah." << endl;
            loginAttempts++;
        }
    }

    if (!isLoggedIn) {
        cout << "Gagal login 3x. Program berhenti." << endl;
        return 0;
    }

    int opsi = 0;
    while (opsi != 6) {
        cout << "\n=== Menu Playlist ===" << endl;
        if (isAdmin) {
            cout << "1. Tambah Lagu\n";
        }
        cout << "2. Tampilkan Semua Lagu\n";
        if (isAdmin) {
            cout << "3. Hapus Lagu\n";
            cout << "4. Ubah Lagu\n";
        }
        cout << "5. Urutkan Lagu\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> opsi;

        if (opsi == 1 && isAdmin) tambahLagu(songs, genres, releaseYears, durations, &songCount);
        else if (opsi == 2) tampilkanSemuaLagu(songs, genres, releaseYears, durations, songCount);
        else if (opsi == 3 && isAdmin) hapusLagu(songs, genres, releaseYears, durations, &songCount);
        else if (opsi == 4 && isAdmin) ubahLagu(songs, genres, releaseYears, durations, songCount);
        else if (opsi == 5) {
            int sortChoice;
            cout << "\n=== Menu Urutkan Lagu ===" << endl;
            cout << "1. Urutkan berdasarkan Judul (Ascending)\n";
            cout << "2. Urutkan berdasarkan Tahun (Descending)\n";
            cout << "3. Urutkan berdasarkan Durasi (Ascending)\n";
            cout << "Pilihan: ";
            cin >> sortChoice;
            if (sortChoice == 1) bubbleSortTitleAsc(songs, genres, releaseYears, durations, songCount);
            else if (sortChoice == 2) selectionSortYearDesc(songs, genres, releaseYears, durations, songCount);
            else if (sortChoice == 3) insertionSortDurationAsc(songs, genres, releaseYears, durations, songCount);
            tampilkanSemuaLagu(songs, genres, releaseYears, durations, songCount);
        }
        else if (opsi == 6) cout << "Terima kasih! Program selesai." << endl;
        else cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}