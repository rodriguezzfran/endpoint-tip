#include <stdio.h>

enum Languages {
    Spanish,
    English,
    French,
    numberOfLanguages
};

enum Messages {
    HelloWorld,
    OutOfMemory,
    FileNotFound,
    numberOfMessages
};

// This is a array of arrays of char pointers
const char* messages[numberOfLanguages][numberOfMessages] = {
    {"Hola Mundo", "Memoria Insuficiente", "Archivo No Encontrado"},
    {"Hello World", "Out of Memory", "File Not Found"},
    {"Bonjour le monde", "Mémoire Insuffisante", "Fichier Non Trouvé"}
};

// We can simply use the enum's field in the switch statement but we will use the internal representation
const char* getMessage(enum Languages lang, enum Messages msg) {
    
    if (lang < 0 || lang >= numberOfLanguages) {
        return "Invalid Language";
    }else if (msg < 0 || msg >= numberOfMessages) {
        return "Invalid Message";
    }else{
        return messages[lang][msg];
    }

}

int main() {
    
    enum Languages lang = Spanish;
    enum Messages msg = HelloWorld;
    printf("%s\n", getMessage(lang, msg));

    lang = English;
    msg = OutOfMemory;
    printf("%s\n", getMessage(lang, msg));

    lang = French;
    msg = FileNotFound;
    printf("%s\n", getMessage(lang, msg));

    lang = 4; // Invalid Language    
    msg = FileNotFound;
    printf("%s\n", getMessage(lang, msg));

    lang = French;
    msg = 7; // Invalid Message
    printf("%s\n", getMessage(lang, msg));

    return 0;
}