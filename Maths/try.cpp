#include <iostream>
#include <iomanip>

using namespace std;


int main()
{

    char name[20];
    char RegNo[20];
    int Mark[5];
    char Grade[5];
    int sum =0;
   
   
    cout<<"Enter the name of student : "; cin.getline(name,20);
    cout<<"Enter the Regiser Number of the student : ";cin.getline(RegNo,20);
    int i=1;
    while(i<=5)
    {
        cout<<"Enter the "<<i<<"th mark of "<<name<<"  :";
        cin>>Mark[i-1];
        sum += Mark[i-1];
        switch(Mark[i-1]/10){
            
        
        case 9:
            Grade[i-1] = 'S';
            break;
        case 10:
            Grade[i-1] = 'S';
            break;
        case 8:
            Grade[i-1] = 'A';
            break;
        case 7:
            Grade[i-1] = 'B';
            break;
        case 6:
            Grade[i-1] = 'C';
            break;
        case 5:
            Grade[i-1] = 'D';
            break;
        default:
            Grade[i-1] = 'F';
            break;
        }
        i++;
       
    }
   
    //display the information

    cout<<"Name of the Student : "<<name<<"\t\t\t"<<"Register Number : "<<RegNo<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
   
    for(int i=0;i<5;i++)
    {
        cout<<"The Mark "<<i+1<<"  :"<<setw(3)<<Mark[i]<<"\t\t\t";
        cout<<"Grade  : "<<Grade[i]<<endl;
    }

    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"The Total Mark is :"<<sum;

    return 0;
   
}