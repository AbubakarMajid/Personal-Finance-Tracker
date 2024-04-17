#include "login_form.h"
#include "home_form.h"
#include "Account.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	USER^ user = nullptr;
	while (true) {
		codebase::login_form log;
		log.ShowDialog();

		if (log.switch_to_account) {
			codebase::Account account;
			account.ShowDialog();
			if (account.switch_to_login) {
				continue;
			}
			else {
				user = account.user;
				break;
			}
		}

		else {
			user = log.user;
			break;
		}

	}

	if (user != nullptr) {
		codebase::home_form home(user);
		Application::Run(% home);
	}
	else {
		MessageBox::Show("Authentication Cancelled!");
	}
}