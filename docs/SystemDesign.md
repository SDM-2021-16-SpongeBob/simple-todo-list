# System Design

## CAPABILITY


Tic-tac-toe (or Noughts and crosses, Xs and Os) is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three respective marks in a horizontal, vertical, or diagonal row wins the game.The game is to be played between the computer and a human opponent. Either of the two can start first.

There are two things to implement for creating the game: the game logic and the game user interface.

There are various possibilities for creating the UI on Windows, including Win32 API, MFC, ATL, GDI+, DirectX, etc. In this article, I will show how we can use the same game logic implementation to build applications using various technologies. We will create two applications, one with Win32 API and one with C++/CX for the Windows Runtime.




## TECHNOLOGY


It was just about a year ago that Caltech scientists in the laboratory of Lulu Qian, assistant professor of bioengineering, announced they had used a technique known as DNA origami to create tiles that could be designed to self-assemble into larger nanostructures that carry predesigned patterns. They chose to make the world's smallest version of the iconic Mona Lisa. The feat was impressive, but the technique had a limitation similar to that of Leonardo da Vinci's oil paints: Once the image was created, it could not easily be changed. Now, the Caltech team has made another leap forward with the technology. They have created new tiles that are more dynamic, allowing the researchers to reshape already-built DNA structures. When Caltech's Paul Rothemund (BS '94) pioneered DNA origami more than a decade ago, he used the technique to build a smiley face. Qian's team can now turn that smile into a frown, and then, if they want, turn that frown upside down. And they have gone even further, fashioning a microscopic game of tic-tac-toe in which players place their X's and O's by adding special DNA tiles to the board. "We developed a mechanism to program the dynamic interactions between complex DNA nanostructures," says Qian. "Using this mechanism, we created the world's smallest game board for playing tic-tac-toe, where every move involves molecular self-reconfiguration for swapping in and out hundreds of DNA strands at once."


## ARCHITECTURE
