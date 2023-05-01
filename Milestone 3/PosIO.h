


#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_
#include <iostream>
#include<fstream>

namespace sdds {

	class PosIO {
	public:
		virtual std::ostream& write(std::ostream& ostr)const=0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
		virtual std::ifstream& load(std::ifstream& ifstr)= 0;
		virtual ~PosIO() {};
		

	};
	std::ostream& operator<<(std::ostream& ostr, const PosIO& pos_io);//ostream insertion
	std::ofstream& operator<<(std::ofstream& ofstr,const PosIO& pos_io);//ofstream insertion

	std::istream& operator>>(std::istream& istr, PosIO& pos_io);//istream insertion
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos_io);//ifstream insertion
	

}
#endif