#include <iostream>
#include <bitset>
using namespace std;

// Dựa vào xâu này để thực hiện tìm biểu diễn dưới hệ Hexa của dãy bit (ở dạng bù 2)
string hexaStr = "0123456789ABCDEF";

// Hàm cộng 1 vào dãy bit
bitset<8> addOne(bitset<8> x) {
    for (int i = 0; i < 8; ++i) {
        if (x[i] == 0) { // Nếu bit hiện tại là 0, ta set nó thành 1 và kết thúc vòng lặp
            x[i] = 1;
            break;
        }
        else { // Nếu bit hiện tại là 1, ta đặt nó thành 0 và tiếp tục xét bit tiếp theo
            x[i] = 0;
        }
    }
    return x;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, flag = 1;
    bitset<8> bitsetArray;

    while (flag) {
        system("cls");
        cout << "___________OPTIONS___________\n";
        cout << "1. Change a signed integer X(8-bits)\n";
        cout << "2. Print the binary bit pattern of X (sign-magnitude form, 1's complement form, 2's complement form)\n";
        cout << "3. Print the hexadecimal form of X (2's complement)\n";
        cout << "4. Stop program\n";
        cout << "Please choose your option: ";
        int choose;
        cin >> choose;

        switch (choose) {
        case 1: {
            cout << "Please enter X value: ";
            cin >> n;
            if (n < -127 || n > 127) {
                cout << "overflow\n";
                system("pause");
                break;
            }
            bitsetArray = n >= 0 ? bitset<8>(n) : bitset<8>(128 - n);
            bitset<8> tempBitset = n < 0 ? ~bitset<8>(-n).to_ulong() + 1 : bitsetArray;
            break;
        }

        case 2: {
            cout << "Sign-Magnitude form: " << bitsetArray << endl;
            cout << "1's complement form: ";

            // In ra biểu diễn bù 1
            if (bitsetArray[7] == 1) {
                for (int i = 7; i >= 0; --i) {
                    if (i == 7) cout << bitsetArray[i];
                    else cout << (bitsetArray[i] ^ 1);
                }
            } else cout << bitsetArray;
            
           

            cout << "\n2's complement form: ";

            // In ra biểu diễn bù 2
            if (bitsetArray[7] == 1) {
                for (int i = 7; i >= 0; --i) {
                    if (i != 7) bitsetArray[i] = (bitsetArray[i] ^ 1);
                }
                bitsetArray = addOne(bitsetArray); // Cộng thêm 1
            }
           
            cout << bitsetArray << endl;
            system("pause");
            break;
        }

        case 3: {
            int hexa[2];
            hexa[1] = bitsetArray.to_ulong() % 16;
            hexa[0] = (bitsetArray.to_ulong() / 16) % 16;
            cout << "Hexadecimal form of X: " << hexaStr[hexa[0]] << hexaStr[hexa[1]] << '\n';
            system("pause");
            break;
        }

        case 4: {
            flag = 0;
            break;
        }
        default: {
            cout << "Not available! Please choose your option again! \n";
            system("pause");
            break;
        }
        }
    }
    return 0;
}
