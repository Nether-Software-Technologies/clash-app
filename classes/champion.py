from internal import APIHandler as API
import os
import json

#Globals
cwd = os.getcwd()
newDir = cwd + "/data/"

def cache(): 
  JSON = API.getChampions()
  try:
      os.mkdir(newDir)
  except:
    print("Error creating directory! It may already exist.")
  with open(newDir + "ccache.dat", "w") as jsonFile:
    json.dump(JSON, jsonFile)

def checkVersion():
  with open(newDir + "ccache.dat", "r") as jsonFile:
    version = json.load(jsonFile)["version"]
    if version != API.CURRENT_VERSION:
      cache()
      
#Class
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
    if not os.path.exists(newDir):
      cache()
    checkVersion()
    with open(newDir + "ccache.dat", "r") as jsonFile:
      JSON = json.load(jsonFile)["data"][name]
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

