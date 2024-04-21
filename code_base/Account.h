#pragma once
//#include <msclr/marshal_cppstd.h> 
#include "User.h"

namespace codebase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Account
	/// </summary>
	public ref class Account : public System::Windows::Forms::Form
	{
	public:
		Account(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Account()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_label;
	private: System::Windows::Forms::Label^ income_label;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ username_label;
	private: System::Windows::Forms::Label^ password_label;



	private: System::Windows::Forms::TextBox^ username_box;
	private: System::Windows::Forms::TextBox^ pass_box;
	private: System::Windows::Forms::TextBox^ Income_box;
	private: System::Windows::Forms::Button^ account_button;
	private: System::Windows::Forms::LinkLabel^ login_link;
	private: System::Windows::Forms::Label^ label1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->header_label = (gcnew System::Windows::Forms::Label());
			this->income_label = (gcnew System::Windows::Forms::Label());
			this->username_label = (gcnew System::Windows::Forms::Label());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->username_box = (gcnew System::Windows::Forms::TextBox());
			this->pass_box = (gcnew System::Windows::Forms::TextBox());
			this->Income_box = (gcnew System::Windows::Forms::TextBox());
			this->account_button = (gcnew System::Windows::Forms::Button());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// header_label
			// 
			this->header_label->AutoSize = true;
			this->header_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->header_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->header_label->Location = System::Drawing::Point(272, 32);
			this->header_label->Name = L"header_label";
			this->header_label->Size = System::Drawing::Size(178, 26);
			this->header_label->TabIndex = 0;
			this->header_label->Text = L"NEW ACCOUNT";
			this->header_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// income_label
			// 
			this->income_label->AutoSize = true;
			this->income_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->income_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->income_label->Location = System::Drawing::Point(31, 318);
			this->income_label->Name = L"income_label";
			this->income_label->Size = System::Drawing::Size(100, 26);
			this->income_label->TabIndex = 1;
			this->income_label->Text = L"INCOME";
			this->income_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// username_label
			// 
			this->username_label->AutoSize = true;
			this->username_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->username_label->Location = System::Drawing::Point(31, 118);
			this->username_label->Name = L"username_label";
			this->username_label->Size = System::Drawing::Size(138, 26);
			this->username_label->TabIndex = 2;
			this->username_label->Text = L"USERNAME";
			this->username_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->password_label->Location = System::Drawing::Point(31, 223);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(142, 26);
			this->password_label->TabIndex = 3;
			this->password_label->Text = L"PASSWORD";
			this->password_label->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// username_box
			// 
			this->username_box->Location = System::Drawing::Point(172, 173);
			this->username_box->Name = L"username_box";
			this->username_box->Size = System::Drawing::Size(367, 20);
			this->username_box->TabIndex = 5;
			// 
			// pass_box
			// 
			this->pass_box->Location = System::Drawing::Point(172, 282);
			this->pass_box->Name = L"pass_box";
			this->pass_box->Size = System::Drawing::Size(367, 20);
			this->pass_box->TabIndex = 6;
			// 
			// Income_box
			// 
			this->Income_box->Location = System::Drawing::Point(172, 378);
			this->Income_box->Name = L"Income_box";
			this->Income_box->Size = System::Drawing::Size(367, 20);
			this->Income_box->TabIndex = 7;
			// 
			// account_button
			// 
			this->account_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->account_button->Location = System::Drawing::Point(277, 453);
			this->account_button->Name = L"account_button";
			this->account_button->Size = System::Drawing::Size(150, 34);
			this->account_button->TabIndex = 8;
			this->account_button->Text = L"CREATE ACCOUNT";
			this->account_button->UseVisualStyleBackColor = true;
			this->account_button->Click += gcnew System::EventHandler(this, &Account::account_button_Click);
			// 
			// login_link
			// 
			this->login_link->AutoSize = true;
			this->login_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_link->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->login_link->Location = System::Drawing::Point(638, 510);
			this->login_link->Name = L"login_link";
			this->login_link->Size = System::Drawing::Size(65, 22);
			this->login_link->TabIndex = 10;
			this->login_link->TabStop = true;
			this->login_link->Text = L"LOGIN";
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Account::login_link_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(459, 515);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 17);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Already have an account\?";
			// 
			// Account
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(725, 541);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->login_link);
			this->Controls->Add(this->account_button);
			this->Controls->Add(this->Income_box);
			this->Controls->Add(this->pass_box);
			this->Controls->Add(this->username_box);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->username_label);
			this->Controls->Add(this->income_label);
			this->Controls->Add(this->header_label);
			this->Name = L"Account";
			this->Text = L"Account";
			this->Load += gcnew System::EventHandler(this, &Account::Account_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Account_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public: bool switch_to_login = false;
private: System::Void login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switch_to_login = true;
	this->Close();
}
	   public: USER^ user = nullptr;
private: System::Void account_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ username = username_box->Text;
	String^ password = pass_box->Text;
	String^ income = Income_box->Text;

	/*msclr::interop::marshal_context context;
	std::wstring incomeStr = context.marshal_as<std::wstring>(income);
	int incomeInt = std::stoi(incomeStr);*/
	int incomeInt = Convert::ToInt32(income);

	if (username->Length == 0 || password->Length == 0 || income->Length == 0) {
		MessageBox::Show("PlEASE ENTER ALL THE FIELDS!!","One or More Empty Fields", MessageBoxButtons::OK);
		return;
	}

	try {

		String^ conn_str = "Data Source=(localdb)\\tracker-app;Initial Catalog=tracker-app-db;Integrated Security=True";
		SqlConnection sqlConn(conn_str);

		sqlConn.Open();

		String^ sqlQuery = "INSERT INTO Credentials (Username , Passkey , Income , Balance) VALUES (@user  , @pwd , @income , @balance)";

		SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
		command->Parameters->AddWithValue("@user", username);
		command->Parameters->AddWithValue("@pwd", password);
		command->Parameters->AddWithValue("@income", incomeInt);
		command->Parameters->AddWithValue("@balance", incomeInt);

		command->ExecuteNonQuery();

		user = gcnew USER;
		user->username = username;
		user->income = incomeInt;
		user->balance = incomeInt;

		this->Close();

	}
	catch(Exception^ e){
		MessageBox::Show("Failed to Create Account", "Account Creation Failed", MessageBoxButtons::OK);
	}

}
};
}
