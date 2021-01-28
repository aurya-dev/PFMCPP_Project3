/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct for each of your 10 types. i.e.:
*/
struct CarWash
{

};
/*
2) Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


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
