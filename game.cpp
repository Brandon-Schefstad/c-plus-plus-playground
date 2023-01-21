/*TODO
1. Author flavor text for rooms
2. Determine win condition flags
3. Separate storyText from flavorText
4. Add items to use?
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include<array>
using namespace std;

class Room {
  public:
  void setRoomName(string name){
    roomName = name;
  };
  int xCoordinate;
  int yCoordinate;
  string roomName;
  string actionList[4] = {"L","F","R","Leave"};
  int flavorTextIndex;

  array<string,3> observationDirectionList;
  array<string,3> observationList;
  int observationDirectionListLength; 

  array<string,4> leavingDirectionList;
  int leavingDirectionListLength;
  // string displayText(string direction){
  //   return direction.compare("left") == 0 ? directionText[0] : direction.compare("forward") == 0 ? directionText[1] : direction.compare("right") == 0 ? directionText[2] : "Invalid";
  // };
  Room(int x, int y, string z){
    xCoordinate = x;
    yCoordinate = y;
    roomName = z;
  };
};

// Please come refactor this later Brandon, can you dynamically check a public class for coordinates and return the name of the room?
// for some reason, I cannot set a string in a derived class



Room getCurrentRoom(int coordinates[2], Room southWest, Room west){
  // Room NorthWest = Room(0,2, "NorthWest");
  // Room South = Room(1,0, "South");
  // Room Center = Room(1,1, "Center");
  // Room North = Room(1,2, "North");
  // Room SouthEast = Room(2,0, "SouthEast");
  // Room East = Room(2,1, "East");
  // Room NorthEast = Room(2,2,"NorthEast");
  if (coordinates[0] == 0 && coordinates[1]==0){
    return southWest;
  }
  // else if (coordinates[0] == 0 && coordinates[1]==1){
    return west;
  // }
  // // else if (coordinates[0] == 0 && coordinates[1]==2)
  // // {
  //   return NorthWest;
  // }else if (coordinates[0] == 1 && coordinates[1]==0)
  // {return South;
  // }else if (coordinates[0] == 1 && coordinates[1]==1)
  // {return Center;
  // }else if (coordinates[0] == 1 && coordinates[1]==2)
  // {return North;
  // }else if (coordinates[0] == 2 && coordinates[1]==0)
  // {return SouthEast;
  // }else if (coordinates[0] == 2 && coordinates[1]==1)
  // {return East;
  // };
  // return NorthEast;
};

bool getUserInput(Room currentRoom){
  cout << "\n- - -" << endl;
  cout << "Where do you look? Options are: \n" << endl;

  for(int i = 0; i < currentRoom.observationDirectionListLength ; i++){
    cout << "-  " << currentRoom.observationDirectionList[i] << endl;
  };
  cout << "\nYou may also 'Leave'"<< endl;
  string userInput;
  cin >> userInput;
  if(userInput.compare("Leave") == 0){
    return false;
  }else if(userInput.compare("Left")==0){
    cout << "~  " << currentRoom.observationList[0] << endl;
  }else if(userInput.compare("Forward")==0){
    cout << "~  " << currentRoom.observationList[1] << endl;
  }else if(userInput.compare("Right")==0){
    cout << "~  " << currentRoom.observationList[2] << endl;
  }else{
    cout << "~  " <<  "invalid entry!" << endl;
  };

  return true;
  };

int main(){
  Room SouthWest = Room(0,0, "SouthWest");
  cout << "You awake in a room, the wood floor feels warm against your head. 'How did I get here?' you wonder."<<endl;
  string SWObservationList[3] = {"To your left you see a worn table, the whorls in the woodtop etched deeep from years of use.", "SWTEXT2", "SWTEXT3"};
  SouthWest.observationDirectionList = {"Left","Forward","Right"};
  SouthWest.observationDirectionListLength = 3;

  SouthWest.leavingDirectionList = {"Forward","Right"};
  SouthWest.leavingDirectionListLength = 2;

  for(int i = 0; i < 3; i++){
  SouthWest.observationList[i] = SWObservationList[i];
  };
  Room West = Room(0,1, "West");
  string WObservationList[3] = {"WEST", "WTEXT2", "WTEXT3"};
  West.observationDirectionList = {"Left","Forward","Right"};
  West.observationDirectionListLength = 3;

  West.leavingDirectionList = {"Forward","Right", "Backward"};
  West.leavingDirectionListLength = 3;

  for(int i = 0; i < 3; i++){
  West.observationList[i] = WObservationList[i];
  };
  // Room NorthWest = Room(0,2, "NorthWest");
  // string NWDirectionText[3] = {"NW", "NW", "NW"};
  // for(int i = 0; i < 3; i++){
  // NorthWest.directionText[i] = NWDirectionText[i];
  // };

  int currentRoomCoordinates[2]{0,0};

  bool winCondition = false;
  Room currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West);
  while(!winCondition){
  bool isUserInRoom = getUserInput(currentRoom);
  // User explores room until "Leave" command
  while(isUserInRoom){
    isUserInRoom = getUserInput(currentRoom);
  };
    for(int i = 0; i < currentRoom.leavingDirectionListLength ; i++){
    cout << "-  " << currentRoom.leavingDirectionList[i] << endl;
  };
  string direction;
  cin >> direction;
  int yCoordinateChange = direction.compare("Forward") == 0 ? 1 : direction.compare("Backward") == 0 ? -1 : 0;
  int xCoordinateChange = direction.compare("Right") == 0 ? 1 : direction.compare("Left") == 0 ? -1 : 0;
  currentRoomCoordinates[0] += xCoordinateChange;
  currentRoomCoordinates[1] += yCoordinateChange;
  cout << currentRoomCoordinates[0] << currentRoomCoordinates[1] << endl;
  currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West);
  cout << "You are now entering the " << currentRoom.roomName << " room. \n"; 
  }
  
  return 0;
};
