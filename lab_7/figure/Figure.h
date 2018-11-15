/* 
 * File:   Figure.h
 * Author: dvdemon
 *
 * Created on August 30, 2015, 6:33 PM
 */

#ifndef FIGURE_H
#define	FIGURE_H

#include <cstdlib>
#include <iostream>
#include <memory>

class Figure {
public:
    virtual double Square() const = 0;
    virtual void   Print() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        std::cout<<"\t\t";
        figure.Print();
        std::cout<<"\t\tS = "<<figure.Square();
        std::cout<< std::endl;
        return os;
    };
    virtual char getType() const =0;
    virtual ~Figure() {};



};

#endif	/* FIGURE_H */

