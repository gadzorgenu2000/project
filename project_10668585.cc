#include <iostream>
#include <cstring>
using namespace std;


class Student_MIS {
	private: 
	string courses[50][3]; //col1->id, col2 -> name, col3->deleted
	string students[50][3]; //col1->id, col2 -> name, col3->deleted
	string staff[50][3]; //col1->id, col2 -> name, col3->deleted
	string courses_student_takes[50][4]; //col1-> stud_id, col2->course_code; col3->grade, col4-deleted
	string courses_staff_takes[50][4]; //col1-> stud_id, col2->course_code; col3->grade, col4-deleted
	
	int course_count;
	int student_count;
	int courses_student_takes_count;
	int courses_staff_takes_count;
	int staff_count;
	
	public:
	Student_MIS() {
		this->student_count = 0;
		this->course_count = 0;
		this->courses_student_takes_count = 0;
		this->courses_staff_takes_count = 0;
		this->staff_count = 0;
	
	}
	
	void add_course(string code, string name) {
		this->courses[course_count][0] = code;
		this->courses[course_count][1] = name;
		this->courses[course_count][2] = '0'; //0 means not deleted
		
		this->course_count++;
	}
	
	void add_student(string id, string name) {
		this->students[student_count][0] = id;
		this->students[student_count][1] = name;
		this->students[student_count][2] = '0'; //0 means not deleted
		
		this->student_count++;
	}
	
	void add_staff(string id, string name) {
		this->staff[staff_count][0] = id;
		this->staff[staff_count][1] = name;
		this->staff[staff_count][2] = '0'; //0 means not deleted
		
		this->staff_count++;
	}
	
	void assign_staff_to_course(string staff_id, string course_id) {
		//check to make sure that staff is not already assigned to course, if assignment is present then update the details
		bool is_assigned = false;
		int len = this->courses_staff_takes_count;
		for(int i=0; i<len; i++) {
			if( (this->courses_staff_takes[i][0] == staff_id) && (this->courses_staff_takes[i][1] == course_id) ) {
				is_assigned = true;
				break;
			}
		}
		
		if(!is_assigned) {
			this->courses_staff_takes[len][0] = staff_id;
			this->courses_staff_takes[len][1] = course_id;
			this->courses_staff_takes[len][2] = '0';
			this->courses_staff_takes_count++;
		}
	}
	
	void assign_student_to_course(string student_id, string course_id) {
		//check to make sure that student is not already assigned to course, if assignment is present then update the details
		bool is_assigned = false;
		int len = this->courses_student_takes_count;
		for(int i=0; i<len; i++) {
			if( (this->courses_student_takes[i][0] == student_id) && (this->courses_student_takes[i][1] == course_id) ) {
				is_assigned = true;
				break;
			}
		}
		
		if(!is_assigned) {
			this->courses_student_takes[len][0] = student_id;
			this->courses_student_takes[len][1] = course_id;
			this->courses_student_takes[len][2] = '0';
			this->courses_student_takes_count++;
		}
	}
	
	void enter_student_grade(string student_id, string course_code, string grade) {
		int len = this->courses_student_takes_count;
		for(int i=0; i<len; i++) {
			if( (this->courses_student_takes[i][0] == student_id) && (this->courses_student_takes[i][1] == course_code) ) {
				this->courses_student_takes[i][2] = grade;
				break;
			}
		}
	}
	
	void print_academic_record(string student_id) {
		int len = this->courses_student_takes_count;
		string student_name = get_student_name(student_id);
		cout << "Student Name: " << student_name << endl;
		for(int i=0; i<len; i++) {
			cout << "COURSE CODE \t GRADE \n";
			if( (this->courses_student_takes[i][0] == student_id) ) {
				cout << courses_student_takes[i][1] << "\t" << courses_student_takes[i][2] << "\n";
			}
		}
	}
	
	//Record modifications
	void edit_course(string course_code, string new_name) {
		int len = this->course_count;
		bool is_updated = false;
		
		for (int i=0; i<len; i++) {
			if(this->courses[i][0] == course_code) {
				this->courses[i][1] = new_name;
				is_updated = true;
				break;
			}
		}
		if(is_updated) {
			cout << "\n Update Successful!\n";
		} else {
			cout << "\n No Update Made!!\n";
		}
			
	}
	void delete_course(string course_code) {
		int len = this->course_count;
		bool is_deleted = false;
		
		for (int i=0; i<len; i++) {
			if(this->courses[i][0] == course_code) {
				this->courses[i][2] = '1';
				is_deleted = true;
				break;
			}
		}
		if(is_deleted) {
			cout << "\n Deletion Successful!\n";
		} else {
			cout << "\n No Deletion Made!!\n";
		}
			
	}
	void edit_staff(string staff_id, string new_name) {
		int len = this->staff_count;
		bool is_updated = false;
		for (int i=0; i<len; i++) {
			if(this->staff[i][0] == staff_id) {
				this->staff[i][1] = new_name;
				is_updated = true;
				break;
			}
		}
		if(is_updated) {
			cout << "\n Update Successful!\n";
		} else {
			cout << "\n No Update Made!!\n";
		}
	}
	void delete_staff(string staff_id) {
		int len = this->staff_count;
		bool is_deleted = false;
		for (int i=0; i<len; i++) {
			if(this->staff[i][0] == staff_id) {
				this->staff[i][2] = '1';
				is_deleted = true;
				break;
			}
		}
		if(is_deleted) {
			cout << "\n Deletion Successful!\n";
		} else {
			cout << "\n No Deletion Made!!\n";
		}
	}
	void edit_student(string student_id, string new_name) {
		int len = this->student_count;
		bool is_updated = false;
		for (int i=0; i<len; i++) {
			if(this->students[i][0] == student_id) {
				this->students[i][1] = new_name;
				is_updated = true;
				break;
			}
		}
		
		if(is_updated) {
			cout << "\n Update Successful!\n";
		} else {
			cout << "\n No Update Made!!\n";
		}
	}
	void delete_student(string student_id) {
		int len = this->student_count;
		bool is_deleted = false;
		for (int i=0; i<len; i++) {
			if(this->students[i][0] == student_id) {
				this->students[i][2] = '1';
				is_deleted = true;
				break;
			}
		}
		
		if(is_deleted) {
			cout << "\n Deletion Successful!\n";
		} else {
			cout << "\n No Deletion Made!!\n";
		}
	}
	
	void display_all_courses() {
		int len = this->course_count;
		cout << "List of all courses \n";
		cout << "#  " << "  CODE \t NAME \n" ;
		
		int i =0, num=1;
		while (i<len) {
			if(courses[i][2] == "0") {
				cout << (num) << ".  " << courses[i][0] << "\t" << courses[i][1] <<endl;
				num++;
			}
			i++;
		}
		
	}
	void display_all_students() {
		int len = this->student_count;	
		cout << "List of all students \n";
		cout << "#  " << "  ID \t NAME \n" ;
		
		int i =0, num=1;
		while (i<len) {
			if(students[i][2] == "0") {
				cout << (num) << ".  " << students[i][0] << "\t" << students[i][1] <<endl;
				num++;
			}
			i++;
		}
	}
	void display_all_staff() {
		int len = this->staff_count;	
		cout << "List of all staff \n";
		cout << "#  " << "  ID \t NAME \n" ;
		
		int i =0, num=1;
		while (i<len) {
			if(staff[i][2] == "0") {
				cout << (num) << ".  " << staff[i][0] << "\t" << staff[i][1] <<endl;
				num++;
			}
			i++;
		}
	}
	void display_all_student_courses() {
		int len = this->courses_student_takes_count;
		cout << "#  " << "   \t NAME \t COURSE \n" ;
		
		for(int i=0; i<len; i++) {
			string id  = this->courses_student_takes[i][0];
			string code  = this->courses_student_takes[i][1];
			string course_name = get_course_name(code);
			string student_name = get_student_name(id);
			
			cout << (i+1) << ". \t" << student_name << "\t" << course_name << endl;
			
		}
	}
	
	void view_score_sheet() {
		int len = this->courses_student_takes_count;
		cout << "#  " << "   \t STD. ID \t NAME \t CS. CODE\t NAME\t GRADE \n" ;
		
		for(int i=0; i<len; i++) {
			string id  = this->courses_student_takes[i][0];
			string code  = this->courses_student_takes[i][1];
			string course_name = get_course_name(code);
			string student_name = get_student_name(id);
			string grade = this->courses_student_takes[i][2];
			
			cout << (i+1) << ". \t" << id << "\t\t" << student_name << "\t" << code << "\t\t" << course_name << "\t" << grade << endl;
			
		}
	}
	
	string get_course_name(string code) {
		int len = this->course_count;
		string name="";
		for (int i=0; i<len; i++) {
			if(this->courses[i][0] == code) {
				name = this->courses[i][1];
				break;
			}
		}
		return name;
	}
	
	string get_student_name(string id) {
		int len = this->student_count;
		string name="";
		for (int i=0; i<len; i++) {
			if(this->students[i][0] == id) {
				name = this->students[i][1];
				break;
			}
		}
		return name;
	}
	
};

int main()
{
	Student_MIS obj;
	char main_menu, option, option_courses,option_students,option_staff,option_assign_courses,option_enter_grade,option_print_record;
	
	do {
		system("CLS");
		cout << "STUDENT MANAGEMENT INFORMATION SYSTEM \n\n";
		cout << "Please enter one of the following options \n\n";
		cout << "1. Press 1 to Manage Courses \n";
		cout << "2. Press 2 to Manage Students \n";
		cout << "3. Press 3 to Manage Staff \n";
		cout << "4. Press 4 to Assign Students To Courses \n";
		cout << "5. Press 5 to Record Student Grade \n";
		cout << "6. Press 6 to Print Academic Record \n";
		cin  >> option;
		
		//CODE FOR MANAGE COURSES
		while (option == '1') {
			system("CLS");
			cout << "MANAGE COURSES PORTAL \n\n";
			cout << "Please enter one of the following options \n\n";
			cout << "1. Press 1 to Add Course \n";
			cout << "2. Press 2 to Edit Course \n";
			cout << "3. Press 3 to Delete Course \n";
			cout << "4. Press 'p' to Go Back To Previous Menu \n";
			cin  >> option_courses;
			
			if(option_courses == 'p') {
				option = 'm';
			} else if(option_courses == '1') {
				//Add course option
				while (option_courses == '1') {
					string course_code, course_name;
					system("CLS");
					//display all courses
					obj.display_all_courses();
					cout << "\n ADD A COURSE \n";
					cout << "Enter course code \n";
					cin  >> course_code;
					
					cout << "Enter course name \n";
					cin  >> course_name;
					cout << "\n";
					
					//call function to add course
					obj.add_course(course_code, course_name);
					system("CLS");
					obj.display_all_courses();
					
					cout << "\n\nDo you want to add another course? Y/N \n";
					cin  >> option_courses;
					option_courses = tolower(option_courses);
					if(option_courses == 'n') {
						option = '1';
						break;
					} else {
						option_courses = '1';
					}
				}
		    } else if(option_courses == '2') {
		    	while(option_courses == '2') {
		    		//Edit course
		    		string course_code, course_name;
					system("CLS");
					//display all courses
					obj.display_all_courses();
					
					cout << "Enter course code" << endl;
					cin  >> course_code;
					
					cout << "Enter new Course Name" << endl;
					cin >> course_name;
					
					//call edit course function
					obj.edit_course(course_code, course_name);
					
					system("CLS");
					obj.display_all_courses();
					
					cout << "\n\nDo you want to Edit another course? Y/N \n";
					cin  >> option_courses;
					option_courses = tolower(option_courses);
					if(option_courses == 'n') {
						option = '1';
						break;
					} else {
						option_courses = '1';
					}
				}
			} else if(option_courses == '3') {
		    	while(option_courses == '3') {
		    		//Delete course
		    		string course_code;
					system("CLS");
					//display all courses
					obj.display_all_courses();
					
					cout << "Enter course code To Delete" << endl;
					cin  >> course_code;
					
					//call edit course function
					obj.delete_course(course_code);
					
					system("CLS");
					obj.display_all_courses();
					
					cout << "\n\nDo you want to Delete another course? Y/N \n";
					cin  >> option_courses;
					option_courses = tolower(option_courses);
					if(option_courses == 'n') {
						option = '1';
						break;
					} else {
						option_courses = '1';
					}
				}
			}
		    
		
		}
		//END OF CODE FOR MANAGE COURSES
		
		
		//CODE FOR MANAGE STUDENTS
		while (option == '2') {
			system("CLS");
			cout << "MANAGE STUDENTS PORTAL \n\n";
			cout << "Please enter one of the following options \n\n";
			cout << "1. Press 1 to Add student \n";
			cout << "2. Press 2 to Edit student \n";
			cout << "3. Press 3 to Delete student \n";
			cout << "4. Press 'p' to Go Back To Previous Menu \n";
			cin  >> option_students;
			
			if(option_students == 'p') {
				option = 'm';
			} else if(option_students == '1') {
				//Add student option
				while (option_students == '1') {
					string id, name;
					system("CLS");
					//display all students
					obj.display_all_students();
					cout << "\n ADD A STUDENT \n";
					cout << "Enter student id \n";
					cin  >> id;
					
					cout << "Enter student name \n";
					cin  >> name;
					cout << "\n";
					
					//call function to add student
					obj.add_student(id, name);
					system("CLS");
					obj.display_all_students();
					
					cout << "\n\nDo you want to add another student? Y/N \n";
					cin  >> option_students;
					option_courses = tolower(option_students);
					if(option_students == 'n') {
						option = '2';
						break;
					} else {
						option_students = '1';
					}
				}
		    } else if(option_students == '2') {
		    	while(option_students == '2') {
		    		//Edit student
		    		string id, name;
					system("CLS");
					//display all students
					obj.display_all_students();
					
					cout << "Enter Student ID" << endl;
					cin  >> id;
					
					cout << "Enter new Student Name" << endl;
					cin >> name;
					
					//call edit course function
					obj.edit_student(id, name);
					
					system("CLS");
					obj.display_all_students();
					
					cout << "\n\nDo you want to Edit another student? Y/N \n";
					cin  >> option_students;
					option_students = tolower(option_students);
					if(option_students == 'n') {
						option = '2';
						break;
					} else {
						option_students = '2';
					}
				}
			} else if(option_students == '3') {
		    	while(option_students == '3') {
		    		//Delete student
		    		string id;
					system("CLS");
					//display all students
					obj.display_all_students();
					
					cout << "Enter student ID To Delete" << endl;
					cin  >> id;
					
					//call edit course function
					obj.delete_student(id);
					
					system("CLS");
					obj.display_all_students();
					
					cout << "\n\nDo you want to Delete another student? Y/N \n";
					cin  >> option_students;
					option_students = tolower(option_students);
					if(option_students == 'n') {
						option = '2';
						break;
					} else {
						option_students = '3';
					}
				}
			}
		    
		
		}
		//END OF CODE FOR MANAGE STUDENTS
		
		
		//CODE FOR MANAGE STAFF
		while (option == '3') {
			system("CLS");
			cout << "MANAGE STAFF PORTAL \n\n";
			cout << "Please enter one of the following options \n\n";
			cout << "1. Press 1 to Add staff \n";
			cout << "2. Press 2 to Edit staff \n";
			cout << "3. Press 3 to Delete staff \n";
			cout << "4. Press 'p' to Go Back To Previous Menu \n";
			cin  >> option_staff;
			
			if(option_staff == 'p') {
				option = 'm';
			} else if(option_staff == '1') {
				//Add staff option
				while (option_staff == '1') {
					string id, name;
					system("CLS");
					//display all staff
					obj.display_all_staff();
					cout << "\n ADD A STAFF \n";
					cout << "Enter STAFF ID \n";
					cin  >> id;
					
					cout << "Enter STAFF name \n";
					cin  >> name;
					cout << "\n";
					
					//call function to add staff
					obj.add_staff(id, name);
					system("CLS");
					obj.display_all_staff();
					
					cout << "\n\nDo you want to add another staff? Y/N \n";
					cin  >> option_staff;
					option_staff = tolower(option_staff);
					if(option_staff == 'n') {
						option = '3';
						break;
					} else {
						option_staff = '1';
					}
				}
		    } else if(option_staff == '2') {
		    	while(option_staff == '2') {
		    		//Edit staff
		    		string id, name;
					system("CLS");
					//display all staff
					obj.display_all_staff();
					
					cout << "Enter Staff ID" << endl;
					cin  >> id;
					
					cout << "Enter new Staff Name" << endl;
					cin >> name;
					
					//call edit staff function
					obj.edit_staff(id, name);
					
					system("CLS");
					obj.display_all_staff();
					
					cout << "\n\nDo you want to Edit another staff? Y/N \n";
					cin  >> option_staff;
					option_staff = tolower(option_staff);
					if(option_staff == 'n') {
						option = '3';
						break;
					} else {
						option_staff = '2';
					}
				}
			} else if(option_staff == '3') {
		    	while(option_staff == '3') {
		    		//Delete student
		    		string id;
					system("CLS");
					//display all staff
					obj.display_all_staff();
					
					cout << "Enter staff ID To Delete" << endl;
					cin  >> id;
					
					//call edit course function
					obj.delete_staff(id);
					
					system("CLS");
					obj.display_all_staff();
					
					cout << "\n\nDo you want to Delete another staff? Y/N \n";
					cin  >> option_staff;
					option_staff = tolower(option_staff);
					if(option_staff == 'n') {
						option = '3';
						break;
					} else {
						option_staff = '3';
					}
				}
			}
		    
		
		}
		//END OF CODE FOR MANAGE STAFF
	
		
			
		//CODE TO ASSIGN STUDENTS TO COURSES
		while(option == '4') {
			string id, code;
			
			system("CLS");
			cout << "ASSIGN STUDENTS TO COURSES PORTAL \n";
			
			//Display all students
			obj.display_all_students();
			
			cout <<"\n\n";
			//Display all courses
			obj.display_all_courses();
			
			cout << "\n\n\n";
			
			//display list of all students that have been assigned courses
			cout << "list of all students that have been assigned courses\n";
			obj.display_all_student_courses();
			
			cout << "\n\n";
			cout << "Enter Student ID\n";
			cin  >> id;
			
			cout << "Enter course code\n";
			cin  >> code;
			
			obj.assign_student_to_course(id,code);
			system("CLS");
			
			//Display all students
			obj.display_all_students();
			
			//Display all courses
			obj.display_all_courses();
			
			//display list of all students that have been assigned courses
			cout << "\n\n\n Students And Their Assigned Courses \n";
			obj.display_all_student_courses();
			
			cout << "Do you want to do any more assignments? (Y/N)\n";
			cin  >> option_assign_courses;
			option_assign_courses = tolower(option_assign_courses);
			if(option_assign_courses == 'n') {
				option = 'm';
				break;
			} else {
				option = '4';
			}
			
		}
		//END OF CODE TO ASSIGN STUDENTS TO COURSES
		
		
		//CODE TO ENTER STUDENT GRADE
		while(option == '5') {
			string id, code, grade;
			
			system("CLS");
			cout << "STUDENT'S SCORE SHEET' \n";
			
			//Display scoresheet
			obj.view_score_sheet();
			
			
		
			cout << "\n\n";
			cout << "Enter Student ID\n";
			cin  >> id;
			
			cout << "Enter course code\n";
			cin  >> code;
			
			cout << "Enter grade\n";
			cin  >> grade;
			
			obj.enter_student_grade(id,code,grade);
			system("CLS");
			
			//Display scoresheet
			obj.view_score_sheet();

			cout << "Do you want to record some more? (Y/N)\n";
			cin  >> option_enter_grade;
			option_enter_grade = tolower(option_enter_grade);
			if(option_enter_grade == 'n') {
				option = 'm';
				break;
			} else {
				option = '5';
			}
			
		}
		//END OF CODE TO ENTER STUDENT GRADE
		
		//CODE TO PRINT ACADEMIC RECORD
		while(option == '6') {
			string id;
			
			system("CLS");
			cout << "STUDENT'S ACADEMIC RECORD PORTAL' \n";
		
			cout << "\n\n";
			//Display all students
			obj.display_all_students();
		
			cout << "\n\n";
			cout << "Enter Student ID\n";
			cin  >> id;		
			
			system("CLS");
			
			//Display academic record
			obj.print_academic_record(id);

			cout << "Do you want to print some more? (Y/N)\n";
			cin  >> option_print_record;
			option_print_record = tolower(option_print_record);
			if(option_print_record == 'n') {
				option = 'm';
				break;
			} else {
				option = '6';
			}
			
		}
		//END OF CODE TO PRINT ACADEMIC RECORD
		
		cout << "\n\n";
		cout << "Please enter 'm' to go to main menu \n";
		cin  >> main_menu;	
		main_menu = tolower(main_menu);
	} while(main_menu == 'm');

}
