/*TODO
1. Author flavor text for rooms
2. Determine win condition flags
3. Separate storyText from flavorText
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
  /*
    Order of Observations = {left, forward, right, [table,key,ghost,window],[locked door]}
  */
  vector<string> observationsOfRoom;
  vector <string> leavingOptions;
  
  int leavingOptionsLength; 
  Room(string z){
    roomName = z;
  };
};

// Please come refactor this later Brandon, can you dynamically check a public class for coordinates and return the name of the room?
// for some reason, I cannot set a string in a derived class

Room getCurrentRoom(int coordinates[2], Room southWest, Room west, Room NorthWest,Room South, Room Center, Room North, Room SouthEast, Room East, Room NorthEast){
  if (coordinates[0] == 0 && coordinates[1]==0){
    return southWest;
  }
  else if (coordinates[0] == 0 && coordinates[1]==1){
    return west;
  }
  else if (coordinates[0] == 0 && coordinates[1]==2)
  {
    return NorthWest;
  }
  else if (coordinates[0] == 1 && coordinates[1]==0)
  {
    return South;
  }
  else if (coordinates[0] == 1 && coordinates[1]==1)
  {
    return Center;
  }
  else if (coordinates[0] == 1 && coordinates[1]==2)
  {
    return North;
  }
  else if (coordinates[0] == 2 && coordinates[1]==0)
  {
    return SouthEast;
  }
  else if (coordinates[0] == 2 && coordinates[1]==1)
  {
    return East;
  };
  return NorthEast;
};

bool getUserInput(Room currentRoom){
  cout << "\n- - -" << endl;
  cout << "Where do you look? Options are: \n" << endl;
  for(int i = 0; i < currentRoom.vantages.size() ; i++){
    cout << "-  " << currentRoom.vantages[i] << endl;
  };
  cout << "\nYou may also 'Leave' \n"<< endl;
  cout << "~ ########################## ~\n" << endl;
  string userInput;
  cin >> userInput;
  if(userInput.compare("Leave") == 0){
    return false;
  }else if(userInput.compare("Left")==0){
    cout << "~  " << currentRoom.observationsOfRoom[0] << endl;
  }else if(userInput.compare("Forward")==0){
    cout << "~  " << currentRoom.observationsOfRoom[1] << endl;
  }else if(userInput.compare("Right")==0){
    cout << "~  " << currentRoom.observationsOfRoom[2] << endl;
  }else{
    cout << "~  " <<  "invalid entry!" << endl;
  };
  return true;
  };

int main(){
  cout << "You awake in a room, the wood floor feels warm against your head. 'How did I get here?' you wonder."<<endl;
  int currentRoomCoordinates[2]{0,0};
  bool winCondition = false;

  //  ~ Create a class for the SW Room
  Room SouthWest = Room("SouthWest");
  SouthWest.observationsOfRoom = {"To your left you see a worn table, the whorls in the woodtop etched deeep from years of use.", "SWTEXT2", "SWTEXT3"};

  //  ~ Available Directions to leave
  SouthWest.leavingOptions = {"Forward","Right"};
  
  cout << SouthWest.leavingOptions[0] << endl; 
  cout << SouthWest.leavingOptions[1] << endl; 
  cout << SouthWest.leavingOptions.size() << endl; 
 
  
  //  ~ Create a class for the W Room
  Room West = Room("West");
  West.observationsOfRoom = {"WEST", "WTEXT2", "WTEXT3"};
  //  ~ Available Directions to leave
  West.leavingOptions = {"Forward","Right", "Backward"};


  //  ~ Create a class for the NW Room
  Room NorthWest = Room("NorthWest");
  NorthWest.observationsOfRoom = {"NORTHWEST", "NWTEXT2", "NWTEXT3"};
  //  ~ Available Directions to leave
  NorthWest.leavingOptions = {"Right", "Backward"};


  //  ~ Create a class for the S Room
  Room South = Room("South");
  South.observationsOfRoom = {"South", "STEXT2", "STEXT3"};
  //  ~ Available Directions to leave
  South.leavingOptions = {"Forward","Left", "Right"};


  //  ~ Create a class for the Center Room
  Room Center = Room("Center");
  Center.observationsOfRoom = {"Center", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  Center.leavingOptions = {"Left", "Forward", "Right", "Backward"};


  //  ~ Create a class for the North Room
  Room North = Room("North");
  North.observationsOfRoom = {"North", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  North.leavingOptions = {"Left", "Right", "Backward"};

  //  ~ Create a class for the SouthEast Room
  Room SouthEast = Room("SouthEast");
  SouthEast.observationsOfRoom = {"SouthEast", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  SouthEast.leavingOptions = {"Left", "Forward"};


  //  ~ Create a class for the East Room
  Room East = Room("East");
  East.observationsOfRoom = {"East", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  East.leavingOptions = {"Left", "Forward", "Backward"};



  //  ~ Create a class for the NorthEast Room
  Room NorthEast = Room("NorthEast");
  NorthEast.observationsOfRoom = {"NorthEast", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  NorthEast.leavingOptions = {"Left","Backward"};



  Room currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West, NorthWest, South, Center, North, SouthEast, East, NorthEast);
  while(!winCondition){
    // If ()
  bool isUserInRoom = getUserInput(currentRoom);
  // User explores room until "Leave" command
  while(isUserInRoom){
    isUserInRoom = getUserInput(currentRoom);
  };
    for(int i = 0; i < currentRoom.leavingOptionsLength ; i++){
    cout << "-  " << currentRoom.leavingOptions[i] << endl;
  };
  string direction;
  cin >> direction;
  int yCoordinateChange = direction.compare("Forward") == 0 ? 1 : direction.compare("Backward") == 0 ? -1 : 0;
  int xCoordinateChange = direction.compare("Right") == 0 ? 1 : direction.compare("Left") == 0 ? -1 : 0;
  currentRoomCoordinates[0] += xCoordinateChange;
  currentRoomCoordinates[1] += yCoordinateChange;
  cout << currentRoomCoordinates[0] << currentRoomCoordinates[1] << endl;
  currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West, NorthWest, South, Center, North, SouthEast, East, NorthEast);
  cout << "You are now entering the " << currentRoom.roomName << " room. \n"; 
  }
  
  return 0;
};
