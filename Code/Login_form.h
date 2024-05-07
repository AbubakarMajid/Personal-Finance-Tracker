#pragma once
#include "User.h"

namespace Project {

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





	private: System::Windows::Forms::TextBox^ username_box;
	private: System::Windows::Forms::TextBox^ password_box;


	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::LinkLabel^ account_link;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(login_form::typeid));
			this->username_box = (gcnew System::Windows::Forms::TextBox());
			this->password_box = (gcnew System::Windows::Forms::TextBox());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->account_link = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// username_box
			// 
			this->username_box->AllowDrop = true;
			this->username_box->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->username_box->Location = System::Drawing::Point(79, 209);
			this->username_box->Multiline = true;
			this->username_box->Name = L"username_box";
			this->username_box->Size = System::Drawing::Size(198, 29);
			this->username_box->TabIndex = 3;
			// 
			// password_box
			// 
			this->password_box->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->password_box->Location = System::Drawing::Point(79, 278);
			this->password_box->Multiline = true;
			this->password_box->Name = L"password_box";
			this->password_box->PasswordChar = '*';
			this->password_box->Size = System::Drawing::Size(198, 31);
			this->password_box->TabIndex = 4;
			// 
			// login_button
			// 
			this->login_button->BackColor = System::Drawing::Color::AliceBlue;
			this->login_button->ForeColor = System::Drawing::Color::MidnightBlue;
			this->login_button->Location = System::Drawing::Point(117, 330);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(123, 38);
			this->login_button->TabIndex = 5;
			this->login_button->Text = L"Login";
			this->login_button->UseVisualStyleBackColor = false;
			this->login_button->Click += gcnew System::EventHandler(this, &login_form::login_button_Click);
			// 
			// account_link
			// 
			this->account_link->AutoSize = true;
			this->account_link->BackColor = System::Drawing::Color::LightSteelBlue;
			this->account_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->account_link->LinkColor = System::Drawing::Color::DarkBlue;
			this->account_link->Location = System::Drawing::Point(137, 397);
			this->account_link->Name = L"account_link";
			this->account_link->Size = System::Drawing::Size(140, 24);
			this->account_link->TabIndex = 7;
			this->account_link->TabStop = true;
			this->account_link->Text = L"Create Account";
			this->account_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &login_form::account_link_LinkClicked);
			// 
			// login_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(914, 558);
			this->Controls->Add(this->account_link);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->password_box);
			this->Controls->Add(this->username_box);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"login_form";
			this->Text = L"login_form";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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
			// COLLATE Latin1_General_CS_AS specifies a case-sensitive collation for the comparison.
			String^ query = "SELECT * FROM Credentials WHERE Username=@username COLLATE Latin1_General_CS_AS AND Passkey=@pwd COLLATE Latin1_General_CS_AS;";
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
	private: System::Void info_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}