# MKS65 - THE FINAL FRONTIER

## FINAL PROJECT PROPOSAL

#### Team Members
- Tammy Chen
- Bernard Wang 
- Alvin Yao

#### Description of Project

CMineSweeper-Multiplayer will be our team&#39;s attempt at recreating the amazing single-player computer game. MineSweeper. The objective of the game is to clear a board (can be both square/rectangular) containing hidden mines with activating any of them. The neighboring mines will give the user a number clue as to how many mines surround it.

**Description of User Interface:**

Once the make file is run, the user will be guided to the main menu where they will have a choice of beginner, intermediate, or advanced level. The main difference amongst all these levels will be the grid size. The user will also have the choice of building their own custom grid. After the user has chosen their preferences, they can create the new game. Once they are in the game, the first click of the user onto the grid will determine all the locations of the mines. The user can then enjoy the regular game of Minesweeper by clicking on other grid areas using the given clues. The user can also mark down the possible mines. There will be two number displays, time and number of mines left. If the user activates a mine, the game will be over &amp; the screen will display options of retrying or exiting the game. If the user wins, the screen will display options of playing again or exiting the game.

**Description of Technical Design:**

- Shared memory and semaphores to save user login information + leaderboard (\*)
  - Leadership board will be implemented if there is sufficient time
- SDLfor low-level access to keyboard, graphics, and mouse
- Allocating memory to store the current status of the gameboard
- Signals for keywords to change settings &amp; exit game

**Data Structures &amp; Algorithms:**

Arrays &amp; Structs

- Used for user login information &amp; gameboard
- For the gameboard, we might incorporate aspects with a struct to be more efficient (tbd)
  - We might try to incorporate structs into the mines

Algorithms

- Research Minesweeper algorithm ([this](https://quantum-p.livejournal.com/19616.html) &amp; [this](https://massaioli.wordpress.com/2013/01/12/solving-minesweeper-with-matricies/))
  - Might implement recursion (not too sure which method will be more efficient yet)
- Might use Quick Sort for leadership board

**Timeline of Expected Completion Dates &amp; Roles**

- __JAN 6TH:__ Write board.c which should have functions that will build boards (Tammy), place mines (Alvin), and print the answer to the board (Bernard)
- __JAN 11TH:__ Write play.c which should be able to run a functioning Minesweeper game with all the given rules and place mine-holders
  - All of us will work together on this!
  - This is when the MVP (Minimum Viable Product)should be done
- __JAN 13TH:__ Check the game for any bugs that can be fixed, make the game more efficient (maybe recursion)
  - All of us will work together on this!
- __JAN 15TH:__ Add on to play.c by adding the main menu with different options for user input, a display screen for winning/losing, implement timer in-game, and mine count
  - Main Menu (Tammy)
  - Display Screen for Winning/Losing (Alvin)
  - Timer &amp; Mine Count (Bernard)
- __JAN 17TH:__ Update README.md, check for last-minute bugs
  - All of us will work on this!
  - Might implement leaderboard &amp; user login
