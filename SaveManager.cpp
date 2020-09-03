#include "SaveManager.h"

// We have to determine a structure of how the data is stored within the save file.
// Player names are easy but things like the mosaic are gonna be fkn difficult

SaveManager::SaveManager() {
    saveCount = 0;
}

void SaveManager::NewSave(std::string saveName) {
    std::ofstream out;
    std::string name = saveName + ".txt"; // adding extension (ease of use for the user)
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
    std::string name = saveName + ".txt"; // adding extension (ease of use for the user)
    std::string line;
    in.open(name);
    for (int i = 0; i < 6; i++) {
        if (in.good()) {
            // Read save file
            in >> line;
            std::cout << line << std::endl;
        }
    }
    in.close();
}

