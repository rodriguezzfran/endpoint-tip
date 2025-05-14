#include <stdio.h>

enum Languages {
    Spanish,
    English,
    French,
    Russian,
    numberOfLanguages
};

enum Messages {
    HelloWorld,
    OutOfMemory,
    FileNotFound,
    OutOfBounds,
    numberOfMessages
};

// This is a array of arrays of char pointers
const char* messages[numberOfLanguages][numberOfMessages] = {
    {"Hola Mundo", "Memoria Insuficiente", "Archivo No Encontrado", "Fuera de los limites"},
    {"Hello World", "Out of Memory", "File Not Found", "Out of Bounds"},
    {"Bonjour le monde", "Mémoire Insuffisante", "Fichier Non Trouvé", "Hors limites"},
    {"Привет мир", "Недостаточно памяти", "Файл не найден", "Выход за пределы"},
};

const char* getMessageWithSwitch(enum Languages lang, enum Messages msg) {
    
    if (lang < 0 || lang >= numberOfLanguages) {
        return "Invalid Language";
    } else if (msg < 0 || msg >= numberOfMessages) {
        return "Invalid Message";
    }

    switch (lang) {

        case Spanish:
            switch (msg) {
                case HelloWorld:
                    return "Hola Mundo";
                case OutOfMemory:
                    return "Memoria Insuficiente";
                case FileNotFound:
                    return "Archivo No Encontrado";
                case OutOfBounds:
                    return "Fuera de los limites";
                case numberOfMessages:
                    return "Invalid Message";
            }
            break;

        case English:
            switch (msg) {
                case HelloWorld:
                    return "Hello World";
                case OutOfMemory:
                    return "Out of Memory";
                case FileNotFound:
                    return "File Not Found";
                case OutOfBounds:
                    return "Out of Bounds";
                case numberOfMessages:
                    return "Invalid Message";
            }
            break;

        case French:
            switch (msg) {
                case HelloWorld:
                    return "Bonjour le monde";
                case OutOfMemory:
                    return "Mémoire Insuffisante";
                case FileNotFound:
                    return "Fichier Non Trouvé";
                case OutOfBounds:
                    return "Hors limites";
                case numberOfMessages:
                    return "Invalid Message";
            }
            break;

        case Russian:
            switch (msg) {
                case HelloWorld:
                    return "Привет мир";
                case OutOfMemory:
                    return "Недостаточно памяти";
                case FileNotFound:
                    return "Файл не найден";
                case OutOfBounds:
                    return "Выход за пределы";
                case numberOfMessages:
                    return "Invalid Message";
            }
            break;

        case numberOfLanguages:
            return "Invalid Language";
    }

    return "end"; // This should never be reached

}

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

    printf("\nNow using switch statement\n\n");

    lang = Spanish;
    msg = HelloWorld;
    printf("%s\n", getMessageWithSwitch(lang, msg));

    lang = English;
    msg = OutOfMemory;
    printf("%s\n", getMessageWithSwitch(lang, msg));

    lang = French;
    msg = FileNotFound;
    printf("%s\n", getMessageWithSwitch(lang, msg));

    lang = 4; // Invalid Language    
    msg = FileNotFound;
    printf("%s\n", getMessageWithSwitch(lang, msg));

    lang = French;
    msg = 7; // Invalid Message
    printf("%s\n", getMessageWithSwitch(lang, msg));

    lang = numberOfLanguages; // Invalid Language

    return 0;
}