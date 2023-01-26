
struct contact
{
    string name;
    string phoneNumber;
    string email;
};


class phonebook {
private:
    int numberOfContacts;
    int size;
    contact* myContacts;
public:
    phonebook(int size1);
    phonebook(phonebook& other);
    phonebook operator==(const phonebook& other);
    ~phonebook();
    int getNumberOfContacts();
    int getSize();
    contact getContact(int i);
    bool addContact(string name, string phonenumber, string email)
};
phonebook::phonebook(int size1) {
    size = size1;
    numberOfContacts = 0;
    contact* myContacts = new contact[size];
}
phonebook::phonebook(phonebook& other) {
    numberOfContacts = other.numberOfContacts;
    size = other.size;
    contact* myContacts = new contact[size];
    for (int i = 0; i < numberOfContacts; i++) {
        myContacts[i]= other.myContacts[i];
    }
}
phonebook phonebook::operator=(const phonebook& other) {
    size = other.size;
    numberOfContacts = other.numberOfContacts;
    for (int i = 0; i < numberOfContacts; i++) {
        myContacts[i] = other.myContacts[i];
    }
    return *this;
}
phonebook::~phonebook()
{
    delete[] myContacts;
}
int phonebook::getnumberOfContacts() {
    return numberOfContacts;
}
int phonebook::getSize() {
    return size;
}
contact phonebook::getContact(int i) {
    return myContacts[i];
}
bool phonebook::addContact(string name, string phonenumber, string email) {
    if (size == numberOfContacts) {
        return false;
    }
    else {
        numberOfContacts++;
        contact newcontact;
        newcontact.name = name;
        newcontact.phoneNumber = phonenumber;
        newcontact.email = email;
        myContacts[numberOfContacts] = newcontact;
        return true;
    }
}