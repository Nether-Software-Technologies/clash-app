/**
 * @
 * @
 * @
 */

#include "Champion.h"
using namespace rapidjson;

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

Champion::Champion(const std::string& name) {
    champID = 0;
    champName = name;
    champTitle = "";
    champBlurb = "";
    champTags = std::vector<std::string>();
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

Champion& Champion::pullChampionData(const JSON& json) {
    std::string sName = this->getChampName();
    const char* championName = sName.c_str();
    if (!json["data"].HasMember(championName)) {
        throw std::invalid_argument("Champion \"" + sName + "\" doesn't exist!");
    }
    const Value& tags = json["data"][championName]["tags"];
    std::vector<std::string> cTags;
    for (SizeType i = 0; i < tags.Size(); i++) {
        cTags.push_back(tags[i].GetString());
    }
    champTags = cTags;
    champBlurb = json["data"][championName]["blurb"].GetString();
    champName = json["data"][championName]["name"].GetString();
    champTitle = json["data"][championName]["title"].GetString();
    champDifficulty = json["data"][championName]["info"]["difficulty"].GetInt();
    champID = std::stol(json["data"][championName]["key"].GetString());
    return *this;
}

std::string Champion::getChampBlurb() const {
    return champBlurb;
}


