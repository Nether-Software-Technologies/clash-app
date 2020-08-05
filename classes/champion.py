from internal import APIHandler as API

class Champion:
  #Initalizer - given a string, name != ""
  def __init__(self, name = "",  ID = 0, title = "", blurb = "", tags = {}, difficulty = 0):
    if name != "":
      self.getChampionData(name)
    else:
      self._champID = ID
      self._champName = name
      self._champTitle = title
      self._champBlurb = blurb
      self._champTags = tags
      self._champDifficulty = difficulty
  
  #General
  def getChampionData(self, name):
    #initalize JSON here, gets created when function ran, deleted when function leaves
    try:
      JSON = API.getChampions()["data"][name]
    except KeyError:
      print("Champion \"" + name + "\" doesn't exist!")   
      return
    self._champID = int(JSON["key"])
    self._champName = JSON["name"]
    self._champTitle = JSON["title"] 
    self._champBlurb = JSON["blurb"]
    self._champTags = JSON["tags"]
    self._champDifficulty = JSON["info"]["difficulty"]
  
  #Getters
  def getChampBlurb(self):
    return self._champBlurb

  def getChampDifficulty(self):
    return self._champDifficulty
  
  def getChampTags(self):
    return self._champTags

  def getChampTitle(self):
    return self._champTitle

  def getChampID(self):
    return self._champID

  def getChampName(self):
    return self._champName

  def spamTest(self):
    API.getChampionRotation()

  #Overloads
  def __str__(self):
    return (str(self._champID) + "\n" + self._champName + ", " 
            + self._champTitle + ".\n" + self._champBlurb + "\n")

