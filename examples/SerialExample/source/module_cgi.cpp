#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#include <bbapi/BBHtml.hpp>
#include <bbapi/BBProcessManager.hpp>
#include <bbapi/BBCgi.hpp>
#include <bbapi/BBConfig.hpp>

#include "module.h"

using namespace std;

static void main_index(void)
{
  BBConfig cfg(MODULE_SETTINGS, MODULE_NAME);
  BBHtml h;

  // Map for a serial device
  vector< pair<string, string> > device;
  device.push_back(make_pair("PORT1", "/dev/ttyS0"));
  device.push_back(make_pair("PORT2", "/dev/ttyS1"));

  cfg.load(); bool b; string s;

  h.pageBegin(MODULE_TITLE);
  
  h.addDropDown("Expansion Port", "device", cfg.getSetting("device", s), device);
  h.addTextField("Text to send: ", "text", cfg.getSetting("text", s));

  h.addSubmitButton("Apply");

  h.pageEnd();
}

static void main_set(void)
{
  BBCgi cgi;
  BBConfig cfg(MODULE_SETTINGS, MODULE_NAME);
  BBHtml h;
  BBProcessManager pm;
  int input_ok;

  cfg.load();
  cgi.begin();
  h.pageBegin(MODULE_TITLE);

  input_ok = cgi.query_ok();
         cfg.setSetting("device"     , cgi.getString("device").c_str());
         cfg.setSetting("text"     , cgi.getString("text").c_str());

  cfg.save();
  if(input_ok) 
  {
    vector<string> params(1);
    pm.startProcess("/opt/SerialExample/bin/SerialExample", 1);
  }

  h.pageEnd();
  cgi.end();
}

int main(int argc, char *argv[])
{
  string name;

  if (argc > 0) {
    name = string(basename(argv[0]));
    if (!name.compare("index.cgi")) {
      main_index();
    } else if (!name.compare("set.cgi")) {
      main_set();
    }
  }

  return 0;
}
