# Auto-RPG
A command line based automatic turn-based role-playing game (RPG).

## Use
> #### File IO
- hero.txt 
  -This file will contain a single line in this format:<br/>
HP, ATK, DEF, MED, Name<br/>
e.g. 20,6,3,1,Arlen
  - HP (Hitpoints) represent the health of the Hero.
  
  - ATK (Attack Point) measures how much damage the Hero can deal to the
enemy.

  - DEF (Defense Point) measures how much damage the Hero can absorb when
receiving an attack from enemy.

  - MED (Medicine) is the medicine the hero can consume when his/her HP is
30% or less. However, if the HP reaches zero, this medicine cannot be used to
revive the Hero.

- enemies.txt – This file will contain a list of any number of enemies that the hero
must fight and will be in this format:<br/>
  HP, ATK, DEF, Monster_Name_1<br/>
  HP, ATK, DEF, Monster_Name_2<br/>
...

  - Every monster will have its own HP, ATK, and DEF. No monster will carry
medicine.

> #### Command Line Arguments 
- Your program should receive only 3 arguments: “hero.txt”, “enemies.txt”, and the amount
of seconds to sleep for every screen transition/turn on the interface.


###### _Made by Anuj Punjani_
