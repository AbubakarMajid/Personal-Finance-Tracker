#include "login_form.h"
#include "dashboard.h"
#include "Account.h"
#include "Transaction.h"
#include "Budget_Setter.h"

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
		user = log.user;
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

		if (user != nullptr) {
			break;
		}
	}

	while (true) {
		codebase::Dashboard dash(user);
		Application::Run(% dash);
		//dash.ShowDialog();
		if (dash.switch_to_transaction) {
			codebase::Transaction transaction;
			transaction.ShowDialog();
			if (transaction.switch_to_dashboard) {
				continue;
			}

		}
		else if (dash.switch_to_budget) {
			codebase::Budget_Setter setter(user);
			setter.ShowDialog();
			if (setter.switch_to_dashboard) {
				continue;
			}
			else if (setter.switch_to_transaction) {
				codebase::Transaction transaction;
				transaction.ShowDialog();
			}

		}
		else {
			break;
		}
	}

}
