#pragma once
#include "User.h"

namespace codebase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for home_form
	/// </summary>
	public ref class home_form : public System::Windows::Forms::Form
	{
	public:
		home_form(USER^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			user_label->Text = "HELLO " + user->username + "!";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~home_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ user_label;
	private: System::Windows::Forms::Label^ header_labl;
	protected:

	protected:

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
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->header_labl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// user_label
			// 
			this->user_label->AutoSize = true;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_label->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->user_label->Location = System::Drawing::Point(35, 128);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(58, 26);
			this->user_label->TabIndex = 0;
			this->user_label->Text = L"label";
			this->user_label->Click += gcnew System::EventHandler(this, &home_form::user_label_Click);
			// 
			// header_labl
			// 
			this->header_labl->AutoSize = true;
			this->header_labl->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->header_labl->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->header_labl->Location = System::Drawing::Point(530, 32);
			this->header_labl->Name = L"header_labl";
			this->header_labl->Size = System::Drawing::Size(528, 44);
			this->header_labl->TabIndex = 1;
			this->header_labl->Text = L"PERSONAL FINANCE TRACKER";
			this->header_labl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// home_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1525, 639);
			this->Controls->Add(this->header_labl);
			this->Controls->Add(this->user_label);
			this->Name = L"home_form";
			this->Text = L"home_form";
			this->Load += gcnew System::EventHandler(this, &home_form::home_form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void user_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void home_form_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
