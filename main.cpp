/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine` and 
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
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
Thing 5) Display
5 properties:
    1) Color Depth
    2) Pixel width
    3) Pixel height
    4) Power consumption
    5) Brightness
3 things it can do:
    1) Display text
    2) Display image
    3) Turn backlight off 
 */

/*
Thing 6) Drumpads
5 properties:
    1) Number of Pads
    2) Pad sensitivity
    3) Width of a Pad
    4) Height of Pad
    5) Pad color Brightness 
3 things it can do:
    1) Lit pad
    2) Check hit pressure
    3) Unlit pad 
 */

/*
Thing 7) Volume Control
5 properties:
    1) Knob diameter
    2) Knob height
    3) Knob range
    4) Poti resitance 
    5) Number of cable connections
3 things it can do:
    1) Increase master volume
    2) Decrease master volume
    3) Switch off volume
 */

/*
Thing 8) Play Button
5 properties:
    1) Button width
    2) Button height
    3) Switch depth
    4) LED Brightness
    5) Number of cable connections
3 things it can do:
    1) Lit green
    2) Flash green
    3) Start pattern
 */

/*
Thing 9) Record Button
5 properties:
    1) Button width
    2) Button height
    3) Switch depth
    4) LED Brightness
    5) Number of cable connections
3 things it can do:
    1) Lit red
    2) Flash red
    3) Record Midi Events
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
