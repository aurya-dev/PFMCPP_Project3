 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

//--------------------------------------------------------
// DrillMachine
//--------------------------------------------------------

struct DrillMachine 
{
    int sizeOfDrillChucks = 10;
    int numOfModes = 2;
    int motorPower = 1500;
    float cableLength = 1.5f;
    bool accuTooWeak = false;
    int screwTime = 0;

    struct DrillBit
    {
        int drillChuck = 10;
        int length = 140;
        std::string material = "steel";
        bool isHardened = true;
        bool isForWood = true;
        bool isStucked = false;
        float maxTemperature = 303.3f;

        void drill(int depth = 10);
        bool isDull(float currentTemperature);
        bool isToHot(float currentTemperature);
    };

    bool drillHole(DrillBit bit);
    bool screwScrew(int speed, bool screwIn);
    void loadAccu();

    DrillBit myDrillBit;
};


void DrillMachine::DrillBit::drill(int depth) 
{
    isStucked = (depth > length);
}


bool DrillMachine::DrillBit::isDull(float currentTemperature) 
{
    return isToHot(currentTemperature);
}


bool DrillMachine::DrillBit::isToHot(float currentTemperature)
{
    return currentTemperature > maxTemperature;
}


bool DrillMachine::drillHole(DrillBit bit)
{
    if(bit.drillChuck <= sizeOfDrillChucks) 
    {
        bit.drill(15);
        return true;
    }
    return false;
}


bool DrillMachine::screwScrew(int speed, bool screwIn)
{
    if(accuTooWeak == false) 
    {
        if(screwIn) 
            screwTime = speed * 5;
        else 
            screwTime = speed * 6;
        return true;
    }
    return false;
}

void DrillMachine::loadAccu()
{
    accuTooWeak = false;
}



//--------------------------------------------------------
// SodaMaker
//--------------------------------------------------------

struct SodaMaker
{
    float waterPressure = 5.0f;
    int containerSize = 2;
    float sodaTankVolume = 0.5f;
    int sparklingWaterFactor = 2;
    bool sodaTankEmpty = false;

    void makeSodaWater(float waterVolume);
    void installSodaTank();
    std::string getManufacturerName();
};


void SodaMaker::makeSodaWater(float waterVolume)
{
    if(!sodaTankEmpty && waterVolume <= sodaTankVolume)
        std::cout << "make sparklingWater" << std::endl;
}


void SodaMaker::installSodaTank()
{
    sodaTankEmpty = false;
}


std::string SodaMaker::getManufacturerName() 
{
    return "SodaStream";
}


//--------------------------------------------------------
// DishWasher
//--------------------------------------------------------

 struct DishWasher
 {
    float washingRoomVolume = 5.2f;
    int numOfPrograms = 12;
    int maxWashingDuration = 120;
    float maxWashTemperature = 90.0f;
    int timerDuration = 360;
    int waitMilliSec = 0;

    bool washDishes(int programNumber);
    bool dryDishes(int duration, float temperature);
    void startAtTimer(int startMinutesLater);   
 };


bool DishWasher::washDishes(int programNumber)
{
    return ! (programNumber > 12);
}


bool DishWasher::dryDishes(int duration, float temperature)
{
    return (duration <= maxWashingDuration || temperature <= maxWashTemperature);
}


void DishWasher::startAtTimer(int startMinutesLater)
{
    waitMilliSec = startMinutesLater * 1000;
    washDishes(1);    
} 

//--------------------------------------------------------
// GasGrill
//--------------------------------------------------------

struct GasGrill
{
    double grillPlateSize = 50;
    int volumeOfCoal = 5;
    int numLevelPositions = 3;
    int heatTemperature = 1000;
    int gasTankPortSize = 5;
    int distanceToCoal = 5;
    float currentTemperature = 0.0f;

    void grillSausage(int levelPosition);
    bool lightFlame();
    void turnOffFlame();
};


void GasGrill::grillSausage(int levelPosition)
{
    lightFlame();
    distanceToCoal = levelPosition * 5;
}


bool GasGrill::lightFlame()
{
    currentTemperature = 932.3f;
    return true;
}


void GasGrill::turnOffFlame()
{
    currentTemperature = 0.0f;
}


//--------------------------------------------------------
// Display
//--------------------------------------------------------

struct Display
{
    int colorDepth = 16;
    int pixelWidth = 1024;
    int pixelHeight = 768;
    float powerConsumption = 0.4f;
    char activePort = 'd';
    std::string currentText = "";
    std::string currentImage = "/media/default.png";

    struct DisplayCable
    {
        int length = 150;
        std::string color = "black";
        std::string type = "LVDS";
        int version = 2;
        bool isHighSpeed = true;
        int currentTransferSpeed = 14400; 
        bool networkActive = false;

        bool isConnected(bool highSpeed = true);
        bool isNetworkConnected();
        std::string getResolution();
    };

    void displayText(std::string text);
    void displayImage(std::string imageFileURL);
    char getActivePort(); 

    DisplayCable myCable;
};


bool Display::DisplayCable::isConnected(bool highSpeed)
{
    return highSpeed && currentTransferSpeed > 10000;
}


bool Display::DisplayCable::isNetworkConnected()
{
    return networkActive;
}


std::string Display::DisplayCable::getResolution()
{
    return "1024x768";
}


void Display::displayText(std::string text)
{
    if(myCable.isConnected(true))
        currentText = text;
}


void Display::displayImage(std::string imageFileURL)
{
    if(myCable.isConnected(true))
        currentImage = imageFileURL;
}


char Display::getActivePort()
{
    return activePort;
} 


//--------------------------------------------------------
// Drumpad
//--------------------------------------------------------

 struct Drumpad 
 {
    int numPads = 16;
    double padSensivity = 3453452345345;
    float padWidth = 20.5f;
    float padHeight = 20.5f;
    char defaultSoundBank = 'a';
    bool padLightOn = false;
    double currentPadSensivity = 6004534534; 

    void litPad();
    double checkHitPreassure();
    void unlitPad();
 };


 void Drumpad::litPad()
 {
     padLightOn = true;
 }


 double Drumpad::checkHitPreassure()
 {
     return currentPadSensivity;
 }


void Drumpad::unlitPad()
{
    padLightOn = false;
}

//--------------------------------------------------------
// VolumeControl
//--------------------------------------------------------

 struct VolumeControl 
 {
    float knobDiameter = 10.3f;
    float knobHeight = 20.7f;
    int knobRange = 270;
    double potiResitance = 12000034523462;
    int numCableConnection = 3;
    int currentVol = 23;

    void increaseMasterVolume(int newVolume);
    void decreaseMasterVolume(int newVolume);
    bool isMaxVolume();
 };


void VolumeControl::increaseMasterVolume(int newVolume) 
{
    if(newVolume < currentVol) 
        currentVol = newVolume;
}


void VolumeControl::decreaseMasterVolume(int newVolume) 
{
    if(newVolume > currentVol) 
        currentVol = newVolume;
}


bool VolumeControl::isMaxVolume()
{
    return (currentVol == 127);
}

//--------------------------------------------------------
// PlayButton
//--------------------------------------------------------

 struct PlayButton 
 {
    float buttonWidth = 10.8f;
    float buttonHeight = 5.2f;
    float switchDepth = 2.0f;
    int ledBrightness = 20;
    int numCableConnection = 2;
    bool lightOn = false;

    void litGreen();
    void flashGreen();
    std::string getLabelName();
 };


 void PlayButton::litGreen()
 {
     lightOn = true;
 }


 void PlayButton::flashGreen() 
 {
    litGreen();
 }


 std::string PlayButton::getLabelName()
 {
     return "Play";
 }


//--------------------------------------------------------
// RecordButton
//--------------------------------------------------------

 struct RecordButton
 {
    float buttonWidth = 10.7f;
    float buttonHeight = 5.8f;
    float switchDepth = 2.0f;
    int ledBrightness = 20;
    int numCableConnection = 2; 
    bool switchOn = false;
    int recMidiPort = 0;
    int recMidiChannel = 0;

    bool isPressed();
    void flashRed();
    void recMidiEvents(int midiPort, int midiChannel);
 };


bool RecordButton::isPressed()
{
    return switchOn;
}


void RecordButton::flashRed()
{
    std::cout << "The record button flash very beautyful!" << std::endl;  
}


void RecordButton::recMidiEvents(int midiPort, int midiChannel)
{
    recMidiPort = midiPort;
    recMidiChannel = midiChannel;
}

//--------------------------------------------------------
// DrumMachine
//--------------------------------------------------------

 struct DrumMachine
 {
    Display display;
    Drumpad drumpad;
    VolumeControl volControl;
    PlayButton playButton;
    RecordButton recButton;
    
    std::string getPatternName (int patternId);
    void playPattern(int patternId);
    void recPattern(int patternLength = 4);
 };


std::string DrumMachine::getPatternName (int patternId)
{
    switch (patternId)
    {
        case 1:
            return "Pattern 1";
        case 2:
            return "Pattern 2";
        default:
            return "Pattern X";
    }
}


void DrumMachine::playPattern(int patternId)
{
    switch (patternId)
    {
        case 1:
            std::cout << "Play [Pattern 1]" << std::endl;
            break;
        case 2:
            std::cout << "Play [Pattern 2]" << std::endl;
            break;
        default:
            std::cout << "Play [Pattern X]" << std::endl;
    }
}


void DrumMachine::recPattern(int patternLength)
{
    if(patternLength > 0)
        std::cout << "Pattern recording with pattern length " << patternLength << std::endl;
}

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
