#include <iostream>
#include <limits>

#ifndef DATE_HPP
#define DATE_HPP

struct Date{
	int year;
	int month;
	int day;

	void input(){
		do{
			std::cout<<"Enter year: ";
			std::cin>>year;
		}while(year < 2020 || year > 2050);

        do{
            std::cout<<"Enter month: ";
			std::cin>>month;
		}while(month < 1 || month > 12);

		do{
			std::cout<<"Enter day: ";
			std::cin>>day;
		}while(day < 1 || day > 31);

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}

	friend std::ostream& operator<<(std::ostream& os, const Date& dat){
		os<<dat.year<<"-"<<dat.month<<"-"<<dat.day;
		return os;
	}

};

#endif