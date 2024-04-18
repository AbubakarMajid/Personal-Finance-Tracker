#pragma once

namespace dashboard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;



	private: System::Windows::Forms::Panel^ panel7;

	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel16;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Label^ label11;




	private: System::ComponentModel::IContainer^ components;
















	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea8 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel11->SuspendLayout();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1166, 64);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 64);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::DarkBlue;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->tableLayoutPanel2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 64);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 615);
			this->panel3->TabIndex = 2;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel3_Paint);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->panel11);
			this->panel7->Controls->Add(this->panel8);
			this->panel7->Controls->Add(this->tableLayoutPanel1);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(200, 64);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(966, 615);
			this->panel7->TabIndex = 3;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Azure;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->label9);
			this->panel8->Controls->Add(this->chart1);
			this->panel8->Controls->Add(this->progressBar1);
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel8->Location = System::Drawing::Point(600, 114);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(364, 499);
			this->panel8->TabIndex = 1;
			this->panel8->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel8_Paint);
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->label8);
			this->panel9->Location = System::Drawing::Point(116, 28);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(134, 120);
			this->panel9->TabIndex = 2;
			this->panel9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel9_Paint);
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->progressBar1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->progressBar1->Location = System::Drawing::Point(39, 198);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(281, 20);
			this->progressBar1->TabIndex = 2;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Dashboard::progressBar1_Click);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::LightSteelBlue;
			chartArea8->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea8);
			legend8->Name = L"Legend1";
			this->chart1->Legends->Add(legend8);
			this->chart1->Location = System::Drawing::Point(39, 259);
			this->chart1->Name = L"chart1";
			series8->ChartArea = L"ChartArea1";
			series8->Legend = L"Legend1";
			series8->Name = L"Series1";
			this->chart1->Series->Add(series8);
			this->chart1->Size = System::Drawing::Size(281, 235);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &Dashboard::chart1_Click);
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::AliceBlue;
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->panel10);
			this->panel11->Location = System::Drawing::Point(0, 114);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(600, 506);
			this->panel11->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(20, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(232, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Monthly Transactions";
			this->label1->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel10->Controls->Add(this->domainUpDown1);
			this->panel10->Controls->Add(this->dataGridView1);
			this->panel10->Controls->Add(this->label1);
			this->panel10->Location = System::Drawing::Point(42, 28);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(519, 447);
			this->panel10->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(24, 69);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(465, 353);
			this->dataGridView1->TabIndex = 4;
			// 
			// domainUpDown1
			// 
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
			this->domainUpDown1->Location = System::Drawing::Point(304, 20);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(185, 29);
			this->domainUpDown1->TabIndex = 5;
			this->domainUpDown1->Text = L"Month";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->panel16, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->panel14, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel15, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(200, 230);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel5->Controls->Add(this->label3);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(231, 4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(183, 106);
			this->panel5->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel6->Controls->Add(this->label4);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(421, 4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(172, 106);
			this->panel6->TabIndex = 2;
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->label5);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(600, 4);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(177, 106);
			this->panel12->TabIndex = 3;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::CornflowerBlue;
			this->panel13->Controls->Add(this->label6);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(784, 4);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(176, 106);
			this->panel13->TabIndex = 4;
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(964, 114);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::tableLayoutPanel1_Paint_1);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::SteelBlue;
			this->panel4->Controls->Add(this->label2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(4, 4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(220, 106);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel4_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 11, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(60, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 26);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Balance";
			this->label2->Click += gcnew System::EventHandler(this, &Dashboard::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 11, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Window;
			this->label3->Location = System::Drawing::Point(41, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 26);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Shopping";
			this->label3->Click += gcnew System::EventHandler(this, &Dashboard::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 11, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Window;
			this->label4->Location = System::Drawing::Point(55, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 26);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Food\r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 11, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Window;
			this->label5->Location = System::Drawing::Point(49, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 26);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Utility";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 11, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Window;
			this->label6->Location = System::Drawing::Point(58, 27);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 26);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Others";
			this->label6->Click += gcnew System::EventHandler(this, &Dashboard::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label7->Location = System::Drawing::Point(0, 8);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(200, 46);
			this->label7->TabIndex = 1;
			this->label7->Text = L"CoinControl";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label8->Font = (gcnew System::Drawing::Font(L"Cambria", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::Window;
			this->label8->Location = System::Drawing::Point(-1, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(134, 21);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Your Net Worth";
			this->label8->Click += gcnew System::EventHandler(this, &Dashboard::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label9->Location = System::Drawing::Point(35, 164);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(139, 26);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Income Goal";
			// 
			// panel14
			// 
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel14->Location = System::Drawing::Point(4, 4);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(192, 107);
			this->panel14->TabIndex = 0;
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Controls->Add(this->label11);
			this->panel15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel15->Location = System::Drawing::Point(4, 118);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(192, 50);
			this->panel15->TabIndex = 1;
			// 
			// panel16
			// 
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel16->Controls->Add(this->label12);
			this->panel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel16->Location = System::Drawing::Point(4, 175);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(192, 51);
			this->panel16->TabIndex = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Cambria", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::Window;
			this->label11->Location = System::Drawing::Point(3, 13);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(111, 23);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Dashboard";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cambria", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::Window;
			this->label12->Location = System::Drawing::Point(3, 13);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(176, 23);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Financial Tool Box";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1166, 679);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel11->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel9_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel8_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};

}
