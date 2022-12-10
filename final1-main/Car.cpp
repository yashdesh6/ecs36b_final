#include "Car.h"
#include "finalServer.h"
// ecs36b


using namespace jsonrpc;
using namespace std;

#ifndef FINALSERVER_H_INCLUDED
#define FINALSERVER_H_INCLUDED

int main(){

 HttpServer httpserver(7375);
  
 MyFinalServer s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
 
  while(!s.completed){
    s.StartListening();
  }
      s.StopListening();

  // getchar();

    Motorcycle* motoLeft = new Motorcycle();
    Motorcycle* motoRight = new Motorcycle(); // we will put some info in motoLeft soon


    int counter = 0;
    for(auto i = s.Motorcycle_Map.begin(); i != s.Motorcycle_Map.end(); i++){

          if(counter==0){
          motoRight->JSON2Object(s.Motorcycle_Map[i->first]->dump2JSON());
          }
        else{
          motoLeft->JSON2Object(s.Motorcycle_Map[i->first]->dump2JSON());
    }

    counter++;

    
      }

		 
			
  
  


    return 0;

}
#endif // 