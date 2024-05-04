#include "login_form.h"
using namespace System;
using namespace System::Windows::Forms;
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	codebase::login_form form;
	Application::Run(% form);
}
