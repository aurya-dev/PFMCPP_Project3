/*
Project 3 - Part 1c / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  
*/


/*
Thing 1) Drill Machine
5 properties:
    1) size of drill chucks
    2) number of modes
    3) motor power
    4) cable length 
    5) drilling speed
3 things it can do:
    1) drill hole
    2) screw screw
    3) load the accu
 */

/*
Thing 2) Soda Maker
5 properties:
    1) water pressure
    2) size of container
    3) volume of soda tank 
    4) years of guarantee
    5) number of bottles
3 things it can do:
    1) make soda water
    2) install soda tank
    3) push the big button
 */

/*
Thing 3) Dish Washer
5 properties:
    1) volume of washing room
    2) number of programs
    3) duration of duration of the washing process
    4) amount of detergen tank
    5) duration of timer
3 things it can do:
    1) wash dishes
    2) dry dishes
    3) start at timer
 */

/*
Thing 4) Gas Grill
5 properties:
    1) size of grill plate
    2) volume of coal
    3) number level positions
    4) heat temperature
    5) port size of gas tank 
3 things it can do:
    1) grill sausage
    2) light the flame
    3) turn of the flame
 */

/*
Thing 10) Drum Machine
5 properties:
    1) Display
    2) Drumpads
    3) Volume Control
    4) Play Button
    5) Record Button
3 things it can do:
    1) Launch drum samples
    2) Play pattern
    3) Record pattern
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
