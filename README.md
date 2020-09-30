#                                                                      BASIC RPG GAME
RPG Game greated in C++.
<p align="center">
<img src="https://github.com/DawidJozwiak/RPG-GAME/blob/master/Images/Screenshot%202020-10-01%20at%2001.14.39.png" width="800" height="450">
</p>

 When I was analysing the topic, I tried to focus on implementing functionality
and program’s reception by user. In order to that I used graphics reminding
medieval games and characters typical to fantasy games. Interface is very simple,
uses graphical backgrounds and buttons to navigate through entire game. Classes
in project can be divided into few groups:
###### - Classes for Interface(eg. MainWindow, Forest) - were created in order to create
graphical interface using QT Creator and handle basic user interactions
###### - Classes for Fight(eg. Fight, Character) - were created in order to handle fight in
fight_handler.cpp, for example Character has a virtual methods for classes
Enemy or Ally to use skills/basic attacks/items
###### - Classes for Character Development(eg. Items, Player) - were created in order to
save user’s progress and help him expand his inventory
###### - Classes for Utility(eg. Exceptions, City) - were created to provide code with some
mechanism like exceptions, templates or reading file.
###### - Classes for Handling Minigames(eg. Guess, Memory) - were created to add a
little extra mechanisms to the game
<p align="center">
<img src="https://github.com/DawidJozwiak/RPG-GAME/blob/master/Images/Screenshot%202020-10-01%20at%2001.25.12.png" width="800" height="450">
</p>
Most interesting file is fight_handler which handles whole fight in almost 1000 lines.
It uses objects and randomisation to provide user interesting battles and different
outcome. I accomplished that by giving every character an interesting abilities. For
example mage can use “Thunder Storm” which sets boolean value stun to true and
skips chosen enemy round. Rouge’s “Distance shot” deals improved damage
depending on distance between him and enemy (simply enemy 1 will get less
damage than enemy 3). Abilities and basic attacks are used in random way but
there are some preventing mechanism using exceptions (for example you can’t
attack dead enemy). Before every turn game is checking if all enemies and allies
are alive. If one team has all members dead, the game ends with either gold gain
from loot or gold loss, in order to pay for medics. Gold obtained during battles can
be later used in shop in order to buy items. Shop contains 3 weapons which
improve given character’s damage. Game doesn’t have an end and it’s goal is to
simply obtain the most gold as it’s possible. Libraries used in project are very
simple C++ libraries (eg. list, vector, memory, exceptions) and QTCreator classes
(eg. QGraphicsScene, QGraphicsView or QWidget) that helped me build interface 
and help send communicates to user during battle or simply moving throughout
windows. Whole game was created on MacOS which may causes problems to
Windows users and used QT graphical interface, which may cause the problems
with trying to open it on another computer
