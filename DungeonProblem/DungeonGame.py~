
# Thomas Morrison
# August 31, 2015
# Assignment 2
# Dungeon Game Problem with extra credit

print ("Welcome to Tom's Dungeon")

room = "k"
choice = ""


while choice != "q" :
 if room == "k":
  choice = input("You are in the kitchen. There are doors to the west (w), south (s), and east (e).")
  if choice == "s":
   room = "f"
  elif choice == "e": 
   room = "lr"
  elif choice == "w": 
   room = "h" 
 elif room == "f":
  print ("You entered the furnace and fry yourself to death!")
  choice = "q"
 elif room == "h":
  choice = input("You are in the hallway. There are doors to the south (s), east (e), and north (n).")
  if choice == "s":
    room = "l"
  elif choice == "e":
    room = "k"
  elif choice == "n":
    room = "br"
 elif room == "lr":
  choice = input("You are in the living room. There is a door to the west (w).")
  if choice == "w" :
   room = "k"
 elif room == "l":
  while room == "l" and choice != "q":
   if room == "l" :
    choice = input("You are in the library. You sense the princess is here, but where? Look around (l).")
    if choice == "l" : 
     room = "l2"
     choice = input("You look, and see a picture (p), bookcase (b), closet (c)")
     while room == "l2" and choice != "q":
      if choice == "c" :
       room = "l2"
       choice = input("You rummage through the closet, and you find SKELETONS!")
      elif choice == "b":
       room = "l2"
       choice = input("You look through the bookcase, and see your Python textbook.")
      elif choice == "p": 
       print ("You look at the picture, and see the princess hidding in it! You are a hero!")
       choice = "q"
      elif choice == "n": 
       room = "h"
    elif choice == "n" :
     room = "h"
      
 
 elif room == "br": 
  choice = input("You are in the bedroom. There are doors to the east (e), west (w), and south (s).")
  if choice == "e":
   room = "ws"
  elif choice == "w":
   room = "stairs"
  elif choice == "s":
   room = "h"
 elif room == "ws":
  while choice != "q" and room == "ws":
   choice = input("You found the mad scientists work shop. You enter a teleportation machine, would you like to teleport to the kitchen (k) or the living room (lr)?") 
   if choice == "k":
    print ("ZZZZZZZZZOOOOOOOOOOMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM")
    room = "k"
   elif choice == "lr": 
    print ("WWWWWWWWHHHHHHIIIIIIIIRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLL")
    room = "lr"
 elif room == "stairs":
  print ("You fell down the stairs and died.") 
  choice = "q"

print ("Goodbye!")
