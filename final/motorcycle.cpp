
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "motorcycle.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>
#include "auto_v.h"

// ecs36b


using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)
// std::map<std::string, Thing *> Thing_Map;
// std::map<std::string, Person *> Person_Map;

// my location

class Motorcycle : public auto_v
{
public:
    Motorcycle(AbstractServerConnector &connector, serverVersion_t type);
    virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);

virtual Json::Value complete(); bool completed = false;

    std::map<std::string, Thing *> Thing_Map;
    std::map<std::string, Person *> Person_Map; 
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

 Json::Value
 Myhw5Server::move (const std::string& action, const std::string& class_id,
  const Json::Value& json_object, const Json::Value& location,
  const std::string& object_id)
 {
//   int error_code = 0;
   Json::Value result;

	if(class_id=="Person"){
	  Person * lv_person_ptr;
	  if (Person_Map.find(object_id) != Person_Map.end())
	    {
	      lv_person_ptr = Person_Map[object_id];
	    }
	  else
	    {
	      lv_person_ptr = new Person {};
	      Person_Map[object_id] = lv_person_ptr;
	    }
    lv_person_ptr->JSON2Object(json_object);
	}

	if(class_id=="Thing"){
	  Thing * lv_Thing_ptr;
	  if (Thing_Map.find(object_id) != Thing_Map.end())
	    {
	      lv_Thing_ptr = Thing_Map[object_id];
	    }
	  else
	    {
	      lv_Thing_ptr = new Thing {};
	      Thing_Map[object_id] = lv_Thing_ptr;
	    }
    lv_Thing_ptr->JSON2Object(json_object);
	}



    result = json_object;

  std::cout << result.toStyledString() << std::endl; // Prints out the info transferred, or essentially just the json object that was passed in
  return result;
 }

 

 Json::Value
 Myhw5Server::complete()
 {
   Json::Value result;
   result["complete"] = "Data Transaction Complete";
   completed = true;
  std::cout << result.toStyledString() << std::endl; // Prints out the info transferred, or essentially just the json object that was passed in
  return result;
 }  





// int main()
// {
//   GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
//   GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
//   GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

//   // set location here
//   process_here = gps_TLC_UCDavis; // server, forrest
  
//   Person Felix { "987654321", "Felix", gps_Home_Woodland };
//   Felix.setLocation(gps_IKEA_Sacramento, (*getNowJvTime()));

//   IP_Address meatball_IP { 2850883174 };
//   IOT_Thing Swedish_Meatball { Felix , meatball_IP };
  
//   Swedish_Meatball.model = "HUVUDROLL";
//   Swedish_Meatball.sequence_num = "123456-0000";
//   Swedish_Meatball.description = "frozen";
//   Swedish_Meatball.location = gps_Home_Woodland;
//   Swedish_Meatball.purchased = *getNowJvTime();
//   Swedish_Meatball.sold = *getNowJvTime();
//   Swedish_Meatball.owner = Felix;

//   int rc;
//   char name_buf[256];
  
//   bzero(name_buf, 256);
//   snprintf(name_buf, 256, "./json_objects/%s_%s.json", "Thing", "000000001");
//   // "./json_objects/Thing_00000001.json"
//   Json::Value jv = Swedish_Meatball.dump2JSON();
//   rc = myJSON2File(name_buf, &jv); // char *, Json::Value *
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }

//   Thing_Map["00000001"] = (Thing *) (&Swedish_Meatball);
//   for (const auto& [key, value] : Thing_Map)
//     std::cout << '[' << key << "] = " << value << ";\n ";

// #define _GPS_STUFF_
// #ifdef _GPS_STUFF_
  
//   bzero(name_buf, 256);
//   snprintf(name_buf, 256, "./json_objects/%s_%s.json", "GPS", "000000001");
//   Json::Value gps_jv = gps_IKEA_Sacramento.dump2JSON();
//   rc = myJSON2File(name_buf, &gps_jv);
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }

//   Json::Value gps_jv_2;
//   rc = myFile2JSON(name_buf, &gps_jv_2);
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }
//   GPS_DD new_one {};
//   new_one.JSON2Object(gps_jv_2);
//   std::cout << (new_one.dump2JSON()).toStyledString() << std::endl;

// #endif /* _GPS_STUFF_ */
  
//   HttpServer httpserver(7374);
//   Myhw5Server s(httpserver,
// 		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
//   s.StartListening();
//   std::cout << "Hit enter to stop the server" << endl;
//   getchar();

//   s.StopListening();
//  return 0;
// }














//   std::cout << "Move\n";
//   if (class_id != "Person")
//     {
//       result["status"] = "failed";
//       strJson = ( "class " + class_id + " unknown");
//       result["reason"] = strJson;
//       error_code = -1;
//     }

//   if (object_id.empty())
//     {
//       result["status"] = "failed";
//       strJson = ( "object_id null ");
//       result["reason"] = strJson;
//       error_code = -2;
//     }

//   GPS_DD incoming_location;
//   if ((location.isNull() == true) ||
//       (location.isObject() == false))
//     {
//       result["status"] = "failed";
//       strJson = ( "location parsing error " );
//       result["reason"] = strJson;
//       error_code = -3;
//     }

//   if ((json_object.isNull() == true) ||
//       (json_object.isObject() == false))
//     {
//       result["status"] = "failed";
//       strJson = ( "person parsing error " );
//       result["reason"] = strJson;
//       error_code = -4;
//     }