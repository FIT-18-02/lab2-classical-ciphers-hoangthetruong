#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// ================== RAIL FENCE ENCRYPT ==================
string railFenceEncrypt(string text, int rails) {
    // Q7: Kiểm tra input không hợp lệ
    if (rails < 2 || text.empty()) {
        return text;
    }

    vector<string> fence(rails, "");
    int row = 0;
    int direction = 1;  // 1: xuống, -1: lên

    // Viết theo zigzag, giữ nguyên dấu cách
    for (char ch : text) {
        fence[row] += ch;
        row += direction;
        if (row == rails - 1) direction = -1;
        else if (row == 0) direction = 1;
    }

    // Đọc theo từng hàng
    string result = "";
    for (string r : fence) {
        result += r;
    }
    return result;
}

// ================== RAIL FENCE DECRYPT ==================
string railFenceDecrypt(string cipher, int rails) {
    if (rails < 2 || cipher.empty()) {
        return cipher;
    }

    int n = cipher.length();
    vector<int> positions(n);
    vector<string> fence(rails, string(n, '*'));  // placeholder

    // Bước 1: Xác định vị trí zigzag
    int row = 0, dir = 1;
    for (int i = 0; i < n; i++) {
        positions[i] = row;
        row += dir;
        if (row == rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }

    // Bước 2: Điền ciphertext vào đúng vị trí theo hàng
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int i = 0; i < n; i++) {
            if (positions[i] == r) {
                fence[r][i] = cipher[idx++];
            }
        }
    }

    // Bước 3: Đọc theo zigzag để ra plaintext
    string result = "";
    row = 0; dir = 1;
    for (int i = 0; i < n; i++) {
        result += fence[row][i];
        row += dir;
        if (row == rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }
    return result;
}

// ================== MAIN - TEST CÁC YÊU CẦU ==================
int main() {
    cout << "=== RAIL FENCE CIPHER TEST ===" << endl << endl;

    string text = "I LOVE YOU";
    int rails = 3;

    cout << "Original text     : " << text << endl;

    string encrypted = railFenceEncrypt(text, rails);
    cout << "Encrypted (" << rails << " rails): " << encrypted << endl;

    string decrypted = railFenceDecrypt(encrypted, rails);
    cout << "Decrypted         : " << decrypted << endl << endl;

    // Test thêm các trường hợp
    cout << "=== Test cases khác ===" << endl;
    cout << "Rails = 2 : " << railFenceEncrypt("HELLO WORLD", 2) << endl;
    cout << "Rails = 4 : " << railFenceEncrypt("RAIL FENCE CIPHER", 4) << endl;
    cout << "Rails = 1 (invalid) : " << railFenceEncrypt("TEST", 1) << endl;
    cout << "Empty text : " << railFenceEncrypt("", 3) << endl << endl;

    // Đọc từ file data/input.txt (Q8)
    ifstream infile("data/input.txt");
    if (infile.is_open()) {
        string fileText;
        getline(infile, fileText);
        infile.close();
        cout << "Từ file input.txt     : " << fileText << endl;
        cout << "Encrypt (3 rails)     : " << railFenceEncrypt(fileText, 3) << endl;
    } else {
        cout << "Khong mo duoc file data/input.txt" << endl;
    }

    return 0;
}
