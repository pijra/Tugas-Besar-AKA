#ifndef AKA_H
#define AKA_H

#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk karakter
struct Character {
    string name;
    int hp;      // Health Points
    int atk;     // Attack Points
    bool isBuffed;   // Status Buff
    bool isDebuffed; // Status Debuff
    float resistDoT; // Resistensi terhadap Damage Over Time (dalam persen)
};

// Fungsi untuk menghitung damage
int calculateDamage(Character& attacker, Character& target);

// Fungsi untuk melaksanakan serangan
void attack(Character& attacker, Character& target);

// Fungsi iteratif untuk memberikan DoT
void applyDoTIterative(Character& target, int dotDamage, int turns);

// Fungsi rekursif untuk memberikan DoT
void applyDoTRecursive(Character& target, int dotDamage, int turns);

#endif
