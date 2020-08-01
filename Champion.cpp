/**
 * @
 * @
 * @
 */

#include "Champion.h"

//"very basic lets add nasus pogchamp" -ep
Champion::Champion() {
   champID = 75;
   champName = "Nasus"; //nasus lets go
   champTitle = "the Curator of the Sands";
   champBlurb = "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...";
   champDifficulty = 6;
   champTags.push_back("Fighter");
   champTags.push_back("Tank");
}

Champion::Champion(long ID, std::string name, std::vector<std::string> tags, std::string title, std::string blurb, int difficulty) {
    champID = ID;
    champName = name;
    champTags = tags;
    champTitle = title;
    champBlurb = blurb;
    champDifficulty = difficulty;
}

Champion::Champion(const Champion& other) {
    champID = other.champID;
    champName = other.champName;
    champTitle = other.champTitle;
    champBlurb = other.champBlurb;
    champTags = other.champTags;
    champDifficulty = other.champDifficulty;
}

Champion::Champion(const long& ID) {
   champID = ID; //for testing
   champName = "Nasus";
   champTitle = "the Curator of the Sands";
   champBlurb = "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...";
   champTags.push_back("Fighter");
   champTags.push_back("Tank");
}

std::ostream& operator<<(std::ostream& os, const Champion& champ) {
    os << champ.champID << std::endl << champ.champName << ", " << champ.champTitle << ".\n" << champ.champBlurb << "\n";
    return os;
}

Champion& Champion::operator=(const Champion& other) {
    if (this != &other) {
        this->champTags = other.champTags;
        this->champBlurb = other.champBlurb;
        this->champID = other.champID;
        this->champDifficulty = other.champDifficulty;
        this->champTitle = other.champTitle;
        this->champName = other.champName;
    }
    return *this;
}

std::string Champion::getChampName() const {
    return champName;
}

long Champion::getChampNumber() const {
    return champID;
}

std::vector<std::string> Champion::getChampTags() const {
    return champTags;
}

int Champion::getChampDifficulty() const {
    return champDifficulty;
}

std::string Champion::getChampBlurb() const {
    return champBlurb;
}


