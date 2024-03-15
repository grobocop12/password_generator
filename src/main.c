#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char specialCharacters[] = "{}()[]#:;^,.?!|&_`~@$\%/\\=+-*'\"";

int getPasswordLength();
void generatePassword(char *passwordPointer, int length);

int main(int argc, char **argv)
{
    int length = getPasswordLength();
    char *password = malloc(length + 1);
    generatePassword(password, length);
    printf("Password:\n%s\n", password);
    free(password);
    return 0;
}

int getPasswordLength()
{
    int length;
    printf("Password length: ");
    scanf("%d", &length);
    printf("\n");
    if (length <= 0)
    {
        printf("%d\n", length);
        printf("Password cannot be empty!\n");
        exit(0);
    }
    return length;
}

void generatePassword(char *passwordPointer, int passwordLength)
{
    int lowercaseLength = strlen(lowercaseLetters);
    int uppercaseLength = strlen(uppercaseLetters);
    int digitsLength = strlen(digits);
    int specialCharactersLength = strlen(specialCharacters);

    srand(time(NULL) * getpid());
    for (int i = 0; i < passwordLength; i++)
    {
        int charType = rand() % 4;
        switch (charType)
        {
        case 0:
            passwordPointer[i] = lowercaseLetters[rand() % lowercaseLength];
            break;
        case 1:
            passwordPointer[i] = uppercaseLetters[rand() % uppercaseLength];
            break;
        case 2:
            passwordPointer[i] = digits[rand() % digitsLength];
            break;
        case 3:
            passwordPointer[i] = specialCharacters[rand() % specialCharactersLength];
            break;
        default:
            break;
        }
    }
    passwordPointer[passwordLength + 1] = '\0';
}