//Nama	: Naufal Rafid Rahmawan
//NIM	: 2300018021
//Kelas	: A
#include <iostream>
#include <fstream>
using namespace std;

char angka[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

int cetak_hasil();
void papan_permainan();
void simpan_pemenang(int pemain);
void tampilkan_history();
void reset_papan();

int main()
{
    int pemain = 1, i, pilih;
    char simbol;
    int menu;  
    bool permainan_berlanjut = true;  

    do
    {
        // Menampilkan menu
        cout << "==========================================" << endl;
        cout << "|      1. Main TicTacToe                 |" << endl;
        cout << "|      2. History Permainan              |" << endl;
        cout << "|      3. Keluar                         |" << endl;
        cout << "==========================================" << endl;

        // Meminta pemain memilih menu
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
            case 1:
                // Game loop untuk TicTacToe
                do
                {
                    papan_permainan();
                    pemain = (pemain % 2) ? 1 : 2;
                    cout << "Pemain " << pemain << ", Masukkan angka: ";
                    cin >> pilih;
                    simbol = (pemain == 1) ? 'X' : 'O';

                    // Memeriksa apakah input angka valid
                    if (pilih >= 1 && pilih <= 9 && angka[(pilih - 1) / 3][(pilih - 1) % 3] == '0' + pilih)
                        angka[(pilih - 1) / 3][(pilih - 1) % 3] = simbol;
                    else
                    {
                        cout << "Jawaban tidak valid ";
                        pemain--;
                        cin.ignore();
                        cin.get();
                    }

                    i = cetak_hasil();
                    pemain++;

                } while (i == -1);

                // Menampilkan hasil game dan menyimpan pemenang jika ada
                if (i == 1)
                {
                    cout << "==>\aPemain " << --pemain << " menang " << endl;
                    simpan_pemenang(pemain);
                }
                else
                    cout << "==>\aGame draw";

                // Menambahkan kondisi untuk mengubah variabel permainan_berlanjut
                permainan_berlanjut = false;
                break;

            case 2:
                // Menampilkan history permainan
                tampilkan_history();
                break;

            case 3:
                // Mengakhiri program
                cout << "PROGRAM SELESAI." << endl;
                return 0;

            default:
                // Menangani pilihan menu tidak valid
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

        // Membersihkan input buffer dan menunggu user menekan Enter
        cin.ignore();
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
        system("cls");
        reset_papan();
    } while (menu != 3 );

    return 0;
}

// Inisialisasi ulang papan permainan
void reset_papan()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            angka[i][j] = '0' + (i * 3 + j + 1);
        }
    }
}

// Pengecekan hasil permainan (menang, seri, atau berlanjut)
int cetak_hasil()
{
    // Menentukan hasil permainan
    if (angka[0][0] == angka[0][1] && angka[0][1] == angka[0][2])
        return 1;
    else if (angka[1][0] == angka[1][1] && angka[1][1] == angka[1][2])
        return 1;
    else if (angka[2][0] == angka[2][1] && angka[2][1] == angka[2][2])
        return 1;
    else if (angka[0][0] == angka[1][0] && angka[1][0] == angka[2][0])
        return 1;
    else if (angka[0][1] == angka[1][1] && angka[1][1] == angka[2][1])
        return 1;
    else if (angka[0][2] == angka[1][2] && angka[1][2] == angka[2][2])
        return 1;
    else if (angka[0][0] == angka[1][1] && angka[1][1] == angka[2][2])
        return 1;
    else if (angka[0][2] == angka[1][1] && angka[1][1] == angka[2][0])
        return 1;
    else if (angka[0][0] != '1' && angka[0][1] != '2' && angka[0][2] != '3' && angka[1][0] != '4' && angka[1][1] != '5' && angka[1][2] != '6' && angka[2][0] != '7' && angka[2][1] != '8' && angka[2][2] != '9')
        return 0;
    else
        return -1;
}

// Menampilkan papan permainan
void papan_permainan()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Pemain 1 (X)  -  Pemain 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[0][0] << "  |  " << angka[0][1] << "  |  " << angka[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[1][0] << "  |  " << angka[1][1] << "  |  " << angka[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[2][0] << "  |  " << angka[2][1] << "  |  " << angka[2][2] << endl;
    cout << "     |     |  " << endl;
}

// Menyimpan pemenang ke dalam file
void simpan_pemenang(int pemain)
{
    ofstream file("pemenang.txt", ios::app);

    if (file.is_open())
    {
        file << "Pemain " << pemain << " menang" << endl;
        file.close();
    }
    else
    {
        cout << "Gagal membuka file untuk menyimpan pemenang." << endl;
    }
}

// Menampilkan history kemenangan dari file
void tampilkan_history()
{
    ifstream file("pemenang.txt");
    string line;

    cout << "=== History Kemenangan ===" << endl;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Gagal membuka file history kemenangan." << endl;
    }
}
