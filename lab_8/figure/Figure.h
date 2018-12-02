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
        figure.Print();
        std::cout<<"S = "<<figure.Square();
        std::cout<< std::endl;
        return os;
    };
    bool operator<(const Figure& other) {
        return Square() < other.Square();
    }
    bool operator>(const Figure& other) {
        return Square() > other.Square();
    }
    bool operator<=(const Figure& other) {
        return Square() <= other.Square();
    }
    bool operator>=(const Figure& other) {
        return Square() >= other.Square();
    }
    bool operator==(const Figure& other) {
        return Square() == other.Square();
    }
    virtual ~Figure() {};



};

#endif	/* FIGURE_H */

