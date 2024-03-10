#include <iostream>

using namespace std;

// Custom function to copy a string
void copyString(const char* source, char* destination, int maxLength)
{
    for (int i = 0; i < maxLength && source[i] != '\0'; i++)
    {
        destination[i] = source[i];
        destination[i + 1] = '\0';
    }
}

// Custom function to compare two strings
bool compareString(const char* str1, const char* str2)
{
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    return true;
}

// Custom function to get string length
int getStringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

class ITransaction
{
public:
    virtual void setDate(const char* date) = 0;
    virtual void setType(const char* type) = 0;
    virtual void setCategory(const char* category) = 0;
    virtual void setAmount(float amount) = 0;
    virtual void displayTransaction() = 0;
};

class AbstractTransaction : public ITransaction
{
protected:
    char date[11];
    char type[11];
    char category[21];
    float amount;

public:
    virtual void setDate(const char* date) override
    {
        copyString(date, this->date, 10);
    }

    virtual void setType(const char* type) override
    {
        copyString(type, this->type, 10);
    }

    virtual void setCategory(const char* category) override
    {
        copyString(category, this->category, 20);
    }

    virtual void setAmount(float amount) override
    {
        this->amount = amount;
    }

    virtual void displayTransaction() override
    {
        cout << "Date: " << date << endl;
        cout << "Type: " << type << endl;
        cout << "Category: " << category << endl;
        cout << "Amount: " << amount << endl;
    }
};

class Expense : public AbstractTransaction
{
private:
    char expenseSpecificAttr[21];

public:
    void setExpenseDetails() {}
};

class Income : public AbstractTransaction
{
};

class Others : public AbstractTransaction
{
};

class FinanceTracker
{
private:

    AbstractTransaction** transactions;
    int capacity;
    int count;


public:
    FinanceTracker(int capacity)
    {
        this->capacity = capacity;
        this->count = 0;
        this->transactions = new AbstractTransaction * [capacity];
    }

    void resize(int newCapacity){
        AbstractTransaction** newTransaction = new AbstractTransaction * [newCapacity];

        for (int i = 0; i < capacity; i++){
            newTransaction[i] = transactions[i];
        }
        transactions = nullptr;
        transactions = newTransaction;
        capacity = newCapacity;
    }

    void inputTransaction(AbstractTransaction& transaction)
    {
        char date[11];
        char type[11];
        char category[21];
        float amount;

        cout << "Enter date (yyyy-mm-dd): ";
        cin >> date;
        transaction.setDate(date);

        cout << "Enter type: ";
        cin >> type;
        transaction.setType(type);

        cout << "Enter category: ";
        cin >> category;
        transaction.setCategory(category);

        cout << "Enter amount: ";
        cin >> amount;
        transaction.setAmount(amount);
    }

    void addTransaction(AbstractTransaction& transaction)
    {
        if (count < capacity)
        {
            transactions[count++] = &transaction;
        }
    }

    void displayTransactions()
    {
        for (int i = 0; i < count; i++)
        {
            transactions[i]->displayTransaction();
            cout << endl;
        }
    }

    int getCap(){
        return capacity;
    }

    ~FinanceTracker()
    {
        for (int i = 0; i < count; i++)
        {
            delete transactions[i];
        }
        delete[] transactions;
    }
};

int main()
{
    int capacity;
    cout << "Enter the capacity of the finance tracker: ";
    cin >> capacity;

    FinanceTracker tracker(capacity);

    char choice;
    int increment;
    do
    {
        cout << "Enter type of transaction (E for expense, I for income, O for others): ";
        cin >> choice;

        AbstractTransaction* transaction;
        if (choice == 'E')
        {
            transaction = new Expense();
        }
        else if (choice == 'I')
        {
            transaction = new Income();
        }
        else if (choice == 'O')
        {
            transaction = new Others();
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }
        if (increment > tracker.getCap()){
            tracker.resize(capacity * 2);
        }
        tracker.inputTransaction(*transaction);
        tracker.addTransaction(*transaction);
        increment++;
        

        cout << "Do you want to add another transaction? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y');

    cout << "Displaying all transactions:" << endl;
    tracker.displayTransactions();

    return 0;
}
