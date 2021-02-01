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

/*
struct CarWash
{

};
*/

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

struct DrillMaschine 
{
    // Size of the drill chucks
    int sizeOfDrillChucks = 10;
    // Number of modes
    int numOfModes = 2;
    // Motor power
    int motorPower = 1500;
    // Cable length
    float cableLength = 1.5f;
    // Drilling speed
    int drillingSpeed = 3000;

    struct DrillBit
    {
        int drillChuck = 10;
        int length = 140;
        std::string material = "steel";
        bool isHardened = true;
        bool isForWood = true;

        void drill(int depth = 10);
        bool isStuck();
        bool isToHot();


    };

    // Drill hole
    void drillHole(DrillBit bit);
    // screw screws 
    void screwScrew(int speed, bool screwIn);
    // load the accu
    void loadAccu();

    DrillBit myDrillBit;
};


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

struct SodaMaker
{
    // Water pressure
    int waterPressure = 5;
    // Size of container
    int containerSize = 2;
    // volume of soda tank 
    int sodaTankVolume = 500;
    // years of guarantee
    int guaranteeYears = 2;
    // number of bottles
    int numBottles = 1;

    // make soda water
    void makeSodaWater(int pressButtonDuration);
    // install soda tank
    void installSodaTank();
    // push the big button
    void pushBigButton();
};



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

 struct DishWasher
 {
    // volume of washing room
    int washingRoomVolume = 5;
    // number of programs
    int numOfPrograms = 12;
    // duration of duration of the washing process
    int washingDuration = 120;
    // amount of detergen tank
    int amountDetergenTank = 200;
    // duration of timer
    int timerDuration = 360;

    // wash dishes
    void washDishes(int programNumber);
    // dry dishes
    void dryDishes(int duration, int temperature);
    // start at timer
    void startAtTimer(int startMinutesLater);   
 };

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

struct GasGrill
{
    // size of grill plate
    int grillPlateSize = 50;
    // volume of coal
    int volumeOfCoal = 5;
    // number level positions
    int numLevelPositions = 3;
    // heat temperature
    int heatTemperature = 1000;
    // port size of gas tank 
    int gasTankPortSize = 5;

    // grill sausage
    void grillSausage(int levelPosition);
    // light the flame
    void ligthFlame();
    // turn off the flame
    void turnOffFlame();

};


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

struct Display
{
    // Color Depth
    int colorDepth = 16;
    // Pixel width
    int pixelWidth = 1024;
    // Pixel height
    int pixelHeight = 768;
    // Power consumption
    int powerConsumption = 400;
    // Brightness
    int brightness = 5;

    struct DisplayCable
    {
        int length = 150;
        std::string color = "black";
        std::string type = "LVDS";
        int version = 2;
        bool isHighSpeed = true;

        bool isConnected(bool highSpeed = true);
        bool isNetworkConnected();
        std::string getResolution();

    };

    // Display text
    void displayText(DisplayCable myCable);
    // Display image
    void displayImage(DisplayCable myCable);
    // Turn backlight off
    void turnOffBackligth(); 

    DisplayCable myCable;

};




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

 struct Drumpad 
 {
    // Number of Pads
    int numPads = 16;
    // Pad sensitivity
    int padSensivity = 127;
    // Width of a Pad
    int padWidth = 20;
    // Height of Pad
    int padHeight = 20;
    // Pad color Brightness 
    int padColorBrightness = 40;

    // Lit pad
    void litPad();
    // Check hit pressure
    void checkHitPreassure();
    // Unlit pad 
    void unlitPad();
 };

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

 struct VolumeControl 
 {
    // Knob diameter
    int knobDiameter = 10;
    // Knob height
    int knobHeight = 20;
    // Knob range
    int knobRange = 270;
    // Poti resitance 
    int potiResitance = 1200;
    // Number of cable connections
    int numCableConnection = 3;

    // Increase master volume
    void increaseMasterVolume(int newVolume);
    // Decrease master volume
    void decreaseMasterVolume(int newVolume);
    // Switch off volume
    void switchOffVolume();
 };

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

 struct PlayButton 
 {
    // Button width
    int buttonWidth = 10;
    // Button height
    int buttonHeight = 5;
    // Switch depth
    int switchDepth = 2;
    // LED Brightness
    int ledBrightness = 20;
    // Number of cable connections
    int numCableConnection = 2;

    // Lit green
    void litGreen();
    // Flash green
    void flashGreen(int pulseSpeed);
    // Start pattern
    void startPattern(int patternId);
 };

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

 struct RecordButton
 {
    // Button width
    int buttonWidth = 10;
    // Button height
    int buttonHeight = 5;
    // Switch depth
    int switchDepth = 2;
    // LED Brightness
    int ledBrightness = 20;
    // Number of cable connections
    int numCableConnection = 2; 

    // Lit red
    void litRed();
    // Flash red
    void flashRed(int pulseSpeed);
    // Record Midi Events
    void recMidiEvents(int midiPort, int midiChannel);

 };

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

 struct DrumMachine
 {
    // Display
    Display display;
    // Drumpads
    Drumpad drumpad;
    // Volume Control
    VolumeControl volControl;
    // Play Button
    PlayButton playButton;
    // Record Button
    RecordButton recButton;
    
    // Launch drum samples
    void playDrumSample(int sampleId);
    // Play pattern
    void playPattern(int patternId);
    // Record pattern
    void recPattern(int patternLength = 4);
 };

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
