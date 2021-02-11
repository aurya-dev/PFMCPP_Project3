/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()





//--------------------------------------------------------
// DrillMachine
//--------------------------------------------------------

struct DrillMachine 
{
    int sizeOfDrillChucks;
    int numOfModes;
    int motorPower;
    float cableLength;
    bool accuTooWeak;
    int screwTime;

    DrillMachine();

    struct DrillBit
    {
        int drillChuck {10};
        int length {140};
        std::string material {"steel"};
        bool isHardened {true};
        bool isForWood {true};
        bool isStucked {false};
        float maxTemperature {303.3f};

        DrillBit();

        void drill(int depth = 10);
        bool isDull(float currentTemperature);
        bool isToHot(float currentTemperature);
        void printStatus();
    };

    bool drillHole(DrillBit bit);
    bool screwScrew(int speed, bool screwIn);
    void loadAccu();
    void printMachineProperties();

    DrillBit myDrillBit;
};


DrillMachine::DrillMachine() : 
sizeOfDrillChucks(10),
numOfModes(2),
motorPower(1500),
cableLength(1.5f),
accuTooWeak(false),
screwTime(0) 
{}


DrillMachine::DrillBit::DrillBit() {}

void DrillMachine::DrillBit::drill(int depth) 
{
    isStucked = (depth > length);
}


bool DrillMachine::DrillBit::isDull(float currentTemperature) 
{
    std::cout << "Current temperature : " << currentTemperature << std::endl;
    return isToHot(currentTemperature);
}


bool DrillMachine::DrillBit::isToHot(float currentTemperature)
{
    return currentTemperature > maxTemperature;
}


void DrillMachine::DrillBit::printStatus()
{
    std::cout << "Drillbit - Status" << std::endl << "---------------------------------" << std::endl;
    std::cout << "drillChuck: " << drillChuck << std::endl;
    std::cout << "length: " << length << std::endl;
    std::cout << "material: " << material << std::endl;
    std::cout << "isHardened: " << isHardened << std::endl;
    std::cout << "isForWood: " << isForWood << std::endl;
    std::cout << "isStucked: " << isStucked << std::endl;
    std::cout << "maxTemperature: " << maxTemperature << std::endl;  
}


bool DrillMachine::drillHole(DrillBit bit)
{
    if(bit.drillChuck <= sizeOfDrillChucks) 
    {
        std::cout << "Drill process starts!" << std::endl;
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


void DrillMachine::printMachineProperties()
{
    std::cout << "Drill machine proberties" << std::endl << "------------------------------------" << std::endl;
    std::cout << "Size of drill chucks: " << sizeOfDrillChucks << std::endl;
    std::cout << "Number of Modes: " << numOfModes << std::endl;
    std::cout << "Motorpower: " << motorPower << std::endl;
    std::cout << "Cable length: " << cableLength << std::endl;
}




//--------------------------------------------------------
// SodaMaker
//--------------------------------------------------------

struct SodaMaker
{
    float waterPressure;
    int containerSize;
    float sodaTankVolume;
    int sparklingWaterFactor;
    bool sodaTankEmpty;

    SodaMaker();

    void makeSodaWater(float waterVolume);
    void installSodaTank();
    std::string getManufacturerName();
};


SodaMaker::SodaMaker()
{
    waterPressure = 5.0f;
    containerSize = 2;
    sodaTankVolume = 0.5f;
    sparklingWaterFactor = 2;
    sodaTankEmpty = false;
}


void SodaMaker::makeSodaWater(float waterVolume)
{
    if(!sodaTankEmpty && waterVolume <= sodaTankVolume)
        std::cout << "make sparklingWater" << std::endl;
}


void SodaMaker::installSodaTank()
{
    std::cout << "Soda tank installed!" << std::endl;
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
    float washingRoomVolume {5.2f};
    int numOfPrograms {12};
    int maxWashingDuration {120};
    float maxWashTemperature {90.0f};
    int timerDuration {360};
    int waitMilliSec {0};

    DishWasher();

    bool washDishes(int programNumber);
    bool dryDishes(int duration, float temperature);
    void startAtTimer(int startMinutesLater); 
    float printMaxDishElements();  
 };


DishWasher::DishWasher() {}


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


float DishWasher::printMaxDishElements() 
{
    float maxDishElements = washingRoomVolume / 0.5f;
    std::cout << "You can put" << maxDishElements << "dish elements in dish washer" << std::endl;
    return maxDishElements;
}



//--------------------------------------------------------
// GasGrill
//--------------------------------------------------------

struct GasGrill
{
    double grillPlateSize;
    int volumeOfCoal;
    int numLevelPositions;
    int heatTemperature;
    int gasTankPortSize;
    int distanceToCoal;
    float currentTemperature;

    GasGrill();

    void grillSausage(int levelPosition);
    bool lightFlame();
    void turnOffFlame();
    void printImportantInfos();
};


GasGrill::GasGrill() :
    grillPlateSize (50),
    volumeOfCoal (5),
    numLevelPositions (3),
    heatTemperature (1000),
    gasTankPortSize (5),
    distanceToCoal (5),
    currentTemperature (0.0f)
{}


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
    std::cout << "Status: No flame" << std::endl;
    currentTemperature = 0.0f;
}


void GasGrill::printImportantInfos()
{
    std::cout << "GasGrill Info" << std::endl << "-------------------------------" << std::endl;
    std::cout << "grillPlateSize: " << grillPlateSize << std::endl;
    std::cout << "volumeOfCoal: " << volumeOfCoal << std::endl;
    std::cout << "numLevelPositions" << numLevelPositions << std::endl;
}


//--------------------------------------------------------
// Display
//--------------------------------------------------------

struct Display
{
    int colorDepth;
    int pixelWidth;
    int pixelHeight;
    float powerConsumption;
    char activePort;
    std::string currentText;
    std::string currentImage;

    Display();

    struct DisplayCable
    {
        int length;
        std::string color;
        std::string type;
        int version;
        bool isHighSpeed;
        int currentTransferSpeed; 
        bool networkActive;

        DisplayCable();

        bool isConnected(bool highSpeed = true);
        bool isNetworkConnected();
        std::string getResolution();
    };

    void displayText(std::string text);
    void displayImage(std::string imageFileURL);
    char getActivePort(); 
    void printInfo();

    DisplayCable myCable;
};


Display::Display()
{
    colorDepth = 16;
    pixelWidth = 1024;
    pixelHeight = 768;
    powerConsumption = 0.4f;
    activePort = 'd';
    currentText = "";
    currentImage = "/media/default.png";   
}


Display::DisplayCable::DisplayCable()
{
    length = 150;
    color = "black";
    type = "LVDS";
    version = 2;
    isHighSpeed = true;
    currentTransferSpeed = 14400; 
    networkActive = false;
}


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


void Display::printInfo()
{
    std::cout << "Color Depth: " << colorDepth << std::endl;
    std::cout << "Pixel Width: " << pixelWidth << std::endl;
    std::cout << "Pixel Height: " << pixelHeight << std::endl;
}

//--------------------------------------------------------
// Drumpad
//--------------------------------------------------------

 struct Drumpad 
 {
    int numPads;
    double padSensivity;
    float padWidth;
    float padHeight;
    char defaultSoundBank;
    bool padLightOn;
    double currentPadSensivity; 

    Drumpad();

    void litPad();
    double checkHitPreassure();
    void unlitPad();
 };


Drumpad::Drumpad()
{
    numPads = 16;
    padSensivity = 3453452345345;
    padWidth = 20.5f;
    padHeight = 20.5f;
    defaultSoundBank = 'a';
    padLightOn = false;
    currentPadSensivity = 6004534534; 
}

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
    float knobDiameter;
    float knobHeight;
    int knobRange;
    double potiResitance;
    int numCableConnection;
    int currentVol;

    VolumeControl();

    void increaseMasterVolume(int newVolume);
    void decreaseMasterVolume(int newVolume);
    bool isMaxVolume();
 };


VolumeControl::VolumeControl()
{    
    knobDiameter = 10.3f;
    knobHeight = 20.7f;
    knobRange = 270;
    potiResitance = 12000034523462;
    numCableConnection = 3;
    currentVol = 23;
}
 

void VolumeControl::increaseMasterVolume(int newVolume) 
{
    if(newVolume > currentVol) 
    {
        std::cout << "Volume increased from " << currentVol << " to " << newVolume << std::endl;
        currentVol = newVolume;
    }
    else 
        std::cout << "New volume isn't bigger than the current volume" << std::endl;
        
}


void VolumeControl::decreaseMasterVolume(int newVolume) 
{
    if(newVolume < currentVol) 
    {
        std::cout << "Volume decreased from " << currentVol << " to " << newVolume << std::endl;
        currentVol = newVolume;
    }
    else 
        std::cout << "New volume isn't smaller than the current volume" << std::endl;
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
    float buttonWidth;
    float buttonHeight;
    float switchDepth;
    int ledBrightness;
    int numCableConnection;
    bool lightOn;

    PlayButton();

    void litGreen();
    void flashGreen();
    std::string getLabelName();
 };


 PlayButton::PlayButton()
 {
    buttonWidth = 10.8f;
    buttonHeight = 5.2f;
    switchDepth = 2.0f;
    ledBrightness = 20;
    numCableConnection = 2;
    lightOn = false;
 }


void PlayButton::litGreen()
{
    std::cout << "Play button lits green" << std::endl;
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
    float buttonWidth;
    float buttonHeight;
    float switchDepth;
    int ledBrightness;
    int numCableConnection; 
    bool switchOn;
    int recMidiPort;
    int recMidiChannel;

    RecordButton();

    bool isPressed();
    void flashRed();
    void recMidiEvents(int midiPort, int midiChannel);
};


RecordButton::RecordButton()
{
    buttonWidth = 10.7f;
    buttonHeight = 5.8f;
    switchDepth = 2.0f;
    ledBrightness = 20;
    numCableConnection = 2; 
    switchOn = false;
    recMidiPort = 0;
    recMidiChannel = 0;
}


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

    DrumMachine();
    
    std::string getPatternName (int patternId);
    void playPattern(int patternId);
    void recPattern(int patternLength = 4);
};


DrumMachine::DrumMachine()
{
    std::cout << "Constructor of DrumMachine executed" << std::endl;
}


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
    Example::main();
    // DrillMachine
    
    DrillMachine myDrillSuperMaschine;
    std::cout << "The power of the drill machine is : " << myDrillSuperMaschine.motorPower << " W" << std::endl;
    if(myDrillSuperMaschine.accuTooWeak) 
        std::cout << "The accu of the drill machine is to weak" << std::endl;
    else
        std::cout << "The accu is loaded" << std::endl;

    if(myDrillSuperMaschine.myDrillBit.isToHot(1000))
        std::cout << "The bit is to hot" << std::endl;;

    myDrillSuperMaschine.printMachineProperties();

    DrillMachine::DrillBit bit;
    bit.printStatus();

    // SodaMaker

    SodaMaker sodaMachine;
    std::cout << "The brand of the soda maker is: " << sodaMachine.getManufacturerName() << std::endl;
    if (sodaMachine.containerSize == 2)
        sodaMachine.makeSodaWater(0.5f);

    // DishWasher

    DishWasher firstDishWasher;
    std::cout << "The maximal temperature of the washing process is " << firstDishWasher.maxWashTemperature << std::endl;

    if(firstDishWasher.washDishes(4)) 
    {
        firstDishWasher.dryDishes(120, 40.3f);
        std::cout << "Wash and dry process sucessfull!" << std::endl;
    }

    firstDishWasher.printMaxDishElements();

    // GasGrill

    GasGrill propanGrill;
    std::cout << "Grill size: " << propanGrill.grillPlateSize << std::endl;

    propanGrill.currentTemperature = 302.2f;

    propanGrill.turnOffFlame();

    propanGrill.printImportantInfos();
    
    
    // Display

    Display d;
    d.currentText = "Hello world!";
    if(d.activePort == 'b')
        std::cout << "Used port " << d.activePort << std::endl;

    d.printInfo();


    // Drumpad

    Drumpad dPad;
    std::cout << "Pad area: " << dPad.padWidth * dPad.padHeight << std::endl;

    if(dPad.currentPadSensivity > 4)
        std::cout << "Too heavy hit!" << std::endl;
    
    // VolumeControl

    VolumeControl vol;
    vol.increaseMasterVolume(3);
    if(vol.currentVol == 0)
        std::cout << "Nothing to hear!" << std::endl;

    // PlayButton

    PlayButton buttonPlay;

    buttonPlay.litGreen();

    if(buttonPlay.lightOn)
        std::cout << "Sequencer is running..." << std::endl;
       
    // RecordButton

    RecordButton rec;
    std::cout << "Rec channel: " << rec.recMidiPort << std::endl;
    rec.flashRed();

    // DrumMachine

    DrumMachine drumMachine;

    if(drumMachine.volControl.isMaxVolume()) 
    {
        std::cout << "The drummachine is to loud!!!" << std::endl;
        drumMachine.volControl.decreaseMasterVolume(50);
    }
    else 
    {
        std::cout << "The drummaschine is to quite" << std::endl;
        drumMachine.volControl.decreaseMasterVolume(80);
        std::cout << "Current volume is " << drumMachine.volControl.currentVol << std::endl;
    }
        

    std::cout << "good to go!" << std::endl;
}
