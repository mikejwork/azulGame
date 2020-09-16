#include "SaveManager.h"

// We have to determine a structure of how the data is stored within the save file.

// If u dont know what tf this is look at week 5 lecture stuff

SaveManager::SaveManager() {
    saveCount = 0;
}

void SaveManager::NewSave(std::string saveName) {
    std::ofstream out;
    std::string name = "saveGame/" + saveName + ".txt"; // adding extension (ease of use for the user)
    out.open(name);
    for (int i = 0; i < 6; i++) {
        if (out.good()) {
            // Write save file
            out << i << std::endl;
        }
    }
    out.close();
}

void SaveManager::LoadSave(std::string saveName) {
    std::ifstream in;
    std::string name = "saveGame/" + saveName + ".txt"; // adding extension (ease of use for the user)
    std::string line;
    in.open(name);
    while (!in.eof()) {
        if (in.good()) {
            // Read save file
            in >> line;
            std::cout << line << std::endl;
        }
    }
    in.close();
}
