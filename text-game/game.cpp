/*TODO
4. Add this_thread::sleep_for(std::chrono::milliseconds(100)) to reduce speed of text render
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include<array>
#include <vector>
using namespace std;

class Room {
  public:
  string roomName;
  array<string,3> vantages{"Left","Forward","Right"};
  vector<string> observationsOfRoom;
  vector <string> leavingOptions; 
  Room(string z){
    roomName = z;
  };
};

Room loadCurrentRoom(int coordinates[2], Room Foyer, Room Kitchen,Room MainHall, Room LivingRoom,  Room MasterBedroom, Room Attic){
  if (coordinates[0] == 0 && coordinates[1]==0){
    return Foyer;
  }
  else if (coordinates[0] == 0 && coordinates[1]==1){
    return Kitchen;
  }
  else if (coordinates[0] == 1 && coordinates[1]==0)
  {
    return MainHall;
  }
  else if (coordinates[0] == 1 && coordinates[1]==1)
  {
    return LivingRoom;
  }
  else if (coordinates[0] == 2 && coordinates[1]==0)
  {
    return MasterBedroom;
  }else if (coordinates[0] == 2 && coordinates[1]==1){
    return Attic;
  }
};

int displayPrompts(Room currentRoom){
  cout << "\n- - - - - - - - - - - - - - -" << endl;
  cout << "Where do you look? Options are:" << endl;
  for(int i = 0; i < 3 ; i++){
    cout << " | " << currentRoom.vantages[i]; 
  };
  return 0; 
}

// Gets user actions within the room 
vector<bool> getUserInput(Room currentRoom, Room Foyer, bool hasKey, bool hasSeenGhost, bool hasUnlockedSafe, bool hasLostAmulet){
  bool hasKeyTemp;
  bool hasSeenGhostTemp;
  bool hasUnlockedSafeTemp = false;
  bool hasLostAmuletTemp;
  displayPrompts(currentRoom);
  string userInput;
  cout << "\nChoose a direction to look, or type 'Leave': ";
  cin >> userInput;
  cout << "\n. . .\n" << endl;
  if(userInput.compare("Leave") == 0){
    return {false, hasKeyTemp, hasSeenGhostTemp, hasUnlockedSafeTemp, hasLostAmuletTemp};
  }else if(userInput.compare("Left") == 0){
    if(currentRoom.roomName.compare("Foyer") == 0){
      hasKeyTemp = true;
    }
    cout << currentRoom.observationsOfRoom[0] << endl;
  }else if(userInput.compare("Forward") == 0){
      if(currentRoom.roomName.compare("Living Room") == 0 && hasLostAmulet ){
        hasSeenGhostTemp = true;
        cout << "The amulet glows white-hot. From the setting of the jewelry, the sheer and silvery presence of a ghost leaps out through the window, escaping into the night." << endl;
        return {true, hasKeyTemp, hasSeenGhostTemp, hasUnlockedSafeTemp};
      }else if(currentRoom.roomName.compare("Kitchen") == 0){
        hasLostAmuletTemp = true;
        cout << currentRoom.observationsOfRoom[1];
      } else {
        cout << currentRoom.observationsOfRoom[1];
      }    
  }else if(userInput.compare("Right") == 0){
      if(currentRoom.roomName.compare("Master Bedroom") == 0 && hasKey){
          cout<<"\tYou used the key on the safe, inside is a map of the house with an arrow pointing to the kitchen.\n"
              <<"\tAnother points to the Living Room, which has a cartoonish ghost drawn over the couch. \n"; 
            hasUnlockedSafeTemp = true;
            return {true, hasKeyTemp, hasSeenGhostTemp, hasUnlockedSafeTemp};
       }else{
        cout << currentRoom.observationsOfRoom[2] << endl;
        }}
  else {
    cout << "~  " <<  "invalid entry!" << endl;
  };
  return {true, hasKeyTemp, hasSeenGhostTemp, hasUnlockedSafeTemp};
};

void displayIntroText(){
    cout 
<< "  88888b                          d888888P                     dP       .d888888        dP                              dP\n" 
<<"d8     88    dP       dP             88                        88      d8     88        88                              88\n"                            
<< "88           88       88             88    .d8888b. dP.  .dP d8888P    88aaaaa88a .d888b88 dP   .dP .d8888b.  88d888b d8888P dP    dP 88d888b   d8888b.\n"
<< "88        88888888 88888888          88    88ooood8   8bd8     88      88     88  88    88 88   d8  88ooood8 88    88   88   88    88 88    88 88ooood8 \n"
<< "Y8.   .88    88       88             88    88.  ...  .d88b.    88      88     88  88.  .88 88 .88   88.  ... 88    88   88   88.  .88 88       88.  ... \n "
<<"Y88888P     dP       dP             dP     88888P  dP    dP   dP      88     88   88888P8 8888P     88888P  dP    dP   dP    88888P  dP        88888P \n"
<< endl;
  cout << "\n \n You awake in a room, the wood floor feels warm against your head. 'How did I get here?' you wonder."<<endl;
}

int main(){
  displayIntroText();
  
  /*GAME SETUP*/
  //  ~ Create a class for the Foyer
  Room Foyer = Room("Foyer");
  Foyer.observationsOfRoom = {
    "You see a worn table, the whorls in the woodtop etched deep from years of use. \nOn top of it lies a key, which wisdom would say must have a matching lock.\nYou pickup the key.",
    "You look at the old paintings of a family long gone. There is a sadness behind their eyes. ",
    "You get a glimpse of a door to your right. It matches the table so well, it may have come from the same tree."};
  //  ~ Available Directions to leave
  Foyer.leavingOptions = {"Forward","Right"};
    
  //  ~ Create a class for the Kitchen
  Room Kitchen = Room("Kitchen");
  Kitchen.observationsOfRoom = {"The large countertop holds a recessed sink. It drips slowly, the sound echoing through the silent room.", "You see a large flower-shaped amulet hanging from the cabinet. It is heavy and dingy from being abandoned. You pick up the amulet, maybe you can pawn it later.", "To your right is a pantry with old bronze handles. The sound of faint whispering can be heard coming from behind the door."};
  //  ~ Available Directions to leave}
  Kitchen.leavingOptions = {"Right", "Backward"};

  //  ~ Create a class for the Main Entrance
  Room MainHall = Room("Main Entrance");
  MainHall.observationsOfRoom = {"The grandfather clock ticks loudly, but the hands don't move", "You hear scratching and scurrying from the shadows.", "The chandelier above swings gently, as if someone had just walked by."};
  //  ~ Available Directions to leave
  MainHall.leavingOptions = {"Forward","Left", "Right"};

  //  ~ Create a class for the Living Room
  Room LivingRoom = Room("Living Room");
  LivingRoom.observationsOfRoom = {"The moon shines through the broken window panes, casting eerie shadows on the walls of the living room. They take on the shape of a figure, that seems to be watching you.", "In front of you lies an incomplete set of jewelry, each representing a different type of flower.", "You look in the mirror on your right. It reflects someone who isn't you. A chill runs up your spine.",};
  //  ~ Available Directions to leave
  LivingRoom.leavingOptions = {"Left", "Right", "Backward"};

  //  ~ Create a class for the Master Bedroom 
  Room MasterBedroom = Room("Master Bedroom");
  MasterBedroom.observationsOfRoom = {"The wardrobe door creaks open, revealing empty hangers. A moth flutters out and flies around your head.", "You see a safe under the desk, if only you had a key."};
  //  ~ Available Directions to leave
  MasterBedroom.leavingOptions = {"Left", "Forward"};

  //  ~ Create a class for the Attic
  Room Attic = Room("Attic");
  Attic.observationsOfRoom = {"Dusty, cobweb-covered dolls stare out from the shadows, their eyes seeming to follow your every move.", "The attic is filled with old trunks and boxes, some of them dating back to several centuries with unknown contents inside.", "A rickety old rocking chair moves on its own, as if someone unseen is sitting in it, rocking back and forth."};
  //  ~ Available Directions to leave
  Attic.leavingOptions = {"Left", "Backward"};

  /*GAME LOGIC*/
  int currentRoomCoordinates[2]{0,0};
  bool winCondition = false;
  Room currentRoom = loadCurrentRoom(currentRoomCoordinates, Foyer, Kitchen, MainHall, LivingRoom,  MasterBedroom, Attic);

  bool hasKey = false;
  bool hasSeenGhost = false;
  bool hasUnlockedSafe = false;
  bool hasLostAmulet = false;
  // Operate game until win conditions have been met
  while(!winCondition){

  bool isUserInRoom = true;
  // User explores room until "Leave" command

  while(true){
    if(isUserInRoom == true){
      vector<bool> responseFromRoom = getUserInput(currentRoom, Foyer, hasKey, hasSeenGhost, hasUnlockedSafe, hasLostAmulet);
      isUserInRoom = responseFromRoom[0]; 
      if (responseFromRoom[1] == true){hasKey = true;};
      if (responseFromRoom[2] == true){hasSeenGhost = true;};
      if (responseFromRoom[3] == true){hasUnlockedSafe = true;};
      if (responseFromRoom[4] == true){hasLostAmulet = true;};
    }else{
      winCondition = hasSeenGhost && hasUnlockedSafe;
      break;
    };
  };
  if(winCondition){
    cout << "A mysterious glow envelopes you, you start floating above the ground." << endl;
    cout << "Groups of shades and spirits appear out of the eaves and walls like liquid. They seem to be waving goodbye." << endl;
    cout << "Everything fades to black." << endl;
    cout << "You wake up on the lawn outside." << endl;
    cout << "You've escaped!" << endl;
    return 0; 
  }else{
  for(int i = 0; i < currentRoom.leavingOptions.size() ; i++){
      cout << "-  " << currentRoom.leavingOptions[i] << endl;
  };
  cout << "\n";
  string direction;
  cout << "Where to go: "; 
  cin >> direction;
  int yCoordinateChange = direction.compare("Forward") == 0 ? 1 : direction.compare("Backward") == 0 ? -1 : 0;
  int xCoordinateChange = direction.compare("Right") == 0 ? 1 : direction.compare("Left") == 0 ? -1 : 0;
  //  Check if valid coordinates
  int tempXCoordinate = currentRoomCoordinates[0] += xCoordinateChange;
  int tempYCoordinate = currentRoomCoordinates[1] += yCoordinateChange;
  if((-1 < tempXCoordinate)  && (tempXCoordinate < 3) && (-1 < tempYCoordinate) && (tempYCoordinate < 2 )){
    currentRoomCoordinates[0] = tempXCoordinate;
    currentRoomCoordinates[1] = tempYCoordinate;
    currentRoom = loadCurrentRoom(currentRoomCoordinates, Foyer, Kitchen, MainHall, LivingRoom, MasterBedroom, Attic);
    cout << "\nYou are now entering the " << currentRoom.roomName << ". \n"<< endl; 
  } else{
    cout<<"\nYou hit a wall, ow."<<endl;
    currentRoom = currentRoom;
    cout << "\nYou are still in the " << currentRoom.roomName << ". \n" << endl; 
  }};
  }
  
  return 0;
};
