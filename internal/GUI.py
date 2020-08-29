import sys
from PySide2.QtWidgets import QApplication, QPushButton
from PySide2.QtCore import Slot

@Slot()
def btn1_click():
  print('btn1 clicked!') 