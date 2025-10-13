#include <fstream>

#include "html_data.h"
#include "text_data.h"
#include "json_data.h"
#include "save_to.h"

int main() {
    std::ofstream htmlFile("output.html");
    std::ofstream textFile("output.txt");
    std::ofstream jsonFile("output.json");

    HTMLData htmlData("html file");
    TextData textData("text file");
    JSONData jsonData("json file");

    saveTo(htmlFile, htmlData);
    saveTo(textFile, textData);
    saveTo(jsonFile, jsonData);

    return EXIT_SUCCESS;
}