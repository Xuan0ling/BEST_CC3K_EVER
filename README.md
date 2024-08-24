# **Game Overview**

This game is a dungeon adventure game where the player explores different levels of a dungeon, fights enemies, and collects items to progress. The game is text-based and offers various character classes, each with unique abilities and strengths.

# **How the Game Works**

- The player starts by choosing a character class (e.g., Shade, Vampire, Werewolf, etc.).
- The game is played on a grid where each cell can contain different elements like enemies, items, or the player.
- The objective is to navigate through the dungeon, defeat enemies, collect gold, and reach the exit.

# **Controls and Gameplay**

- Use the following keys to move your character on the grid:
  - j/no : Move Up/North
  - k/so : Move Down/South
  - l/ea : Move Right/East
  - h/we : Move Left/West
  - K/ne : Move top-right/NorthEast
  - J/nw : Move top-left/NorthWest
  - L/se : Move down-right/SouthEast
  - H/sw : Move down-left/SouthWest

- Enemy automatically attacks when the player steps into one of its surrounding cells. Player can attack the enemy using 'a' key followed by a space and the direction of the attack.
  For example: _a ne_, attacks the enemy in the cell that is top-right/NorthEast of the player.
- The combat between player and enemies depend on their races. Each character class has unique attributes that affect gameplay (e.g., health points, attack power).
  
- Potions can be picked up by the player using 'u' key followed by a space and the direction of the potion that is one cell away from the player.
  For example: _u no_, uses the potion in the cell that is top/north of the player.
- There are potions that increase the stats of the player as well as decrease them. Player will find out the effect a potion has only after he uses it.

- Treasures can be picked up by walking over them except the treasure that is being guarded by a dragon. Player has to defeat the dragon to gain the treasure.


# **Winning the Game**

The game ends when the player successfully reaches the exit of the fifth level or when the player’s health drops to zero.

# **Installation and Execution**

- Clone the repository to your local machine.
- Compile the game using the provided makefile or compile the source code directly if needed.
- Run the executable to start the game.

# **Requirements**

- C++ Compiler (e.g., g++)
- Standard C++ Libraries including ncurses library for the DLC.

# **Additional Information**

#### - More Information related to the player races, enemy races, potion effects can be found in Gameplay.pdf
#### - Instructions on how to play the DLC can be found in design.pdf
#### - A detailed explanation into the structure of the code and all the classes can be found in design.pdf
#### - See uml-final.pdf to understand the inheritance and polymorphism of all the classes used.

# Some Screenshots from the game:

<img width="474" alt="Screenshot 2024-08-25 at 3 08 40 AM" src="https://github.com/user-attachments/assets/671582f0-4d90-4654-8a24-b278769d736e">

<img width="721" alt="Screenshot 2024-08-25 at 3 09 01 AM" src="https://github.com/user-attachments/assets/b264d726-6c49-4afa-b46b-f939b75815f7">

<img width="721" alt="Screenshot 2024-08-25 at 3 09 40 AM" src="https://github.com/user-attachments/assets/eca01049-4e91-45ce-80b8-c8877d600c87">

<img width="721" alt="Screenshot 2024-08-25 at 3 10 11 AM" src="https://github.com/user-attachments/assets/43200414-f82c-4282-ab49-84f3f9d7cd17">

<img width="721" alt="Screenshot 2024-08-25 at 3 10 29 AM" src="https://github.com/user-attachments/assets/e7b35630-a53c-4d89-baab-61b81e68e98a">

<img width="721" alt="Screenshot 2024-08-25 at 3 10 37 AM" src="https://github.com/user-attachments/assets/108ecddf-35b7-4eda-a3a4-fd94cee9780b">

<img width="721" alt="Screenshot 2024-08-25 at 3 11 15 AM" src="https://github.com/user-attachments/assets/ebff2fa3-a6d6-432f-ad7f-5cfa10413ca3">

<img width="721" alt="Screenshot 2024-08-25 at 3 11 23 AM" src="https://github.com/user-attachments/assets/6ecb9583-5aaf-43be-822b-40f799958ff8">

<img width="721" alt="Screenshot 2024-08-25 at 3 17 19 AM" src="https://github.com/user-attachments/assets/3c32ed1f-a3c5-49b7-aced-f5e060b2797f">

<img width="721" alt="Screenshot 2024-08-25 at 3 17 41 AM" src="https://github.com/user-attachments/assets/61aa9115-1e4c-4ff2-9696-69c656987757">

## DLC Look:
<img width="721" alt="Screenshot 2024-08-25 at 3 19 08 AM" src="https://github.com/user-attachments/assets/946b2431-9ca5-42ce-8271-ca404e6b303d">



## **Additional Notes**

The game is designed to be extensible, allowing for additional features or character classes to be added with minimal adjustments to the existing codebase.
