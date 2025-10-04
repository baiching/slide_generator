#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argsv[]){
    FILE *input = fopen("./slides.txt", "r");
    printf("hello world\n");
    system("pwd");
    printf("Input file pointer: %p\n", (void*)input);
    FILE *output = fopen("slide0001.html", "w");
    char line[256];
    int slide_num = 1;
    char filename[50];

    fprintf(output, "<html>\n");
    fprintf(output, "<head>\n");

    while (fgets(line, sizeof(line), input)) {
        printf("%s\n", line);
        // Removing \n
        line[strcspn(line, "\n")] = 0;
        printf("%s\n", line);

        if (strlen(line) == 0) {
            char *title = "This is title";
            fclose(output);
            slide_num++;
            sprintf(filename, "slide%04d.html", slide_num);
            output = fopen(filename, "w");

            fprintf(output, "<html>\n");
            fprintf(output, "<head>\n");
            fprintf(output, "<title>%s</title>\n", title);
            //here are the stylings
            fprintf(output, "<style>\n");
            fprintf(output, "body {\n");
            fprintf(output, "text-align: center;\n");
            fprintf(output, "font-size: 2vw;\n");
            fprintf(output, "}\n");
            fprintf(output, "ul {\n");
            fprintf(output, "display: inline-block;\n");
            fprintf(output, "text-align: left;\n");
            fprintf(output, "}\n");
            fprintf(output, "</style>\n");
            fprintf(output, "</head>\n");
            fprintf(output, "<body>\n");
        }
        else if (line[0] == '-') {
            fprintf(output, "<li>%s</li>\n", line + 2);
        }
        else {
            fprintf(output, "<h1>%s</h1>\n", line);
        }
    }

    fprintf(output, "</body>\n");
    fprintf(output, "</head>\n");
    fprintf(output, "</html>");

    fclose(output);
    fclose(input);
    return 0;
}
