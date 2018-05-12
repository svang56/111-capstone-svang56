# Capstone Description
    
(Description of project)
My project is a text adventure game. It features an adventurer who is on an "Adventure
Quest" and has come to defeat the Dragon. The objective of the game is to battle monsters
and become stronger in order to defeat the Dragon. However, there is also a Black knight 
who is almost as fearsome as the Dragon. As you enter the game, the user will be given 
options to navigate throughout the game.
(the following is a general run down of my game)
There are four different areas within my game.
There is a "Town," "Forest," "Dungeon," and "Castle." The town consists of a shop
where players can buy potions to replenish their health and Inn where players
are able to rest at to also replenish health. The next 3 locations, which are the
"Forest," "Dungeon," and "Castle," each have three monsters and functions that
are unique to their location. The "Forest" contains a goblin, black bear, and wolf as
monsters. Also, players have the option to search the forest to look for random 
items. In the "Dungeon," there are 3 monsters which are: the zombie, slime, and dragon.
This is where the player will find and battle the dragon. However, the player must be
a certain level before the player is able to fight and defeat it. At the "Castle," 
the three enemies are a guard, magician, and black knight. The black knight at the 
"castle" is also considered a boss because of how powerful it is bit is not as
significant as the dragon. In addition, the player can search the castle for
chests in hopes of finding money. However, there is a chance that the player will
have to battle an enemy at the castle when they search for treasure chests.


# Getting Started

(provide command to compile, run, and interact with the program)

In order to compile the program, I had to type "g++ main.cpp textadventure.cpp".
To run the program, I had to type "./a.out".
As you run the program, you have to type numbers as input in order to traverse
through it. There are also statements tell the user exactly what each number
will do when playing the game.

# REQUIREMENTS

The project uses the following components to demonstrate appropriate use of the concepts learned in class.

## Input/Output

(put description of HOW it is used and WHY it is appropriate)

For my input/output, I used cin and cout statements to print out messages to the player
and used cin statements to gather input from the player. This is vital to the player as
it allows the player to navigate and interact with the game I have created.

## Control Flow

(put description of HOW it is used and WHY it is appropriate)

For Control Flow, I used many if statements, else if statements, else statements,
and switch statement. These statements were used for the player to 
navigate throughout the game depending on their input. Also, the statements
determined different outcomes for the player based on their input. Control Flow is
important because it allows the program to function depending on user input.

## Data Structure/Source

(put description of HOW it is used and WHY it is appropriate)

For my data structure, I used a vector for the player's "health". The size of 
the vector "health" represented the capacity that the player could store their
health in. Within the vector, every slot would be filled with "FILLED" which 
represented how much of the health capacity was filled with health. It was used 
in this way because I needed a way to separate the capacity of health a player 
could have without actually changing the size. In addition, the player could lose
health, so a health counter would not work in keeping track of how much health a 
player would have.


## Function

(put description of HOW it is used and WHY it is appropriate)

I used my ability to create functions as well as I could in order to shorten my
int main() as much as possible. The functions were also used to prevent myself from
writing similar code over and over. For instance, I made the function 
"void encounterMonster(std::string monsterName)" in order to go through the process
of having to battle a monster. There are many more functions that I created, but that 
is an example of one of the many functions I made.

## Class

 (put description of HOW it is used and WHY it is appropriate)

 The class I created was used to create functions for the game I was making. By 
 creating it class, I am able to also able to make my int main() less chaotic as
 it could have been if the functions were created within my int main(). The functions
 were used to determine outcomes based on the user input and what the player wants
 to do accordingly to how the game is played. 
