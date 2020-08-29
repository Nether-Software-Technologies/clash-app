from internal import APIHandler as API
import os
import json

#Globals
cwd = os.getcwd()
newDir = cwd + "/data/"
cacheFile = newDir + "ccache.dat"

def cache(): 
  JSON = API.getChampions()
  try:
      os.mkdir(newDir)
  except:
    print("Error creating directory! If the directory exists, this error can be safely ignored.")
  with open(cacheFile, "w") as jsonFile:
    json.dump(JSON, jsonFile)

def checkVersion():
  with open(cacheFile, "r") as jsonFile:
    version = json.load(jsonFile)["version"]
  if version != API.CURRENT_VERSION:
    print("VERSION OUT OF DATE!")
    cache()
    print("UPDATED")
  else:
    print("VERSION IS UP TO DATE!")
    return
      
#Class
class Champion:

  #Initalizer

  def __init__(self, name = None,  ID = None, title = None, blurb = None, tags = None, difficulty = None):
    self._champID = ID
    self._champName = name
    self._champTitle = title
    self._champBlurb = blurb
    self._champTags = tags
    self._champDifficulty = difficulty
  
  #General

  @classmethod
  def fromName(cls, name):
    if not os.path.exists(newDir):
      cache()
    checkVersion()
    with open(cacheFile, "r") as jsonFile:
      try:
        JSON = json.load(jsonFile)["data"][name]
      except KeyError:
        print("ERROR: Champion doesn't exist!")
        return
    champID = int(JSON["key"])
    champName = JSON["name"]
    champTitle = JSON["title"] 
    champBlurb = JSON["blurb"]
    champTags = JSON["tags"]
    champDifficulty = JSON["info"]["difficulty"]
    return cls(champName, champID, champTitle, champBlurb, champTags, champDifficulty)

  
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

