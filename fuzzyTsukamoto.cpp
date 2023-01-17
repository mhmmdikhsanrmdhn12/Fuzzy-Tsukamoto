#include<iostream>
#include<cmath>

using namespace std;

float x, y; // x adalah variable permintaan | y adalah variable persediaan
float miuPermintaanTurun, miuPermintaanNaik; // variable untuk nilai miu x
float miuPersediaanSedikit, miuPersediaanBanyak; // variable untuk nilai miu y
float z1, z2, z3, z4; // variable untuk nilai z1 sampai z4
float aPredikat1, aPredikat2, aPredikat3, aPredikat4; // variable untuk aPredikat1 sampai aPredikat4
int z; // variable untuk nilai z terbobot

void permintaanTurun(){
    if (x <= 1000)
    {
        miuPermintaanTurun = 1;
    }
    else if (x > 1000 && x < 5000)
    {
        miuPermintaanTurun = (5000 - x) / 4000;
    }
    else
    {
        miuPermintaanTurun = 0;
    }
}

void permintaanNaik(){
    if (x <= 1000)
    {
        miuPermintaanNaik = 0;
    }
    else if (x > 1000 && x < 5000)
    {
        miuPermintaanNaik = (x - 1000) / 4000;
    }
    else
    {
        miuPermintaanNaik = 1;
    }
}

void persediaanSedikit(){
    if (y <= 100)
    {
        miuPersediaanSedikit = 1;
    }
    else if (y > 100 && y < 600)
    {
        miuPersediaanSedikit = (600 - y) / 500;
    }
    else
    {
        miuPersediaanSedikit = 0;
    }
}

void persediaanBanyak(){
    if (y <= 100)
    {
        miuPersediaanBanyak = 0;
    }
    else if (y > 100 && y < 600)
    {
        miuPersediaanBanyak = (y - 100) / 500;
    }
    else
    {
        miuPersediaanBanyak = 1;
    }
}

void fuzzyFication(){
    permintaanTurun();
    permintaanNaik();
    persediaanSedikit();
    persediaanBanyak();
}

void rule1(){
    aPredikat1 = fmin(miuPermintaanTurun, miuPersediaanBanyak);

    z1 = 7000 - (aPredikat1 * 5000);
}

void rule2(){
    aPredikat2 = fmin(miuPermintaanTurun, miuPersediaanSedikit);

    z2 = 7000 - (aPredikat2 * 5000);
}

void rule3(){
    aPredikat3 = fmin(miuPermintaanNaik, miuPersediaanBanyak);

    z3 = 2000 + (aPredikat3 * 5000);
}

void rule4(){
    aPredikat4 = fmin(miuPermintaanNaik, miuPersediaanSedikit);

    z4 = 2000 + (aPredikat4 * 5000);
}

void inferensi(){
    rule1();
    rule2();
    rule3();
    rule4();
}

void deFuzzyFikasi(){
    z = ((aPredikat1 * z1) + (aPredikat2 * z2) + (aPredikat3 * z3) + (aPredikat4 * z4)) / (aPredikat1 + aPredikat2 + aPredikat3 + aPredikat4);
}

int main(){
    cout << "Masukkan permintaan = ";
    cin >> x;
    cout << "Masukkan persediaan = ";
    cin >> y;
    fuzzyFication();
    cout << "\nPermintaan Turun = " << miuPermintaanTurun << endl;
    cout << "Permintaan Naik = " << miuPermintaanNaik << endl;
    cout << "persediaan Sedikit = " << miuPersediaanSedikit << endl;
    cout << "persediaan Banyak = " << miuPersediaanBanyak << endl;
    inferensi();
    cout << "\nz1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << "z3 = " << z3 << endl;
    cout << "z4 = " << z4 << endl;
    deFuzzyFikasi();
    cout << "\nJumlah makanan kaleng yang harus di produksi = " << z << endl;
}