/**
 * @
 * @
 * @
 */

#include "Champion.h"

const JSON CHAMPION_DATA = API_LINK.getChampions();

//"very basic lets add nasus pogchamp" -ep
Champion::Champion() { 
    // andyW
}

Champion::Champion(const long& ID) {
   champID = ID; //for testing
   champName = "Nasus";
   champTitle = "the Curator of the Sands";
   champBlurb = "Nasus is an imposing, jackal-headed Ascended being from ancient Shurima, a heroic figure regarded as a demigod by the people of the desert. Fiercely intelligent, he was a guardian of knowledge and peerless strategist whose wisdom guided the ancient...";
   champTags.push_back("Fighter");
   champTags.push_back("Tank");
}

Champion::Champion(const std::string& name) {
    pullChampionData(name.c_str());
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


Champion& Champion::pullChampionData(const std::string& initName) {
	if (CHAMPION_DATA["data"].find(initName) == CHAMPION_DATA["data"].end()) {
        throw std::invalid_argument("Champion \"" + initName + "\" doesn't exist!");
    }
    const std::vector<std::string> cTags = CHAMPION_DATA["data"][initName]["tags"].get<std::vector<std::string>>();
    champTags = cTags;
    champBlurb = CHAMPION_DATA["data"][initName]["blurb"].get<std::string>();
    champName = CHAMPION_DATA["data"][initName]["name"].get<std::string>();
    champTitle = CHAMPION_DATA["data"][initName]["title"].get<std::string>();
    champDifficulty = CHAMPION_DATA["data"][initName]["info"]["difficulty"].get<int>();
    champID = std::stol(CHAMPION_DATA["data"][initName]["key"].get<std::string>());
    return *this;
}

std::string Champion::getChampBlurb() const {
    return champBlurb;
}


