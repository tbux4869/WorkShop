#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
using namespace std;

class Gym_record
{
private:
    char account_number[20];
    char firstName[10];
    char familyName[10];
    char date[10];
    float calories;
public:
    void read_data();
    void show_data();
    void read_rec();
    void write_rec();
    void search_rec();
    void delete_rec();
    void edit_rec();
};

void Gym_record::read_data()
{
    cout<<"Enter Account Number:"<<endl;
    cin>>account_number;
    cout<<"Enter First Name:"<<endl;
    cin>>firstName;
    cout<<"Enter Family Name:"<<endl;
    cin>>familyName;
    cout<<"Enter Date:"<<endl;
    cin>>date;
    cout<<"Enter Calories:"<<endl;
    cin>>calories;
}

void Gym_record::show_data()
{
    cout<<"Account Number:"<<account_number<<endl;
    cout<<"First Name:"<<firstName<<endl;
    cout<<"Family Name:"<<familyName<<endl;
    cout<<"Date:"<<date<<endl;
    cout<<"Calories:"<<calories<<endl;  
    cout<<"------------------------------------------"<<endl;
}

void Gym_record::write_rec()
{
    ofstream outfile;
    outfile.open("record.gym", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();  
}

void Gym_record::read_rec()
{
    ifstream infile;
    infile.open("record.gym", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Data from file****"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}

void Gym_record::search_rec()
{
    int n;
    ifstream infile;
    infile.open("record.gym", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}

void Gym_record::edit_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.gym", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void Gym_record::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("record.gym", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.gym", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.gym");
    rename("tmpfile.gym", "record.gym");
}
int main()
{
    Gym_record A;
    int choice;
    cout<<"***Gym Record System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_rec();
            break;
        case 4:
            A.edit_rec();
            break;
        case 5:
            A.delete_rec();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";
            exit(0);
        }
    }
    system("pause");
    return 0;
}


















