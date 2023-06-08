#include "BabblerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
BabblerApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

BabblerApp::BabblerApp(InputParameters parameters) : MooseApp(parameters)
{
  ModulesApp::registerAllObjects<BabblerApp>(_factory, _action_factory, _syntax);
}

BabblerApp::~BabblerApp() {}

void
BabblerApp::registerApps()
{
  registerApp(BabblerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BabblerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<BabblerApp>(f, af, s);
}
extern "C" void
BabblerApp__registerApps()
{
  BabblerApp::registerApps();
}
