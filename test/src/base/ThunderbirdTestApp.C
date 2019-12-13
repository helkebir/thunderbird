//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ThunderbirdTestApp.h"
#include "ThunderbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
ThunderbirdTestApp::validParams()
{
  InputParameters params = ThunderbirdApp::validParams();
  return params;
}

ThunderbirdTestApp::ThunderbirdTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ThunderbirdTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ThunderbirdTestApp::~ThunderbirdTestApp() {}

void
ThunderbirdTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ThunderbirdApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ThunderbirdTestApp"});
    Registry::registerActionsTo(af, {"ThunderbirdTestApp"});
  }
}

void
ThunderbirdTestApp::registerApps()
{
  registerApp(ThunderbirdApp);
  registerApp(ThunderbirdTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ThunderbirdTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ThunderbirdTestApp::registerAll(f, af, s);
}
extern "C" void
ThunderbirdTestApp__registerApps()
{
  ThunderbirdTestApp::registerApps();
}
