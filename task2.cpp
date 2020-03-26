// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <set>
#include <fstream>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(string);
		string getname();


		Person(); 				// default constructor
		Person(string);
		Person(const Person &); 		// copy constructor


		virtual ~Person();

};

void Person::setname(string n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(string n)
{
	setname(n);
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(string, double);

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << ", " << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(string n, double g): Person(n)
{
	setgrade(g);
}


Student::~Student()
{
}

int main(){

    //task 2
    ifstream fin;
    fin.open("names.txt");
    set <string> students;
    set <string> :: iterator i;

    string name;
    int grade;
    while(!fin.eof()){
        fin >> name;
        fin >> grade;
        if(grade < 50){
            students.insert(name);
        }
    }

    for(i = students.begin(); i != students.end(); i++){
        cout << (*i) << endl;
    }


}

