# Advanced-Programming-1 ex1
# This project is for the first assignment in the course 'Advanced Programming 1' in Bar Ilan university.

# In this project, we have implemented a KNN (K Nearest Neighbors) algorithm, which is used to categorize certain objects into different groups based on given data.
# What it does, is it searches through a database that was given to us in a .csv file, and interprets it into objects with their given categories, specifically here, we had iris flowers and three different types of iris.
# Then, for a certain yet uncategorized iris flower, it compares it to all other flowers in the database using three different metrics* (for three different output files), and takes the k (given by the user) flowers with the closest distances to our current flower.
# To decide what type it is most probable to be, it checks which type is the most common out of the k flowers we've listed.
# This algorithm works on 15 uncategorized flowers that were given to us.
# *the metrics take 4 different values about the flowers that we were tasked to work with: petal length and width, and cup leaves length and width.

# We have made sure to write this code in a way that will be most convenient for future changes/additions
# * We've generalized the objects we want to measure with a class called Measurable, so that we can compare not only flowers
# * We've generalized the metric function into a super class, and passed a metric object as an argument to functions that use a metric function. This is so we don't have to duplicate code, and so that it's easy to add more metrics if we wish to do so.
# * During our programming sessions, we decided to change the class MeasurableList, which holds all the functions to do with KNN to be a static class, since we didn't need nor want to hold objects inside it.
# This is because if we already had a list of measurable objects given to us, we would need to duplicate all of them into the class, which would be wasteful in time and space.

# To compile the program, navigate to the folder of the projects, which should be called Advanced-Programming-1, using $ cd <folder>. You can use the command $ ls to see which folders are immediately available to you, or you could immediately write the full path.
# Once you're in the folder, write $ g++ *.cpp -o Output
# (You can write whatever name you want after the -o as long as it's not an existing file name in the directory)
# Note: Make sure you have the same version of g++ as us (11.2.0), and more importantly make sure you have g++ installed. You can do this using:
# $ whereis g++
# $ which g++
# $ g++ --version
# To run the program, navigate to the CMake folder using $ cd cmake-build-debug, then type "./Advanced_Programming_1 k", while k is the parameter for the function KNN, so how many flowers you want to compare to for the calculation.
# k values too low might give imprecise results, as not enough samples are taken for comparison, while values too high might also cause inaccuracies, as you will count from most of the samples. Consider that we have 135 classified samples.