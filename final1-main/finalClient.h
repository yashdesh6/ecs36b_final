/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_FINALCLIENT_H_
#define JSONRPC_CPP_STUB_FINALCLIENT_H_

#include <jsonrpccpp/client.h>
#include <iostream>

#include <jsonrpccpp/client/connectors/httpclient.h>
#include <iostream>


// JSON RPC part

#include <jsonrpccpp/client/connectors/httpclient.h>


class finalClient : public jsonrpc::Client
{
    public:
        finalClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

        Json::Value move(const std::string& action, const std::string& class_id, const Json::Value& json_object, const Json::Value& location, const std::string& object_id) // throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["action"] = action;
            p["class_id"] = class_id;
            p["json_object"] = json_object;
            p["location"] = location;
            p["object_id"] = object_id;
            Json::Value result = this->CallMethod("move",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value complete() throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p = Json::nullValue;
            Json::Value result = this->CallMethod("complete",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
};

#endif //JSONRPC_CPP_STUB_FINALCLIENT_H_
