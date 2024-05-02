#pragma once
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
	/// Summary for login_form
	/// </summary>
	public ref class login_form : public System::Windows::Forms::Form
	{
	public:
		login_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ password_label;

	private: System::Windows::Forms::Label^ username_label;

	private: System::Windows::Forms::TextBox^ username_box;
	private: System::Windows::Forms::TextBox^ password_box;


	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::LinkLabel^ account_link;
	private: System::Windows::Forms::Label^ info_label;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->username_label = (gcnew System::Windows::Forms::Label());
			this->username_box = (gcnew System::Windows::Forms::TextBox());
			this->password_box = (gcnew System::Windows::Forms::TextBox());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->account_link = (gcnew System::Windows::Forms::LinkLabel());
			this->info_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(241, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOGIN";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &login_form::label1_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->password_label->Location = System::Drawing::Point(55, 220);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(172, 31);
			this->password_label->TabIndex = 1;
			this->password_label->Text = L"PASSWORD";
			// 
			// username_label
			// 
			this->username_label->AutoSize = true;
			this->username_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->username_label->Location = System::Drawing::Point(55, 120);
			this->username_label->Name = L"username_label";
			this->username_label->Size = System::Drawing::Size(168, 31);
			this->username_label->TabIndex = 2;
			this->username_label->Text = L"USERNAME";
			// 
			// username_box
			// 
			this->username_box->AllowDrop = true;
			this->username_box->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->username_box->Location = System::Drawing::Point(60, 164);
			this->username_box->Name = L"username_box";
			this->username_box->Size = System::Drawing::Size(440, 38);
			this->username_box->TabIndex = 3;
			// 
			// password_box
			// 
			this->password_box->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->password_box->Location = System::Drawing::Point(60, 271);
			this->password_box->Name = L"password_box";
			this->password_box->PasswordChar = '*';
			this->password_box->Size = System::Drawing::Size(440, 38);
			this->password_box->TabIndex = 4;
			// 
			// login_button
			// 
			this->login_button->Location = System::Drawing::Point(230, 334);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(123, 38);
			this->login_button->TabIndex = 5;
			this->login_button->Text = L"LOGIN";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &login_form::login_button_Click);
			// 
			// account_link
			// 
			this->account_link->AutoSize = true;
			this->account_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->account_link->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->account_link->Location = System::Drawing::Point(491, 460);
			this->account_link->Name = L"account_link";
			this->account_link->Size = System::Drawing::Size(215, 26);
			this->account_link->TabIndex = 7;
			this->account_link->TabStop = true;
			this->account_link->Text = L"CREATE ACCOUNT";
			this->account_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &login_form::account_link_LinkClicked);
			// 
			// info_label
			// 
			this->info_label->AutoSize = true;
			this->info_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->info_label->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->info_label->Location = System::Drawing::Point(300, 465);
			this->info_label->Name = L"info_label";
			this->info_label->Size = System::Drawing::Size(185, 20);
			this->info_label->TabIndex = 8;
			this->info_label->Text = L"Don\'t have an account\?";
			// 
			// login_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(734, 500);
			this->Controls->Add(this->info_label);
			this->Controls->Add(this->account_link);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->password_box);
			this->Controls->Add(this->username_box);
			this->Controls->Add(this->username_label);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"login_form";
			this->Text = L"login_form";
			this->Load += gcnew System::EventHandler(this, &login_form::login_form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	public:
		USER^ user = nullptr;
	private: System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->username_box->Text;
		String^ password = this->password_box->Text;
		if (username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter username or password");
			return;
		}

		try {
			String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
			SqlConnection sqlConn(conn_str);

			sqlConn.Open();

			String^ query = "SELECT * FROM Credentials WHERE Username=@username AND Passkey=@pwd;";
			SqlCommand^ command = gcnew SqlCommand(query, % sqlConn);
			command->Parameters->AddWithValue("@username", username);
			command->Parameters->AddWithValue("@pwd", password);

			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read()) {
				user = gcnew USER;
				user->username = reader->GetString(0);
				user->password = reader->GetString(1);
				user->income = reader->GetInt64(2);
				user->balance = reader->GetInt64(3);
				this->Close();
			}
			else {
				MessageBox::Show("Username or password is incorrect",
					"Email or Password Error", MessageBoxButtons::OK);

			}
		}
		catch (Exception^ e) {
			MessageBox::Show("No Database connection !!");
		}

	}
	private: System::Void account_button_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: bool switch_to_account = false;
	private: System::Void account_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->switch_to_account = true;
		this->Close();

	}
	private: System::Void login_form_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}