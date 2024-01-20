#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>  

class Brain{
    protected:
        std::string _ideas[100];

    public:
		//orthodox canonical form
        Brain(); 
        Brain(const Brain& src);
        Brain &operator =(const Brain &another);
        virtual ~Brain();

		//getter & setter
		const std::string* getIdeas() const;

		void  setIdeas(const std::string* ideas, std::size_t size);

};

#endif
