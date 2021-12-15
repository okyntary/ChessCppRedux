# ChessCppRedux

ChessCpp is a program written in C++ that runs in the console, that allows you to simulate a game of chess, and to play against a basic chess AI. I wrote it over the first two weeks of December 2021.

A small demo of ChessCpp is available in the /Demo folder.

Since it's written in Visual Studio, I expect that only Windows users can use it. I haven't checked how to compile Visual Studio C++ files in other OS's, so I'm not certain if that's possible, but I suspect that all that's required for compilation are the .cpp and .h files.

# Features

The player can enter moves into the console to play them on the chessboard, against a rudimentary AI. ChessCpp does move validation to ensure that only legal moves can be played at any time.

There are a whole host of other features, including:
  - Displaying the move history
  - Displaying the legal moves at any point in time
  - Undoing the last move played on the chessboard.

Check out the help message in the ChessCpp for all the available commands and features.

# Future Improvements

Some possilbe future improvements:
  - Feature for alternative variants of chess (e.g. Fischer random)
  - Feature to set up any initial board state
  - More sophisticated move inputs (e.g. using "Ng7" instead of "f5g7")
  - More sophisticated evaluation engine and AI (I will have to study this)

# Design Details & Decisions

I started with an MVC design that I learnt about in my software engineering module (CS2103). I decided to adapt the observer pattern to parts of the architecture.

That was the plan, anyway. I'd say I stuck to it fairly well, but I did introduce some unintended coupling which could have gone wrong if I had decided to work on the project further.

After completing the main body of the chess software, I added the analysis portion afterwards, so that the player could play against _some_ sort of AI, instead of having to play both sides.

# Retrospective

This was my second concerted attempt at writing a chess program that runs on the console in C++. The last attempt petered out - failed, to be honest - so I took another stab at it over the holidays, which was much more successful.

I took it more slowly this time, learning more about the details of C++ before jumping into actually coding. learncpp.com was a godsend for learning the features and best practices of modern C++, much better than some of the other books I tried to study. One thing that I had to get used to was the use of C++ smart pointers, which I was initially very hesitant about using. They required knowledge of how memory management was handled in C++, but they ultimately turned out to be simpler to use than I had originally anticipated.

Something else I improved on this time was beginning with a proper structure. The software engineering module I took was very helpful in this regard, and I used an MVC structure and observer pattern that was taught to plan the overall architecture of the program.

I'm glad with the lessons I learnt and the progress I made with this project, but I think it's time I worked on something else.

okyntary - 15 Dec 21