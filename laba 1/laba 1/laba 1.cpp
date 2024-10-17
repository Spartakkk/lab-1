#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string processString(char text[], int length) {
    int maxSpaces = 0;
    int Spaces = 0;
    string result = "";
    int x = 0;

    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (c == ' ') {
            Spaces++;
        }
        else {
            if (Spaces > maxSpaces) {
                maxSpaces = Spaces;
                x = i - maxSpaces;
                
            }
            Spaces = 0;
        }
    }

   

    if (maxSpaces % 3 == 0) {
        for (int i = 0; i < length; i++) {
            char c = text[i];
            if (c == ' ' && x == i) {

                result += '*';
                while (i < length && text[i] == ' ') {
                    i++;
                }
            }
            else if (c == ' ') {
                i++;
            }                        
            else {
                result += c;
            }
            
        } 
    }
    else {
        for (int i = 0; i < length; i++) {
            char c = text[i];
            if (c != ' ') {
                result += c;
            }
        }
    }

    return result;
}

//массив из файла
int z3() {
    FILE* initial_file;
    FILE* final_file;
    char input[100] = { '\0' };

    initial_file = fopen("initial_file.txt", "r");
    if (initial_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if (fgets(input, sizeof(input), initial_file) != NULL) {
        int len = strlen(input);
        
        fclose(initial_file);
        final_file = fopen("final_file.txt", "w");
        if (final_file == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        fputs(processString(input, len).c_str(), final_file);

        fclose(final_file);
    }
    else {
        printf("Error reading from file\n");
    }
    return 0;
}
//массив-С++
int z2() {
    char input[100] = { '\0' };

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    string res = processString(input, len);
    cout << res << endl;


    return 0;
}
//массив-СИ
int z1() {
    char input[100] = { '\0' };
    int i = 0;

    printf("Enter a string: ");
    while ((input[i] = getchar()) != '\n') {
        i++;
    }
    int len = strlen(input);
    processString(input, len);
    len = strlen(input);
    string res = processString(input, len);
    cout << res << endl;

    return 0;
}


void main() {
    z3();
}