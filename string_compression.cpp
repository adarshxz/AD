#include <iostream>
#include <string>
#include <cctype>

// Compresses a string using basic Run-Length Encoding (e.g. "aabcccccaaa" -> "a2b1c5a3")
std::string compressString(const std::string& str) {
    if (str.empty()) return "";

    std::string compressed;
    int count = 1;

    for (size_t i = 1; i <= str.length(); ++i) {
        if (i < str.length() && str[i] == str[i - 1]) {
            count++;
        } else {
            compressed += str[i - 1];
            compressed += std::to_string(count);
            count = 1;
        }
    }

    return compressed;
}

// Decompresses a run-length encoded string (e.g. "a2b1c5a3" -> "aabcccccaaa")
std::string decompressString(const std::string& compressed) {
    std::string decompressed;
    size_t i = 0;

    while (i < compressed.length()) {
        char ch = compressed[i++];
        std::string countStr = "";

        while (i < compressed.length() && std::isdigit(static_cast<unsigned char>(compressed[i]))) {
            countStr += compressed[i++];
        }

        int count = countStr.empty() ? 1 : std::stoi(countStr);
        decompressed.append(count, ch);
    }

    return decompressed;
}

int main() {
    std::cout << "--- String Compression (Run-Length Encoding) ---\n";
    std::cout << "Enter a string to compress (e.g., aabcccccaaa): ";

    std::string input;
    if (std::cin >> input) {
        std::string compressed = compressString(input);
        std::string decompressed = decompressString(compressed);

        std::cout << "\n--- Results ---\n";
        std::cout << "Original String:     " << input << " (Length: " << input.length() << ")\n";
        std::cout << "Compressed String:   " << compressed << " (Length: " << compressed.length() << ")\n";
        std::cout << "Decompressed String: " << decompressed << "\n";
        std::cout << "Compression Ratio:   "
                  << (static_cast<double>(compressed.length()) / input.length()) * 100.0 << "%\n";
    }

    return 0;
}
