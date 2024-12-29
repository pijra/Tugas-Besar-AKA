#include "aka.h"

// Fungsi untuk menghitung damage berdasarkan status
int calculateDamage(Character& attacker, Character& target) {
    int damage = attacker.atk;

    // Buff meningkatkan damage
    if (attacker.isBuffed) {
        damage = damage * 1.5;
    }

    // Debuff meningkatkan damage yang diterima target
    if (target.isDebuffed) {
        damage = damage * 1.2;
    }

    return damage;
}

// Fungsi untuk melaksanakan serangan
void attack(Character& attacker, Character& target) {
    int damage = calculateDamage(attacker, target);
    target.hp -= damage;

    cout << attacker.name << " menyerang " << target.name << " dengan damage " << damage << "!" << endl;
    if (target.hp <= 0) {
        cout << target.name << " telah dikalahkan!" << endl;
    }
}

// Fungsi iteratif untuk memberikan DoT
void applyDoTIterative(Character& target, int dotDamage, int turns) {
    for (int i = 1; i <= turns && target.hp > 0; ++i) {
        int effectiveDamage = dotDamage * (1.0 - target.resistDoT / 100.0);
        target.hp -= effectiveDamage;

        cout << "[Iterasi] Turn " << i << ": " << target.name << " menerima DoT sebesar "
             << effectiveDamage << " (resistensi " << target.resistDoT << "%). HP sekarang: " << target.hp << endl;

        target.resistDoT += 1.0; // Tambahkan resistensi
        if (target.resistDoT > 100.0) target.resistDoT = 100.0;

        if (target.hp <= 0) {
            cout << target.name << " telah dikalahkan oleh DoT!" << endl;
            break;
        }
    }
}

// Fungsi rekursif untuk memberikan DoT
void applyDoTRecursive(Character& target, int dotDamage, int turns) {
    if (turns == 0 || target.hp <= 0) {
        return; // Basis rekursi: jika tidak ada giliran tersisa atau target mati
    }

    int effectiveDamage = dotDamage * (1.0 - target.resistDoT / 100.0);
    target.hp -= effectiveDamage;

    cout << "[Rekursif] Turn " << turns << ": " << target.name << " menerima DoT sebesar "
         << effectiveDamage << " (resistensi " << target.resistDoT << "%). HP sekarang: " << target.hp << endl;

    target.resistDoT += 1.0; // Tambahkan resistensi
    if (target.resistDoT > 100.0) target.resistDoT = 100.0;

    if (target.hp <= 0) {
        cout << target.name << " telah dikalahkan oleh DoT!" << endl;
        return;
    }

    // Rekursi ke giliran berikutnya
    applyDoTRecursive(target, dotDamage, turns - 1);
}
