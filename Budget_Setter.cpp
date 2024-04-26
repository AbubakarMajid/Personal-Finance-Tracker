#include "Budget_Setter.h"

using namespace System;
using namespace System::Windows::Forms;
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	codebase::Budget_Setter form;
	Application::Run(% form);
}