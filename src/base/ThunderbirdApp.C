#include "ThunderbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ThunderbirdApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  return params;
}

ThunderbirdApp::ThunderbirdApp(InputParameters parameters) : MooseApp(parameters)
{
  ThunderbirdApp::registerAll(_factory, _action_factory, _syntax);
}

ThunderbirdApp::~ThunderbirdApp() {}

void
ThunderbirdApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"ThunderbirdApp"});
  Registry::registerActionsTo(af, {"ThunderbirdApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ThunderbirdApp::registerApps()
{
  registerApp(ThunderbirdApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ThunderbirdApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ThunderbirdApp::registerAll(f, af, s);
}
extern "C" void
ThunderbirdApp__registerApps()
{
  ThunderbirdApp::registerApps();
}
