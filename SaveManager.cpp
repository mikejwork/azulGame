#include "SaveManager.h"

SaveManager::SaveManager() {
    saveCount = 0;
}

void SaveManager::NewSave(std::string saveName) {
    std::ofstream out;
    std::string name = saveName + ".txt"; // adding extension (ease of use for the user)
    if (out.good()) {
        out.open(name);
        // Write save file
         out << "Save#" << saveCount << std::endl;
        out.close();
    }
    saveCount++;
}

void SaveManager::LoadSave(std::string saveName) {
    std::ifstream in;
    std::string name = saveName + ".txt"; // adding extension (ease of use for the user)
    if (in.good()) {
        in.open(name);
        
    }
}

