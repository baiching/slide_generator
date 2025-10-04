#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argsv[]){
    FILE *input = fopen("./slides.txt", "r");
    FILE *output = fopen("slide0001.html", "w");
    char line[256];
    int slide_num = 1;
    char filename[50];
    char *title = "This is title";

    fprintf(output, "<html>\n");
    fprintf(output, "<head>\n");

    while (fgets(line, sizeof(line), input)) {
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
        // Removing \n
       line[strcspn(line, "\r\n")] = 0;
       printf("%s", line);

        if (strlen(line) == 0) {

            fclose(output);
            slide_num++;
            sprintf(filename, "slide%04d.html", slide_num);
            output = fopen(filename, "w");
        }
        else if (line[0] == '-') {
            fprintf(output, "<li>%s</li>\n", line + 2);
            fprintf(output, "</body>\n");
            fprintf(output, "</html>");
        }
        else {
            fprintf(output, "<h1>%s</h1>\n", line);
        }
    }



    fclose(output);
    fclose(input);
    return 0;
}
