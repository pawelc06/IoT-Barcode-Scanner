
#ifdef _PLUGIN_H
/*

Plugin Module description
Plugin Copyright

*/

//*for better readability and usage of this template file the writing style is:
//* (//*) for comments
//* (//) for commented code (just delete the // to activate)
//* This plugin templat allows web interface provisioning the fronand
//* HTML, JS, CSS needs to be coded into the original core (on current design)

//*---------------------------------------------------------------------------
//* Plugin includes
//*---------------------------------------------------------------------------
#include <EEPROM.h>
#include <Ticker.h>
#include <ArduinoJson.h>
#include <vector>
#include <functional>
//#include <otherPluginIncludeFiles>

//*----------------------------------------------------------------------------
//* Private
//*----------------------------------------------------------------------------
//*----------------------------------------------------------------------------
//* Plugin globals
//*----------------------------------------------------------------------------
bool _plugin1_enabled = false;;
unsigned long _pluginReportInterval = 1000 * PLUGIN_REPORT_EVERY;
unsigned long _pluginLastUpdate = 0;
unsigned long _pluginCounter = PLUGIN_PARAMETER_1;

//*----------------------------------------------------------------------------
//* Plugin helper functions
//*----------------------------------------------------------------------------

//* Plugin loop helper function(s)
//*------------------------------
void _plugin1Function1() {
    //* This is were the plugin magic happens...
    //* plugin functions called from _pluginLoop()
    //* _pluginLoop() is regitered to
    //* plugin loop helper function code goes here

    //* to get a sensor value for the plugin
    //*-------------------------------------
//    #if SENSOR_SUPPORTED
//        unsigned char _sensorID;
//        double _sensorValue;
//        _sensorValue = _getSensorValue(_sensorID, "current");
//        _sensorValue = _getSensorValue(_sensorID, "filtered");
//        _sensorValue = _getSensorValue(_sensorID, "reported");
//    #endif

    //* changing relay based on plugin logic
    //*-------------------------------------
//    unsigned char _relayID;
    //* set to true, false ot toggle status
//    _setRaleyStatus(_relayID, "ON");
//    _setRaleyStatus(_relayID, "OFF");
//    _setRaleyStatus(_relayID, "TOGGLE");

    //* In case of factory reset need
    //*------------------------------
//    resetSettings();
//    deferredReset(100, CUSTOM_RESET_FACTORY);

    //* In case of AP  need
    //*--------------------
//     createAP();

    //* In case of system reset need
    //*-----------------------------
//     deferredReset(100, CUSTOM_RESET_HARDWARE);

    //* In case of params setter/getter need
    //*-------------------------------------
//    setSetting(key, value);
//    getSetting(key, value, defaultValue);

    //* Broker publish
    //*-------------
//    #if BROKER_SUPPORT
//        brokerPublish(MQTT_TOPIC_PLUGIN, [id], message);
//    #endif

    //* MQTT publish
    //*-------------
//    #if MQTT_SUPPORT
//        mqttSend(MQTT_TOPIC_PLUGIN, [id], message);
//    #endif

    //* DOMOTICZ publish
    //*-----------------
//    #if DOMOTICZ_SUPPORT
//        domoticzSend(DOMOTICZ_TOPIC_PLUGIN, payload);
//    #endif

    //* INFLUXDB publish
    //*-----------------
//    #if INFLUXDB_SUPPORT
//        idbSend(INFLUXDB_TOPIC_PLUGIN,payload);
//    #endif

    //* THINGSPEAK publish
    //*-----------------
//    #if THINGSPEAK_SUPPORT
//        _tspkEnqueue(field_id, field_payload);
//        tspkFlush();
//    #endif

    //* Debug messages (anywere in your code)
    //*--------------------------------------
    #if PLUGIN_REPORT_EVERY != 0
      //DEBUG_MSG_P(PSTR("[PLUGIN] Plugin debug message c format: {%.}\n"), {.});
        if (millis() - _pluginLastUpdate > _pluginReportInterval) {
            _pluginLastUpdate = millis();
            DEBUG_MSG_P(PSTR("[PLUGIN] Loop counter: %d\n"),_pluginCounter);
            _pluginCounter++;
        }
    #endif
}

//* If frontend support needed
//* Websocket support helper functions
//*-----------------------------------
//#if WEB_SUPPORT
     //* parse ws values
//      unsigned char pluginParsePayload(const char * payload) {
//          char * p = ltrim((char *)payload);
//            if (strcmp(p, "query") == 0) {
//                return 0;
//           }
//      }
//      void _pluginWebSocketUpdate(JsonObject& root) {
//          JsonArray& plugin = root.createNestedArray("pluginStatus");
//          plugin.add("OK");
//      }
//      void _pluginWebSocketOnAction(uint32_t client_id, const char * action, JsonObject& data) {
		      //* on action register event action code here
//          if (strcmp(action, "plugin") != 0) return;
//          if (data.containsKey("status")) {
//              unsigned char value = pluginParsePayload(data["status"]);
//              if (value == 0) {
//                  wsSend(_pluginWebSocketUpdate);
//              }
//	        }
//      }
//      bool _pluginWebSocketOnReceive(const char * key, JsonVariant& value) {
	        //* on recieve event code here
//          return (strncmp(key, "plugin", 6) == 0);
//	    }
//        void _pluginWebSocketOnParse(JsonObject& root) {
	      //* socket parse event code here
//	    }
//      void _pluginWebSocketOnStart(JsonObject& root) {
	      //* socket start event code here
//        _relayWebSocketUpdate(root);

        //* Configuration params
//        JsonArray& config = root.createNestedArray("pluginConfig");
//        JsonObject& line = config.createNestedObject();
//        line["pluginParam1"] = "Param1";
//        line["pluginParam2"] = "Param2";
//        root["pluginRoot"]   = "pluginRoot";
//	    }
      //* set websocket handlers
//      void _pluginSetupWS() {
//          wsOnSendRegister(_pluginWebSocketOnStart);
//          wsOnReceiveRegister(_pluginWebSocketOnReceive);
//          wsOnActionRegister(_pluginWebSocketOnAction);
//          wsOnAfterParseRegister(_pluginWebSocketOnParse);
//	    }
//#endif

//* helper function to get sensor value
//*------------------------------------
//#if SENSOR_SUPPORT
//    double _getSensorValue(unsigned char id, const char * type ) {
//        char * p = ltrim((char *)type);
//        if (strcmp(p, "current") != 0) return _magnitudes[id].current;
//        else if (strcmp(p, "filtered") != 0) return _magnitudes[id].filtered;
//        else if (strcmp(p, "reported") != 0) return _magnitudes[id].reported;
//        return 0;
//    }
//#endif

//* helper function to set relay
//*-----------------------------
//void _setRaleyStatus(unsigned char id, const char * action ) {
//    char * p = ltrim((char *)action);
//    if (strcmp(p, "ON") != 0) {
//        relayStatus(id - 1, true);
//        return;
//    }
//    else if (strcmp(p, "OFF") != 0) {
//        relayStatus(id - 1, true);
//        return;
//    }
//    else if (strcmp(p, "TOGGLE") != 0) {
//        relayToggle(id - 1);
//        return;
//    }
//}

//* If API support needed
//* API register helper function
//*-----------------------------
#if WEB_SUPPORT
    //* register api functions
    //* apiRegister(key, _getFunction, _putFunction);
    //* this is API registraion to enable disable the plugin
    //* use this as template to create additional API calls for the plugin
    void _pluginSetupAPI() {
          char key[15];
          snprintf_P(key, sizeof(key), PSTR("%s"), MQTT_TOPIC_PLUGIN1);
          apiRegister(key, [](char * buffer, size_t len) {
               //snprintf_P(buffer, sizeof(buffer), PSTR("Ok - %d"), _pluginCounter);
               snprintf_P(buffer, len, PSTR("%d"), _plugin1_enabled ? "ON" : "OFF");
               DEBUG_MSG_P(PSTR("[PLUGIN1] API call return: (%s)\n"), buffer);},
               [](const char * payload) {
                   unsigned char value = relayParsePayload(payload);
                   if (value == 0xFF) {
                       DEBUG_MSG_P(PSTR("[PLUGIN1] Wrong payload (%s)\n"), payload);
                       return;
                   }
                   _plugin1_enabled = (value == 1);
                   setSetting("PLG1_EN", _plugin1_enabled);
                   //snprintf_P(buffer, len, PSTR("%d"), _plugin1_enabled ? "ON" : "OFF");
                   //DEBUG_MSG_P(PSTR("[PLUGIN1] API call return: (%s)\n"), buffer);
                });
	    }
#endif

//* If MQTT support needed
//* MQTT callback handling helper functions
//*----------------------------------------
//#if MQTT_SUPPORT
//    void _pluginMQTTCallback(type, topic, payload) {
//        if (type == MQTT_CONNECT_EVENT) {
          //* Subscribe to own /set topic
//            mqttSubscribe(topic);
          //* Subscribe to group topics
//            mqttSubscribeRaw(group);
//       }
//       if (type == MQTT_MESSAGE_EVENT) {
            //* manage mtww palyload here
//         String t = mqttMagnitude((char *) topic);
            //* manage group topics code here
//         }
//          if (type == MQTT_DISCONNECT_EVENT) {
             //* MQTT disonnect code here
//          }
//      }

//      void _pluginSetupMQTT() {
//          _mqttRegister(_pluginMQTTCallback);
//      }
//#endif

//* If terminal Terminal commands needed
//* Plugin terminal commands helper function
//*-----------------------------------------
#if TERMINAL_SUPPORT
      void _pluginInitCommands() {
          //* Register Terminal commad to turn on/off the plugin
          //* use this as template to create additional plugin terminal commands
          settingsRegisterCommand(F("PLUGIN1"), [](Embedis* e) {
                  if (e->argc == 0) {
                      DEBUG_MSG_P(PSTR("Pluin1 Status: %s\n"), _plugin1_enabled ? "ON" : "OFF");
                      DEBUG_MSG_P(PSTR("Send 0/1 to enable/disable\n"));
                      DEBUG_MSG_P(PSTR("+OK\n"));
                      return;
                  }
                  _plugin1_enabled = (String(e->argv[1]).toInt() == 1);
                  setSetting("PLG1_EN", _plugin1_enabled);
                  DEBUG_MSG_P(PSTR("Pluin1 Set Status: %s\n"), _plugin1_enabled ? "ON" : "OFF");
                  DEBUG_MSG_P(PSTR("+OK\n"));
              });

      }
#endif

//* end of helper functions
//*----------------------------------------------------------------------------

//*----------------------------------------------------------------------------
//* Plugin setup
//*----------------------------------------------------------------------------
void iotBarcodeScannerSetup() {
    //*    plugin setup code
    //* myPluginSetup() is called by custom.h - espurna plugin entry point

    _plugin1_enabled = getSetting("PLG1_EN", IOTBARCODESCANNER_ENABLE).toInt() == 1;

    //* Register plugin loop to espurna main loop
    //*------------------------------------------
    espurnaRegisterLoop(_pluginLoop);

    //* If API used set up Api
    //*-----------------------
    #if WEB_SUPPORT
        _pluginSetupAPI();
    #endif

    //* If Web Sockets set up WS
    //*-------------------------
//    #if WEB_SUPPORT
//        _pluginSetupWS();
//    #endif

    //* If MQTT used set up MQTT
    //*-------------------------
//    #if MQTT_SUPPORT
//        _pluginSetupMQTT();
//    #endif

    //* If trminal used set up terminal
    //*-------------------------------
	  #if TERMINAL_SUPPORT
	      _pluginInitCommands();
	  #endif
    DEBUG_MSG_P(PSTR("[PLUGIN] Plugin setup code finished \n"));
}
//* end of plugin setup
//*----------------------------------------------------------------------------

//*----------------------------------------------------------------------------
//* PLUGIN loop
//*----------------------------------------------------------------------------
void _pluginLoop() {
    //*   plugin loop code
    //* _pluginLoop regitered (espurnaRegisterLoop) by myPluginSetup()
    //* myPluginSetup() is called by custom.h - espurna plugin entry point

    //* if plugin disabled dont run the coded
    if (_plugin1_enabled != 1) return;

    //* here call all plugin loop functions (copy sumple function as needed)
    _plugin1Function1();
}

//*----------------------------------------------------------------------------
//* Public - Plugin API
//*----------------------------------------------------------------------------
//* Here goes ublic plugin API definitions and coded
//* currently plugin enabled query implemented
//* use this as template to create additionl API calls
//* to Set/Get internal plugin data or use plugin functions
bool plugin1Enabled() {
    return _plugin1_enabled;
}
#endif  //#ifdef _PLUGIN_H
