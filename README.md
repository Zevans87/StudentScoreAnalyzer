# StudentScoreMenu
COSC-1336 - College Assignment

Project Overview - This C++ programs was created to read an input file of data that contained student names
and their test scores. It then provides an interactive menu to analyze the students academic performance. 
This was created while at UHV for COSC-1336. This was developed while using programming fundamentals such 
as file handling, conditional logic, loops, and functions.

Objectives of the program - Reads and processes structered data from a text file and provides an interactive 
menu for the user. Performs an analysis of the test scores and converts to a letter grade based on conditions.
Uses clearly defined functions.

Menu features of the program - 
  * List Students with Letter Grade : This option will display each student's name and their averages score by converting
      score to a letter grade.
  * List Students Who Made All A's : This option will show the students whose lowest score is 90 or higher.
  * Find Top Scorer on a Specific Test : This option will prompt the user for a test number between 1-3 and shows
      the student with the highest score on that test.
  * List Students with Continuous Progress : This option will display the students whose test scores increase
      consecutively ( Test 1 < Test 2 < Test 3 ).
  * Count Students by Letter Grade for a Specific Test : This option will allow a user to enter a letter grade
      and test number. The program will then return how many students earned that grade on the selected test.
  * Exit - This option will exit the program entirely.

Files - 
  * Main source file : Assignment4.cpp
  * Input file containing names and test scores : studentData.txt

How to run - 
  * Use a C++ compiler to compile the program.
  * Ensure that the file "studentData.txt" exists in the same directory.
