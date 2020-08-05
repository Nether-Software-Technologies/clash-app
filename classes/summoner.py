from internal import APIHandler as API

class Summoner:
  #Initalizer - given a string, name != ""
  def __init__(self, name = "",  ID = "", accountID = "", profileIconID = 0, PUUID = "", revisionDate = 0, level = 0):
    if name != "":
      self.getSummonerData(name)
    else:
      _summonerName = name
      _summonerID = ID
      _summonerAccountID = accountID
      _summonerProfileIconID = profileIconID
      _summonerPUUID = PUUID
      _summonerRevisionDate = revisionDate
      _summonerLevel = level
  
  #General
  def getSummonerData(self, name):
    #initalize JSON here, gets created when function ran, deleted when function leaves; API covers failed attempt
    JSON = API.getSummoner(name)
    self._summonerName = JSON["name"]
    self._summonerID = JSON["id"]
    self._summonerAccountID = JSON["accountId"]
    self._summonerPUUID = JSON["puuid"]
    self._summonerRevisionDate = JSON["revisionDate"]
    self._summonerLevel = JSON["summonerLevel"]
  
  #Getters
  def getSummonerName(self):
    return self._summonerName

  def getSummonerID(self):
    return self._summonerID
  
  def getSummonerAccountID(self):
    return self._summonerAccountID

  def getSummonerPUUID(self):
    return self._summonerPUUID

  def getSummonerRevisionDate(self):
    return self._summonerRevisionDate

  def getSummonerLevel(self):
    return self._summonerLevel

  #Overloads
  def __str__(self):
    return (self._summonerName + ", level " + str(self._summonerLevel) + "\n" + "Encrypted Summoner ID: " 
            + self._summonerID + "\n" + "Encrypted Account ID: " + self._summonerAccountID + "\n"
            + "Player Unique User ID: " + self._summonerPUUID + "\n")
            
    


