#include <stdio.h>
#include <string.h>

void compilePseudocodeToC(const char *inputFile) {
    FILE *input = fopen(inputFile, "r");
    //FILE *output = fopen(outputFile, "w");

    if (input == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char line[100];

    // Start writing the C program structure in output file
    printf( "#include <stdio.h>\n\n");
    printf("int main() {\n");

    while (fgets(line, sizeof(line), input) != NULL) {
        // Remove newline character
         line[strcspn(line, "\n")] = 0;

        // Translate pseudocode to C code
        if (strcmp(line, "START") == 0) {
            // Do nothing for START
        } else if (strcmp(line, "END") == 0) {
            // Close the main function
            printf("    return 0;\n");
        } else if (strcmp(line, "READ A") == 0) {
            printf( "    int A;\n");
            printf("    printf(\"Enter value for A: \");\n");
            printf( "    scanf(\"%%d\", &A);\n");
        } else if (strcmp(line, "READ B") == 0) {
            printf( "    int B;\n");
            printf( "    printf(\"Enter value for B: \");\n");
            printf( "    scanf(\"%%d\", &B);\n");
        } else if (strcmp(line, "SUM = A + B") == 0) {
            printf( "    int SUM = A + B;\n");
        } else if (strcmp(line, "PRINT SUM") == 0) {
            printf( "    printf(\"Sum = %%d\\n\", SUM);\n");
        }
    }

    printf( "}\n");

    fclose(input);
    


}

int main() {
    compilePseudocodeToC("pseudocode.txt");
    return 0;
}