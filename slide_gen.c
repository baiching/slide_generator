#include <stdio.h>
#include <string.h>

int main(int argc, char* argsv[]){
    FILE *input = fopen("./slides.txt", "r");
    FILE *output = fopen("slide0001.html", "w");
    char line[256];
    int slide_num = 1;
    char filename[50];
    const char *CSS_STYLES = "<style>body{margin:0;padding:0;display:flex;justify-content:center;align-items:center;min-height:100vh;background:linear-gradient(135deg,#667eea 0%,#764ba2 100%);font-family:'Segoe UI',Tahoma,Geneva,Verdana,sans-serif;}.slide-container{background:white;width:80vw;max-width:1000px;height:70vh;border-radius:20px;box-shadow:0 20px 60px rgba(0,0,0,0.3);padding:60px 80px;display:flex;flex-direction:column;justify-content:center;}h1{font-size:3.5vw;color:#2d3748;margin:0 0 50px 0;text-align:left;border-bottom:4px solid #667eea;padding-bottom:20px;}ul{list-style:none;padding:0;margin:0;display:block;}li{font-size:2.2vw;color:#4a5568;margin:30px 0;padding-left:50px;position:relative;line-height:1.6;animation:slideIn 0.5s ease-out forwards;opacity:0;display:block;}li:nth-child(1){animation-delay:0.2s;}li:nth-child(2){animation-delay:0.4s;}li:nth-child(3){animation-delay:0.6s;}li::before{content:\"\\25B6\";position:absolute;left:0;color:#667eea;font-size:1.5vw;top:0.3vw;}@keyframes slideIn{from{opacity:0;transform:translateX(-30px);}to{opacity:1;transform:translateX(0);}}.navigation{position:fixed;bottom:40px;width:80vw;max-width:1000px;display:flex;justify-content:space-between;padding:0 20px;}.nav-button{background:white;color:#667eea;text-decoration:none;padding:15px 30px;border-radius:10px;font-size:1.2vw;font-weight:600;box-shadow:0 5px 15px rgba(0,0,0,0.2);transition:all 0.3s ease;}.nav-button:hover{transform:translateY(-3px);box-shadow:0 8px 20px rgba(0,0,0,0.3);background:#667eea;color:white;}.nav-button.prev::before{content:\"\\2190 \";}.nav-button.next::after{content:\" \\2192\";}@media (max-width:768px){.slide-container{width:90vw;height:auto;padding:40px;}h1{font-size:6vw;}li{font-size:4vw;}li::before{font-size:3vw;}.navigation{width:90vw;}.nav-button{font-size:3vw;padding:12px 20px;}}</style>";
    fprintf(output, "%s", CSS_STYLES);
    fprintf(output, "</head>\n");
    char *title = "This is title";

    fprintf(output, "<html>\n");
    fprintf(output, "<head>\n");
    fprintf(output, "<title>%s</title>\n", title);
    while (fgets(line, sizeof(line), input)) {

        // Removing \n
       line[strcspn(line, "\r\n")] = 0;
       printf("%s", line);

        if (strlen(line) == 0) {
            // This section will appear at the button
            fprintf(output, "</ul>\n");
            fprintf(output, "</div>\n");
            fprintf(output, "<div class=\"navigation\">\n");
            fprintf(output, "  <a href=\"slide%04d.html\" class=\"nav-button prev\">Previous</a>\n", slide_num-1);
            fprintf(output, "  <a href=\"slide%04d.html\" class=\"nav-button next\">Next</a>\n", slide_num+1);
            fprintf(output, "</div>\n");
            fprintf(output, "</body>\n");
            fprintf(output, "</html>");
            //-----------------------------------------
            fclose(output);
            slide_num++;
            sprintf(filename, "slide%04d.html", slide_num);
            output = fopen(filename, "w");

            //This will appear at the top
            fprintf(output, "<html>\n");
            fprintf(output, "<head>\n");
            fprintf(output, "<title>%s</title>\n", title);
            fprintf(output, "%s", CSS_STYLES);
            fprintf(output, "</head>\n");
            fprintf(output, "<body>\n");
        }
        else if (line[0] == '-') {
            fprintf(output, "<li>%s</li>\n", line + 2);
        }
        else {
            fprintf(output, "<div class=\"slide-container\">");
            fprintf(output, "<h1>%s</h1>\n", line);
            fprintf(output, "<ul>\n");
        }

    }
    fprintf(output, "<div class=\"navigation\">\n");
    fprintf(output, "  <a href=\"slide%04d.html\" class=\"nav-button prev\">Previous</a>\n", slide_num-1);
    fprintf(output, "  <a href=\"slide%04d.html\" class=\"nav-button next\">Next</a>\n", slide_num+1);
    fprintf(output, "</div>\n");
    fprintf(output, "</body>\n");
    fprintf(output, "</html>");
    fclose(output);
    fclose(input);
    return 0;
}
