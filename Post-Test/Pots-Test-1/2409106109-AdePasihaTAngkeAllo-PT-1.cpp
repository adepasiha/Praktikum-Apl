#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengecek apakah bilangan adalah prima
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Fungsi untuk mengecek apakah bilangan memenuhi syarat habis dibagi 2 dan 3 tetapi tidak oleh 5
bool isDivisible(int num) {
    return (num % 2 == 0 && num % 3 == 0 && num % 5 != 0);
}

int main() {
    string username, password;
    int code;
    
    // Login
    cout << "Masukkan Username: ";
    getline(cin, username);
    cout << "Masukkan Password (NIM): ";
    getline(cin, password);
    
    if (username != "AdePasihaTangkeAllo" || password != "2409106109") {
        cout << "Login gagal! Username atau password salah." << endl;
        return 0;
    }
    
    while (true) {
        cout << "\nMasukkan kode sandi (antara 100 dan 99999): ";
        cin >> code;
        
        if (code < 100 || code > 99999) {
            cout << "Kode sandi tidak valid! Harus antara 100 dan 99999." << endl;
            continue;
        }
        
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Cek apakah kode sandi adalah bilangan prima" << endl;
            cout << "2. Cek apakah kode sandi habis dibagi 2 dan 3 tetapi tidak oleh 5" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilih opsi: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    if (isPrime(code))
                        cout << "Kode sandi adalah bilangan prima." << endl;
                    else
                        cout << "Kode sandi bukan bilangan prima." << endl;
                    break;
                case 2:
                    if (isDivisible(code))
                        cout << "Kode sandi memenuhi syarat habis dibagi 2 dan 3 tetapi tidak oleh 5." << endl;
                    else
                        cout << "Kode sandi tidak memenuhi syarat tersebut." << endl;
                    break;
                case 3:
                    cout << "Program berhenti." << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
        } while (true);
    }
    return 0;
}

// /Ade ganteng
