/*
Nama (npm)  : - Ade Dwi Fatwa Sembiring  (140810200044)
PROGRAM SIFT CIPHER
20 Sept 2022
*/

#include <iostream>

using namespace std;

// SHIFT CIPHER
void enkripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;
    cout << "Ketikan pesan : ";
    cin.ignore();
    getline(cin, plainteks);
    cout << "Masukan key : ";
    cin >> k;
    cipherteks = " "; // inisialisasi cipherteks dengan null string

    for (i = 0; i < plainteks.length(); i++)
    {
        c = plainteks[i];
        if (isalpha(c)) // hanya memproses huruf alfabet saja
        {
            c = toupper(c);   // ubah menjadi huruf kapital
            c = c - 65;       // kodekan huruf ke angka 0 s/d 25
            c = (c + k) % 26; // enkripisi, geser sejauh k ke kanan
            c = c + 65;
        }
        cipherteks = cipherteks + c; // sambungkan ke cipherteks
    }
    cout << "cipherteks : " << cipherteks << endl<<endl; // cetak cipherteks
}

void dekripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "Ketikan cipherteks : ";
    cin.ignore();
    getline(cin, cipherteks);
    cout << "MasukanKey : ";
    cin >> k;
    plainteks = ""; // inisialisasi plainteks dengan null string

    for (i = 0; i < cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c)) // hanya memproses alpabet
        {
            c = toupper(c); // ubah karakter ke huruf besar
            c = c - 65;     // kodekan huruf ke angka 0 sampai 25
            if (c - k < 0)  // kasus pembagian bilangan negatif
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65;     // kodekan kembali ke huruf semula
            c = tolower(c); // plainteks dinyatakan dengan huruf kecil
        }
        plainteks = plainteks + c; // sambungkan ke plainteks
    }
    cout << "plainteks : " << plainteks << endl<<endl; // cetak plainteks
}


int main()
{ // begin
    int pil;
    bool stop;
    stop = false;

    while (!stop)
    {
       cout << "\\___________________________//"<<endl;
        cout << "// KRIPTOGRAFI Shift Chipher \\"<<endl;
        cout << "||Menu :                     ||" << endl;
        cout << "||1. Enkripsi                ||" << endl;
        cout << "||2. Dekripsi                ||" << endl;
        cout << "||3. Exit                    ||" << endl;
        cout << "\\___________________________//"<<endl;
        cout << "Silahkan masukkan nomor menu : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            enkripsi();
            break;
        case 2:
            dekripsi();
            break;
        case 3:
            stop = true;
            break;
        }
    }
} // end