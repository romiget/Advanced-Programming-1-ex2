# Advanced-Programming-1 ex2
# This project is for the second assignment in the course 'Advanced Programming 1' in Bar Ilan university.
# This project is built on top of the previous assignment.

# In this assignment, we've added a server-client interaction. In the previous project, you had to supply the flower database and the file of unclassified flowers in the run command.
# Here, you actually run two programs: one for the server and one for the client.
# As for the server program, you still need to supply the flower databse in the run command. But instead of supplying with a file of unclassified flowers immediately, the server waits for a client connection.
# The client supplies a file of unclassified flowers, and a place to write the classifications of those flowers, in the run command.
# At the end of the interaction the client and server sockets close.

# We have implemented this using sockets with a TCP protocol.

# Since there are two programs, to run them, you will need to open two instances of the terminal
# It's always good to make sure you have the same version of g++ as us (11.2.0), and more importantly make sure you have g++ installed. You can do this using:
# $ whereis g++
# $ which g++
# $ g++ --version

# In the terminal instance which should run the server program, navigate to Advanced-Programming-1-ex2/Server Side using cd <folder> and ls (to see which files are available)
# To compile, use the command $ g++ -o output *.cpp
# * You can write whatever you want after -o as long as it's not a file name that exists in the directory already
# Then, run the program using $ ./output
# * "output" corresponds to what I wrote after -o in the compilation, so if you wrote "-o blablabla" you should also write "./blablabla"
# The server then waits for the client connection

# Go to the second instance of terminal, and navigate to Advanced-Programming-1-ex2/Client_Side
# Compilation is the same as the server side
# To run the program, you will need to supply two paths. The first one is the file of unclassified flowers, and the second is the file to which the program writes.
# The files should lie in the folder cmake-build-debug
# The second file doesn't have to exist yet, but make sure it is empty if it does
# The run command is $ ./output cmake-build-debug/<unclassified>.csv cmake-build-debug/<classified>.csv

# The program will quickly finish, and you should find a file in Client_Side/cmake-build-debug that will hold the classifications of the flowers you sent.
