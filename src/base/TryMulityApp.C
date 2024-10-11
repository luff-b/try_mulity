#include "TryMulityApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
TryMulityApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

TryMulityApp::TryMulityApp(InputParameters parameters) : MooseApp(parameters)
{
  TryMulityApp::registerAll(_factory, _action_factory, _syntax);
}

TryMulityApp::~TryMulityApp() {}

void
TryMulityApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<TryMulityApp>(f, af, s);
  Registry::registerObjectsTo(f, {"TryMulityApp"});
  Registry::registerActionsTo(af, {"TryMulityApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TryMulityApp::registerApps()
{
  registerApp(TryMulityApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TryMulityApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TryMulityApp::registerAll(f, af, s);
}
extern "C" void
TryMulityApp__registerApps()
{
  TryMulityApp::registerApps();
}
