#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char *word)
{
    char *front = word;
    char *back = word + strlen(word) - 1;
    while (front < back)
    {
        if (*front != *back)
        {
            return false;
        }
        ++front;
        --back;
    }
    return true;
}

int main()
{
    char s1[50] = "neveroddoreven";
    char s2[50] = "not a palindrome";
    cout << boolalpha;
    cout << isPalindrome(s1) << endl;
    cout << isPalindrome(s2) << endl;
    return 0;
}
