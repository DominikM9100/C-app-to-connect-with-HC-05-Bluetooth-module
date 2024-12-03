#include <iostream>
#include <string>
#include <cctype>

//#define POLISH_ALPHABET "aąbcćdeęfghijklłmnńoóprsśtuwyzźż"
#define POLISH_ALPHABET "pkolimnjubygvhtfcxerdszwaq"
#define POLISH_ALPHABET_LEN 26

char shift_char(char c, int shift) {
    std::string alphabet = POLISH_ALPHABET;
    auto pos = alphabet.find(tolower(c));
    if (pos != std::string::npos) {
        int new_pos = (pos + shift + POLISH_ALPHABET_LEN) % POLISH_ALPHABET_LEN;
        char shifted = alphabet[new_pos];
        return isupper(c) ? toupper(shifted) : shifted;
    }
    return c;
}

void encrypt(std::string &text, int shift) {
    for (char &c : text) {
        c = shift_char(c, shift);
    }
}

void decipher(std::string &text, int shift) {
    for (char &c : text) {
        c = shift_char(c, -shift);
    }
}

int main() {
    std::string text_e;
    std::string text_d;
    int shift;

    std::cout << "Podaj tekst do zaszyfrowania: ";
    std::getline(std::cin, text_e);

    std::cout << "Podaj przesunięcie: ";
    std::cin >> shift;
    std::cin.ignore(); // Ignoruje resztę wiersza wejścia

    text_d = text_e;

    encrypt(text_e, shift);
    decipher(text_d, shift);

    std::cout << "Zaszyfrowany tekst: " << text_e << std::endl;
    std::cout << "Odszyfrowany tekst: " << text_d << std::endl;

    return 0;
}
