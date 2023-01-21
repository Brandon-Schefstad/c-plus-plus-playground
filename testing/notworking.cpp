/*TODO
1. Author flavor text for rooms
2. Determine win condition flags
3. Separate storyText from flavorText
4. Add items to use?
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class Room {
  public:
  string roomName;
  int xCoordinate;
  int yCoordinate;
  int flavorTextIndex;
  string text[8];
  string displayText(string direction){
    return direction.compare("left") == 0 ? text[5] : direction.compare("forward") == 0 ? text[6] : direction.compare("right") == 0 ? text[7] : "Invalid";
  };
  string displayPrompt;
  Room(int x, int y, string roomName){
    cout << "Making a room" << endl;
    cout << x << endl;
    xCoordinate = x;
    yCoordinate = y;
    roomName = roomName;
  };
};

class SouthWest : public Room {
  public:
  string flavorText[5] = {"You awake in a room, the wood floor feels warm against your head. 'How did I get here?' you wonder.",
    "SW flavortext1",
    "SW flavortext2",
    "SW flavortext3",
    "SW flavortext4",
    };
  string observableText[3] = {"SW directionTextLeft",
    "SW directionTextForward",
    "SW directionTextRight",};
  SouthWest(int xCoordinate, int yCoordinate, int flavorTextIndex){};
};
class West : public Room {
  public:
  string flavorText[5] = {"West Room.",
    "W flavortext1",
    "W flavortext2",
    "W flavortext3",
    "W flavortext4",
    };
  string observableText[3] ;
  West(int xCoordinate, int yCoordinate, int flavorTextIndex){};
};

SouthWest southWest = SouthWest(1,1,0);
West west = West(1,1,0);


// Room northWest = Room(0,2);
// Room south = Room(1,0);
// Room center = Room(1,1);
// Room north = Room (1,2);
// Room southEast = Room(2,0);
// Room east = Room(2,1);
// Room northEast = Room(2,2);

// Please come refactor this later Brandon, can you dynamically check a public class for coordinates and return the name of the room?
Room getCurrentRoom(int * coordinates){
  if(coordinates[0] == 0){
     if(coordinates[1]==0){
      southWest.roomName = "SW";
      return southWest;
     }
     if(coordinates[1]==1){
      west.roomName ="W";
      return west;
     }
  };
  return southWest;
};



int main(){
  SouthWest southWest()
  int currentRoomCoordinates[2] ;
  currentRoomCoordinates[0] = 0;
  currentRoomCoordinates[1] = 1;
  bool hasWon = false;
  Room currentRoom = getCurrentRoom(currentRoomCoordinates);

//  cout << currentRoom.flavorTextIndex << endl;
  cout << currentRoom.roomName << endl;
  cout << currentRoom.xCoordinate << "  " << currentRoom.yCoordinate << endl;
  // cout << currentRoomCoordinates[0] << " "<< currentRoomCoordinates[1] << endl;
 // cout << southWest.SWFlavorText[2] << endl;
  return 0;
};
