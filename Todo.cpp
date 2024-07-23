
#include <iostream>
#include <fstream>

using namespace std;
class Todo{
    public:
        void add();
        void remove();
        void display();
};

void Todo:: add()
{
    ofstream out("sample.txt", ios::app);
    string tasks;
    cout<<"Enter Tasks: ";
    cin.ignore(); // Ignore the newline left in the buffer from previous input
    getline(cin,tasks);
    out<<tasks<<endl;
    out.close();
    
}
void Todo:: display()
{
    string line;
    ifstream in("sample.txt");
    while(getline(in,line)){
        cout<<line<<endl;
    }
    in.close();
}

void Todo:: remove()
{
    ofstream out("sample.txt", ios::trunc); // Open in truncate mode to clear the file
    cout << "All tasks removed" << endl;
    out.close(); // Close the file
}

void UserInterface()
{  

    int i = -1;
    while (i !=0)
    {
        Todo a;

        cout<<"Enter 1 for Writing Tasks"<<endl;
        cout<<"Enter 2 for Displaying  Tasks"<<endl;
        cout<<"Enter 3 for Removing Tasks"<<endl;
        cout<<"Enter 0 for Exit "<<endl;

        cin>>i;


        switch(i)
        {
            case 1:
                a.add();
                break;
            case 2:
                a.display();
                break;
            case 3:
                a.remove();
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;

        }
    }
        

}
int main()
{   
    UserInterface();

    return 0;
}