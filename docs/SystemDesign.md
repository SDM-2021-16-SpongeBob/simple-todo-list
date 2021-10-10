# System Design

## CAPABILITY


Tic-tac-toe (or Noughts and crosses, Xs and Os) is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three respective marks in a horizontal, vertical, or diagonal row wins the game.The game is to be played between the computer and a human opponent. Either of the two can start first.

There are two things to implement for creating the game: the game logic and the game user interface.

There are various possibilities for creating the UI on Windows, including Win32 API, MFC, ATL, GDI+, DirectX, etc. In this article, I will show how we can use the same game logic implementation to build applications using various technologies. We will create two applications, one with Win32 API and one with C++/CX for the Windows Runtime.

## PROCESSES

1. Draw the board

   First, you have to draw the board, which is made up of a 3 x 3 grid of squares. This means it has three rows of three squares. Some people play with a 4 x 4 grid, but that is for more advanced players, and we will focus on the 3 x 3 grid here.

2. Have the first player go  first

   Though traditionally, the first player goes with "X", you can allow the first player to decide whether he wants to go with "X"s or "O"s. These symbols will be placed on the table, in the attempt to have three of them in a row. If you're going first, then the best move you can make is to move into the center. This will maximize your chances of winning, since you'll be able to create a row of three "X"s or "O"s in more combinations (4) this way than if you chose a different square.

3. Have the second player go second

   After the first player goes, then the second player should put down his symbol, which will be different from the symbol of the first player. The second player can either try to block the first player from creating a row of three, or focus on creating his or her own row of three. Ideally, the player can do both.

4. Keep alternating moves until one of the players has drawn a row of three symbols or until no one can win.

   The first player to draw three of his or her symbols in a row, whether it is horizontal, vertical, or diagonal, has won tic-tac-toe. However, if both players are playing with optimal strategy, then there's a good chance that no one will win because you will have blocked all of each other's opportunities to create a row of three.  

5. Keep practicing

   Contrary to popular belief, tic-tac-toe isn't purely a game of chance. There are some strategies that can help you optimize your skills and to become an expert tic-tac-toe player. If you keep playing, you'll soon learn all of the tricks to making sure you win every time -- or, at least, you'll learn the tricks to make sure you never lose. Its like 0's and x's.


## TECHNOLOGY


It was just about a year ago that Caltech scientists in the laboratory of Lulu Qian, assistant professor of bioengineering, announced they had used a technique known as DNA origami to create tiles that could be designed to self-assemble into larger nanostructures that carry predesigned patterns. They chose to make the world's smallest version of the iconic Mona Lisa. The feat was impressive, but the technique had a limitation similar to that of Leonardo da Vinci's oil paints: Once the image was created, it could not easily be changed. Now, the Caltech team has made another leap forward with the technology. They have created new tiles that are more dynamic, allowing the researchers to reshape already-built DNA structures. When Caltech's Paul Rothemund (BS '94) pioneered DNA origami more than a decade ago, he used the technique to build a smiley face. Qian's team can now turn that smile into a frown, and then, if they want, turn that frown upside down. And they have gone even further, fashioning a microscopic game of tic-tac-toe in which players place their X's and O's by adding special DNA tiles to the board. "We developed a mechanism to program the dynamic interactions between complex DNA nanostructures," says Qian. "Using this mechanism, we created the world's smallest game board for playing tic-tac-toe, where every move involves molecular self-reconfiguration for swapping in and out hundreds of DNA strands at once."


## ARCHITECTURE
