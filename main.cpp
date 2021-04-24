#include<cstdlib>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

class report
{
private :   int admno;
            char name[30];
            char fname[30];
            int sem;
            char section;
            int OOP;
            int DMS;
            int	math;
            int	CO;
            int	DADC;
            int	total;
            float per;
            char grade[3];
public	:
	void main_menu();
	void search_menu();
	void report_menu();
    void read_data();
    void calculate();
	void disp_data();
	void add_record();
	void del_record();
	void modify_record();
	void search_name();
	void search_admno();
	void search_class();
    void single_report_card();
    void report_single();
    void report_class();
};
void  report ::main_menu()
{
    int choice;
     do
       {
           system("cls");
         cout<<"\n\n\n\t\t\t\t\t NITTE MEENAKSHI INSTITUTE OF TECHNOLOGY \n\n";
         cout<<"\n\n\tSelect one of the options below to continue\n";
         cout<<"\n\n\t\t1. Add New Student to the Database ";
         cout<<"\n\n\t\t2. Delete  Student from the Database";
         cout<<"\n\n\t\t3. Modify student details or marks";
         cout<<"\n\n\t\t4. Search Menu";
         cout<<"\n\n\t\t5. Report Menu ";
         cout<<"\n\n\t\t6. Exit ";
         cin>>choice;
         switch(choice)
         {
            case 1:    add_record();
                       break;
            case 2:    del_record();
                       break;
            case 3:    modify_record();
                       break;
            case 4:    search_menu();
                       break;
            case 5:    report_menu();
                       break;
            case 6:    break;
            default :   cout<<"\n Wrong Choice.... Try again";
         }
      }while(choice!=6);
return;
}

void  report ::report_menu()
{
 int choice;
     do
       {
         cout<<"\n\n\n\t\t R e p o r t   M e n u\n\n";
         cout<<"\n\n\t\t   Enter your choice: ";
         cout<<"\n\n\t\t1. Single Student";
         cout<<"\n\n\t\t2. Single class";
         cout<<"\n\n\t\t3. Exit ";
         cin>>choice;
         switch(choice)
         {
            case 1:
                       report_single();
                       break;
            case 2:
                       report_class();
                       break;
            case 3:    break;
            default :
                       cout<<"\n Wrong Choice.... Try again";
         }
      }while(choice!=3);
return;
}

void  report ::search_menu()
{
 int choice;
     do
       {
         cout<<"\n\n\n\t\t S e a r c h   M e n u \n\n";
         cout<<"\n\n\t\t1. Admission number of Student";
         cout<<"\n\n\t\t2. Student Name";
         cout<<"\n\n\t\t3. Class wise";
         cout<<"\n\n\t\t4. Exit ";
         cout<<"\n\n\n\n\t\t   Enter your choice (1..4) : ";
         cin>>choice;
         switch(choice)
         {

            case 1:
                       search_admno( );
                       getch();
                       break;

            case 2:
                       search_name();
                       getch();
                       break;

            case 3:
                       search_class();
                       getch();
                       break;

            case 4:    break;

            default :
                       cout<<"\n Wrong Choice.... Try again";
         }
      }while(choice!=4);

return;
}

void report:: read_data( )
 {
    system("cls");
   cout<<"\n Enter Adm No :";
   cin>>admno;
   cout<<"\n Enter Name : ";
   cin>>name;
   cout<<"\n Enter Father Name : ";
   cin>>fname;
   cout<<"\n Enter sem : ";
   cin>>sem;
   cout<<"\n Enter Section :";
   cin>>section;
   cout<<"\n Enter marks obtained in OOP : ";
   cin>>OOP;
   cout<<"\n Enter marks obtained in DMS : ";
   cin>>DMS;
   cout<<"\n Enter marks obtained in math : ";
   cin>>math;
   cout<<"\n Enter marks obtained in CO : ";
   cin>>CO;
   cout<<"\n enter marks obtained in DADC : ";
   cin>>DADC;
    return;
 }

void report::calculate()
{
  total = OOP+DMS+math+CO+DADC;
  per = total/5.0;

  if(per>=95)
             strcpy(grade,"A+");

 if(per<95 &&  per>=90)
             strcpy(grade,"A");

 if(per<90 &&  per>=80)
             strcpy(grade,"B+");

 if(per<80 &&  per>=70)
             strcpy(grade,"B");

 if(per<70 &&  per>=60)
             strcpy(grade,"C+");
 if(per<60)
             strcpy(grade,"C");
  return;
}

void  report::disp_data()
{
 cout<<"\n Admno               : "<<admno;
 cout<<"\n Student Name        : "<<name;
 cout<<"\n Father Name         : "<<fname;
 cout<<"\n Class & Sem         : "<<sem<<"-"<<section;
 cout<<"\n OOP                 : "<<OOP;
 cout<<"\n DMS                 : "<<DMS;
 cout<<"\n Math                : "<<math;
 cout<<"\n CO                  : "<<CO;
 cout<<"\n DADC                : "<<DADC;
 cout<<"\n Total Marks         : "<<total;
 cout<<"\n Percentage          : "<<per;
 cout<<"\n Grade               : "<<grade;
 return ;
}

void  report::add_record()
{
   ofstream fout;
   fout.open("report.dat",ios::app);
   read_data();
   calculate();
   fout.write((char*)this, sizeof(report));
   fout.close();
}

void report::search_name()
{
    ifstream fin;
    fin.open("report.dat");
    char tname[30];
    int flag=0;
    cout<<"\n Enter Name to search :";
    cin>>tname;
    while(fin.read((char*)this,sizeof(report)))
    {
        if(strcmpi(tname,name)==0)
           {
              cout<<"\n Student Information ";
              cout<<"\n--------------------------------------------------------"<<endl;
              disp_data();
              flag=1;
            }
    }
    fin.close();
    if(flag==0)
    cout<<"\n No such name : "<<strupr(tname)<<" exist in our record... Try again";
    return;
}

void report::search_class()
{
    ifstream fin;
    fin.open("report.dat");
    char tsect;
    int tsem;
    int flag;
    cout<<"\n Enter student Sem to search :";
    cin>>tsem;
    cout<<"\n Enter student section to search :";
    cin>>tsect;
    cout<<"\n Class :"<<tsem<<" - "<<tsect<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"Admno\tName\tFname\t OOP \t DMS\t Math \t CO \t DADC \t Total \t per\n";
    cout<<"-------------------------------------------------------------------------------"<<endl;
    while(fin.read((char*)this,sizeof(report)))
    {
        if(tsect==section && tsem == sem)
           {
                cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<OOP<<"\t"<<DMS<<"\t"<<math<<"\t"<<CO<<"\t"<<DADC<<"\t"<<total<<"\t"<<per<<endl;
                flag=1;
            }
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    fin.close();
    if(flag==0)
      cout<<"\n\n information Not available for sem :"<<tsem <<" - "<<tsect;
    return;
}

void report :: search_admno( )
{
    ifstream fin;
    fin.open("report.dat");
    int tadmno;
    int flag=0;
    cout<<"\n Enter Admission Number to search : ";
    cin>>tadmno;
    while(fin.read((char*)this,sizeof(report)))
    {
        if(tadmno == admno)
         {
              cout<<"\n Student Information ";
              cout<<"\n--------------------------------------------------------"<<endl;
              disp_data();
              flag = 1;
          }
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n Admission No : "<<tadmno <<" does not exist.... Try again";
    return;
}

void report::single_report_card()
{
    system("cls");
    cout<<"\n\t\t Nitte Meenakshi Institute Of Technology , Bengaluru";
    cout<<"\n\t\t Session : 2018-19";
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\n Admno :"<<admno;
    cout<<"\n\n Name  :"<<name <<"\t\t Father Name :"<<fname<<"\t\t Sem:"<<sem<<"-"<<section;
    cout<<"\n\n-------------------------------------------------------------------------------";
    cout<<"\n Subject\tMax Mark\tMin Mark\t Marks Obtained";
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\n OOP\t\t100\t\t33\t\t\t"<<OOP;
    cout<<"\n\n DMS\t\t100\t\t33\t\t\t"<<DMS;
    cout<<"\n\n Math\t\t100\t\t33\t\t\t"<<math;
    cout<<"\n\n CO\t\t100\t\t33\t\t\t"<<CO;
    cout<<"\n\n DADC\t\t100\t\t33\t\t\t"<<DADC;
    cout<<"\n\n-------------------------------------------------------------------------------";
    cout<<"\n Total Marks :\t\t"<<total<<"\t\tPercentage : "<<per<<"\tGrade :"<<grade;
    cout<<"\n---------------------------------------------------------------------------------";
    return;
}

void report:: report_single()
{
    system("cls");
    int tadmno;
    int flag =0;
    ifstream fin;
    fin.open("report.dat",ios::binary);
    cout<<"\n Enter admission No : ";
    cin>>tadmno;
    while(fin.read((char*)this, sizeof(report)))
    {
       if(tadmno ==admno)
            single_report_card();
       else
            flag =1;
    }
    fin.close();
    if(flag==0)
        cout<<"\n\n Admission No :"<<tadmno <<" does not exist.... Try again";
    getch();
    return;
}

void report:: report_class()
{
    system("cls");
    int tsem;
    char tsect;
    int row =6;
    int no =0;
    ifstream  fin;
    fin.open("report.dat");
    cout<<"\n Enter semester :";
    cin>>tsem;
    cout<<"\n Enter section :";
    cin>>tsect;
    cout<<"\n\t\t Nitte Meenakshi Institute Of Technology , Bengaluru.";
    cout<<"\n\t\t Class :"<<tsem<<"-"<<tsect<<"\t\t Session : 208-19"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"Admno\tName\tFname\t OOP \t DMS\t Math \t CO \t DADC \t Total \t per\n";
    cout<<"-------------------------------------------------------------------------------"<<endl;
    while(fin.read((char*)this, sizeof(report)))
    {
      if(tsem==sem && tsect== section )
       {
         row= row+1;
         no++;
         if(row>=30)
          {
                cout<<"\n\n  Press any key to continue ................";
                getch();
                cout<<"\n\t\t Nitte Meenakshi Institute Of Technology, Bengaluru";
                cout<<"\n\t\t Class :"<<tsem<<"-"<<tsect<<"\t\t Session : 2018-19"<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<<"Admno\tName\tFname\t OOP \t DMS\t Math \t CO \t DADC \t Total \t per\n";
                cout<<"-------------------------------------------------------------------------------"<<endl;
                row =6;
           }
            cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<OOP<<"\t"<<DMS<<"\t"<<math<<"\t"<<CO<<"\t"<<DADC<<"\t"<<total<<"\t"<<per<<endl;
         }
    }
    fin.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"\n Total Student : "<<no<<" Report prepared By  :"<<" NMIT ";
    getch();
    return;
}

void  report::del_record ()
{
    ifstream fin;
    ofstream fout;
    int tadmno;
    int flag =0;
    system("cls");
    cout<<"\n Enter admno to delete :";
    cin>>tadmno;
    fin.open("report.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(report)))
    {
        if(tadmno!=admno)
            fout.write((char*)this,sizeof(report));
        else
            flag=1;
  }
    fin.close();
    fout.close();
    remove("report.dat");
    rename("temp.dat","report.dat");
    if(flag==1)
        cout<<"\n\n Record Sucessfully removed ";
    else
        cout<<"\n Admission No :"<<tadmno <<" does not exist...Try again";
    getch();
    return;
}

void report:: modify_record( )
{
    ifstream fin;
    ofstream fout;
    int tadmno;
    int flag =0;
    system("cls");
    cout<<"\n Enter Admno to Modify :";
    cin>>tadmno;
    fin.open("report.dat",ios::binary);
    fout.open("temp.dat");
    while(fin.read((char*)this, sizeof(report)))
    {
        if(tadmno == admno)
        {
            read_data();
            calculate();
            flag=1;
        }
    fout.write((char*)this,sizeof(report));
  }
    fin.close();
    fout.close();
    remove("report.dat");
    rename("temp.dat","report.dat");
    if(flag==1)
        cout<<"\n\n Record Sucessfully modified ";
    else
        cout<<"\n Admission No :"<<tadmno<<" does not exist...Try again";
    getch();
    return;
}

int main()
{
    report r;
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNITTE MEENAKSHI INSTITUTE OF TECHNOLOGY\n";
    cout<<"\n\n\t\t\t\t\t\tPress enter to continue\n";
    getch();
    system("cls");
    r.main_menu();
    return 0;
}

