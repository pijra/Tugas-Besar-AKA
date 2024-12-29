#include "aka.h"
#include <chrono> // Untuk mengukur waktu eksekusi
using namespace std;
using namespace std::chrono;

int main() {
    cout << "=== Pertarungan Dimulai ===" << endl;

    // Input data karakter
    Character player = {"Hero", 300, 50, true, false, 40.0};
    Character enemy = {"Enemy", 200, 30, false, true, 40.0};

    // Variabel DoT dan jumlah giliran
    int dotDamage, turns;

    cout << "Pilih metode: " << endl;
    cout << "1. Iteratif" << endl;
    cout << "2. Rekursif" << endl;
    cout << "Masukkan pilihan Anda: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        // Input untuk versi iteratif
        cout << "Masukkan damage DoT: ";
        cin >> dotDamage;
        cout << "Masukkan jumlah giliran: ";
        cin >> turns;

        // Mengukur waktu eksekusi iteratif
        auto start = high_resolution_clock::now();
        applyDoTIterative(enemy, dotDamage, turns);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "\nWaktu eksekusi (Iteratif): " << duration.count() << " ms" << endl;

    } else if (choice == 2) {
        // Input untuk versi rekursif
        cout << "Masukkan damage DoT: ";
        cin >> dotDamage;
        cout << "Masukkan jumlah giliran: ";
        cin >> turns;

        // Mengukur waktu eksekusi rekursif
        auto start = high_resolution_clock::now();
        applyDoTRecursive(enemy, dotDamage, turns);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "\nWaktu eksekusi (Rekursif): " << duration.count() << " ms" << endl;

    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}
