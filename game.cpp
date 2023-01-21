/*TODO
1. Author flavor text for rooms
2. Determine win condition flags
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
    Order of Observations = {left, forward, right, [table,key,window],[locked door]}
  */
  vector<string> observationsOfRoom;
  vector<string> observationsAlreadySeen;
  vector <string> leavingOptions; 
  Room(string z){
    roomName = z;
  };
};

// Please come refactor this later Brandon, can you dynamically check a public class for coordinates and return the name of the room?
// for some reason, I cannot set a string in a derived class

Room getCurrentRoom(int coordinates[2], Room southWest, Room west,Room South, Room Center,  Room SouthEast, Room East){
  if (coordinates[0] == 0 && coordinates[1]==0){
    return southWest;
  }
  else if (coordinates[0] == 0 && coordinates[1]==1){
    return west;
  }
  else if (coordinates[0] == 1 && coordinates[1]==0)
  {
    return South;
  }
  else if (coordinates[0] == 1 && coordinates[1]==1)
  {
    return Center;
  }
  else if (coordinates[0] == 2 && coordinates[1]==0)
  {
    return SouthEast;
  }else if (coordinates[0] == 2 && coordinates[1]==1){
    return East;
  }
};



// Gets user actions within the room 
vector<bool> getUserInput(Room currentRoom, Room SouthWest){
  bool hasKey;
  bool hasSeenGhost;
  cout << "\n- - - - - - - - - - - - - - -" << endl;
  cout << "Where do you look? Options are: \n" << endl;
  for(int i = 0; i < currentRoom.vantages.size() ; i++){
    cout << "-  " << currentRoom.vantages[i] << endl;
  };
  cout << "\nYou may also 'Leave' \n"<< endl;
  cout << "~ ########################## ~\n" << endl;
  string userInput;
  cin >> userInput;
  if(userInput.compare("Leave") == 0){
      hasKey = hasKey;
      return {false, hasKey};
  }else if(userInput.compare("Left")==0){
    if(currentRoom.roomName.compare("Foyer")==0){
      hasKey = true;
      cout << hasKey <<endl;
    }
    cout << "Looking " << userInput << " ~ "  << currentRoom.observationsOfRoom[0] << endl;
  }else if(userInput.compare("Forward")==0){
      if(currentRoom.roomName.compare("Living Room")==0){
      hasSeenGhost = true;
    }
    cout << "Looking " << userInput << " ~ "  << currentRoom.observationsOfRoom[1] << endl;
  }else if(userInput.compare("Right")==0){
    cout << "Looking " << userInput << " ~ "  << currentRoom.observationsOfRoom[2] << endl;
  }
    // Adjust win conditions here? Feels like a react component tree lol
  else{
    cout << "~  " <<  "invalid entry!" << endl;
  };
  return {true, hasKey, hasSeenGhost};
};

int main(){
  cout << "You awake in a room, the wood floor feels warm against your head. 'How did I get here?' you wonder."<<endl;
  int currentRoomCoordinates[2]{0,0};
  bool winCondition = false;
  
  //  ~ Create a class for the SW Room
  Room SouthWest = Room("Foyer");
  SouthWest.observationsOfRoom = {
    "You see a worn table, the whorls in the woodtop etched deep from years of use. On top of it lies a key, which wisdom would say must have a matching lock.",
    "You look at the old paintings of a family long gone. There is a sadness behind their eyes. ",
    "You get a glimpse of a door to your right. It matches the table so well, it may have come from the same tree"};
  //  ~ Available Directions to leave
  SouthWest.leavingOptions = {"Forward","Right"};
    
  //  ~ Create a class for the W Room
  Room West = Room("Kitchen");
  West.observationsOfRoom = {"WEST", "WTEXT2", "WTEXT3"};
  //  ~ Available Directions to leave}
  West.leavingOptions = {"Right", "Backward"};

  //  ~ Create a class for the S Room
  Room South = Room("Main Entrance");
  South.observationsOfRoom = {"South", "STEXT2", "STEXT3"};
  //  ~ Available Directions to leave
  South.leavingOptions = {"Backward","Left", "Right"};

  //  ~ Create a class for the Center Room
  Room Center = Room("Living Room");
  Center.observationsOfRoom = {"Center", "CTEXT2", "CTEXT3"};
  //  ~ Available Directions to leave
  Center.leavingOptions = {"Left", "Forward", "Backward"};

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
  Room currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West, South, Center,  SouthEast, East);

  bool hasKey = false;
  bool hasSeenGhost = false;


  // Operate game until win conditions have been met
  while(!winCondition){
  // Check win condition (array of booleans maybe?)
  
  // First pass allows user to leave room without looking first. 
  bool isUserInRoom = true;
  // User explores room until "Leave" command
  while(true){
    if(isUserInRoom == true){
      vector<bool> responseFromRoom = getUserInput(currentRoom, SouthWest);
        cout << "In Room? " << responseFromRoom[0] << endl; 
        isUserInRoom = responseFromRoom[0]; 
        if (responseFromRoom[1] == true){hasKey = true;};
        if (responseFromRoom[2] == true){hasSeenGhost = true;};;
    }else{
      cout << "Exiting Room" << endl;
      cout << "Have Key? " << hasKey << endl;
      cout << "Seen Ghost?" << hasSeenGhost << endl;
      break;
    };
  };
  for(int i = 0; i < currentRoom.leavingOptions.size() ; i++){
      cout << "-  " << currentRoom.leavingOptions[i] << endl;
  };
  string direction;
  cin >> direction;
  int yCoordinateChange = direction.compare("Forward") == 0 ? 1 : direction.compare("Backward") == 0 ? -1 : 0;
  int xCoordinateChange = direction.compare("Right") == 0 ? 1 : direction.compare("Left") == 0 ? -1 : 0;
  //  Check if valid coordinates
  int tempXCoordinate = currentRoomCoordinates[0] += xCoordinateChange;
  int tempYCoordinate = currentRoomCoordinates[1] += yCoordinateChange;
  if((-1 < tempXCoordinate)  && (tempXCoordinate < 3) &&(-1<tempYCoordinate) && (tempYCoordinate < 2 )){
    currentRoomCoordinates[0] = tempXCoordinate;
    currentRoomCoordinates[1] = tempYCoordinate;
    currentRoom = getCurrentRoom(currentRoomCoordinates, SouthWest, West, South, Center, SouthEast, East);
    cout << "You are now entering the " << currentRoom.roomName << ". \n"<< endl; 
  } else{
    cout<<"\nYou hit a wall, ow."<<endl;
    currentRoom = currentRoom;
    cout << "You are still in the " << currentRoom.roomName << ". \n" << endl; 
  };
  }
  
  return 0;
};
