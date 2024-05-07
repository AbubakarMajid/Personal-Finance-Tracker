#pragma once
#include "User.h"
namespace Project
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Budget_Setter
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(USER^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			if (user != nullptr)
			{
				this->label6->Text = Convert::ToString(user->balance);

			}

			cat_label_data(this->label10, "Utility", user->username);
			cat_label_data(this->label9, "Entertainment", user->username);
			cat_label_data(this->label8, "health", user->username);
			cat_label_data(this->label11, "Food", user->username);

			try {
				String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
				SqlConnection sqlConn(conn_str);

				sqlConn.Open();

				String^ tmpQuery = "Select i.income_goal ,c.Balance from Income_goal as i JOIN Credentials as c ON i.Username = c.Username WHERE c.Username = @user";

				SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
				command->Parameters->AddWithValue("@user", user->username);
				//command->Parameters->AddWithValue("@cat", "Utility");
				SqlDataReader^ reader = command->ExecuteReader();

				if (reader->Read()) {
					this->progressBar1->Maximum = reader->GetInt64(0);
					this->progressBar1->Value = reader->GetInt64(1);
					//this->label10->Text = Convert::ToString(reader->GetInt64(0));
					//this->label11->Text = Convert::ToString(reader->GetInt64(1));

				}
				else {
					//this->label10->Text = "0";
				}
			}

			catch (Exception^ e) {
				MessageBox::Show(e->Message);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel13;

	private: System::Windows::Forms::Panel^ panel12;

	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::Panel^ panel5;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel10;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ label13;
	public: System::Windows::Forms::ProgressBar^ progressBar1;
	private:



	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Label^ user_name;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;

private: System::Windows::Forms::Label^ label24;



private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Label^ label27;



private: System::Windows::Forms::RadioButton^ radioButton1;

private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::RadioButton^ radioButton4;
private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label28;



	private: System::Windows::Forms::Panel^ panel7;
	//private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;







		   void cat_label_data(Label^ label, String^ cat, String^ username) {
			   try {
				   String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
				   SqlConnection sqlConn(conn_str);

				   sqlConn.Open();

				   String^ tmpQuery = "SELECT SUM(Amount) FROM Transactions WHERE Username = @user AND Category = @cat GROUP BY Username , Category";

				   SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
				   command->Parameters->AddWithValue("@user", username);
				   command->Parameters->AddWithValue("@cat", cat);
				   SqlDataReader^ reader = command->ExecuteReader();

				   if (reader->Read()) {
					   label->Text = Convert::ToString(reader->GetInt64(0));
				   }
				   else {
					   label->Text = "0";
				   }
			   }

			   catch (Exception^ e) {
				   label->Text = e->Message;
			   }
		   }























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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->user_name = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1370, 90);
			this->panel1->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(-1, -1);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(250, 90);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel2_Paint);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label7->ForeColor = System::Drawing::Color::Navy;
			this->label7->Location = System::Drawing::Point(-5, 18);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(254, 57);
			this->label7->TabIndex = 1;
			this->label7->Text = L"CoinControl";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SteelBlue;
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->user_name);
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 90);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(250, 659);
			this->panel3->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SteelBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(0, 286);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(250, 47);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Budget/Goal Setup Form";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Dashboard::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SteelBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(0, 239);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(250, 47);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Transaction Log";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Dashboard::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(0, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 47);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Dashboard";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.65931F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.76867F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.61199F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.13775F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.82229F)));
			this->tableLayoutPanel1->Controls->Add(this->panel13, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel12, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel6, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(250, 90);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1120, 88);
			this->tableLayoutPanel1->TabIndex = 7;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel13->Controls->Add(this->label21);
			this->panel13->Controls->Add(this->label22);
			this->panel13->Controls->Add(this->label11);
			this->panel13->Controls->Add(this->label5);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(910, 3);
			this->panel13->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(207, 82);
			this->panel13->TabIndex = 4;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Location = System::Drawing::Point(60, 44);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 21);
			this->label11->TabIndex = 3;
			this->label11->Text = L"label11";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(15, 12);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Food";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::LightSkyBlue;
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->label19);
			this->panel12->Controls->Add(this->label20);
			this->panel12->Controls->Add(this->label8);
			this->panel12->Controls->Add(this->label3);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(696, 3);
			this->panel12->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(209, 82);
			this->panel12->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Location = System::Drawing::Point(58, 43);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(54, 21);
			this->label8->TabIndex = 2;
			this->label8->Text = L"label8";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(2, 11);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Health care";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel6->Controls->Add(this->label17);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Controls->Add(this->label9);
			this->panel6->Controls->Add(this->label4);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel6->Location = System::Drawing::Point(488, 3);
			this->panel6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(203, 82);
			this->panel6->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label9->Location = System::Drawing::Point(57, 44);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 21);
			this->label9->TabIndex = 3;
			this->label9->Text = L"label9";
			this->label9->Click += gcnew System::EventHandler(this, &Dashboard::label9_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(2, 12);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Entertainment";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::LightSkyBlue;
			this->panel5->Controls->Add(this->label15);
			this->panel5->Controls->Add(this->label16);
			this->panel5->Controls->Add(this->label10);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(267, 3);
			this->panel5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(216, 82);
			this->panel5->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label10->Location = System::Drawing::Point(62, 44);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 21);
			this->label10->TabIndex = 4;
			this->label10->Text = L"label10";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(15, 12);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Utility";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::SteelBlue;
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(259, 82);
			this->panel4->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->Location = System::Drawing::Point(148, 44);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 21);
			this->label6->TabIndex = 1;
			this->label6->Text = L"label6";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(37, 12);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Balance";
			this->label1->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// panel11
			// 
			this->panel11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel11->BackColor = System::Drawing::Color::AliceBlue;
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->panel10);
			this->panel11->Location = System::Drawing::Point(250, 178);
			this->panel11->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(1147, 833);
			this->panel11->TabIndex = 8;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel10->Controls->Add(this->comboBox1);
			this->panel10->Controls->Add(this->dataGridView1);
			this->panel10->Controls->Add(this->label12);
			this->panel10->Location = System::Drawing::Point(22, 25);
			this->panel10->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(641, 538);
			this->panel10->TabIndex = 3;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"January", L"February", L"March", L"April", L"May",
					L"June", L"July", L"August", L"September", L"October", L"November", L"December"
			});
			this->comboBox1->Location = System::Drawing::Point(472, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(141, 23);
			this->comboBox1->TabIndex = 6;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(22, 52);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(591, 404);
			this->dataGridView1->TabIndex = 4;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::Window;
			this->label12->Location = System::Drawing::Point(17, 16);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(198, 25);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Monthly Transactions";
			this->label12->Click += gcnew System::EventHandler(this, &Dashboard::label12_Click);
			// 
			// panel8
			// 
			this->panel8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel8->BackColor = System::Drawing::Color::Azure;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Controls->Add(this->radioButton4);
			this->panel8->Controls->Add(this->radioButton3);
			this->panel8->Controls->Add(this->radioButton2);
			this->panel8->Controls->Add(this->label27);
			this->panel8->Controls->Add(this->radioButton1);
			this->panel8->Controls->Add(this->pictureBox2);
			this->panel8->Controls->Add(this->label25);
			this->panel8->Controls->Add(this->label23);
			this->panel8->Controls->Add(this->label24);
			this->panel8->Controls->Add(this->panel7);
			this->panel8->Controls->Add(this->label13);
			this->panel8->Controls->Add(this->progressBar1);
			this->panel8->Location = System::Drawing::Point(918, 178);
			this->panel8->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(681, 678);
			this->panel8->TabIndex = 9;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel7->Controls->Add(this->label28);
			this->panel7->Controls->Add(this->label14);
			this->panel7->Location = System::Drawing::Point(90, 41);
			this->panel7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(271, 70);
			this->panel7->TabIndex = 5;
			this->panel7->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel7_Paint);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::Window;
			this->label14->Location = System::Drawing::Point(42, 11);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(197, 25);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Total Amount Earned";
			this->label14->Click += gcnew System::EventHandler(this, &Dashboard::label14_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::DarkBlue;
			this->label13->Location = System::Drawing::Point(32, 252);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(121, 25);
			this->label13->TabIndex = 3;
			this->label13->Text = L"Income Goal";
			this->label13->Click += gcnew System::EventHandler(this, &Dashboard::label13_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->progressBar1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->progressBar1->Location = System::Drawing::Point(37, 290);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(372, 19);
			this->progressBar1->TabIndex = 2;
			this->progressBar1->Value = 20;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Dashboard::progressBar1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(55, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(137, 136);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// user_name
			// 
			this->user_name->AutoSize = true;
			this->user_name->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_name->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->user_name->Location = System::Drawing::Point(86, 159);
			this->user_name->Name = L"user_name";
			this->user_name->Size = System::Drawing::Size(72, 25);
			this->user_name->TabIndex = 4;
			this->user_name->Text = L"label15";
			this->user_name->Click += gcnew System::EventHandler(this, &Dashboard::label15_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label15->Location = System::Drawing::Point(127, 44);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(60, 21);
			this->label15->TabIndex = 7;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label16->Location = System::Drawing::Point(114, 44);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(17, 21);
			this->label16->TabIndex = 8;
			this->label16->Text = L"/";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label17->Location = System::Drawing::Point(116, 44);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(60, 21);
			this->label17->TabIndex = 9;
			this->label17->Text = L"label17";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label18->Location = System::Drawing::Point(103, 44);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(17, 21);
			this->label18->TabIndex = 10;
			this->label18->Text = L"/";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label19->Location = System::Drawing::Point(117, 43);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(60, 21);
			this->label19->TabIndex = 11;
			this->label19->Text = L"label19";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label20->Location = System::Drawing::Point(105, 43);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(17, 21);
			this->label20->TabIndex = 12;
			this->label20->Text = L"/";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label21->Location = System::Drawing::Point(128, 44);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(60, 21);
			this->label21->TabIndex = 13;
			this->label21->Text = L"label21";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label22->Location = System::Drawing::Point(116, 44);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(17, 21);
			this->label22->TabIndex = 14;
			this->label22->Text = L"/";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::DarkBlue;
			this->label24->Location = System::Drawing::Point(348, 258);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(50, 17);
			this->label24->TabIndex = 7;
			this->label24->Text = L"label24";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::DarkBlue;
			this->label23->Location = System::Drawing::Point(273, 258);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(50, 17);
			this->label23->TabIndex = 8;
			this->label23->Text = L"label23";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::DarkBlue;
			this->label25->Location = System::Drawing::Point(329, 258);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(13, 17);
			this->label25->TabIndex = 9;
			this->label25->Text = L"/";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(198, 116);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(38, 36);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->ForeColor = System::Drawing::Color::DarkBlue;
			this->radioButton1->Location = System::Drawing::Point(101, 528);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(46, 19);
			this->radioButton1->TabIndex = 11;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"PKR";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::DarkBlue;
			this->label27->Location = System::Drawing::Point(19, 490);
			this->label27->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(134, 20);
			this->label27->TabIndex = 15;
			this->label27->Text = L"Currency Switcher";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->ForeColor = System::Drawing::Color::DarkBlue;
			this->radioButton2->Location = System::Drawing::Point(288, 528);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(47, 19);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"GBP";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->ForeColor = System::Drawing::Color::DarkBlue;
			this->radioButton3->Location = System::Drawing::Point(233, 528);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(49, 19);
			this->radioButton3->TabIndex = 17;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"USD";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->ForeColor = System::Drawing::Color::DarkBlue;
			this->radioButton4->Location = System::Drawing::Point(169, 528);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(46, 19);
			this->radioButton4->TabIndex = 18;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"EUR";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::AliceBlue;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::DarkBlue;
			this->button4->Location = System::Drawing::Point(6, 607);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(239, 40);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Log Out";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label28->Location = System::Drawing::Point(104, 36);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(63, 21);
			this->label28->TabIndex = 2;
			this->label28->Text = L"label28";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label26->Location = System::Drawing::Point(104, 36);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(63, 21);
			this->label26->TabIndex = 2;
			this->label26->Text = L"label26";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::SystemColors::Window;
			this->label29->Location = System::Drawing::Point(42, 11);
			this->label29->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(186, 25);
			this->label29->TabIndex = 1;
			this->label29->Text = L"Total Amount Spent";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel9->Controls->Add(this->label26);
			this->panel9->Controls->Add(this->label29);
			this->panel9->Location = System::Drawing::Point(90, 157);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(271, 70);
			this->panel9->TabIndex = 19;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Name = L"Dashboard";
			this->Text = L"Budget_Setter";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Dashboard::Budget_Setter_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: bool switch_to_transaction = false;
	public: bool switch_to_budget = false;

	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Budget_Setter_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_transaction = true;
		this->Close();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_budget = true;
		this->Close();
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}




	private: System::Void panel9_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
#pragma once

namespace dashboard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Budget_Setter
	/// </summary>
	public ref class Budget_Setter : public System::Windows::Forms::Form
	{
	public:
		Budget_Setter(void)
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
		~Budget_Setter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel13;

	private: System::Windows::Forms::Panel^ panel12;

	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::Panel^ panel5;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ label14;






























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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->SuspendLayout();
			this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1689, 137);
			this->panel1->TabIndex = 6;
			this->panel2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(-2, -2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(374, 137);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Budget_Setter::panel2_Paint);
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label7->ForeColor = System::Drawing::Color::Navy;
			this->label7->Location = System::Drawing::Point(-8, 28);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(374, 87);
			this->label7->TabIndex = 1;
			this->label7->Text = L"CoinControl";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel3->BackColor = System::Drawing::Color::SteelBlue;
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 137);
			this->panel3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(375, 913);
			this->panel3->TabIndex = 4;
			this->button3->BackColor = System::Drawing::Color::SteelBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Perpetua", 15.75, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(0, 315);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(375, 72);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Budget/Goal Setup Form";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			this->button2->BackColor = System::Drawing::Color::SteelBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Perpetua", 15.75, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(0, 234);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(375, 72);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Transaction Log";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Perpetua", 15.75, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(0, 152);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(375, 72);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Dashboard";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.65931)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.76867)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.61199)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.13775)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.82229)));
			this->tableLayoutPanel1->Controls->Add(this->panel13, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel12, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel6, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(375, 137);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1314, 135);
			this->tableLayoutPanel1->TabIndex = 7;
			this->panel13->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel13->Controls->Add(this->label11);
			this->panel13->Controls->Add(this->label5);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(1068, 4);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(242, 127);
			this->panel13->TabIndex = 4;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(121, 67);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(60, 20);
			this->label11->TabIndex = 3;
			this->label11->Text = L"label11";
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Perpetua", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(28, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Food";
			this->panel12->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->label8);
			this->panel12->Controls->Add(this->label3);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(817, 4);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(244, 127);
			this->panel12->TabIndex = 3;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(133, 66);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 20);
			this->label8->TabIndex = 2;
			this->label8->Text = L"label8";
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Perpetua", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 32);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Health care";
			this->panel6->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel6->Controls->Add(this->label9);
			this->panel6->Controls->Add(this->label4);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(573, 4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(237, 127);
			this->panel6->TabIndex = 2;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(121, 67);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 20);
			this->label9->TabIndex = 3;
			this->label9->Text = L"label9";
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Perpetua", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(173, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Entertainment";
			this->panel5->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel5->Controls->Add(this->label10);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(314, 4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(252, 127);
			this->panel5->TabIndex = 1;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(126, 67);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 20);
			this->label10->TabIndex = 4;
			this->label10->Text = L"label10";
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Perpetua", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Utilities";
			this->panel4->BackColor = System::Drawing::Color::LightBlue;
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(4, 4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(303, 127);
			this->panel4->TabIndex = 0;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(172, 67);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 1;
			this->label6->Text = L"label6";
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Perpetua", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(34, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Balance";
			this->panel11->BackColor = System::Drawing::Color::AliceBlue;
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->panel10);
			this->panel11->Location = System::Drawing::Point(379, 272);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(980, 715);
			this->panel11->TabIndex = 8;
			this->panel10->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel10->Controls->Add(this->domainUpDown1);
			this->panel10->Controls->Add(this->dataGridView1);
			this->panel10->Controls->Add(this->label12);
			this->panel10->Location = System::Drawing::Point(39, 39);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(884, 637);
			this->panel10->TabIndex = 3;
			this->domainUpDown1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Cambria", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown1->ForeColor = System::Drawing::SystemColors::Window;
			this->domainUpDown1->Items->Add(L"January");
			this->domainUpDown1->Items->Add(L"February");
			this->domainUpDown1->Items->Add(L"March");
			this->domainUpDown1->Items->Add(L"April");
			this->domainUpDown1->Items->Add(L"May");
			this->domainUpDown1->Items->Add(L"June");
			this->domainUpDown1->Items->Add(L"July");
			this->domainUpDown1->Items->Add(L"August");
			this->domainUpDown1->Items->Add(L"September");
			this->domainUpDown1->Items->Add(L"October");
			this->domainUpDown1->Items->Add(L"November");
			this->domainUpDown1->Items->Add(L"December");
			this->domainUpDown1->Location = System::Drawing::Point(630, 25);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(185, 29);
			this->domainUpDown1->TabIndex = 5;
			this->domainUpDown1->Text = L"Month";
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(33, 69);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(826, 535);
			this->dataGridView1->TabIndex = 4;
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cambria", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::Window;
			this->label12->Location = System::Drawing::Point(34, 23);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(232, 26);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Monthly Transactions";
			this->panel8->BackColor = System::Drawing::Color::Azure;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->label13);
			this->panel8->Controls->Add(this->progressBar1);
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel8->Location = System::Drawing::Point(1355, 272);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(334, 778);
			this->panel8->TabIndex = 9;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Cambria", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label13->Location = System::Drawing::Point(35, 164);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(139, 26);
			this->label13->TabIndex = 3;
			this->label13->Text = L"Income Goal";
			this->progressBar1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->progressBar1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->progressBar1->Location = System::Drawing::Point(39, 198);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(281, 20);
			this->progressBar1->TabIndex = 2;
			this->panel9->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->label14);
			this->panel9->Location = System::Drawing::Point(116, 28);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(134, 120);
			this->panel9->TabIndex = 2;
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label14->Font = (gcnew System::Drawing::Font(L"Cambria", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::Window;
			this->label14->Location = System::Drawing::Point(-1, 30);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(134, 21);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Your Net Worth";
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(1689, 1050);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Budget_Setter";
			this->Text = L"Budget_Setter";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Budget_Setter::Budget_Setter_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Budget_Setter_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}