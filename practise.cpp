#include <iostream>
#include <cstring> // for strlen and strcmp

using namespace std;

class PalindromeChecker {
public:
    // Constructor that accepts a C-style string
    PalindromeChecker(const char* str) {
        size_t length = strlen(str);
        // Allocate memory for the string array
        data = new char[length + 1];
        strcpy(data, str); // Copy the input string
    }
    
    // Destructor to free allocated memory
    ~PalindromeChecker() {
        delete[] data;
    }

    // Function to check if the string is a palindrome
    bool isPalindrome() const {
        size_t length = strlen(data);
        char* left = data;
        char* right = data + length - 1;
        
        while (left < right) {
            if (*left != *right) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

private:
    char* data; // Pointer to store the string
};

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100);
    
    // Create a PalindromeChecker object
    PalindromeChecker checker(input);
    
    if (checker.isPalindrome()) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}

