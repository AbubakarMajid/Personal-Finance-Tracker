//1.  Fine but limited
//#include "MyForm.h"
//using namespace System::Drawing;
//using namespace System;
//using namespace System::Windows::Forms;
//// Login Form
//public ref class LoginForm : public Form
//{
//public:
//    LoginForm()
//    {
//        Text = "Login Form";
//        Width = 300;
//        Height = 200;
//
//        Label^ usernameLabel = gcnew Label();
//        usernameLabel->Text = "Username:";
//        usernameLabel->Location = Point(10, 20);
//
//        TextBox^ usernameTextBox = gcnew TextBox();
//        usernameTextBox->Location = Point(80, 20);
//
//        Label^ passwordLabel = gcnew Label();
//        passwordLabel->Text = "Password:";
//        passwordLabel->Location = Point(10, 50);
//
//        TextBox^ passwordTextBox = gcnew TextBox();
//        passwordTextBox->PasswordChar = '*';
//        passwordTextBox->Location = Point(80, 50);
//
//        Button^ loginButton = gcnew Button();
//        loginButton->Text = "Login";
//        loginButton->Location = Point(100, 80);
//        loginButton->Click += gcnew EventHandler(this, &LoginForm::loginButton_Click);
//
//        Controls->Add(usernameLabel);
//        Controls->Add(usernameTextBox);
//        Controls->Add(passwordLabel);
//        Controls->Add(passwordTextBox);
//        Controls->Add(loginButton);
//    }
//
//private:
//    void loginButton_Click(Object^ sender, EventArgs^ e)
//    {
//        // Add authentication logic here
//        MessageBox::Show("Login logic goes here.");
//    }
//};
//// Main Form
//public ref class MainForm : public Form
//{
//private:
//    TextBox^ incomeTextBox;
//    TextBox^ expensesTextBox;
//    Label^ budgetLabel;
//
//public:
//    MainForm()
//    {
//        Text = "Personal Finance Tracker";
//        Width = 800;
//        Height = 600;
//
//        // Create labels
//        Label^ incomeLabel = gcnew Label();
//        incomeLabel->Text = "Income:";
//        incomeLabel->Location = Point(10, 20);
//
//        Label^ expensesLabel = gcnew Label();
//        expensesLabel->Text = "Expenses:";
//        expensesLabel->Location = Point(10, 50);
//
//        // Create text boxes
//        incomeTextBox = gcnew TextBox();
//        incomeTextBox->Location = Point(80, 20);
//        incomeTextBox->Width = 200;
//
//        expensesTextBox = gcnew TextBox();
//        expensesTextBox->Location = Point(80, 50);
//        expensesTextBox->Width = 200;
//
//        // Create calculate button
//        Button^ calculateButton = gcnew Button();
//        calculateButton->Text = "Calculate Budget";
//        calculateButton->Location = Point(300, 50);
//        calculateButton->Click += gcnew EventHandler(this, &MainForm::calculateButton_Click);
//
//        // Create budget label
//        budgetLabel = gcnew Label();
//        budgetLabel->Text = "";
//        budgetLabel->Location = Point(10, 80);
//
//        // Add controls to the form
//        Controls->Add(incomeLabel);
//        Controls->Add(expensesLabel);
//        Controls->Add(incomeTextBox);
//        Controls->Add(expensesTextBox);
//        Controls->Add(calculateButton);
//        Controls->Add(budgetLabel);
//    }
//
//private:
//    void calculateButton_Click(Object^ sender, EventArgs^ e)
//    {
//        try
//        {
//            float income = Convert::ToSingle(incomeTextBox->Text);
//            float expenses = Convert::ToSingle(expensesTextBox->Text);
//            float budget = income - expenses;
//            budgetLabel->Text = "Your budget is: $" + budget.ToString("N2");
//        }
//        catch (FormatException^)
//        {
//            MessageBox::Show("Invalid input. Please enter valid numbers for income and expenses.");
//        }
//        catch (Exception^ ex)
//        {
//            MessageBox::Show("An error occurred: " + ex->Message);
//        }
//    }
//};
//
//
//
//
//[STAThread]
//int main(array<String^>^ args)
//{
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//
//    // Start with the login form
//    Application::Run(gcnew LoginForm());
//
//    // Once logged in, switch to the main form
//    Application::Run(gcnew MainForm());
//
//    return 0;
//}
//
//
//
//
//2. ISSUE
//#include <iostream>
//#include <Windows.h>
//#include <msclr/marshal_cppstd.h>
//
//using namespace System;
//using namespace System::Drawing;
//using namespace System::Windows::Forms;
//
//// Custom function to copy a string
//void copyString(const char* source, char* destination, int maxLength)
//{
//    for (int i = 0; i < maxLength && source[i] != '\0'; i++)
//    {
//        destination[i] = source[i];
//        destination[i + 1] = '\0';
//    }
//}
//
//// Custom function to compare two strings
//bool compareString(const char* str1, const char* str2)
//{
//    int i = 0;
//    while (str1[i] != '\0' || str2[i] != '\0')
//    {
//        if (str1[i] != str2[i])
//            return false;
//        i++;
//    }
//    return true;
//}
//
//// Custom function to get string length
//int getStringLength(const char* str)
//{
//    int length = 0;
//    while (str[length] != '\0')
//    {
//        length++;
//    }
//    return length;
//}
//
//class User
//{
//private:
//    char* username;
//    char* password;
//
//public:
//    User(const char* username, const char* password)
//    {
//        this->username = new char[getStringLength(username) + 1];
//        this->password = new char[getStringLength(password) + 1];
//        copyString(username, this->username, getStringLength(username) + 1);
//        copyString(password, this->password, getStringLength(password) + 1);
//    }
//
//    bool authenticate(const char* username, const char* password) const
//    {
//        return compareString(this->username, username) && compareString(this->password, password);
//    }
//
//    ~User()
//    {
//        delete[] username;
//        delete[] password;
//    }
//};
//
//// MainForm class definition
//public ref class MainForm : public Form
//{
//private:
//    TextBox^ incomeTextBox;
//    TextBox^ expensesTextBox;
//    Label^ budgetLabel;
//
//public:
//    MainForm()
//    {
//        Text = "Personal Finance Tracker";
//        WindowState = FormWindowState::Maximized;
//
//        Label^ incomeLabel = gcnew Label();
//        incomeLabel->Text = "Income:";
//        incomeLabel->Location = Point(10, 20);
//
//        Label^ expensesLabel = gcnew Label();
//        expensesLabel->Text = "Expenses:";
//        expensesLabel->Location = Point(10, 50);
//
//        incomeTextBox = gcnew TextBox();
//        incomeTextBox->Location = Point(80, 20);
//        incomeTextBox->Width = 200;
//
//        expensesTextBox = gcnew TextBox();
//        expensesTextBox->Location = Point(80, 50);
//        expensesTextBox->Width = 200;
//
//        Button^ calculateButton = gcnew Button();
//        calculateButton->Text = "Calculate Budget";
//        calculateButton->Location = Point(300, 50);
//        calculateButton->Click += gcnew EventHandler(this, &MainForm::calculateButton_Click);
//
//        budgetLabel = gcnew Label();
//        budgetLabel->Text = "";
//        budgetLabel->Location = Point(10, 80);
//
//        Controls->Add(incomeLabel);
//        Controls->Add(expensesLabel);
//        Controls->Add(incomeTextBox);
//        Controls->Add(expensesTextBox);
//        Controls->Add(calculateButton);
//        Controls->Add(budgetLabel);
//    }
//
//private:
//    void calculateButton_Click(Object^ sender, EventArgs^ e)
//    {
//        try
//        {
//            float income = Convert::ToSingle(incomeTextBox->Text);
//            float expenses = Convert::ToSingle(expensesTextBox->Text);
//            float budget = income - expenses;
//            budgetLabel->Text = "Your budget is: $" + budget.ToString("N2");
//        }
//        catch (FormatException^)
//        {
//            MessageBox::Show("Invalid input. Please enter valid numbers for income and expenses.");
//        }
//        catch (Exception^ ex)
//        {
//            MessageBox::Show("An error occurred: " + ex->Message);
//        }
//    }
//};
//// Forward declaration of MainForm
//ref class MainForm;
//
//// LoginForm class definition
//public ref class LoginForm : public Form
//{
//private:
//    User** users;
//    int numUsers;
//    TextBox^ usernameTextBox;
//    TextBox^ passwordTextBox;
//
//public:
//    LoginForm()
//    {
//        Text = "Login Form";
//        WindowState = FormWindowState::Maximized;
//
//        numUsers = 1;
//        users = new User * [numUsers];
//        users[0] = new User("admin", "admin");
//
//        Label^ usernameLabel = gcnew Label();
//        usernameLabel->Text = "Username:";
//        usernameLabel->Location = Point(10, 20);
//
//        usernameTextBox = gcnew TextBox();
//        usernameTextBox->Location = Point(80, 20);
//        usernameTextBox->Width = 200; // Increase width for easier text entry
//        usernameTextBox->MaxLength = 50;
//
//        Label^ passwordLabel = gcnew Label();
//        passwordLabel->Text = "Password:";
//        passwordLabel->Location = Point(10, 50);
//
//        passwordTextBox = gcnew TextBox();
//        passwordTextBox->PasswordChar = '*';
//        passwordTextBox->Location = Point(80, 50);
//        passwordTextBox->Width = 200; // Increase width for easier text entry
//        passwordTextBox->MaxLength = 50; // Set MaxLength property to allow longer input
//
//        Button^ loginButton = gcnew Button();
//        loginButton->Text = "Login";
//        loginButton->Location = Point(100, 80);
//        loginButton->Click += gcnew EventHandler(this, &LoginForm::loginButton_Click);
//
//        Controls->Add(usernameLabel);
//        Controls->Add(usernameTextBox);
//        Controls->Add(passwordLabel);
//        Controls->Add(passwordTextBox);
//        Controls->Add(loginButton);
//    }
//
//private:
//    void loginButton_Click(Object^ sender, EventArgs^ e)
//    {
//        if (String::IsNullOrEmpty(usernameTextBox->Text) || String::IsNullOrEmpty(passwordTextBox->Text))
//        {
//            MessageBox::Show("Username and password are required.");
//            return;
//        }
//
//        char* username = new char[usernameTextBox->Text->Length + 1];
//        char* password = new char[passwordTextBox->Text->Length + 1];
//        msclr::interop::marshal_context context; // Create a marshal_context object for string conversion
//        copyString(context.marshal_as<const char*>(usernameTextBox->Text), username, usernameTextBox->Text->Length + 1);
//        copyString(context.marshal_as<const char*>(passwordTextBox->Text), password, passwordTextBox->Text->Length + 1);
//
//        for (int i = 0; i < numUsers; i++)
//        {
//            if (users[i]->authenticate(username, password))
//            {
//                MessageBox::Show("Login successful.");
//                this->Hide();
//                MainForm^ mainForm = gcnew MainForm();
//                mainForm->ShowDialog();
//                this->Close();
//                delete[] username;
//                delete[] password;
//                return;
//            }
//        }
//
//        MessageBox::Show("Login failed. Please try again.");
//        delete[] username;
//        delete[] password;
//    }
//
//protected:
//    ~LoginForm()
//    {
//        for (int i = 0; i < numUsers; i++)
//        {
//            delete users[i];
//        }
//        delete[] users;
//    }
//};
//
//
//
//[STAThread]
//int main(array<String^>^ args)
//{
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//
//    Application::Run(gcnew LoginForm());
//
//    return 0;
//}